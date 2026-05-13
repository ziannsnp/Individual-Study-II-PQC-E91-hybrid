#include "Attack.h"

int brute_force_attack(uint16_t A[FRODO_N][FRODO_N], 
                       uint16_t B[N_DIM][N_DIM], 
                       int16_t recovered_S[N_DIM][N_DIM]) {
    
    int16_t guess_S[N_DIM][N_DIM];
    
    // วนลูปเดาค่าทุกพิกัดของ S (สำหรับ 2x2 จะมี 4 พิกัด)
    for (int s00 = -SEARCH_RANGE; s00 <= SEARCH_RANGE; s00++) {
    for (int s01 = -SEARCH_RANGE; s01 <= SEARCH_RANGE; s01++) {
    for (int s10 = -SEARCH_RANGE; s10 <= SEARCH_RANGE; s10++) {
    for (int s11 = -SEARCH_RANGE; s11 <= SEARCH_RANGE; s11++) {
        
        guess_S[0][0] = s00; guess_S[0][1] = s01;
        guess_S[1][0] = s10; guess_S[1][1] = s11;

        // ตรวจสอบความถูกต้องของคำตอบ
        int is_correct = 1;
        for (int i = 0; i < N_DIM; i++) {
            for (int j = 0; j < N_DIM; j++) {
                int32_t as_val = 0;
                for (int k = 0; k < FRODO_N; k++) {
                    as_val += (int32_t)A[i][k] * guess_S[k][j];
                }

                // คำนวณหา Error ที่ควรจะเป็น: E' = (B - AS) mod q 
                int16_t error_prime = (int16_t)((B[i][j] - as_val) % MOD_Q);
                
                // ปรับค่าให้อยู่ในขอบเขต Signed [-q/2, q/2] เพื่อเช็คความ "เล็ก"
                if (error_prime > MOD_Q / 2) error_prime -= MOD_Q;
                if (error_prime < -MOD_Q / 2) error_prime += MOD_Q;

                // ถ้า Error เกินขอบเขตมาตรฐาน แสดงว่า S ชุดนี้ไม่ใช่คำตอบ 
                if (error_prime < -SEARCH_RANGE || error_prime > SEARCH_RANGE) {
                    is_correct = 0;
                    break;
                }
            }
            if (!is_correct) break;
        }

        if (is_correct) {
            // บันทึกผลลัพธ์เมื่อเจอค่า S ที่ทำให้ Error เล็กตามเงื่อนไข [cite: 338]
            for(int r=0; r<N_DIM; r++)
                for(int c=0; c<N_DIM; c++) recovered_S[r][c] = guess_S[r][c];
            return 1; 
        }
    }
    }
    }
    }
    return 0; // โจมตีล้มเหลว
}