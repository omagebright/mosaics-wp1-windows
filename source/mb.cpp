//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <iostream.h>
//#include <iomanip.h>

#include "standard.h"

//#define M_PI 3.14159265358979323846

float ran1(long * );

double mb(double m, double T, long* seed) 
// Maxwel Boltzman sampling of particle velocities
// m: mass, T: temperature  
 {
   double sig,chi,psi,eta;
   double v;

   sig = sqrt(T/m);
   chi = ran1(seed);
   psi = ran1(seed);
   eta = sqrt(-log(chi+1.e-30))*sqrt(2.0)*cos(2.0*M_PI*psi);
   v   = sig*eta;
   
   return v;
 }  
