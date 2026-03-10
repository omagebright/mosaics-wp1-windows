#include "standard.h" 
#include "utillib.h"
#include "definitions.h"
#include "typedefs.h"



/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
int atom_entry(char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

    if (strncasecmp(pdb_entry_line,"ATOM",strlen("ATOM"))==0)     return 1;
    if (strncasecmp(pdb_entry_line,"HETATM",strlen("HETATM"))==0) return 1;

    return 0;
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/

/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
int stride_entry(char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

      if (strncasecmp(pdb_entry_line,"STRIDE",strlen("STRIDE"))==0) return 1;

      return 0;
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/

/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
int torcompl_entry(char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

 if (strncasecmp(pdb_entry_line,"TORCOMPL",strlen("TORCOMPL"))==0) return 1;

 return 0;
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/


/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
int cblc_entry(char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

 if (strncasecmp(pdb_entry_line,"CBLC",strlen("CBLC"))==0) return 1;

 return 0;
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/


/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
int closcompl_entry(char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

 if (strncasecmp(pdb_entry_line,"CLOSCOMPL",strlen("CLOSCOMPL"))==0) return 1;

 return 0;
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/



/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
void get_stride(char *stride, char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

    char* ptr;
   
    cutHeadEndBlank(pdb_entry_line);
    ptr = strtok(pdb_entry_line," ");
    ptr = strtok(NULL," ");
    strcpy(stride,ptr);
    ptr = strtok(stride,"\n");

/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/

/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
void get_torcompl(char *torcompl, char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

   get_stride(torcompl,pdb_entry_line);

/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/

/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
void get_cblc(char *cblc, char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

    char* ptr;
   
    cutHeadEndBlank(pdb_entry_line);
    ptr = strtok(pdb_entry_line," ");
    ptr = strtok(NULL," ");
    strcpy(cblc,ptr);
    ptr = strtok(cblc,"\n");

/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/


/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
void get_closcompl(char *closcompl, char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

    char* ptr;
   
    cutHeadEndBlank(pdb_entry_line);
    ptr = strtok(pdb_entry_line," ");
    ptr = strtok(NULL," ");
    strcpy(closcompl,ptr);
    ptr = strtok(closcompl,"\n");

/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/


/*=========================================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*=========================================================================*/
int end_entry(char *pdb_entry_line)
/*-------------------------------------------------------------------------*/
{ /*begin routine */
/*-------------------------------------------------------------------------*/

      if (strncasecmp(pdb_entry_line,"END",strlen("END"))==0) return 1;

      return 0;
/*-------------------------------------------------------------------------*/
} /*end routine */
/*=========================================================================*/


/*==========================================================================*/
/*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*==========================================================================*/
void print_line()
/*==========================================================================*/
{/*begin routine */
/*==========================================================================*/
   printf("-----------------------------------------------------------------------------------\n");
/*-------------------------------------------------------------------------*/
}/*end routine*/
/*==========================================================================*/

/*==========================================================================*/
/*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*==========================================================================*/
void print_doubleline()
/*==========================================================================*/
{/*begin routine */
/*==========================================================================*/
  printf("===================================================================================\n");
/*-------------------------------------------------------------------------*/
}/*end routine*/
/*==========================================================================*/

/*==========================================================================*/
/*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*==========================================================================*/
void empty_line()
/*==========================================================================*/
{/*begin routine */
/*==========================================================================*/
  printf("\n");
/*-------------------------------------------------------------------------*/
}/*end routine*/
/*==========================================================================*/

/*==========================================================================*/
/*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*==========================================================================*/
void PAS_title()
/*==========================================================================*/
{/*begin routine */
/*==========================================================================*/
  printf("###################################################################################\n");
  printf("#   Copyright (c) 2007 Peter Minary.        ~---------------------------------~   #\n");
  printf("#   All Rights Reserved.                    |     |              /    /    / ~|   #\n");
  printf("#      __           ~-           __         |    \\|/     _      /         / ~ |   #\n");
  printf("#     /^^\\     M   -  ~   M     /^^\\        |   \\_|_/  ((|))   /  M /  _ / ~ ~|   #\n");
  printf("#    /^^^^\\   O   -    ~   O   /^^^^\\       |  \\__|__/ ((|))  /      ((|))~ ~ |   #\n");
  printf("#     |  |     S   -  ~   S     |  |        |     |      |   /  O /  ((|)) ~ ~|   #\n");
  printf("#     |  |      A   ~-   A      |  |        |  _     _   |  /         /|~ ~ ~ |   #\n");
  printf("#     |  |     I   ~  -   I     |  |        | {|}  ((|)) | /  S /  _ /~| ~_~ ~|   #\n");
  printf("#    _|__|_   C   ~    -   C   _|__|_       |{{|}} ((|))  /      ((|)) |~{|}~ |   #\n");
  printf("#              S   ~  -   S                 |  |     |   /  A /  ((|))~ {{|}}~|   #\n");
  printf("#   --------------- -~ ----------------     |    _   |  /         /| ~ ~ ~| ~ |   #\n");
  printf("#    Methodologies for Optimization and     |  ((|)) | /  I /  _ / |~ ~ ~| ~ ~|   #\n");
  printf("#    SAmpling In Computational Studies      |  ((|))  /      ((|)) | ~  \\|/ ~ |   #\n");
  printf("#   -----------------------------------     |    |   /  C /  ((|))~ ~  \\_|_/ ~|   #\n");
  printf("#                                           |    |  /         /| ~ ~  \\__|__/~|   #\n");
  printf("#          >>  version.3.8  <<              |    | /  S /    /~|~ ~ ~ ~ ~| ~ ~|   #\n");
  printf("#                                           |     /         /~ | ~ ~ ~ ~ ~ ~ ~|   #\n");
  printf("#                                           ~---------------------------------~   #\n");
  printf("###################################################################################\n");
  LINE
  LINE
/*-------------------------------------------------------------------------*/
}/*end routine*/
/*==========================================================================*/

/*==========================================================================*/
/*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*==========================================================================*/
void PAS_end()
/*==========================================================================*/
{/*begin routine */
/*==========================================================================*/
  
  FILE *pptr;
  char Date[40];
  pptr = popen("date","r");
  fgets(Date,(int)sizeof(Date),pptr);

  printf("###################################################################################\n");
  printf("##===============================================================================##\n");
  printf("##                M.O.S.A.I.C.S    Successfully Completed                        ##\n");
  printf("##===============================================================================##\n");
  printf("###################################################################################\n");
  printf(" Current Date %s ",Date);
  printf("===================================================================================\n");

  LINE
  LINE
/*-------------------------------------------------------------------------*/
}/*end routine*/
/*==========================================================================*/



/*==========================================================================*/
/* Uniform random numbers */
/*==========================================================================*/
/*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*==========================================================================*/
void rand_block(double *rnd, int n)
/*==========================================================================*/
{/*begin routine */
/*==========================================================================*/
  /*Generate a block of n uniformly distributed random number. */
  for (int i=1; i<=n; i++) {
    rnd[i] = drand48();
  }
/*-------------------------------------------------------------------------*/
}/*end routine*/
/*==========================================================================*/


void durand(double *seed,int &n, double *x,int &ierr) 
/*==========================================================================*/
  {/*begin routine */
/*==========================================================================*/
    int i;
    double xr, xadd, xsub;
    double s, t, xm, xmp, scaleu, scaled, onemep, onepep;

    xm = 16807.;
    xmp= 16807.0000078263692557811737060546875;
    scaleu = 2147483648.;
    scaled =  .0000000004656612873077392578125;
    onepep = 1.0000000004656612873077392578125;
    onemep =  .9999999995343387126922607421875;
    xr     = 0.5;
    xadd   = 4503599627370497.;
    xsub   = 4503599627370497.;
    
    ierr =0;
    if (n<0)       { ierr=1; return;}
    if ((*seed)<1) { ierr=1; return;}
    if ((*seed)>2147483646.) { ierr=1; return;}
    t = (*seed)*scaled;
    for (i=1; i<=n; i++) {
      s=(int)(t*xmp);
      t=t*xm;
      t=t-s*onepep;
      x[i-1] = t*onepep;
    }
    (*seed) = t*scaleu;
    
/*-------------------------------------------------------------------------*/
   }/*end routine*/
/*==========================================================================*/

    
double ran_essl(double *qseed)

/*==========================================================================*/
  {/*begin routine */
/*==========================================================================*/
  int n=1,ierr=0;
  double x;
/*==========================================================================*/
  
  durand(qseed, n, &x, ierr);
  
  if(ierr==1){
    printf("@@@@@@@@@@@@@@@@@@@@_ERROR_@@@@@@@@@@@@@@@@@@@@");
    printf("Error in random number generator: Durand");
    if(n    < 0           ){printf("Parameter n=%d < 0"             ,n);}
    if(*qseed< 1.0        ){printf("Parameter qseed=%g < 1.0"       ,*qseed);}
    if(*qseed>2147483646.0){printf("Parameter qseed=%g > 2147483646",*qseed);}
    printf("@@@@@@@@@@@@@@@@@@@@_ERROR_@@@@@@@@@@@@@@@@@@@@");
    fflush(stdout);
    exit(1);
  }/*endif*/  
  return x;

/*-------------------------------------------------------------------------*/
   }/*end routine*/
/*==========================================================================*/


/*===============================================================*/
/* Gaussian Random numbers */
/*==========================================================================*/
/*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*==========================================================================*/

void gaussran(int nran, int *iseed, int *iseed2, double *qseed, double *gauss)

/*========================================================================*/
{/*begin routine*/
/*========================================================================*/
/*             Local variable declarations                                */
   int i,iii,loop;
   double twopi,rad2,al,r,phi,arg;
/*========================================================================*/
/* I) Constants */
    twopi = 2.0*M_PI;
    rad2 = sqrt(2.0);
    loop = nran/2;

/*========================================================================*/
/* II) Make nran (or nran-1 if nran odd) Gaussian random numbers          */
    for(i=1;i<=loop;i++){
/*------------------------------------------------------------------------*/
/* A) uniform random numbers in r and phi */
       r   = ran_essl(qseed);
       r   = MAX(r,1e-30);
       r   = MIN(r,1.0);
       phi = ran_essl(qseed);
/*------------------------------------------------------------------------*/
/* B) Gaussify in x and y*/
       al  = sqrt(-log(r))*rad2;
       arg = twopi*phi;
       gauss[2*i-1] = al*cos(arg);
       gauss[2*i]   = al*sin(arg);
     }/*endfor*/
/*========================================================================*/
/* III) Make one more if nran is odd */
    if((nran % 2)!=0){
       r   = ran_essl(qseed);
       r   = MAX(r,1e-30);
       r   = MIN(r,1.0);
       phi = ran_essl(qseed);
       arg = twopi*phi;
       al  = sqrt(-log(r))*rad2;
       gauss[nran] = al*cos(arg);
     }/*endif*/

/*------------------------------------------------------------------------*/
}/*end routine*/
/*========================================================================*/

/*---------------------------------------------------------------------*/
double switchFun(double gama) {
  double gama2, s;
  gama2 = gama*gama;
  if (gama <= 0.0)      { s = 0.0;}
  else if (gama >= 1.0) { s = 1.0;}
  else {
    s = -gama2*gama2*(20.0*gama*gama2 - 70.0*gama2 +
		      84.0*gama - 35.0);
  }
  return s;
}/*end routine: switchFun */


/*---------------------------------------------------------------------*/
double derSwitchFun(double gama) {
  double gama2, derS;
  gama2 = gama*gama;
  if (gama<=0.0 || gama>=1.0)      { derS = 0.0;}
  else {
    derS = -140.0*gama2*gama*(gama*gama2 - 3.0*gama2 +
			      3.0*gama - 1.0);
  }
  return derS;
}/*end routine: switchFun */


/*---------------------------------------------------------------------*/
int strReadArray(char *array_str, int n_max, int type, void *array) {
  int i, n_read, n_read_sum;
  char head_char;
  char   *curr_str;
  int    *int_array;
  char   *char_array;
  float  *float_array;
  double *double_array;
  
  switch (type) {
  case TYPE_INT:
    int_array = (int *)array;
    break;
  case TYPE_CHAR:
    char_array = (char *)array;
    break;
  case TYPE_FLOAT:
    float_array = (float *)array;
    break;
  case TYPE_DOUBLE:
    double_array = (double *)array;
    break;
  default:
    printf("strReadArray(): array type not supported: %d\n", type);
    exit(1);
    break;
  } /*end switch */
  
  n_read_sum=0;
  curr_str = array_str;

  head_char = curr_str[0];
  i = 1;
  while (i<n_max && head_char!='\0') {
    while ( head_char!='\0' && !(head_char>' '&&head_char<='\x7e')) {
      curr_str++;
      head_char = curr_str[0];
    }
    switch(type) {
    case TYPE_INT:
      n_read = sscanf(curr_str, "%d", &(int_array[i]));
      n_read_sum += n_read;
      break;
    case TYPE_CHAR:
      n_read = sscanf(curr_str, "%c", &(char_array[i]));
      n_read_sum += n_read;
      break;
    case TYPE_FLOAT:
      n_read = sscanf(curr_str, "%f", &(float_array[i]));
      n_read_sum += n_read;
      break;
    case TYPE_DOUBLE:
      n_read = sscanf(curr_str, "%lf", &(double_array[i]));
      n_read_sum += n_read;
      break;
    default:
      n_read = 0;
      break;
    } /*end switch */
    if (n_read==1) { i++;}
    while (head_char>' '&&head_char<='\x7e') {
      curr_str++;
      head_char = curr_str[0];
    }
  }
  if (n_read_sum!=i-1) {
    printf("Error while reading array from a string.\n");
    fflush(stdout);
    exit(1);
  }

  return n_read_sum;
} /*end routine: strReadArray() */
  

/*---------------------------------------------------------------------*/
void cutEndBlank(char *line) {
  /*This routine cuts the ending blank chars in a string */
  int i;
  
  i=strlen(line)-1;
  while ( i>-1 && !(line[i]>' ' &&line[i]<='\x7e')) { i--; }
  line[i+1] = '\0';

}/*end routine: cutEndBlank() */


/*---------------------------------------------------------------------*/
void cutHeadEndBlank(char *line) {
  /*This routine cuts the head and ending blank chars in a string */
  int i, n_head, line_len;
  char c_head;
  
  line_len = strlen(line);
  n_head=0;
  c_head = line[n_head];
  while ( n_head<=line_len && !(line[n_head]>' ' &&line[n_head]<='\x7e')) {
    n_head++;
  }
  for (i=0; i<=line_len-n_head; i++) {
    line[i] = line[i+n_head];
  }
  
  line_len = strlen(line);
  i=line_len-1;
  while ( i>-1 && !(line[i]>' ' &&line[i]<='\x7e')) { i--; }
  line[i+1] = '\0';
  
}/*end routine: cutHeadEndBlank() */

/*---------------------------------------------------------------------*/
int readOneEntry(FILE *file, char c_entry, char c_def_begin, 
		 char c_def_end, char *entry_line, int &line_num) {
  int c_entry_found=0, c_end_found=0;
  char line[LINE_NCHARMAX];
  char *result;
  entry_line[0]='\0'; /*empty the entry line */
  while (c_entry_found!=1 && !feof(file)) {
    line[0]='\0';     /* empty the line: in case no char is read,
		       * the line is empty.
		       */
    result = fgets(line, LINE_NCHARMAX, file);
    if (strlen(line)==LINE_NCHARMAX-1){return -2;}        /*internal error */
    line_num++;
    if (strchr(line, c_entry)!=NULL) { c_entry_found =1;} 
    if (feof(file)) {break;}                              /*end of file    */
    if (result==NULL) { return -2;   }                    /*internal error */ 
  }
  if (c_entry_found==0) { return 0;}                      /*Already end of file */
  cutEndBlank(line);
  strcat(entry_line, line);
  if (strchr(entry_line,c_def_end)!=NULL) {c_end_found =1;} 
  while (c_end_found!=1 && !feof(file)) {
    line[0]='\0';
    result = fgets(line, LINE_NCHARMAX, file);
    if (strlen(line)==LINE_NCHARMAX-1){return -2;}        /*internal error */
    line_num++;
    cutEndBlank(line);
    strcat(entry_line, line);
    if (strlen(entry_line)>=LINE_NCHARMAX-1){return -2;}    /*internal error */
    if (strchr(entry_line, c_def_end)!=NULL) { c_end_found =1;} 
    if (feof(file)) {break;}                              /*end of file    */    
    if (result==NULL) { return -2;   }                    /*internal error */ 
  }
  if (strchr(entry_line, c_entry)    ==NULL || 
      strchr(entry_line, c_def_begin)==NULL ||
      strchr(entry_line, c_def_end)  ==NULL   ) { return -1;} /*syntax error   */
  if ((strchr(entry_line, c_entry    )!=strrchr(entry_line, c_entry)    ) ||
      (strchr(entry_line, c_def_begin)!=strrchr(entry_line, c_def_begin)) ||
      (strchr(entry_line, c_def_end  )!=strrchr(entry_line, c_def_end)  )   ) 
    { return -1;}                                             /*syntax error   */
  return 1;
} /*end routine: readOneEntry()*/

  
/*---------------------------------------------------------------------*/
int readOneEntry2(FILE *file, char c_entry, char c_def_begin, 
		  char c_def_end, char *entry_line, int &line_num) {
  int n=0;
  int c_entry_found=0, c_end_found=0;
  char line[LINE_NCHARMAX];
  char *result;
  entry_line[0]='\0'; /*empty the entry line */
  while (c_entry_found!=1 || c_end_found!=1) {
    result = fgets(line, LINE_NCHARMAX, file);
    if (feof(file))   { n= 0; break; }
    if (result==NULL) { n=-2; break; }              /*internal error */ 
    line_num++;
    if (strlen(line)==LINE_NCHARMAX-1){n=-2;break;} /*internal error */
    if (strchr(line, c_entry)!=NULL) {
      if ((strchr(line, c_entry)!=strrchr(line, c_entry)) || 
	  c_entry_found==1) { n = -1; break; }      /*syntax error   */
      else { c_entry_found =1; }             
    }
    if (strchr(line, c_def_end)!=NULL) {
      if (strchr(line, c_def_end)!=strrchr(line, c_def_end) ||
	  c_entry_found==0) { n = -1; break; }      /*syntax error   */
      else { c_end_found = 1; n=1; }
    }
    if (c_entry_found==1) {
      cutEndBlank(line);
      strcat(entry_line, line);
    }
  } /*end while */
  if (n==0 && ((c_entry_found+c_end_found)==1)) 
    { n=-1;}                              /*EOF before an entry ends */
  if (n==1) {
    if (strchr(entry_line, c_def_begin)==NULL){n=-1;} /*syntax error */
    else if (strchr(entry_line,c_def_begin)!=strrchr(entry_line,c_def_begin))
      { n=-1; }
    else if (strchr(entry_line, c_entry)>strchr(entry_line, c_def_end)  ||
	     strchr(entry_line, c_entry)>strchr(entry_line,c_def_begin) ||
	     strchr(entry_line, c_def_begin)>strchr(entry_line,c_def_begin))
      { n=-1; }  
  }
  return n;
} /*end routine: readOneEntry2()*/


/*---------------------------------------------------------------------*/
int getEntryName(char *line, char c_entry, char c_def_begin, 
		 char *entry_name, char *&def_line) {
  char *def, *entry_tmp; 
  
  if ((def=strchr(line, c_def_begin))==NULL) { return -1; } /*Syntax error */
  def[0]='\0';                                      /*line is splitted now */
  def_line = def+1; 
  
  if ((entry_tmp=strchr(line,c_entry))==NULL) { return -1;} /*Syntax error */
  if (entry_tmp!=(strrchr(line, c_entry)))    { return -1;} /*Syntax error */
  strcpy(entry_name, entry_tmp+1);
  cutEndBlank(entry_name);
  return 1;
} /*end routine: getEntryName() */


/*---------------------------------------------------------------------*/
int getKeyArgPair(char *def, char *key, char *arg, char c_key, 
		  char c_arg_begin, char c_arg_end, char *&new_def) {
  char *def_tmp, *key_tmp, *arg_tmp;
  if ((key_tmp=strchr(def, c_key))==NULL) {return 0;} /*No more key-arg pair*/
  key_tmp++;                                
  if((arg_tmp=strchr(key_tmp,c_arg_begin))==NULL){return -1;}/*Syntax error */
  if((def_tmp=strchr(key_tmp,c_arg_end))  ==NULL){return -1;}/*Syntax error */
  if( arg_tmp>def_tmp) { return -1;}                         /*Syntax error */
  arg_tmp[0]='\0';                          /*Splitting to get the key word */
  arg_tmp++;
  def_tmp[0]='\0';                          /*splitting to get the argument */
  def_tmp++;
  new_def = def_tmp;
    
  strcpy(key, key_tmp);
  strcpy(arg, arg_tmp);
  if (strchr(arg, c_key)!=NULL || 
      strchr(arg, c_arg_begin)!=NULL) {return -1;}
  if (strchr(key, c_key)!=NULL || 
      strchr(key, c_arg_end)!=NULL)   {return -1;}
  cutEndBlank(key);
  cutHeadEndBlank(arg);
  if (strlen(key)==0 || strlen(arg)==0) { return -1;}
  return 1;
} /*end routine: getKeyArgPair() */


/*---------------------------------------------------------------------*/
void barf(char *words) {
  printf("@@@@@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("Wrong setting with:\n%s\n", words);
  printf("@@@@@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  exit(1);
}

/*---------------------------------------------------------------------*/
void errorMessage(char *words) {
  printf("@@@@@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("%s\n", words);
  printf("@@@@@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  fflush(stdout);
  exit(1);
}

/*---------------------------------------------------------------------*/
void warnMessage(char *words) {
  printf("!!!!!!!!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  printf("%s\n", words);
  printf("!!!!!!!!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  fflush(stdout);
}

/*---------------------------------------------------------------------*/
int wild_strcasecmp(const char *s1, const char *s2) {
  if ((strcasecmp(s1, "X")==0) || (strcasecmp(s2, "X")==0)) 
    { return 0; }
  return strcasecmp(s1,s2);
}


/*=====================================================================*/
/*---------------------------------------------------------------------*/
void DZero(double *v, int n) {  /*initialize a vector to zero */
  int i;
  for (i=0; i<n; i++) {
    v[i]=0;
  }
}

void DCopy( double *v1, double *v2, int n) {  /* copy v2 into v1 */
  int i;
  for (i=0; i<n; i++) {
    v1[i]=v2[i];
  }
}
				     

void DScale(double a, double *v, int n) {
  int i;
  for (i=0; i<n; i++) {
    v[i]*=a;
  }
}

void Daxpy(double a, double *x, double *y, double *z, int n) {
  int i;
  for (i=0; i<n; i++) {
    z[i]=a*x[i]+y[i];
  }
}

double DDot( double *v1, double *v2, int n) {
  int i;
  double dot=0;
  for (i=0; i<n; i++) {
    dot+=v1[i]*v2[i];
  }
  return dot;
}

double DNorm( double *v, int n) {
  int i;
  double norm=0;
  for (i=0; i<n; i++) {
    norm+=v[i]*v[i];
  }
  return sqrt(norm);
}

void DCross( double *v1, double *v2, double *v3, int n) {
  double tmp[3];
  if (n!=3) printf("Not implemented for dimension not being 3!\n");
  else {
    tmp[0]=v1[1]*v2[2]-v1[2]*v2[1];
    tmp[1]=v1[2]*v2[0]-v1[0]*v2[2];
    tmp[2]=v1[0]*v2[1]-v1[1]*v2[0];

    v3[0] = tmp[0];
    v3[1] = tmp[1];
    v3[2] = tmp[2];
  }
}

void DMetrxVect(double **Mtr, double *v1, double *v2, int m, int n) {
  int i, j;
  for (i=0; i<m; i++) v2[i]=0;
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      v2[i]+=Mtr[i][j]*v1[j];
    }
  }
}
    
void DVectMetrx(double *v1, double **Mtr, double *v2, int m, int n) {
  int i, j;
  for (i=0; i<n; i++) v2[i]=0;
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) {
      v2[i]+=v1[j]*Mtr[j][i];
    }
  }
}
  
void DMetrxMetrx( double **Mtr1, double **Mtr2, double **Mtr3,
		  int l, int m, int n) {
  int i, j, k;
  for (i=0; i<l; i++) {
    for (j=0; j<n; j++) {
      Mtr3[i][j]=0;
    }
  }
  for (i=0; i<l; i++) {
    for (j=0; j<n; j++) {
      for (k=0; k<m; k++) {
	Mtr3[i][j]+=Mtr1[i][k]*Mtr2[k][j];
      }
    }
  }
}


/*===============================================================*/
/*             Gaussian-Legendre polynomial routines             */
/*===============================================================*/

int getLegenGauss( int pN, long double *pnodesN, long double *pnodesPre, 
		   long double *pweightsN) {
  long double x1,x2,x0,y0,y1;
  int i,iii,n,nn;
  
  if (pN<=1) {
    /*errors*/
    printf("@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@\n");    
    printf("N for getLegenGauss should be larger than 1!\n"); 
    printf("@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@\n");
    fflush(stdout);
    exit(1);
  }
  n=pN/2;
  pnodesN[n]=1.0;

  for (i=n-1; i>=0; i--) {
    pnodesN[i]=pnodesPre[i];
  }
  for (i=n; i>0; i--) {
    x1=pnodesN[(i-1)];
    x2=pnodesN[i];
    x0=(x1+x2)/2.0;
    while (x0!=x1 && x0!=x2) {
      y0=legendre(pN,x0);
      y1=legendre(pN,x1);
      if ( sign(y0)*sign(y1)<0){ x2=x0;}else{x1=x0;}
      x0=(x1+x2)/2.0;
    }
    pnodesN[i]=x0;
  }
  pnodesN[0]=0.0;
  nn=(pN+1)/2;
  if (nn==n) 
    for ( i=0; i<nn; i++) {
      pnodesN[i]=pnodesN[i+1];
    }
  for ( i=0; i<nn; i++) {
      x0=pnodesN[i];
      y0=legendre(pN+1,x0);
      pweightsN[i]=2.0*(1-x0*x0)/((pN+1)*(pN+1))/(y0*y0);
    }
  return 1;
}
/*===============================================================*/


/*===============================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*===============================================================*/
long double legendre( int pN, long double px) {
  /*local variables*/
  int i;
  long double P0,P1,P2;

  if (pN<0) {
    /*error*/
    printf("@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@\n");
    printf("Error in calculating Pn(x): n should be nonnegative!\n");
    printf("@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@\n");
    fflush(stdout);
    exit(1);
  }
  if ( fabs((double)(px-1.0))<2e-16) return 1.0;
  if ( fabs((double)(px+1.0))<2e-16) {
    if (pN==2*(pN/2)) return 1.0;
    else return -1.0;
  }
  P0=1.0;
  P1=px;
  if (pN==0) return P0;
  else if (pN==1) return P1;
  else {
    for (i=2; i<=pN; i++) {
      P2=((long double)(2.0*i-1)*px*P1-(long double)(i-1)*P0)/(long double)(i);
      P0=P1;
      P1=P2;
    }
  }
  return P2;
}
/*===============================================================*/


/*===============================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*===============================================================*/
int  legendreArray( int pN, long double px, long double *legPoly) {
  /*local variables*/
  int i;
  long double P0,P1,P2;

  if (pN<0) {
    /*error*/
    printf("@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@\n");
    printf("Error in calculating Pn(x): n should be nonnegative!\n");
    printf("@@@@@@@@@@@@@@@@@@@@_error_@@@@@@@@@@@@@@@@@@@@\n");
    fflush(stdout);
    exit(1);
  }
  else if ( fabs((double)(px-1.0))<2e-16) {
    for (i=0; i<=pN; i++) { legPoly[i]=1.0;}
    return 1;
  }
  else if ( fabs((double)(px+1.0))<2e-16) {
    for (i=0; i<pN; i+=2) { legPoly[i]=1.0; legPoly[i+1]=-1.0;}
    if (pN==2*(pN/2))  legPoly[pN]=1.0;
    return 1;
  }
  else {
    P0=1.0;
    P1=px;
    if (pN==0) { legPoly[0]=P0; return 1;}
    else if (pN==1) { legPoly[0]=P0; legPoly[1]=P1; return 1;}
    else {
      legPoly[0]=P0; 
      legPoly[1]=P1;
      for (i=2; i<=pN; i++) {
	P2=((long double)(2.0*i-1)*px*P1-(long double)(i-1)*P0)
	  /(long double)(i);
	P0=P1;
	P1=P2;
	legPoly[i]=P2;
      }
    }
    return 1;
  }
  return 0;
}
/*===============================================================*/


/*===============================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*===============================================================*/
int sign(long double px) {
  if (px==0.0) return 0;
  else return (px > 0) ? 1:-1;
}
/*===============================================================*/


/*===============================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*===============================================================*/
double getCosTorsAngle(double *x, double *y, double *z,
		       int j1, int j2, int j3, int j4) {
  double dx21, dy21, dz21;
  double dx23, dy23, dz23;
  double dx34, dy34, dz34;
  double n123[3], n234[3], l123, l234, cost;

  dx21 = x[j1] - x[j2];
  dy21 = y[j1] - y[j2];
  dz21 = z[j1] - z[j2];
  
  dx23 = x[j3] - x[j2];
  dy23 = y[j3] - y[j2];
  dz23 = z[j3] - z[j2];
  
  dx34 = x[j4] - x[j3];
  dy34 = y[j4] - y[j3];
  dz34 = z[j4] - z[j3];
  
  n123[0] = dy23*dz21 - dz23*dy21;
  n123[1] = dz23*dx21 - dx23*dz21;
  n123[2] = dx23*dy21 - dy23*dx21;
  
  n234[0] = dy23*dz34 - dz23*dy34;
  n234[1] = dz23*dx34 - dx23*dz34;
  n234[2] = dx23*dy34 - dy23*dx34;
  
  l123 = sqrt(n123[0]*n123[0]+n123[1]*n123[1]+n123[2]*n123[2]);
  l234 = sqrt(n234[0]*n234[0]+n234[1]*n234[1]+n234[2]*n234[2]);
  
  cost  = n123[0]*n234[0] + n123[1]*n234[1] + n123[2]*n234[2];
  cost /= (l123*l234); 
  
  if (cost> 1) cost = 1;
  if (cost<-1) cost =-1;
  
  return  cost;

}/*end routine: getCosTorsAngle() */
/*===============================================================*/

/*===============================================================*/
/*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*/
/*===============================================================*/
void moveGroupAtoms(double *x, double *y, double *z,
		    int j1, int j2, int j3, int j4, 
		    double phi, int natm, int *atm_group) {
  int i, iatm, jatm; 

  double cos_theta, sin_theta, cos_phi, sin_phi;
  double l21, l32, l34;
  
  double n123[3], n234[3];
  double r21[3], r23[3], r32[3], r34[3];
  double ex1[3], ey1[3], ez1[3];
  double ex2[3], ey2[3], ez2[3];
  double tmp_vec[3];
  
  r21[0] = x[j1] - x[j2];
  r21[1] = y[j1] - y[j2];
  r21[2] = z[j1] - z[j2];
  
  r23[0] = x[j3] - x[j2];
  r23[1] = y[j3] - y[j2];
  r23[2] = z[j3] - z[j2];

  r32[0] = x[j2] - x[j3];
  r32[1] = y[j2] - y[j3];
  r32[2] = z[j2] - z[j3];
  
  r34[0] = x[j4] - x[j3];
  r34[1] = y[j4] - y[j3];
  r34[2] = z[j4] - z[j3];
  
  l21 = DNorm(r21,3);
  l32 = DNorm(r32,3);
  l34 = DNorm(r34,3);
  
  ez1[0] = r32[0]/l32;
  ez1[1] = r32[1]/l32;
  ez1[2] = r32[2]/l32;
  
  DCross(r32, r34, n234, 3);
  DScale(1.0/DNorm(n234,3), n234, 3);
  ey1[0] = n234[0];
  ey1[1] = n234[1];
  ey1[2] = n234[2];
  DCross(ey1, ez1, ex1, 3);  

  cos_theta = DDot(r21, r32, 3)/(l21*l32);
  if (cos_theta> 1.0) cos_theta = 1.0;
  if (cos_theta<-1.0) cos_theta =-1.0;
  sin_theta = sqrt(1-cos_theta*cos_theta);
  
  if (natm>1) {
    DCross(r21, r23, n123, 3);
    DScale(1.0/DNorm(n123,3), n123, 3);
    cos_phi = DDot(n123, n234, 3);
    if (cos_phi> 1.0) cos_phi = 1.0;
    if (cos_phi<-1.0) cos_phi =-1.0;
    sin_phi = sqrt(1-cos_phi*cos_phi);
    DCross(n123, n234, tmp_vec, 3);
    if ( DDot(tmp_vec, r23, 3)<0) { sin_phi = -sin_phi; }

    ex2[0]=-sin_phi;          ex2[1]=cos_phi;           ex2[2]=0;
    ey2[0]=sin_theta*cos_phi; ey2[1]=sin_theta*sin_phi; ey2[2]=cos_theta;
    DCross(ex2, ey2, ez2, 3);
  } 
      
  /*From absolute coord system to relative one */
  for (iatm=2; iatm<=natm; iatm++) {
    jatm = atm_group[iatm];
    x[jatm] -= x[j1];
    y[jatm] -= y[j1];
    z[jatm] -= z[j1];
  }
  /*R1 in Original (X) space */
  for (iatm=2; iatm<=natm; iatm++) {
    jatm = atm_group[iatm];
    tmp_vec[0] = x[jatm]*ex1[0]+y[jatm]*ex1[1]+z[jatm]*ex1[2];
    tmp_vec[1] = x[jatm]*ey1[0]+y[jatm]*ey1[1]+z[jatm]*ey1[2];
    tmp_vec[2] = x[jatm]*ez1[0]+y[jatm]*ez1[1]+z[jatm]*ez1[2];
    x[jatm] = tmp_vec[0];
    y[jatm] = tmp_vec[1];
    z[jatm] = tmp_vec[2];
  }
  /*R2 in Original (X) space */
  for (iatm=2; iatm<=natm; iatm++) {
    jatm = atm_group[iatm];
    tmp_vec[0] = x[jatm]*ex2[0]+y[jatm]*ex2[1]+z[jatm]*ex2[2];
    tmp_vec[1] = x[jatm]*ey2[0]+y[jatm]*ey2[1]+z[jatm]*ey2[2];
    tmp_vec[2] = x[jatm]*ez2[0]+y[jatm]*ez2[1]+z[jatm]*ez2[2];
    x[jatm] = tmp_vec[0];
    y[jatm] = tmp_vec[1];
    z[jatm] = tmp_vec[2];
  }  
  
  /*In transformed (U) space */
  sin_phi = sin(phi);
  cos_phi = cos(phi);
  if (natm>1) {
    ex2[0]=-sin_phi;          ex2[1]=cos_phi;           ex2[2]=0;
    ey2[0]=sin_theta*cos_phi; ey2[1]=sin_theta*sin_phi; ey2[2]=cos_theta;
    DCross(ex2, ey2, ez2, 3);
  } 
  
  x[j1] = l21*sin_theta*cos_phi;
  y[j1] = l21*sin_theta*sin_phi;
  z[j1] = l21*cos_theta;
  /*R2_u' in transformed (U) space */
  for (iatm=2; iatm<=natm; iatm++) {
    jatm = atm_group[iatm];
    tmp_vec[0] = x[jatm]*ex2[0]+y[jatm]*ey2[0]+z[jatm]*ez2[0];
    tmp_vec[1] = x[jatm]*ex2[1]+y[jatm]*ey2[1]+z[jatm]*ez2[1];
    tmp_vec[2] = x[jatm]*ex2[2]+y[jatm]*ey2[2]+z[jatm]*ez2[2];
    x[jatm] = tmp_vec[0];
    y[jatm] = tmp_vec[1];
    z[jatm] = tmp_vec[2];
  }
  /*R1_u' in transformed (U) space */
  /*Making it back to relative coord system.*/
  /*Note R1_u = R1, since atom j1, j2, j3 not changed*/
  for (iatm=2; iatm<=natm; iatm++) {
    jatm = atm_group[iatm];
    tmp_vec[0] = x[jatm]*ex1[0]+y[jatm]*ey1[0]+z[jatm]*ez1[0];
    tmp_vec[1] = x[jatm]*ex1[1]+y[jatm]*ey1[1]+z[jatm]*ez1[1];
    tmp_vec[2] = x[jatm]*ex1[2]+y[jatm]*ey1[2]+z[jatm]*ez1[2];
    x[jatm] = tmp_vec[0];
    y[jatm] = tmp_vec[1];
    z[jatm] = tmp_vec[2];
  }
  tmp_vec[0] = x[j1]*ex1[0]+y[j1]*ey1[0]+z[j1]*ez1[0];
  tmp_vec[1] = x[j1]*ex1[1]+y[j1]*ey1[1]+z[j1]*ez1[1];
  tmp_vec[2] = x[j1]*ex1[2]+y[j1]*ey1[2]+z[j1]*ez1[2];
  x[j1] = tmp_vec[0] + x[j2];
  y[j1] = tmp_vec[1] + y[j2];
  z[j1] = tmp_vec[2] + z[j2];
  
  /*From relative coord system to absolute one */
  for (iatm=2; iatm<=natm; iatm++) {
    jatm = atm_group[iatm];
    x[jatm] += x[j1];
    y[jatm] += y[j1];
    z[jatm] += z[j1];
  }
} /*end routine */
