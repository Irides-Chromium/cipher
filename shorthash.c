// Hash function by Paul Hsieh SHORTENED VERSION
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define _s switch
#define _f for
#define _c case
#define _b break
#define _r return
#define g(d) (*((uint16_t*) (d)))
typedef uint32_t u;
typedef char c;
typedef c*s;
typedef int i;

u h(s d, i l){u h=l,t;i r;r=l&3;l>>=2;_f(;l;l--){h+=g(d);t=(g(d+2)<<11)^h;h=(h<<16)^t;d+=4;h+=h>>11;}_s(r){_c 3:h+=g(d);h^=h<<16;h^=d[2]<<18;h+=h>>11;_b;_c 2:h+=g(d);h^=h<<11;h+=h>>17;_b;_c 1:h+=(c)*d;h^=h<<10;h+=h>>1;}h^=h<<3;h+=h>>5;h^=h<<4;h+=h>>17;h^=h<<25;h+=h>>6;_r h;}

int main (int argc, char **argv) {
    printf("%x\n", h(argv[1], strlen(argv[1])));
    return 0;
}
