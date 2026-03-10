#include "standard.h"
#include "definitions.h"

double vpot(double x, int type)
{//begin//
  double temp = 0.0;
  double L = 10.0;
  double a1 = 8.0;
  double a2 = 1.0;
  if (type == 1) {
     temp = a1/(a2*a2*a2*a2)*(x*x-a2*a2)*(x*x-a2*a2);
     return temp;
  }
  double coeff[21];
  int nc = 20;
  int i;
  #include "random.lib"
  for (i=1;i<=nc;i++) {
      temp += coeff[i]*sin( ((double)i)*2.0*M_PI*x/L );
  }
  return temp; 
}//end// 

double force(double x, int type)
{//begin//
  double temp = 0.0;
  double L = 10.0;
  double a1 = 8.0;
  double a2 = 1.0;
  if (type == 1) {
     temp = -4.0*x*a1/(a2*a2*a2*a2)*(x*x-a2*a2);
     return temp;
  }
  double coeff[21];
  int nc = 20;
  int i;
  #include "random.lib"
  for (i=1;i<=nc;i++) {
     temp -= coeff[i]*( ((double)i)*2.0*M_PI/L )
            *cos( ((double)i)*2.0*M_PI*x/L );
  }
  return temp; 
}//end// 
