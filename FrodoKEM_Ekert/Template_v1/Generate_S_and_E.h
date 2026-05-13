#ifndef GENERATE_S_AND_E_H
#define GENERATE_S_AND_E_H

#include <stdint.h>

// พารามิเตอร์สำหรับ Nano Scale Testing 
#define N_DIM 2        // มิติเมทริกซ์ n x n
#define MOD_Q 32768    // ค่า Modulus q = 2^15 

// ฟังก์ชันสำหรับสุ่มค่า S และ E ตามรูปแบบ FrodoKEM Original
void generate_S_matrix(int16_t S[N_DIM][N_DIM]);
void generate_E_matrix(int16_t E[N_DIM][N_DIM]);

#endif