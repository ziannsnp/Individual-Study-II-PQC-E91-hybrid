#include "Compute_B.h"
#include <stdint.h>

void compute_B(uint16_t A[FRODO_N][FRODO_N],
               int16_t S[FRODO_N][FRODO_N],
               int16_t E[FRODO_N][FRODO_N],
               uint16_t B[FRODO_N][FRODO_N]) {
    for (int i = 0; i < FRODO_N; i++) {
        for (int j = 0; j < FRODO_N; j++) {
            int32_t sum = 0;

            for (int k = 0; k < FRODO_N; k++) {
                sum += (int32_t)A[i][k] * S[k][j];
            }

            sum += E[i][j];
            B[i][j] = (uint16_t)((sum % FRODO_Q + FRODO_Q) % FRODO_Q);
        }
    }
}
