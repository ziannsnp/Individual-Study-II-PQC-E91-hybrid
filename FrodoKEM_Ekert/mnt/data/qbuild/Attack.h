#ifndef ATTACK_H
#define ATTACK_H

#include "Compute_B.h"

#ifndef SEARCH_RANGE
#define SEARCH_RANGE 12
#endif

int brute_force_attack(uint16_t A[FRODO_N][FRODO_N],
                       uint16_t B[FRODO_N][FRODO_N],
                       int16_t recovered_S[FRODO_N][FRODO_N]);

#endif
