#! /usr/bin/perl -w
# converts bond parameters
# usage:
#  ./convert_charmm_bond.pl charmm_bond.prm > pas_bond.prm

  $kcal2K = 315777.0/627.50921;
  while (<>) {
        s/!.*//; s/\*.*//;      # ignore comments
        next if /^(\s)*$/;      # skip blank lines
        @entry = split;        
        if ($entry[0] ne 'BONDS') {
            $atom1 = $entry[0];
            $atom2 = $entry[1];
            $Kb    = $entry[2]; $Kb*=$kcal2K; $Kb*=2.0; 
            $b0    = $entry[3];
            $Kbs   = sprintf("%.9g",$Kb);
            $b0s   = sprintf("%.7g",$b0);
#	    print "@entry\n";
            print "~bond_parm[\\atom1{$atom1}";
            print            "\\atom2{$atom2}";
            print            "\\pot_type{harm}";
            print            "\\fk{$Kbs}\\eq{$b0s}]\n"; 
        }#end if#
  }#end while#
