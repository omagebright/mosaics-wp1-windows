/*-------------------------------------------------------------------------*/
class System {
 public:
    void init(long *seed, double Tg, int pot_typeg, int nstatg) 
    {
         int i;

         m        =  1.0;
         T        =  Tg;
         pot_type = pot_typeg;
         // initial conditions
         x  =  mb(m,T,seed); 
         vx =  mb(m,T,seed);
         fx =  force(x,pot_type);
         // histogram variables
         if (pot_type == 1) {dmax=2.0; dmin=-2.0; resol=.04;}
         if (pot_type == 2) {dmax=10.0;dmin=0.0;resol=.04;}
         hdim  = (int((dmax-dmin)/resol));
         for (i=1;i<=hdim;i++) {
             hist[i] = 0.0;
             dist[i] = 0.0;
             dista[i] = 0.0;
         }
         nprop = 0;
         nacc  = 0;
         neeprop = 0;
         neeacc  = 0;
         ntprop  = 0;
         nptprop = 0;
         nptacc  = 0;
         nstat = nstatg;
    }
   
    void prop(long *seed, int nstep_md, double dt)
    {
      int i,ic;
      double H,Hp;
      double xi,dt2,pacc;
      double sum,xii,suma;
      
      nprop++; ntprop++;
      if (nprop == 1) {
         suma = 0.0;
         for (i=1;i<=hdim;i++) {
             xii = dmin + (i-0.5)*resol;
             dista[i] = exp(-vpot(xii,pot_type)/T);
             suma += dista[i]*resol;
         }
         for (i=1;i<=hdim;i++) {dista[i] /= suma;}
      }
 
      dt2 = dt/2.0;
      vx = mb(m,T,seed);
      H  = 1.0/2.0*m*vx*vx + vpot(x,pot_type);
      xi = x;
      for (i=1;i<=nstep_md;i++) {
          vx = vx + fx/m*dt2;
          xi = xi + vx*dt;
          if (pot_type == 2) {
              if (xi >= 10.0) {xi -= 10.0;}
              if (xi < 0.0) {xi += 10.0;}
          }
          fx = force(xi,pot_type);
          vx = vx + fx/m*dt2;
      }
      Hp = 1.0/2.0*m*vx*vx + vpot(xi,pot_type);
      pacc = MIN(1.0,exp(-(Hp-H)/T));
      acc  = 0;
      if (pacc > ran1(seed)) {
         acc = 1;
         x = xi;
         nacc++;
         ic = (int((x-dmin)/resol)) + 1;
         hist[ic] += 1.0;
      }
      if ((ntprop % nstat) == 0) {
         sum = 0.0;
         for (i=1;i<=hdim;i++) {
             sum += hist[i]*resol;
         }
         f_d = 0;
         for (i=1;i<=hdim;i++) {
             dist[i] = hist[i]/sum;
             f_d += fabs(dist[i]-dista[i])/(double)hdim;
         }   
      }
    }
    
    void get_I(double* H, int K) {
         int i;
         double V = vpot(x,pot_type);
         I = K;
         for (i=0;i<=K;i++) {
             if ((V >= H[i]) && (V < H[i+1])) {
                I = i;
             }
         }
    }

    void ee_jump(double pacc, double y, long* seed) {
         int i,ic;
         double sum;
         neeprop++; ntprop++;
         eeacc = 0;
         if (pacc > ran1(seed)) {
            eeacc = 1;
            neeacc++;
            x = y;
            ic = (int((x-dmin)/resol)) + 1;
            hist[ic] += 1.0; 
         }           
         if ((ntprop % nstat) == 0) {
            sum = 0.0;
            for (i=1;i<=hdim;i++) {
                sum += hist[i]*resol;
            }
            f_d = 0;
            for (i=1;i<=hdim;i++) {
                dist[i] = hist[i]/sum;
                f_d += fabs(dist[i]-dista[i])/(double)hdim;
            }   
         }
    }

    void add(double y) {
         int i,ic;
         double sum;
         ntprop++;
         x = y;
         ic = (int((x-dmin)/resol)) + 1;
         hist[ic] += 1.0; 
         if ((ntprop % nstat) == 0) {
            sum = 0.0;
            for (i=1;i<=hdim;i++) {
                sum += hist[i]*resol;
            }
            f_d = 0;
            for (i=1;i<=hdim;i++) {
                dist[i] = hist[i]/sum;
                f_d += fabs(dist[i]-dista[i])/(double)hdim;
            }   
         }
    }

 public:
     int pot_type;
     int nprop,nacc,nstat,acc,eeacc,I;
     int ntprop,neeprop,neeacc,nptprop,nptacc; 
     double x,vx,fx,m,T;
     double hist[MAXD];
     double dist[MAXD];
     double dista[MAXD];
     double resol,dmin,dmax,hdim;
     double f_d;
};//System//
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
class Disk {
 public:
    Disk() {
         length = 0; 
    }
    void add(double x, long* seed) {
       int ith;
       if (length > MDISK-2) {
          ith = (int)(ran1(seed)*((double)length));
          stock[ith] = x;
       } else { 
          length++; 
          stock[length] = x;
       }
    }
 public:
    int length;
    double stock[MDISK];
};//Disk//
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
class General {
 public:
  int method; 
  int system;
  int nchain;
  int nstep_md;
  int nstep_mc;
  int nstat;
  long seed;
  double dt;
  double pee;
  double temp;
  double egap;
  

  General() {
    seed     = -2039480938l;
    method   = 1;
    system   = 1; 
    nchain   = 5;
    pee      = 0.15;
    temp     = 1.0;
    egap     = 1.1;
    nstep_md = 10;
    nstep_mc = 10;
    nstat    = 1000;
    dt       = 0.03;
  }
};//General//
/*-------------------------------------------------------------------------*/ 
