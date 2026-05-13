#include "Generate_S_and_E.h"
#include <openssl/rand.h>
#include <stdint.h>

static const uint16_t frodo640_cdf_table[] = {
    9288, 26312, 38256, 45874, 50359, 52766, 53977, 54514, 54721, 54784, 54803, 54808, 54810
};

static int16_t sample_chi(void) {
    uint16_t rand_val;
    RAND_bytes((uint8_t *)&rand_val, 2);

    uint16_t sign = rand_val & 0x1;
    uint16_t sample = rand_val >> 1;

    int16_t e = 0;
    int table_size = (int)(sizeof(frodo640_cdf_table) / sizeof(frodo640_cdf_table[0]));

    for (int i = 0; i < table_size - 1; i++) {
        if (sample > frodo640_cdf_table[i]) {
            e++;
        }
    }

    if (sign == 1 && e != 0) {
        e = -e;
    }

    return e;
}

void generate_S_matrix(int16_t S[FRODO_N][FRODO_N]) {
    for (int i = 0; i < FRODO_N; i++) {
        for (int j = 0; j < FRODO_N; j++) {
            S[i][j] = sample_chi();
        }
    }
}

void generate_E_matrix(int16_t E[FRODO_N][FRODO_N]) {
    for (int i = 0; i < FRODO_N; i++) {
        for (int j = 0; j < FRODO_N; j++) {
            E[i][j] = sample_chi();
        }
    }
}
