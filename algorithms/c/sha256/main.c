/** 
 * SHA-256
 *
 * @author Marcus Östling
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))
#define ROTL(x, n) ((x << n) | (x >> (32 - n)))
#define SHR(x, n) (x >> n)
#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SIGMAs0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define SIGMAs1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))
#define HEX_DECODE(x) ((x < 'a') ? (x-'0') : (x-'a'+10))
#define HEX_ENCODE(x) ((x < 10) ? (x+'0') : (x+'a'-10))

/* SHA-256 initial hash values */
uint32_t init_hash_value[8] =
{
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
};

/* SHA-256 constants */
uint32_t K[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void print_hash(uint32_t hash[8])
{
        for (uint32_t i = 0; i < 8; i++) {
                for (uint32_t j = 8; j > 0; j--) {
                        uint32_t mask = (uint32_t)15 << ((j - 1) * 4);
                        uint32_t val = (hash[i] & mask) >> ((j - 1)*4);
                        printf("%c", HEX_ENCODE(val));
                }
        }
}

int main(void)
{
        while(!feof(stdin)) {
                char chr;
                size_t chr_cnt = 0;
                size_t blk_size = 16;
                size_t num_blks = 1;

                uint32_t* message = (uint32_t*)calloc(
                                blk_size*num_blks,
                                sizeof(uint32_t));

                /* Read message */
                while (scanf("%c", &chr) == 1 && chr != '\n') {
                        if (chr_cnt != 0 && chr_cnt % 128 == 0) {
                                num_blks++;
                                message = (uint32_t*)realloc(
                                                message, 
                                                blk_size*num_blks*sizeof(uint32_t));
                                for (size_t i = blk_size*num_blks-1; 
                                                i < num_blks*blk_size; i++) {
                                        message[i] = 0; 
                                }
                        }
                        message[chr_cnt/8] |= (uint32_t)HEX_DECODE(chr)<<(28 - (chr_cnt%8)*4);
                        chr_cnt++;
                }
                if (feof(stdin)) break;

                /* Padding */
                if (chr_cnt*4 >= 448) {
                        num_blks++;
                        message = (uint32_t*)realloc(
                                        message, 
                                        blk_size*num_blks*sizeof(uint32_t));
                        for (size_t i = blk_size*(num_blks-1); 
                                        i < num_blks*blk_size; i++) {
                                message[i] = 0; 
                        }
                }

                /* Parsing */
                message[chr_cnt/8] |= ((uint32_t)1<<(31-(chr_cnt%8)*4));
                message[num_blks*blk_size-1] |= 4*chr_cnt;

                /* Init hash */
                uint32_t hash_value[8];
                memcpy(hash_value, init_hash_value, 8*sizeof(uint32_t));

                /* Hash computation */
                for (size_t i = 0; i < num_blks; i++) {

                        /* Prepare the message schedule */
                        uint32_t W[64];
                        for (size_t t = 0; t < 16; t++) {
                                size_t offset = i*16;
                                W[t] = message[offset+t];
                        }
                        for (size_t t = 16; t < 64; t++) {
                                W[t] = SIGMAs1(W[t-2]) 
                                        + W[t-7] 
                                        + SIGMAs0(W[t-15]) 
                                        + W[t-16];
                        }

                        /* Initialize the eight working variables */
                        uint32_t a = hash_value[0];
                        uint32_t b = hash_value[1];
                        uint32_t c = hash_value[2];
                        uint32_t d = hash_value[3];
                        uint32_t e = hash_value[4];
                        uint32_t f = hash_value[5];
                        uint32_t g = hash_value[6];
                        uint32_t h = hash_value[7];
                        for (uint32_t t = 0; t < 64; t++) {
                                uint32_t t1 = h + SIGMA1(e) + CH(e, f, g) + K[t] + W[t];
                                uint32_t t2 = SIGMA0(a) + MAJ(a, b, c);
                                h = g;
                                g = f;
                                f = e;
                                e = d + t1;
                                d = c;
                                c = b;
                                b = a;
                                a = t1 + t2;
                        }

                        hash_value[0] = a + hash_value[0];
                        hash_value[1] = b + hash_value[1];
                        hash_value[2] = c + hash_value[2];
                        hash_value[3] = d + hash_value[3];
                        hash_value[4] = e + hash_value[4];
                        hash_value[5] = f + hash_value[5];
                        hash_value[6] = g + hash_value[6];
                        hash_value[7] = h + hash_value[7];
                }
                print_hash(hash_value);
                printf("\n");

                /* Free memory */
                free(message);
        }
        return 0;
}
