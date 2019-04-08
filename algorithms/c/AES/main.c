/** 
 * 128 bit AES
 * key size: 16 bit, block size: 16 bit, rounds: 10
 *
 * @author Marcus Östling
 */
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // memcpy

#define BLOCK_SIZE 16
#define KEY_SIZE 16
#define NB 4
#define NK 4
#define NR 10 // Number of rounds

// S-box, used for SubBytes()
static const uint8_t sbox[256] = {
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

/* Round constant */
static const uint8_t rcon[11] = {
        0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 
};

void sub_bytes(uint8_t state[NB][NB])
{
        for (uint8_t i = 0; i < NB; i++) {
                for (uint8_t j = 0; j < NB; j++) {
                        state[i][j] = sbox[state[i][j]];
                }
        }
}

void shift_rows(uint8_t state[NB][NB])
{
        for (uint8_t i = 1; i < NB; i++) {
                for(uint8_t shifts = 0; shifts < i; shifts++) {
                        uint8_t tmp = state[0][i];
                        state[0][i] = state[1][i];
                        state[1][i] = state[2][i];
                        state[2][i] = state[3][i];
                        state[3][i] = tmp;
                }
        }
}

void mix_columns(uint8_t state[NB][NB])
{
        /* Source: https://en.wikipedia.org/wiki/Rijndael_MixColumns */
        for (uint8_t i = 0; i < NB; i++) {
                unsigned char a[4];
                unsigned char b[4];
                unsigned char c;
                unsigned char h;
                for (c = 0; c < 4; c++) {
                        a[c] = state[i][c];
                        h = (unsigned char)((signed char)state[i][c] >> 7); 
                        b[c] = state[i][c] << 1; 
                        b[c] ^= 0x1B & h;
                }
                state[i][0] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1];
                state[i][1] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2];
                state[i][2] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3];
                state[i][3] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0];
        }
}

void add_round_key(uint8_t state[NB][NB], uint8_t round_keys[NB*(NR+1)][NB], uint8_t round)
{
        for (uint8_t i = 0; i < NB; i++) {
                for (uint8_t j = 0; j < NB; j++) {
                        state[i][j] ^= round_keys[round*NB+i][j];
                }
        }
}

void key_schedule(uint8_t in_key[NB][NB], uint8_t round_keys[NB*(NR+1)][NB])
{
        for (uint8_t i = 0; i < NB; i++) {
                for (uint8_t j = 0; j < NB; j++) {
                        round_keys[i][j] = in_key[i][j];
                }
        }

        for (uint8_t i = NB; i < NB*(NR+1); i++) {
                memcpy(round_keys[i], round_keys[i-1], NB);

                if (i % NB == 0) {
                        // RotWord
                        int8_t tmp = round_keys[i][0];
                        round_keys[i][0] = round_keys[i][1]; 
                        round_keys[i][1] = round_keys[i][2]; 
                        round_keys[i][2] = round_keys[i][3]; 
                        round_keys[i][3] = tmp; 

                        // SubWord
                        round_keys[i][0] = sbox[round_keys[i][0]];
                        round_keys[i][1] = sbox[round_keys[i][1]];
                        round_keys[i][2] = sbox[round_keys[i][2]];
                        round_keys[i][3] = sbox[round_keys[i][3]];
                        
                        // rcon
                        round_keys[i][0] ^= rcon[i/NK];
                }

                round_keys[i][0] ^= round_keys[i-NK][0];
                round_keys[i][1] ^= round_keys[i-NK][1];
                round_keys[i][2] ^= round_keys[i-NK][2];
                round_keys[i][3] ^= round_keys[i-NK][3];
        }
}

int main(void)
{
        uint8_t key[NB][NB];
        uint8_t round_keys[NB*(NR+1)][NB];
        uint8_t state[4][4];

        // read key
        read(0, &key[0], KEY_SIZE);
        key_schedule(key, round_keys);

        //read blocks
        while(read(0, &state, BLOCK_SIZE) > 0) {
                add_round_key(state, round_keys, 0);

                for(uint8_t r = 1; r < NR; r++) {
                        sub_bytes(state);
                        shift_rows(state);
                        mix_columns(state);
                        add_round_key(state, round_keys, r);
                }

                sub_bytes(state);
                shift_rows(state);
                add_round_key(state, round_keys, NR);
                write(1, state, BLOCK_SIZE);
        }

        return 0;
}
