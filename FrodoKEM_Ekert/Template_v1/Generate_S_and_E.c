#include "Generate_S_and_E.h"
#include <openssl/rand.h>
#include <stdio.h>

/**
 * ตาราง CDF สำหรับ Frodo-640 (NIST Standard)
 * ค่าเหล่านี้กำหนดความน่าจะเป็นของ Error ในช่วง [0, 12]
 * แล้วจึงนำมาสะท้อน (Mirror) เพื่อให้ได้ช่วง [-12, 12]
 */
static const uint16_t frodo640_cdf_table[] = {
    9288, 26312, 38256, 45874, 50359, 52766, 53977, 54514, 54721, 54784, 54803, 54808, 54810
};

int16_t sample_chi() {
    uint16_t rand_val;
    // ใช้ 2 bytes เพื่อความละเอียด 16-bit (0-65535)
    RAND_bytes((uint8_t *)&rand_val, 2);
    
    // บิตแรกใช้กำหนดเครื่องหมาย (Sign bit)
    uint16_t sign = rand_val & 0x1;
    uint16_t sample = rand_val >> 1; // ค่าสุ่มที่เหลือใช้เทียบ CDF
    
    int16_t e = 0;
    int table_size = sizeof(frodo640_cdf_table) / sizeof(frodo640_cdf_table[0]);

    // เปรียบเทียบกับตาราง CDF เพื่อหาค่า Error
    for (int i = 0; i < table_size - 1; i++) {
        if (sample > frodo640_cdf_table[i]) {
            e++;
        }
    }

    // ถ้า sign bit เป็น 1 และค่าไม่ใช่ 0 ให้ติดลบ
    if (sign == 1 && e != 0) {
        e = -e;
    }

    return e;
}

// สร้างเมทริกซ์ความลับ S (ใช้ค่าจากการกระจายตัว Chi)
void generate_S_matrix(int16_t S[N_DIM][N_DIM]) {
    for (int i = 0; i < N_DIM; i++) {
        for (int j = 0; j < N_DIM; j++) {
            S[i][j] = sample_chi();
        }
    }
}

// สร้างเมทริกซ์ความคลาดเคลื่อน E (ใช้ค่าจากการกระจายตัว Chi)
void generate_E_matrix(int16_t E[N_DIM][N_DIM]) {
    for (int i = 0; i < N_DIM; i++) {
        for (int j = 0; j < N_DIM; j++) {
            E[i][j] = sample_chi();
        }
    }
}