#---------------------------------------------------------------#
# Homework 3 Makefile
#	Joseph Wagner		(phraxos@phraxos.biz)
#	Donald Villarreal	(donaldjvillarreal@gmail.com)
#---------------------------------------------------------------#

CC	= g++	# Use gcc compiler. Use g++ for C++ compilation.
CFLAGS	=	# Compiler flags: -g for debug, -O for optimization
LDFLAGS	= 	# Linker flags
LIBS	= -lm	# Libraries to link with (-lm is the math library)

# This is the Master Compile command, which can be used for
# all executables. Simply make a new entry for each one underneath,
# and change the ALL variable.
# YOU SHOULD NOT NEED TO TOUCH THIS.
#
#   $@ stands for the target name (i.e., the resulting executable)
#   $? stands for the dependency list (i.e., the .o files)
#
COMPILE_EXECUTABLE = $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $? $(LIBS)

# These are all the files to be compiled.
ALL	= dft fft spectrum swapPhase

all:	$(ALL)

# List of executable targets
dft:		$($@.o) IPutil.o
fft: 		$($@.o) IPutil.o
spectrum: 	$($@.o) IPutil.o
swapPhase: 	$($@.o) IPutil.o

# Clean target to remove backup, object, and core files
clean:
	rm -f *~ *.o core
cleanx:
	rm -f *~ *.o core $(ALL)

# Dependencies

dft.o:			IP.h
fft.o:			IP.h
spectrum.o:		IP.h
swapPhase.o:	IP.h