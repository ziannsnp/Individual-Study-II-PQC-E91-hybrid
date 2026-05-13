#include "Generate_A.h"
#include <openssl/evp.h>

int expand_matrix_A(const uint8_t *seed, uint16_t matrix[FRODO_N][FRODO_N]) {
    EVP_MD_CTX *mdctx;
    // คำนวณจำนวนไบต์ที่ต้องใช้: N * N พิกัด * 2 ไบต์ต่อพิกัด
    size_t out_len = FRODO_N * FRODO_N * sizeof(uint16_t);
    uint8_t output[out_len];

    if ((mdctx = EVP_MD_CTX_new()) == NULL) return 0;

    // ใช้ SHAKE-128 เป็น XOF ตามระเบียบมาตรฐาน FrodoKEM
    if (EVP_DigestInit_ex(mdctx, EVP_shake128(), NULL) != 1) goto err;
    if (EVP_DigestUpdate(mdctx, seed, FRODO_SEED_LEN) != 1) goto err;
    
    // ดึงข้อมูลออกมาตามความยาวที่ต้องการ
    if (EVP_DigestFinalXOF(mdctx, output, out_len) != 1) goto err;

    // Mapping บิตสตริงลงใน Matrix A (Little-endian)
    for (int i = 0; i < FRODO_N; i++) {
        for (int j = 0; j < FRODO_N; j++) {
            int idx = (i * FRODO_N + j) * 2;
            // ประกอบไบต์และทำ Modulo q [cite: 291, 295]
            matrix[i][j] = ((uint16_t)output[idx] | ((uint16_t)output[idx+1] << 8)) % FRODO_Q;
        }
    }

    EVP_MD_CTX_free(mdctx);
    return 1;

err:
    EVP_MD_CTX_free(mdctx);
    return 0;
}