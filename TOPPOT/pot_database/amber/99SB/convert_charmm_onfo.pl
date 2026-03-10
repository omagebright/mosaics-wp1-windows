#! /usr/bin/perl -w
# converts vdw parameters
# usage:
#  ./convert_charmm_onfo.pl charmm_nonbonded.prm > pas_onfo.prm


  $kcal2K = 315777.0/627.50921;
  $natom = 0;
  while (<>) {
        s/!.*//; s/\*.*//;      # ignore comments
        next if /^(\s)*$/;      # skip blank lines
        @entry = split;        
        if ($entry[0] ne 'NONBONDED') {
            $natom++;
            $length = @entry;
            if ($length==4) {
               $atom[$natom] = $entry[0];
               $eps[$natom]  = $entry[2];
               $rmin[$natom] = $entry[3];    
	    }   
            elsif ($length==7) {
               $atom[$natom] = $entry[0];
               $eps[$natom]  = $entry[5];
               $rmin[$natom] = $entry[6];    
            }            
#            print "@entry $length\n";
#            <STDIN>; 
       }#end if#
  }#end while#

  $two_pow_i6 = 1.122462048;    # 2^(1/6)

  for ($iatom=1;$iatom<=$natom;$iatom++) {
       for ($jatom=$iatom;$jatom<=$natom;$jatom++) {
            $atom1 = $atom[$iatom];
            $atom2 = $atom[$jatom]; 
            $rmin  = $rmin[$iatom] + $rmin[$jatom];
            $sig   = $rmin/$two_pow_i6;
            $eps   = sqrt($eps[$iatom]*$eps[$jatom])*$kcal2K;
            $epss  = sprintf("%.9g",$eps);            
            $sigs  = sprintf("%.9g",$sig);
            print "~onefour_parm[\\atom1{$atom1}";
            print             "\\atom2{$atom2}";
            print             "\\pot_type{lennard-jones}\n";
            print "            \\eps{$epss}\\sig{$sigs}\n";
            print "            \\min_dist{0.5}\\max_dist{10}\\res_dist{6.8}]\n";
       }#end for#
  }#end for#    
