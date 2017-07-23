#define MNOGO_DEFIS printf("\n\n\n\n------------------------------\n\n\n\n")
#ifdef DEBUG
#define D_MNOGO_DEFIS printf("\n\n\n\n------------------------------\n\n\n\n")
#define Gde printf("Line %d, Function %s\n", __LINE__, __PRETTY_FUNCTION__)
#define Err ;\
printf("Errno %x\n", errno);\
Gde;
#define SUPER_NOT_OK_DUMP(wat);\
{\
    if (!wat##_OK(This)){\
        wat##_Dump(This);\
        printf("All will have been broken down in a moment if you tap any key\n");\
        assert(!"Ok_failed");\
    };\
}
#define p(n, code) if (DEBUG >= n) {printf code;}
#define d(n, code) if (DEBUG >= n) {code;}
#else
#define D_MNOGO_DEFIS
#define SUPER_NOT_OK_DUMP(wat)
#define DBG 0
#define d(arg, code)
#define p(arg, code)
#define Gde
#define Err
#endif
