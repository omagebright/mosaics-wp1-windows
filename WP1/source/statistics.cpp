#include "standard.h"
#include "definitions.h"
#include "typedefs.h"
#include "utillib.h"

/*=========================================================================*/
void statistics(System *X, int K, int type)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/
     
  int i;
  // acceptance ratio for Chains
  print_doubleline();
  cout << " Acceptance ratio for MH Chains " <<endl;
  print_line();
  cout << "       " <<  "# of accepted   ||  # of total   || acceptance ratio" << endl; 
  for (i=0;i<=K;i++) {
      cout <<" Chain "<<i;
      if (X[i].nprop == 0) { 
        cout <<" Not initialized yet => Increse # of steps " << endl;
      } else {
        cout <<"     "<< X[i].nacc <<'\t'; 
        cout <<"     "<<  X[i].nprop <<'\t'; 
        cout <<"     "<< (double)X[i].nacc/(double)X[i].nprop << endl;      
      }
  } 
  if ( type == 1 ) {/* PT */ 
   cout << endl << endl;
   cout << " Acceptance ratio for PT jumps " <<endl<<endl;
   cout << "       " <<  "# of accepted   ||  # of total   || acceptance ratio" << endl; 
   for (i=0;i<=K-1;i++) {
       cout <<" Chain "<<i; 
       if (X[i].nptprop == 0) { 
         cout <<" Not initialized yet  " << endl;
       } else {
         cout <<"     "<< X[i].nptacc <<'\t'; 
         cout <<"     "<<  X[i].nptprop <<'\t'; 
         cout <<"     "<< (double)X[i].nptacc/(double)X[i].nptprop << endl;      
      }
   }
  } 
  if ( type == 2 ) {/* EEMC */
   cout << endl << endl;
   cout << " Acceptance ratio for EE jumps " <<endl<<endl;
   cout << "       " <<  "# of accepted   ||  # of total   || acceptance ratio" << endl; 
   for (i=0;i<=K-1;i++) {
       cout <<" Chain "<<i; 
       if (X[i].neeprop == 0) { 
         cout <<" Not initialized yet  " << endl;
       } else {
         cout <<"     "<< X[i].neeacc <<'\t'; 
         cout <<"     "<<  X[i].neeprop <<'\t'; 
         cout <<"     "<< (double)X[i].neeacc/(double)X[i].neeprop << endl;      
      }
   }
  }
  print_line();
  cout << " Acceptance ratio for MH Chains " <<endl;
  print_doubleline();
  LINE
  LINE


/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/


