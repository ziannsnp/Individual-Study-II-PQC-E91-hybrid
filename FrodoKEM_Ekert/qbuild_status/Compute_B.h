#ifndef COMPUTE_B_H
#define COMPUTE_B_H

#include "Generate_A.h"
#include "Generate_S_and_E.h"

void compute_B(uint16_t A[FRODO_N][FRODO_N],
               int16_t S[FRODO_N][FRODO_N],
               int16_t E[FRODO_N][FRODO_N],
               uint16_t B[FRODO_N][FRODO_N]);

#endif
