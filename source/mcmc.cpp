#include "standard.h" 
#include "definitions.h"
#include "typedefs.h"

/*=========================================================================*/
/*=========================================================================*/
int main(int argc, char *argv[])
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

    int ii,jj,i,j,n,k,ith;

//  input file
    char *input_filename;
    input_filename = argv[1];
// read in variables
    General general;
    parse_input(input_filename,general);
// input variables
    int nstep_md, nstep_mc, nstat;
    double dt, pee, egap, temp;
    int method, system, nchain; 
    long  seed;
// assign input variables
    method = general.method; system = general.system; nchain = general.nchain;
    nstep_md = general.nstep_md; nstep_mc = general.nstep_mc; nstat = general.nstat;
    seed = general.seed; dt = general.dt; pee = general.pee; temp = general.temp;
    egap = general.egap;
// title page
    EEMC_title(input_filename);
// setup Markov Chain
    int K;
    double y,length,pacc;
    double pi_iy,pi_ix,pi_ip1y,pi_ip1x;
    K = nchain - 1;
    System X[K+1];
// setup energy levels and T 
    double H[K+2], T[K+2];
    double E_lower, E_upper, E_gap;
    if (system == 1) {E_lower=0.0;E_upper=4.0;}    // DW 
    if (system == 2) {E_lower=-4.68;E_upper=4.68;} // FPS
    E_gap = egap;
    double T0 = temp; 
    partition(T,H,T0,E_lower,E_upper,E_gap,K);
// setup Energy Disks
    Disk D[K+1][K+1];
// setup method
    double ptemp; 
    if (method == 1) {ptemp = 1;}
    if (method == 2) {ptemp = 0;} 
// burn in periods
    int B = 1000; // 10000
    int N = 1000; // 10000
// Initialize
    for (k=0;k<=K;k++) {
        X[k].init(&seed,T[k],system,nstat);
    }
// Extended Ensemble Monte Carlo with K + 1 Chains
    for (n=1;n<=nstep_mc;n++) {
        for (i=K;i>=0;i--) {
            if (n>(K-i)*(B+N)) {
               X[i].get_I(H,K); j = X[i].I;
               length = D[j][i+1].length; 
               if (i==K) {
                  X[i].prop(&seed,nstep_md,dt);            
               } else {//i!=K//
                  if (length==0) {
                     X[i].prop(&seed,nstep_md,dt);
                  } else {
                     if (pee > ran1(&seed)) {
                       ith = (int)(ran1(&seed)*((double)length));     
                       if (!ptemp) {
                          y = D[j][i+1].stock[ith];
                       } else {
                          y = X[i+1].x;
                       }
                       pi_iy = exp(-vpot(y,system)/T[i]);
                       pi_ix = exp(-vpot(X[i].x,system)/T[i]);
                       pi_ip1y = exp(-vpot(y,system)/T[i+1]);
                       pi_ip1x = exp(-vpot(X[i].x,system)/T[i+1]);
                       pacc = MIN(1.0,pi_iy*pi_ip1x/(pi_ix*pi_ip1y));
                       if (!ptemp) {
                          X[i].ee_jump(pacc,y,&seed);
                       } else {
                          (X[i].nptprop)++;
                          if ( pacc > ran1(&seed) ) {
                             (X[i].nptacc)++;
                             X[i+1].add(X[i].x);
                             X[i].add(y);
                          }
                       }    
                     } else {
                       X[i].prop(&seed,nstep_md,dt);
                     } 
                  } 
               }//i!=K//
               if (n>(K-i)*(B+N)+B) {  // && (X[i].acc || X[i].eeacc) {
                  X[i].get_I(H,K); j = X[i].I;
                  D[j][i].add(X[i].x,&seed);
               }
            }
            if ( (n>(K)*(B+N)) && ((n % nstat) == 0) ) {
               output(X,K,n,2); // output convergence
            }
        }
    }//end_MC// 
// output distribution 
    output(X,K,n,1);    
// acceptance ratio
    statistics(X,K,method);
// end of program
    EEMC_end();
    return 0;
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/
