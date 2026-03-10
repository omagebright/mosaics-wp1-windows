#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

#ifdef _WIN32
  #ifndef M_PI
    #define M_PI 3.14159265358979323846
  #endif
  #ifndef M_PI_2
    #define M_PI_2 1.57079632679489661923
  #endif
  inline double drand48() { return (double)rand() / ((double)RAND_MAX + 1.0); }
  inline void srand48(long seed) { srand((unsigned int)seed); }
  #define strncasecmp _strnicmp
  #define strcasecmp _stricmp
#endif
