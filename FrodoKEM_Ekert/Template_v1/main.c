#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> // <--- เพิ่มสำหรับฟังก์ชัน sqrt()
#include "Generate_A.h"
#include "Generate_S_and_E.h"
#include "Compute_B.h"
#include "Attack.h"

#define NUM_TRIALS 10000 

int main() {
    uint8_t seed_A[FRODO_SEED_LEN];
    uint16_t A[FRODO_N][FRODO_N];
    int16_t S[N_DIM][N_DIM], E[N_DIM][N_DIM];
    int16_t recovered_S[N_DIM][N_DIM];
    uint16_t B[N_DIM][N_DIM];
    
    double total_time = 0;
    double sq_total_time = 0; // สำหรับคำนวณ Variance
    int success_count = 0;

    srand(time(NULL)); 

    printf("--- Phase 1: Exhaustive Search Analysis (%d Trials) ---\n", NUM_TRIALS);

    for (int t = 0; t < NUM_TRIALS; t++) {
        // 1. สร้างพารามิเตอร์ใหม่ (v1 baseline) [cite: 104, 105]
        for(int i=0; i<FRODO_SEED_LEN; i++) seed_A[i] = rand() % 256;
        expand_matrix_A(seed_A, A);
        generate_S_matrix(S);
        generate_E_matrix(E);
        compute_B(A, S, E, B); // B = AS + E mod q [cite: 295]

        // 2. เริ่มการโจมตีและจับเวลา [cite: 104, 107]
        clock_t start = clock();
        int found = brute_force_attack(A, B, recovered_S); 
        clock_t end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        // 3. บันทึกสถิติเพื่อการวิเคราะห์ภายหลัง [cite: 104, 109, 141]
        if (found) {
            int match = 1;
            for(int i=0; i<N_DIM; i++)
                for(int j=0; j<N_DIM; j++)
                    if(S[i][j] != recovered_S[i][j]) match = 0;
            
            if (match) success_count++;
        }
        
        total_time += time_spent;
        sq_total_time += (time_spent * time_spent); // เก็บผลรวมกำลังสอง

        // แสดงความคืบหน้าทุก 10,000 รอบ
        if ((t + 1) % 10000 == 0) {
            printf("Progress: %d/%d trials completed...\n", t + 1, NUM_TRIALS);
        }
    }

    // 4. คำนวณค่าสถิติเชิงลึก [cite: 101, 109]
    double mean = total_time / NUM_TRIALS;
    // สูตร Variance: (Sum(X^2) - (Sum(X)^2 / N)) / (N - 1)
    double variance = (sq_total_time - (total_time * total_time) / NUM_TRIALS) / (NUM_TRIALS - 1);
    double std_dev = sqrt(variance);

    printf("\n--- Statistical Results (Baseline v1) ---\n");
    printf("Average Time per Attack: %.10f seconds\n", mean);
    printf("Variance:                %.10e\n", variance);
    printf("Standard Deviation:      %.10f seconds\n", std_dev);
    printf("Success Rate:            %d/%d (%.4f%%)\n", 
           success_count, NUM_TRIALS, ((double)success_count/NUM_TRIALS)*100);

    return 0;
}