#! /usr/bin/perl -w
# converts impr parameters
# usage:
#  ./convert_charmm_impr.pl charmm_impr.prm > pas_impr.prm

  $kcal2K = 315777.0/627.50921;
  while (<>) {
        s/!.*//; s/\*.*//;      # ignore comments
        next if /^(\s)*$/;      # skip blank lines
        @entry = split;        
        if ($entry[0] ne 'IMPROPER') {
            $atom1 = $entry[0];
            $atom2 = $entry[1];
            $atom3 = $entry[2];
            $atom4 = $entry[3];
            $Kpsi  = $entry[4]; $Kpsi*=2.0*$kcal2K; 
            # skip entry[5]
            $psi0  = $entry[6];
            $Kpsis =  sprintf("%.7g",$Kpsi);
            $psi0s =  sprintf("%.7g",$psi0);
#            print "@entry\n";
            print "~torsion_parm[\\atom1{$atom1}";
            print               "\\atom2{$atom2}";
            print               "\\atom3{$atom3}";
	    print               "\\atom4{$atom4}";
            print               "\\pot_type{harm}\n";
            print "              \\fk{$Kpsis}\\eq{$psi0s}\\label{improper}]\n";
        }#end if#
  }#end while#
