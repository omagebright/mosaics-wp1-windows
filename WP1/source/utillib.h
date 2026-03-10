#define TYPE_INT    1
#define TYPE_CHAR   2
#define TYPE_FLOAT  3
#define TYPE_DOUBLE 4

/*----------------------------------------------------------------------*/
int atom_entry(char *);

int stride_entry(char *);

int torcompl_entry(char *);

int closcompl_entry(char *);

int cblc_entry(char *);

int end_entry(char *);

void get_stride(char *, char *);

void get_torcompl(char *, char *);

void get_cblc(char *, char *);

void get_closcompl(char *, char *);

void print_line();

void print_doubleline();

void empty_line();

void PAS_title();

void PAS_end();

void rand_block(double *, int n);

void durand(double *,int &, double *,int &);

double ran_essl(double *);

void gaussran(int, int *, int *, double *, double *);

double switchFun(double );

double derSwitchFun(double );

int    strReadArray(char *, int, int,  void *);

void   cutEndBlank(char *);

void   cutHeadEndBlank(char *);

int    readOneEntry(FILE *, char, char, char, char *, int &);

int    readOneEntry2(FILE *, char, char, char, char *, int &);

int    getEntryName(char *, char, char, char *, char *&);

int    getKeyArgPair(char *, char *, char *, char, char, char, char *&);

void   barf(char *);

void errorMessage(char *);

void warnMessage(char *);

int wild_strcasecmp(const char *, const char *); /*wild char string comparison */

/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/* basic vector routines. */

void DZero(double *, int n);

void DCopy( double *, double *, int n);

void DScale(double, double *, int n);

void Daxpy(double, double *, double *, double *, int n);

double DDot(double *, double *, int n);

double DNorm(double *, int n);

void DCross(double *, double *, double *, int n);

/*-----------------------------------------------------------------------*/
/* basic metrix-vector routines */ 

void DMetrxVect(double **, double *, double *, int m, int n);

void DVectMetrx(double *, double **, double *, int m, int n);

/*-----------------------------------------------------------------------*/
/* basic metrix-metrix routines. */

void DMetrxMetrx( double **, double **, double **, int l, int m, int n); 


/*-----------------Legendre-Gauss polynormial routines------------------*/

int getLegenGauss(int, long double *, long double *, long double *);

long double legendre(int, long double);

int legendreArray(int, long double, long double *);

int sign(long double);

/*----------------------------------------------------------------------*/
double getCosTorsAngle(double *, double *, double *,
		       int, int, int, int);
void   moveGroupAtoms(double *, double *, double *,
		      int, int, int, int, double, int, int *);

/*----------------------------------------------------------------------*/
