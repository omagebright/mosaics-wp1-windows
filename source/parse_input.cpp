#include "standard.h" 
#include "definitions.h"
#include "typedefs.h"
#include "utillib.h"

#define DEBUG_OFF

/*=========================================================================*/
/*=========================================================================*/
void parse_input(char *input_filename, General& general) 
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/
   
  int    i, n, nkey, key_defined;
  int    line_num;
  int   *key_found;
  int    int_arg;
  long   long_arg;
  double real_arg;
  char   str_arg[NCHARMAX];
  char   err_msg[LINE_NCHARMAX];

  char entry_line[LINE_NCHARMAX];
  char entry_name[NCHARMAX], key[NCHARMAX], arg[NCHARMAX];
  char *def;
  
  FILE *input_file;
  const char *sim_gen_keys[]= {"",
			 "method", "energy_surface", "replica_number", "total_step_mc",
			 "local_step_md", "time_step_md", "statistics_freq",
                         "prob_eemc_jump", "temperature", "energy_gap", "random_seed"};
  
  if ( (input_file=fopen(input_filename, "r")) == NULL) {
    sprintf(err_msg, "Cannot open input file %s.", input_filename);
    errorMessage(err_msg);
  }    
  
  key_found = new int[11] - 1;

/*------------------------------------------------------------------------*/
/*Read an entry */
  line_num = 0;
  while((n=readOneEntry(input_file,'~','[',']',entry_line, line_num))!=0) {
    if (n!=1) {
      sprintf(err_msg, "%s at line %d while reading file %s.",
	      (n==-1) ? "Syntax error" : "Internal error", 
	      line_num, input_filename);
      errorMessage(err_msg);
    }
    n=getEntryName(entry_line, '~', '[', entry_name, def);
    if (n!=1) {
      sprintf(err_msg, "Syntax error at input file line:\n%s", entry_line);
      errorMessage(err_msg);
    }

/*-------------------------------------------------------------------------*/
/* 1) ~sim_gen_def: alias ~method:                                         */
    if ( (strcasecmp(entry_name, "sim_gen_def")==0) || 
         (strcasecmp(entry_name, "method")==0) ) {
      nkey = 11;
      for ( i=1; i<=nkey; i++) { key_found[i] = 0; }
      while ((n=getKeyArgPair(def, key, arg, '\\', '{', '}', def))==1) {
	key_defined = 0;
	for ( i=1; i<=nkey; i++) {                     /*loop for key words.*/
	  if (strcasecmp(key, sim_gen_keys[i])==0) {   /*it's a keyword.    */
	    key_defined  = 1;
	    key_found[i] = 1;
	    switch (i) {
	    case 1:
	      strcpy(str_arg, arg);
	      if      (strcasecmp(str_arg,"PT")==0)    {general.method=1;}
	      else if (strcasecmp(str_arg,"EEMC")==0)  {general.method=2;}
	      else { barf(key); }
	      break;
	    case 2:
	      strcpy(str_arg, arg);
	      if      (strcasecmp(str_arg,"DWP")==0)  {general.system=1;}
	      else if (strcasecmp(str_arg,"RFP")==0)  {general.system=2;}
	      else { barf(key); }
	      break;
	    case 3:
              sscanf(arg, "%d", &int_arg);
	      general.nchain = int_arg;
	      break;	      
	    case 4:
              sscanf(arg, "%d", &int_arg);
	      general.nstep_mc = int_arg;
	      break;	      
	    case 5:
	      sscanf(arg, "%d", &int_arg);
	      general.nstep_md = int_arg;
	      break;
	    case 6:
	      sscanf(arg, "%lf", &real_arg);
              general.dt = real_arg;
	      break; 
	    case 7:
	      sscanf(arg, "%d", &int_arg);
	      general.nstat = int_arg;
	      break;
	    case 8:
              sscanf(arg, "%lf", &real_arg);
	      general.pee = real_arg;
	      break;
            case 9:
              sscanf(arg, "%lf", &real_arg);
              general.temp = real_arg;
	      break;
            case 10:
              sscanf(arg, "%lf", &real_arg);
	      general.egap = real_arg;
	      break;
            case 11:
	      sscanf(arg, "%d", &int_arg);
	      general.seed = int_arg;
	      break;
	    }/*end switch*/
	  }/*end if */
	}/*end for */
	if (key_defined==0) {
	  sprintf(err_msg, "Key word %s unknown in input file line:\n%s",
		  key, entry_line);
	  errorMessage(err_msg);
	}
      }/*end while: getKeyArgPair */
      if (n!=0) {
	sprintf(err_msg, "Syntax error in input file line:\n%s",entry_line);
	errorMessage(err_msg);
      }
      for ( i=1; i<=nkey; i++) { 
	if (key_found[i]==0) {
	  sprintf(err_msg, "Key word %s missed in input file line:\n%s",
		  sim_gen_keys[i], entry_line);
	  errorMessage(err_msg);
	}
      }
    }/*end if: sim_gen_def*/

/*-------------------------------------------------------------------------*/
/* 2) Error: not recodnized entry name*/
    else {
      sprintf(err_msg, "Entry name not defined in input file:\n%s",entry_name);
      errorMessage(err_msg);
    }
  }/*end while: readOneEntry*/

/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/

