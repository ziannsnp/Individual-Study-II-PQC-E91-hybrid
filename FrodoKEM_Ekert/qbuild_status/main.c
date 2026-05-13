#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "Generate_A.h"
#include "Generate_S_and_E.h"
#include "Compute_B.h"
#include "Attack.h"

#define NUM_TRIALS 1000
#define PROGRESS_BAR_WIDTH 40

static void print_progress(int current, int total) {
    double percent = (total > 0) ? (100.0 * current / total) : 100.0;
    int filled = (int)((double)current * PROGRESS_BAR_WIDTH / total);

    printf("\rProgress: [");
    for (int i = 0; i < PROGRESS_BAR_WIDTH; i++) {
        if (i < filled) {
            putchar('=');
        } else if (i == filled && current < total) {
            putchar('>');
        } else {
            putchar(' ');
        }
    }
    printf("] %4d/%d (%.1f%%)", current, total, percent);
    fflush(stdout);

    if (current == total) {
        putchar('\n');
    }
}

int main(void) {
    uint8_t seed_A[FRODO_SEED_LEN];
    uint16_t A[FRODO_N][FRODO_N];
    int16_t S[FRODO_N][FRODO_N], E[FRODO_N][FRODO_N];
    int16_t recovered_S[FRODO_N][FRODO_N];
    uint16_t B[FRODO_N][FRODO_N];

    double total_time = 0;
    double sq_total_time = 0;
    int success_count = 0;

    srand((unsigned int)time(NULL));

    printf("--- Phase 1: Exhaustive Search Analysis (%d Trials) ---\n", NUM_TRIALS);
    printf("Build parameters: N=%d, q=%d, SEARCH_RANGE=%d\n", FRODO_N, FRODO_Q, SEARCH_RANGE);

    print_progress(0, NUM_TRIALS);

    for (int t = 0; t < NUM_TRIALS; t++) {
        for (int i = 0; i < FRODO_SEED_LEN; i++) seed_A[i] = rand() % 256;
        if (!expand_matrix_A(seed_A, A)) {
            fprintf(stderr, "expand_matrix_A failed\n");
            return 1;
        }
        generate_S_matrix(S);
        generate_E_matrix(E);
        compute_B(A, S, E, B);

        clock_t start = clock();
        int found = brute_force_attack(A, B, recovered_S);
        clock_t end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        if (found) {
            int match = 1;
            for (int i = 0; i < FRODO_N; i++) {
                for (int j = 0; j < FRODO_N; j++) {
                    if (S[i][j] != recovered_S[i][j]) match = 0;
                }
            }
            if (match) success_count++;
        }

        total_time += time_spent;
        sq_total_time += time_spent * time_spent;

        /*
         * Update the status bar only after timing has finished,
         * so progress-display overhead is NOT included in the benchmark.
         */
        print_progress(t + 1, NUM_TRIALS);
    }

    double mean = total_time / NUM_TRIALS;
    double variance = (sq_total_time - (total_time * total_time) / NUM_TRIALS) / (NUM_TRIALS - 1);
    double std_dev = sqrt(variance);

    printf("\n--- Statistical Results ---\n");
    printf("Average Time per Attack: %.10f seconds\n", mean);
    printf("Variance:                %.10e\n", variance);
    printf("Standard Deviation:      %.10f seconds\n", std_dev);
    printf("Success Rate:            %d/%d (%.4f%%)\n",
           success_count, NUM_TRIALS, ((double)success_count / NUM_TRIALS) * 100);

    return 0;
}
