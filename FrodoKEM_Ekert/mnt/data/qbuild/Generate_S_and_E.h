#ifndef GENERATE_S_AND_E_H
#define GENERATE_S_AND_E_H

#include <stdint.h>
#include "Generate_A.h"

void generate_S_matrix(int16_t S[FRODO_N][FRODO_N]);
void generate_E_matrix(int16_t E[FRODO_N][FRODO_N]);

#endif
