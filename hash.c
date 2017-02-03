// Hash function by Paul Hsieh
// Using int32_t instead of uint32_t to be compatible with the Java version
// #include "pstdint.h" /* Replace with <stdint.h> if appropriate */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
//                       +(uint32_t)(((const uint8_t *)(d))[0]) )

int16_t get16bits(const char *d) {
    return ((char) d[0] << 8) + (char) d[1];
}

int32_t SuperFastHash (const char * data, int len) {
    int32_t hash = len, tmp;
    int rem;

    if (len <= 0 || data == NULL) return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits(data);
        tmp    = (get16bits(data + 2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2 * 2;
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits(data);
                hash ^= hash << 16;
                hash ^= ((signed char) data[2]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits(data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char) *data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

int main (int argc, char **argv) {
    printf("%d\n", SuperFastHash(argv[1], strlen(argv[1])));
    //int i = atoi(argv[1]);
    //printf("%x\n", SuperFastHash(&i, 4));
    return 0;
}
