#define magic_timing_begin(cycleLo, cycleHi) {\
    /* asm volatile( "rdtsc": "=a" (cycleLo), "=d" (cycleHi));*/ \
	asm volatile ("rdcycle %0" : "=r" (cycleLo)); \
}\

#define magic_timing_end(cycleLo, cycleHi) {\
    unsigned tempCycleLo, tempCycleHi; \
    /*asm volatile( "rdtsc": "=a" (tempCycleLo), "=d" (tempCycleHi));*/ \
	asm volatile ("rdcycle %0" : "=r" (tempcycleLo)); \
    cycleLo = tempCycleLo-cycleLo;\
    /*cycleHi = tempCycleHi - cycleHi;*/\
}\



#define magic_timing_report(cycleLo, cycleHi) {\
    printf("Timing report: %d %d\n", cycleLo, cycleHi); \
}\

#else
#define magic_timing_begin(cycleLo, cycleHi) {\
     asm volatile( "rdtsc": "=a" (cycleLo), "=d" (cycleHi)); \
    /*    asm volatile ("rdcycle %0" : "=r" (cycleLo));*/ \
}\

#define magic_timing_end(cycleLo, cycleHi) {\
    unsigned tempCycleLo, tempCycleHi; \
    asm volatile( "rdtsc": "=a" (tempCycleLo), "=d" (tempCycleHi)); \
    /*    asm volatile ("rdcycle %0" : "=r" (tempcycleLo)); */\
    cycleLo = tempCycleLo-cycleLo;\
    cycleHi = tempCycleHi - cycleHi;\
}\



#define magic_timing_report(cycleLo, cycleHi) {\
    printf("Timing report: %d %d\n", cycleLo, cycleHi); \
}\