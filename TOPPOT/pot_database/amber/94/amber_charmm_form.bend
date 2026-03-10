*  AMBER Cornell et al. (parm94) force field conversion
*  See: JACS (1995) 117, 5179-5197.  
*  nucleic acid part converted by tec3, march 1997
*  protein part converted by tec3, feb 1999
*

!
!  This is a hand-conversion of the Cornell et. al. force field
!  parm94.dat file (except for the torsion which were converted via
!  a perl script).  All the atom type names are the same except where
!  otherwise noted.
!
!  Any problems?  Let me know...
!  cheatham@helix.nih.gov, cheatham@cgl.ucsf.edu
!
!  note: types N* remaned to NS
!              C* renamed to CS
!
!  note: the HO and HW nonbonded parameters, although zero in 
!  Cornell et al. should not have a 0.0 vdw radius in CHARMM 
!  to avoid difficulties with the 0.0/0.0 in the FAST OFF 
!  van der Waal code...
!
!  note: the default nonbonded options chosen here are to match AMBER.
!  It is not recommended that users actually run with GROUP based 
!  truncation and a switch unless really trying to match AMBER.  
!  Better would be ATOM based FSHIFT VSHIFT, however note that this
!  does modify the energies (and effectively the parameters).
!


ANGLES
HW   OW   HW    100.      104.52  !  TIP3P water
HW   HW   OW      0.      127.74  !  (found in crystallographic water with 3 bonds)
CB   C    NA    70.0      111.30  !  NA
CB   C    O     80.0      128.80  !
CM   C    NA    70.0      114.10  !
CM   C    O     80.0      125.30  !
CT   C    O     80.0      120.40  !
CT   C    O2    70.0      117.00  !
CT   C    OH    70.0      117.00  !
NS   C    NA    70.0      115.40  !
NS   C    NC    70.0      118.60  !
NS   C    O     80.0      120.90  !
NA   C    O     80.0      120.60  !
NC   C    O     80.0      122.50  !
CT   C    N     70.0      116.60  !  AA general
N    C    O     80.0      122.90  !  AA general
O    C    O     80.0      126.00  !  AA COO    terminal residues
O2   C    O2    80.0      126.00  !  AA GLU            (SCH JPC 79,2379)
O    C    OH    80.0      126.00  !
CA   C    CA    63.0      120.00  !  changed from 85.0  bsd on C6H6 nmodes; AA tyr
CA   C    OH    70.0      120.00  !  AA tyr
C    CA   CA    63.0      120.00  !  changed from 85.0  bsd on C6H6 nmodes
CA   CA   CA    63.0      120.00  !  changed from 85.0  bsd on C6H6 nmodes
CA   CA   CB    63.0      120.00  !  changed from 85.0  bsd on C6H6 nmodes
CA   CA   CT    70.0      120.00  !
CA   CA   HA    35.0      120.00  !
CA   CA   H4    35.0      120.00  !
CB   CA   HA    35.0      120.00  !
CB   CA   H4    35.0      120.00  !
CB   CA   N2    70.0      123.50  !
CB   CA   NC    70.0      117.30  !
CM   CA   N2    70.0      120.10  !
CM   CA   NC    70.0      121.50  !
N2   CA   NA    70.0      116.00  !
N2   CA   NC    70.0      119.30  !
NA   CA   NC    70.0      123.30  !
C    CA   HA    35.0      120.00  !  AA tyr
N2   CA   N2    70.0      120.00  !  AA arg
CN   CA   HA    35.0      120.00  !  AA trp
CA   CA   CN    63.0      120.00  !  changed from 85.0  bsd on C6H6 nmodes; AA trp
C    CB   CB    63.0      119.20  !  changed from 85.0  bsd on C6H6 nmodes; NA gua
C    CB   NB    70.0      130.00  !
CA   CB   CB    63.0      117.30  !  changed from 85.0  bsd on C6H6 nmodes; NA ade
CA   CB   NB    70.0      132.40  !  
CB   CB   NS    70.0      106.20  !
CB   CB   NB    70.0      110.40  !
CB   CB   NC    70.0      127.70  !
NS   CB   NC    70.0      126.20  !
CS   CB   CA    63.0      134.90  !  changed from 85.0  bsd on C6H6 nmodes; AA trp
CS   CB   CN    63.0      108.80  !  changed from 85.0  bsd on C6H6 nmodes; AA trp
CA   CB   CN    63.0      116.20  !  changed from 85.0  bsd on C6H6 nmodes; AA trp
H5   CK   NS    35.0      123.05  !
H5   CK   NB    35.0      123.05  !
NS   CK   NB    70.0      113.90  !
C    CM   CM    63.0      120.70  !  changed from 85.0  bsd on C6H6 nmodes; NA thy
C    CM   CT    70.0      119.70  !
C    CM   HA    35.0      119.70  !
C    CM   H4    35.0      119.70  !
CA   CM   CM    63.0      117.00  !  changed from 85.0  bsd on C6H6 nmodes; NA cyt
CA   CM   HA    35.0      123.30  !
CA   CM   H4    35.0      123.30  !
CM   CM   CT    70.0      119.70  !
CM   CM   HA    35.0      119.70  !
CM   CM   H4    35.0      119.70  !
CM   CM   NS    70.0      121.20  !
H4   CM   NS    35.0      119.10  !
H5   CQ   NC    35.0      115.45  !
NC   CQ   NC    70.0      129.10  !
CM   CT   HC    50.0      109.50  !  changed based on NMA nmodes
CT   CT   CT    40.0      109.50  !
CT   CT   HC    50.0      109.50  !  changed based on NMA nmodes
CT   CT   H1    50.0      109.50  !  changed based on NMA nmodes
CT   CT   H2    50.0      109.50  !  changed based on NMA nmodes
CT   CT   HP    50.0      109.50  !  changed based on NMA nmodes
CT   CT   NS    50.0      109.50  !
CT   CT   OH    50.0      109.50  !
CT   CT   OS    50.0      109.50  !
HC   CT   HC    35.0      109.50  !
H1   CT   H1    35.0      109.50  !
HP   CT   HP    35.0      109.50  !  AA lys, ch3nh4+
H2   CT   NS    50.0      109.50  !  changed based on NMA nmodes
H1   CT   NS    50.0      109.50  !  changed based on NMA nmodes
H1   CT   OH    50.0      109.50  !  changed based on NMA nmodes 
H1   CT   OS    50.0      109.50  !  changed based on NMA nmodes 
H2   CT   OS    50.0      109.50  !  changed based on NMA nmodes
NS   CT   OS    50.0      109.50  !
H1   CT   N     50.0      109.50  !  AA general  changed based on NMA nmodes
C    CT   H1    50.0      109.50  !  AA general  changed based on NMA nmodes
C    CT   HP    50.0      109.50  !  AA zwitterion  changed based on NMA nmodes
H1   CT   S     50.0      109.50  !  AA cys     changed based on NMA nmodes
H1   CT   SH    50.0      109.50  !  AA cyx     changed based on NMA nmodes
CT   CT   S     50.0      114.70  !  AA cyx            (SCHERAGA  JPC 79,1428)
CT   CT   SH    50.0      108.60  !  AA cys
H2   CT   H2    35.0      109.50  !  AA lys
H1   CT   N2    50.0      109.50  !  AA arg     changed based on NMA nmodes
HP   CT   N3    50.0      109.50  !  AA lys, ch3nh3+, changed based on NMA nmodes
CA   CT   CT    63.0      114.00  !  AA phe tyr          (SCH JPC  79,2379)
C    CT   HC    50.0      109.50  !  AA gln      changed based on NMA nmodes
C    CT   N     63.0      110.10  !  AA general
CT   CT   N2    80.0      111.20  !  AA arg             (JCP 76, 1439)
CT   CT   N     80.0      109.70  !  AA ala, general    (JACS 94, 2657)
C    CT   CT    63.0      111.10  !  AA general
CA   CT   HC    50.0      109.50  !  AA tyr     changed based on NMA nmodes
CT   CT   N3    80.0      111.20  !  AA lys             (JCP 76, 1439)
CC   CT   CT    63.0      113.10  !  AA his
CC   CT   HC    50.0      109.50  !  AA his     changed based on NMA nmodes
C    CT   N3    80.0      111.20  !  AA amino terminal residues
CS   CT   CT    63.0      115.60  !  AA trp
CS   CT   HC    50.0      109.50  !  AA trp    changed based on NMA nmodes
CT   CC   NA    70.0      120.00  !  AA his
CT   CC   CV    70.0      120.00  !  AA his
CT   CC   NB    70.0      120.00  !  AA his
CV   CC   NA    70.0      120.00  !  AA his
CW   CC   NA    70.0      120.00  !  AA his
CW   CC   NB    70.0      120.00  !  AA his
CT   CC   CW    70.0      120.00  !  AA his
H5   CR   NA    35.0      120.00  !  AA his
H5   CR   NB    35.0      120.00  !  AA his
NA   CR   NA    70.0      120.00  !  AA his
NA   CR   NB    70.0      120.00  !  AA his
CC   CV   H4    35.0      120.00  !  AA his
CC   CV   NB    70.0      120.00  !  AA his
H4   CV   NB    35.0      120.00  !  AA his
CC   CW   H4    35.0      120.00  !  AA his
CC   CW   NA    70.0      120.00  !  AA his
H4   CW   NA    35.0      120.00  !  AA his
CS   CW   H4    35.0      120.00  !  AA trp
CS   CW   NA    70.0      108.70  !  AA trp
CT   CS   CW    70.0      125.00  !  AA trp
CB   CS   CT    70.0      128.60  !  AA trp
CB   CS   CW    63.0      106.40  !  changed from 85.0  bsd on C6H6 nmodes; AA trp
CA   CN   NA    70.0      132.80  !  AA trp
CB   CN   NA    70.0      104.40  !  AA trp
CA   CN   CB    63.0      122.70  !  changed from 85.0  bsd on C6H6 nmodes; AA trp
C    N    CT    50.0      121.90  !  AA general
C    N    H     30.0      120.00  !  AA general, gln, asn,changed based on NMA nmodes
CT   N    H     30.0      118.04  !  AA general,     changed based on NMA nmodes
CT   N    CT    50.0      118.00  !  AA pro             (DETAR JACS 99,1232)
H    N    H     35.0      120.00  !  ade,cyt,gua,gln,asn     **
C    NS   CM    70.0      121.60  !
C    NS   CT    70.0      117.60  !
C    NS   H     30.0      119.20  !  changed based on NMA nmodes
CB   NS   CK    70.0      105.40  !
CB   NS   CT    70.0      125.80  !
CB   NS   H     30.0      125.80  !  for unmethylated n.a. bases,chngd bsd NMA nmodes
CK   NS   CT    70.0      128.80  !
CK   NS   H     30.0      128.80  !  for unmethylated n.a. bases,chngd bsd NMA nmodes
CM   NS   CT    70.0      121.20  !
CM   NS   H     30.0      121.20  !  for unmethylated n.a. bases,chngd bsd NMA nmodes
CA   N2   H     35.0      120.00  !  
H    N2   H     35.0      120.00  !  
CT   N2   H     35.0      118.40  !  AA arg
CA   N2   CT    50.0      123.20  !  AA arg
CT   N3   H     50.0      109.50  !  AA lys,     changed based on NMA nmodes
CT   N3   CT    50.0      109.50  !  AA pro/nt
H    N3   H     35.0      109.50  !  AA lys, AA(end)
C    NA   C     70.0      126.40  !
C    NA   CA    70.0      125.20  !
C    NA   H     30.0      116.80  !  changed based on NMA nmodes
CA   NA   H     30.0      118.00  !  changed based on NMA nmodes
CC   NA   CR    70.0      120.00  !  AA his
CC   NA   H     30.0      120.00  !  AA his,    changed based on NMA nmodes
CR   NA   CW    70.0      120.00  !  AA his
CR   NA   H     30.0      120.00  !  AA his,    changed based on NMA nmodes
CW   NA   H     30.0      120.00  !  AA his,    changed based on NMA nmodes
CN   NA   CW    70.0      111.60  !  AA trp
CN   NA   H     30.0      123.10  !  AA trp,    changed based on NMA nmodes
CB   NB   CK    70.0      103.80  !
CC   NB   CR    70.0      117.00  !  AA his
CR   NB   CV    70.0      117.00  !  AA his
C    NC   CA    70.0      120.50  !
CA   NC   CB    70.0      112.20  !
CA   NC   CQ    70.0      118.60  !
CB   NC   CQ    70.0      111.00  !
C    OH   HO    35.0      113.00  !
CT   OH   HO    55.0      108.50  !
HO   OH   P     45.0      108.50  !
CT   OS   CT    60.0      109.50  !
CT   OS   P    100.0      120.50  !
P    OS   P    100.0      120.50  !
O2   P    OH    45.0      108.23  !
O2   P    O2   140.0      119.90  !
O2   P    OS   100.0      108.23  !
OH   P    OS    45.0      102.60  !
OS   P    OS    45.0      102.60  !
CT   S    CT    62.0       98.90  !  AA met
CT   S    S     68.0      103.70  !  AA cyx             (SCHERAGA  JPC 79,1428)
CT   SH   HS    43.0       96.00  !  changed from 44.0 based on methanethiol nmodes
HS   SH   HS    35.0       92.07  !  AA cys
F    CT   F     77.0      109.10  !  JCC,13,(1992),963;
F    CT   H1    35.0      109.50  !  JCC,13,(1992),963;
