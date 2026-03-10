#! /usr/bin/perl -w
# converts bend parameters
# usage:
#  ./convert_charmm_bend.pl charmm_bend.prm > pas_bend.prm

  $kcal2K = 315777.0/627.50921;
  while (<>) {
        s/!.*//; s/\*.*//;      # ignore comments
        next if /^(\s)*$/;      # skip blank lines
        @entry = split;        
        if ($entry[0] ne 'ANGLES') {
            $atom1   = $entry[0];
            $atom2   = $entry[1];
            $atom3   = $entry[2];
            $Ktheta  = $entry[3]; $Ktheta*=2.0*$kcal2K; 
            $theta0  = $entry[4];
            $Kthetas = sprintf("%.9g",$Ktheta);
            $theta0s = sprintf("%.7g",$theta0);
            $length = @entry;
            if ($length==7) {
               $Kub  = $entry[5]; $Kub*=2.0*$kcal2K;
               $S0   = $entry[6];
               $Kubs = sprintf("%.9g",$Kub);
               $S0s = sprintf("%.7g",$S0);               
            } 
            if ($length==5) {
#	      print "@entry $length\n";
              print "~bend_parm[\\atom1{$atom1}";
              print            "\\atom2{$atom2}";
              print            "\\atom3{$atom3}\n";
              print "           \\pot_type_bend{harm}";
              print            "\\fk_bend{$Kthetas}\\eq_bend{$theta0s}]\n";
	    }
	    elsif ($length==7) {
#              print "@entry $length\n";
              print "~bend_parm[\\atom1{$atom1}";
              print            "\\atom2{$atom2}";
              print            "\\atom3{$atom3}\n";
              print "           \\pot_type_bend{harm}";
              print            "\\fk_bend{$Kthetas}\\eq_bend{$theta0s}\n";
              print "           \\pot_type_bond{harm}";
              print            "\\fk_bond{$Kubs}\\eq_bond{$S0s}]\n";
            }
            else {
		die "Input file is corrupted";
            }            
        }#end if#
  }#end while#
