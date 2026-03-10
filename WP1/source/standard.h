#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

/* Windows compatibility shims for POSIX functions */
#ifdef _WIN32
  #ifndef M_PI
    #define M_PI 3.14159265358979323846
  #endif
  /* drand48() returns double in [0,1) - POSIX only */
  inline double drand48() { return (double)rand() / ((double)RAND_MAX + 1.0); }
  inline void srand48(long seed) { srand((unsigned int)seed); }
  /* strncasecmp is _strnicmp on Windows */
  #define strncasecmp _strnicmp
#endif
