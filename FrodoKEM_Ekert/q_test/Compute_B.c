#include "Compute_B.h"

void compute_B(uint16_t A[FRODO_N][FRODO_N], 
               int16_t S[N_DIM][N_DIM], 
               int16_t E[N_DIM][N_DIM], 
               uint16_t B[N_DIM][N_DIM]) {
    
    for (int i = 0; i < FRODO_N; i++) {
        for (int j = 0; j < FRODO_N; j++) {
            int32_t sum = 0;

            // 1. Matrix Multiplication: A * S
            for (int k = 0; k < FRODO_N; k++) {
                sum += (int32_t)A[i][k] * S[k][j];
            }

            // 2. Add Error: (A * S) + E [cite: 361]
            sum += E[i][j];

            // 3. Modular Reduction: sum mod q 
            // ใช้สูตรป้องกันค่าติดลบเพื่อให้ผลลัพธ์อยู่ในช่วง [0, q-1]
            uint16_t res = (uint16_t)((sum % FRODO_Q + FRODO_Q) % FRODO_Q);
            
            B[i][j] = res;
        }
    }
}