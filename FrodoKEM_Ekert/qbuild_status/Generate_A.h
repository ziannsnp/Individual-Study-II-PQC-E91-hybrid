#ifndef GENERATE_A_H
#define GENERATE_A_H

#include <stdint.h>
#include <stddef.h>

#ifndef FRODO_N
#define FRODO_N 2
#endif

#ifndef FRODO_Q
#define FRODO_Q 32768
#endif

#define FRODO_SEED_LEN 16

int expand_matrix_A(const uint8_t *seed, uint16_t matrix[FRODO_N][FRODO_N]);

#endif
