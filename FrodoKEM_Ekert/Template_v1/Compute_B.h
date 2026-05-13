#ifndef COMPUTE_B_H
#define COMPUTE_B_H

#include "Generate_A.h"
#include "Generate_S_and_E.h"

/**
 * คำนวณ Public Key B = (A * S + E) mod q
 * @param A: Matrix A (uint16_t) ขนาด N x N [cite: 281]
 * @param S: Secret Matrix S (int16_t) ขนาด N x N
 * @param E: Error Matrix E (int16_t) ขนาด N x N
 * @param B: Output Matrix B (uint16_t) ขนาด N x N
 */
void compute_B(uint16_t A[FRODO_N][FRODO_N], 
               int16_t S[N_DIM][N_DIM], 
               int16_t E[N_DIM][N_DIM], 
               uint16_t B[N_DIM][N_DIM]);

#endif