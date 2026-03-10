#include "standard.h"
#include "definitions.h"
#include "typedefs.h"
#include "utillib.h"

/*=========================================================================*/
void partition(double *T, double *H, 
               double T0, double E_lower, double E_upper, double E_gap, int K) 
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

  int i;
  double c,l1,l2; 
  double H0   = E_lower;
  double HKp1 = E_upper;
  double* H_  = new double[K+2];
     
  for (i=0;i<=K+1;i++) {
      H_[i] = pow(E_gap,i);
  }

  l1 = H_[K+1] - H_[0];  
  l2 = HKp1 - H0;

  LINE
  print_doubleline();
  cout << " Energy/Temperature Partitioning " <<endl;
  print_line();

  cout << " Levels in energy partitioning " << endl << endl;  

  for (i=0;i<=K+1;i++) {
      H[i] = H0+(H_[i]-H_[0])*l2/l1;
      cout << setprecision(3) << H[i] << " "; 
  }
  c = (H[1] - H[0])/T0;  // such that T[0] = T0
 
  cout << endl << endl;
  cout << " Temperature ladder" << endl << endl;
  
  for (i=0;i<=K;i++) {   
      T[i] = (H[i+1]-H[i])/c;
      cout << setprecision(3) << T[i] << " "; 
  }      
  cout << endl << endl;

  cout << "current c value = (E[1] - E0)/T0 " << (H[1] - H[0])/T[0] << endl; 

  print_line();
  cout << " Energy/Temperature Partitioning" <<endl;
  print_doubleline();
  LINE

/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/

