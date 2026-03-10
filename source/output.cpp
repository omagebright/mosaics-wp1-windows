#include "standard.h"
#include "definitions.h"
#include "typedefs.h"

   static bool files_opened = false;
   static ofstream esurf;
   static ofstream ndist;
   static ofstream adist;
   static ofstream convd;
   static ofstream energy;

   static void ensure_open() {
     if (!files_opened) {
       esurf.open("esurf", ios::out);
       ndist.open("ndist", ios::out);
       adist.open("adist", ios::out);
       convd.open("convd", ios::out);
       energy.open("energy", ios::out);
       files_opened = true;
     }
   }

/*==========================================================================*/
void output(System *X, int K, int nstep, int type)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

    int i,k,ii,jj;
    int hdim;
    int system;
    double dmin, resol;
    double xi;

    ensure_open();
    hdim = X[0].hdim;
    dmin = X[0].dmin;
    resol = X[0].resol;
    system = X[0].pot_type; 

    if (type == 1) {//distribution//
        for (i=1;i<=hdim;i++) {
             xi = dmin + (i-0.5)*resol;
             ndist << xi;
             adist << xi;
             esurf  << xi <<'\t'<< vpot(xi,system) << endl;
             for (k=0;k<=K;k++) { 
                  ndist <<'\t'<< X[k].dist[i];
                  adist <<'\t'<< X[k].dista[i];
             }
             ndist << endl;
             adist << endl;
        }
    }//endif distribution//
    if (type == 2) {//convergence, energy//
             convd << nstep;
             for (k=0;k<=K;k++) { 
                  convd <<'\t'<< X[k].f_d;
             }
             convd << endl;
             energy << nstep;
             for (k=0;k<=K;k++) { 
                  energy <<'\t'<< vpot(X[k].x,system);
             }
             energy << endl;
    }//endif convergence//
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/

