#ifndef ATTACK_H
#define ATTACK_H

#include "Generate_S_and_E.h"
#include "Compute_B.h"

// ขอบเขตการเดาค่าแต่ละพิกัดใน S อิงตามช่วงของ Chi Distribution [-12, 12]
#define SEARCH_RANGE 12 

/**
 * โจมตีเพื่อกู้คืน S จาก A และ B
 * @return 1 หากกู้คืนได้สำเร็จ, 0 หากล้มเหลว
 */
int brute_force_attack(uint16_t A[FRODO_N][FRODO_N], 
                       uint16_t B[N_DIM][N_DIM], 
                       int16_t recovered_S[N_DIM][N_DIM]);

#endif