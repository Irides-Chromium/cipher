#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>

#ifndef DEBUG
#   define DEBUG 1
#endif

#if DEBUG == 1
#   define PRINTINT(var) printf("\e[32mINT\e[0m %s::%d\n", #var, var);
#   define PRINTCHAR(var) printf("\e[33mCHAR\e[0m %s::%d <%c>\n", #var, var, var);
#   define PRINTLONG(var) printf("\e[34mLONG\e[0m %s::%ld\n", #var, var);
#   define PRINTPTR(var) printf("\e[35mPTR\e[0m %s::%p\n", #var, var);
#   define PRINTSTR(var) printf("\e[36mSTR\e[0m %s::%s\n", #var, var);
#   define CHECKPOINT() printf("\e[1;31mPASSED\e[0m line no. %d\n", __LINE__);
#   define HORI() puts("-------------------------------------");
#else
#   define PRINTINT(var) 
#   define PRINTCHAR(var) 
#   define PRINTLONG(var) 
#   define PRINTPTR(var) 
#   define PRINTSTR(var) 
#   define CHECKPOINT()
#   define HORI() 
#endif

char *scale(int cur, int res, char *num, bool *freeable) {
//          int, int, str -> str
// Default Settings
    bool caps = false, posi = true;
    *freeable = false;

    // Input
    if (cur == res || strcmp(num, "0") == 0) return num;
    if (cur < 2 || cur > 64 || res < 2 || res > 64) return NULL;
    if (num[0] == '-') {
        posi = false;
        num++;
    }
    int iresult = 0, unit = 1;
    // iresult: Intermediate result
    char *sresult = NULL, value;

    for (char *i = num + strlen(num) - 1; i >= num; i --) {
        value = *i;
        if (value > 47 && value < 58) value -= 48;
        else if (value > 64 && value < 92) value -= 55;
        else if (value > 96 && value < 123) value -= 61;
        else if (value == 64) value = 62;
        else if (value == 95) value = 63;
        if (value > cur) return NULL;
        iresult += value * unit;
        unit *= cur;
    }
    int len = log10(iresult) + 1;
    sresult = calloc(len + 1, sizeof(char));
    *freeable = true;
    snprintf(sresult, len + 1, "%d", iresult);

    // Output
    free(sresult);
    len = (int) (log(iresult) / log(res)) + 1;
    sresult = calloc(len + 1, sizeof(char));
    *freeable = true;
    char *ptr = sresult;
    ptr = len + sresult - 1;
    do {
        value = fmod(iresult, res);
        iresult /= (float) res;
        if (value < 10) value += 48;
        else if (value < 36) value += 55;
        else if (value < 62) value += 61;
        else if (value == 62) value = 64;
        else if (value == 63) value = 95;
        *ptr = value;
        ptr--;
    } while (iresult > 0);
    return sresult;
}

int main(int argc, char **argv) {
    if (argc != 4) return 1;
    bool f;
    char *s = scale(atoi(argv[1]), atoi(argv[2]), argv[3], &f);
    if (s) puts(s);
    if (f) free(s);
    return 0;
}
