#! /usr/bin/perl -w
# converts tors parameters
# usage:
#  ./convert_charmm_tors.pl charmm_tors.prm > pas_tors.prm

  $cn[0][0] = 1;  $cn[0][1] = 0; $cn[0][2] = 0;
  $cn[1][0] = 0;  $cn[1][1] = 1; $cn[1][2] = 0;
  $cn[2][0] =-1;  $cn[2][1] = 0; $cn[2][2] = 2;
  $cn[3][0] = 0;  $cn[3][1] =-3; $cn[3][2] = 0;
  $cn[4][0] = 1;  $cn[4][1] = 0; $cn[4][2] =-8;
  $cn[5][0] = 0;  $cn[5][1] = 5; $cn[5][2] = 0;
  $cn[6][0] =-1;  $cn[6][1] = 0; $cn[6][2] =18;

  $cn[0][3] = 0;  $cn[0][4] = 0;  $cn[0][5] = 0;  $cn[0][6] = 0;
  $cn[1][3] = 0;  $cn[1][4] = 0;  $cn[1][5] = 0;  $cn[1][6] = 0;
  $cn[2][3] = 0;  $cn[2][4] = 0;  $cn[2][5] = 0;  $cn[2][6] = 0;
  $cn[3][3] = 4;  $cn[3][4] = 0;  $cn[3][5] = 0;  $cn[3][6] = 0;
  $cn[4][3] = 0;  $cn[4][4] = 8;  $cn[4][5] = 0;  $cn[4][6] = 0;
  $cn[5][3] =-20; $cn[5][4] = 0;  $cn[5][5] = 16; $cn[5][6] = 0;
  $cn[6][3] = 0;  $cn[6][4] =-48; $cn[6][5] = 0;  $cn[6][6] = 32;

  $sn[0][1] = 0; $sn[0][2] = 0;
  $sn[1][1] = 1; $sn[1][2] = 0;
  $sn[2][1] = 0; $sn[2][2] = 2;
  $sn[3][1] = 3; $sn[3][2] = 0;
  $sn[4][1] = 0; $sn[4][2] = 4;
  $sn[5][1] = 5; $sn[5][2] = 0;
  $sn[6][1] = 0; $sn[6][2] = 37;

  $sn[0][3] = 0;  $sn[0][4] = 0;  $sn[0][5] = 0;  $sn[0][6] = 0;
  $sn[1][3] = 0;  $sn[1][4] = 0;  $sn[1][5] = 0;  $sn[1][6] = 0;
  $sn[2][3] = 0;  $sn[2][4] = 0;  $sn[2][5] = 0;  $sn[2][6] = 0;
  $sn[3][3] = 0;  $sn[3][4] = 0;  $sn[3][5] = 0;  $sn[3][6] = 0;
  $sn[4][3] = 0;  $sn[4][4] =-8;  $sn[4][5] = 0;  $sn[4][6] = 0;
  $sn[5][3] = 0;  $sn[5][4] = 0;  $sn[5][5] = 0;  $sn[5][6] = 0;
  $sn[6][3] = 0;  $sn[6][4] =-63; $sn[6][5] = 0;  $sn[6][6] = 32;

  $spn[0][2] = 0;
  $spn[1][2] = 0;
  $spn[2][2] = 0;
  $spn[3][2] = 0;
  $spn[4][2] = 0;
  $spn[5][2] = 0;
  $spn[6][2] = 0;

  $spn[0][3] = 0;  $spn[0][4] = 0;  $spn[0][5] = 0;  $spn[0][6] = 0;
  $spn[1][3] = 0;  $spn[1][4] = 0;  $spn[1][5] = 0;  $spn[1][6] = 0;
  $spn[2][3] = 0;  $spn[2][4] = 0;  $spn[2][5] = 0;  $spn[2][6] = 0;
  $spn[3][3] =-4;  $spn[3][4] = 0;  $spn[3][5] = 0;  $spn[3][6] = 0;
  $spn[4][3] = 0;  $spn[4][4] = 0;  $spn[4][5] = 0;  $spn[4][6] = 0;
  $spn[5][3] =-20; $spn[5][4] = 0;  $spn[5][5] =16;  $spn[5][6] = 0;
  $spn[6][3] = 0;  $spn[6][4] = 0;  $spn[6][5] = 0;  $spn[6][6] = 0;


  $ndihedral = 0;
  $nentry = 0;
  $atom1_save = 'DUMMY';
  $atom2_save = 'DUMMY';
  $atom3_save = 'DUMMY';
  $atom4_save = 'DUMMY';
  $kcal2K = 315777.0/627.50921;
  while (<>) {
        s/!.*//; s/\*.*//;      # ignore comments
        next if /^(\s)*$/;      # skip blank lines
        @entry = split;
        if ($entry[0] ne 'DIHEDRALS') {
            $nentry++;
            $atom1 = $entry[0];
            $atom2 = $entry[1];
            $atom3 = $entry[2];
            $atom4 = $entry[3];
            $Kchi  = $entry[4]; $Kchi*=$kcal2K;
            $n     = $entry[5];
            $delta = $entry[6];

            $Kchi_cos_delta = $Kchi*cos($delta);
            $Kchi_sin_delta = $Kchi*sin($delta);

            $new_dihedral = 0;
            if ( ($atom1 ne $atom1_save) ||
                 ($atom2 ne $atom2_save) ||
                 ($atom3 ne $atom3_save) ||
                 ($atom4 ne $atom4_save) ) {
		  $new_dihedral = 1; 
                  $ndihedral++; $multi[$ndihedral] = 0;
                  for ($ip=0;$ip<=6;$ip++) {$p[$ip] = 0.0;}
                  for ($is=1;$is<=6;$is++) {$s[$is] = 0.0;}
                  for ($isp=2;$isp<=6;$isp++) {$sp[$isp] = 0.0;}
	    }
	    $multi[$ndihedral]++;
            for ($ip=0;$ip<=6;$ip++) {
                 $p[$ip] += $Kchi_cos_delta*$cn[$n][$ip];
            }
            for ($is=1;$is<=6;$is++) {
                 $s[$is] += $Kchi_sin_delta*$sn[$n][$is];
            }
            for ($isp=2;$isp<=6;$isp++) {
                 $sp[$isp] += $Kchi_sin_delta*$spn[$n][$isp];
            }
            $p[0] += $Kchi; 
            for ($ip=0;$ip<=6;$ip++) {
                 $ps[$ip] =  sprintf("%.7g",$p[$ip]);
		  if ($ps[$ip]==0) {$ps[$ip] = '0';}
            }
            for ($is=1;$is<=6;$is++) {
                 $so[$is] =  sprintf("%.7g",$s[$is]);
		  if ($so[$is]==0) {$so[$is] = '0';}
            }
            for ($isp=2;$isp<=6;$isp++) {
                 $spo[$isp] =  sprintf("%.7g",$sp[$isp]);
		  if ($spo[$isp]==0) {$spo[$isp] = '0';}
            }
         
#            print "@entry\n";
   
            $atom1[$nentry] = $atom1;
            $atom2[$nentry] = $atom2;
            $atom3[$nentry] = $atom3;
            $atom4[$nentry] = $atom4;
            for ($ip=0;$ip<=6;$ip++) {
                 $p_[$nentry][$ip] = $ps[$ip];
            }
            for ($is=1;$is<=6;$is++) {
                 $s_[$nentry][$is] = $so[$is];
            }
            for ($isp=2;$isp<=6;$isp++) {
                 $sp_[$nentry][$isp] = $spo[$isp];
            }

            $atom1_save = $atom1;
            $atom2_save = $atom2;
            $atom3_save = $atom3;
            $atom4_save = $atom4;
        }#end if#
  }#end while#


  $nentry = 0;
  for ($idihedral=1;$idihedral<=$ndihedral;$idihedral++) {
      for ($imulti=1;$imulti<=$multi[$idihedral];$imulti++) {
          $nentry++;
          if ($imulti==$multi[$idihedral]) {
              $atom1 = $atom1[$nentry];
              $atom2 = $atom2[$nentry];
              $atom3 = $atom3[$nentry];
              $atom4 = $atom4[$nentry];
              for ($ip=0;$ip<=6;$ip++) {
                   $ps[$ip] = $p_[$nentry][$ip];
              }
              for ($is=1;$is<=6;$is++) {
                   $so[$is] = $s_[$nentry][$is];
              }
              for ($isp=2;$isp<=6;$isp++) {
                   $spo[$isp] = $sp_[$nentry][$isp];
              }
              print "~torsion_parm[\\atom1{$atom1}";
              print               "\\atom2{$atom2}";
              print               "\\atom3{$atom3}";
	      print               "\\atom4{$atom4}";
              print               "\\pot_type{power}\n";
              print "              \\p0{$ps[0]}\\p1{$ps[1]}";
  	      print               "\\p2{$ps[2]}\\p3{$ps[3]}\n";
              print "              \\p4{$ps[4]}\\p5{$ps[5]}";
              print               "\\p6{$ps[6]}\n";
              print "              \\s1{$so[1]}\\s2{$so[2]}\\s3{$so[3]}\n";
              print "              \\s4{$so[4]}\\s5{$so[5]}\\s6{$so[6]}\n";
              print "              \\sp2{$spo[2]}\\sp3{$spo[3]}\\sp4{$spo[4]}\n";
              print "              \\sp5{$spo[5]}\\sp6{$spo[6]}]\n";
          }
      }
  }


