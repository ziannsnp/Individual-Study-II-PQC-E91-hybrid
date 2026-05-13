#include "Attack.h"
#include <stdint.h>
#include <string.h>

static int candidate_is_valid(uint16_t A[FRODO_N][FRODO_N],
                              uint16_t B[FRODO_N][FRODO_N],
                              int16_t guess_S[FRODO_N][FRODO_N]) {
    for (int i = 0; i < FRODO_N; i++) {
        for (int j = 0; j < FRODO_N; j++) {
            int32_t as_val = 0;
            for (int k = 0; k < FRODO_N; k++) {
                as_val += (int32_t)A[i][k] * guess_S[k][j];
            }

            int32_t error_prime = ((int32_t)B[i][j] - as_val) % FRODO_Q;
            if (error_prime > FRODO_Q / 2) error_prime -= FRODO_Q;
            if (error_prime < -FRODO_Q / 2) error_prime += FRODO_Q;

            if (error_prime < -SEARCH_RANGE || error_prime > SEARCH_RANGE) {
                return 0;
            }
        }
    }
    return 1;
}

static int search_recursive(uint16_t A[FRODO_N][FRODO_N],
                            uint16_t B[FRODO_N][FRODO_N],
                            int16_t guess_S[FRODO_N][FRODO_N],
                            int index,
                            int16_t recovered_S[FRODO_N][FRODO_N]) {
    int total_entries = FRODO_N * FRODO_N;
    if (index == total_entries) {
        if (candidate_is_valid(A, B, guess_S)) {
            memcpy(recovered_S, guess_S, sizeof(int16_t) * FRODO_N * FRODO_N);
            return 1;
        }
        return 0;
    }

    int row = index / FRODO_N;
    int col = index % FRODO_N;

    for (int val = -SEARCH_RANGE; val <= SEARCH_RANGE; val++) {
        guess_S[row][col] = (int16_t)val;
        if (search_recursive(A, B, guess_S, index + 1, recovered_S)) {
            return 1;
        }
    }

    return 0;
}

int brute_force_attack(uint16_t A[FRODO_N][FRODO_N],
                       uint16_t B[FRODO_N][FRODO_N],
                       int16_t recovered_S[FRODO_N][FRODO_N]) {
    int16_t guess_S[FRODO_N][FRODO_N];
    memset(guess_S, 0, sizeof(guess_S));
    return search_recursive(A, B, guess_S, 0, recovered_S);
}
