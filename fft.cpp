///////
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// fft.cpp - Fast Fourier Transform
//
// Written by: Donald Villarreal
//             Joseph Wagner
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "IP.h"
using namespace std;

// function prototype
void fft(complexP, int, complexP);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// main:
//
// Main routine to compute the fast Fourier transform of a 1-D list of complex numbers 
// using the recursive Danielson-Lanczos solution.
//
int
main(int argc, char** argv)
{
	int			dir; 
	complexP	I1, I2;

	// error checking: proper usage
	if(argc != 4) {
		cerr << "Usage: dft in dir out\n";
		exit(1);
	}

	// read input image (I1) and reserve space for output (I2)
	I1 = IP_readImage(argv[1]);
	I2 = NEWIMAGE;

	// read lower and upper thresholds
	dir  = atoi(argv[2]);

	if(dir < 0 || dir > 1) {
		cerr << "dir must be a 0 (for forward) or 1 (for inverse)\n";
		exit(1);
	}

	// blur image and save result in file
	dft(I1, dir, I2);
	IP_saveImage(I2, argv[4]);

	// free up image structures/memory
	IP_freeImage(I1);
	IP_freeImage(I2);

	return 1;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// fft:
//
// Fast Fourier Transform
// 

void
dft(imageP I1, int dir, imageP I2)
{




}