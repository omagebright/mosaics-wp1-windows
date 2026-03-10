#define P16 setprecision(16)
//#define M_PI 3.14159265358979323846
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MAXD 10000
#define MDISK 10000 
#define LINE printf("\n");
#define NMEM_MIN 100
#define BOLTZ 315777.0
#define KCAL 627.50921
#define EV 27.211396
#define NCHARMAX 128
#define LINE_NCHARMAX 30000
#define NNAMECHARMAX  20
#define TIME_CONV 0.0241888

#define MIN(A,B) (((A)<(B))?(A):(B))
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MAX3(A,B,C) (MAX(MAX((A),(B)),(C)))

extern char err_msg[LINE_NCHARMAX];
extern char wrn_msg[LINE_NCHARMAX];

class System;
float ran1(long *);
double mb(double,double,long *);
double vpot(double, int); 
double force(double, int);
void statistics(System *, int, int);
void output(System *, int, int, int);
void partition(double *, double *, double, double, double, double, int);
void EEMC_title(char *);
void EEMC_end();

class General;
void parse_input(char *, General& );
 
