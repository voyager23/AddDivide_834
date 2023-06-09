#Makefile

qs : Makefile quadsoln.cxx
	clang++ quadsoln.cxx toolbox.cxx -g --std=c++20 -o qs
	
fss: fs_s.cxx Makefile 
	clang++ fs_s.cxx toolbox.cxx --std=c++20 -g -o fss

svalues: s_values.cxx Makefile
	clang++ s_values.cxx --std=c++20 -o sv
	
resid: residues.cxx Makefile
	clang residues.cxx --std=c++20 -o resid
	
sfind: s_find.cxx Makefile
	clang s_find.cxx --std=c++20 -o sf
	

