#ifndef GENERATE_A_H
#define GENERATE_A_H

#include <stdint.h>
#include <stddef.h>

// กำหนดพารามิเตอร์ตามมาตรฐาน Frodo-640
#define FRODO_N 2       // มิติ N (ปรับเป็น 640 เมื่อรันระบบจริง) [cite: 281, 320]
#define FRODO_Q 32768   // Modulus q = 2^15 [cite: 282]
#define FRODO_SEED_LEN 16 // 128-bit seed A

/**
 * ขยาย Seed เป็น Matrix A
 * @param seed: pointer ไปยัง seed_A
 * @param matrix: อาเรย์ 2 มิติรับค่าเมทริกซ์ที่ขยายแล้ว
 * @return 1 หากสำเร็จ, 0 หากเกิดข้อผิดพลาด
 */
int expand_matrix_A(const uint8_t *seed, uint16_t matrix[FRODO_N][FRODO_N]);

#endif