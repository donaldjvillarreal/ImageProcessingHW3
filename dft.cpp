///////
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// dft.cpp - Discrete Fourier Transform
//
// Written by: Donald Villarreal
//             Joseph Wagner
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "IP.h"
using namespace std;

// function prototype
void dft(char*, int, char*);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// main:
//
// Main routine to compute the discrete Fourier transform of a 1-D list of complex numbers .
//
int
main(int argc, char** argv)
{
	int			dir; 

	// error checking: proper usage
	if(argc != 4) {
		cerr << "Usage: dft in dir out\n";
		exit(1);
	}

	// read input image (I1) and reserve space for output (I2)
	char *in = argv[1];

	// read lower and upper thresholds
	dir  = atoi(argv[2]);

	if(dir < 0 || dir > 1) {
		cerr << "dir must be a 0 (for forward) or 1 (for inverse)\n";
		exit(1);
	}

	char *out = argv[3];
	// blur image and save result in file
	dft(in, dir, out);

	return 1;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// dft:
//
// Discrete Fourier Transform
// 

void
dft(char *in, int dir, char *out)
{
	int width, N, i, u, x;
	double real, imag;
	//Read input from kernel file
    ifstream file(in);
    if(file.is_open()) {
    	file >> width;		file >> N;
    }

	double Fr[N], Fi[N], f[N];
	if(dir==0) {
	    if(file.is_open())
			for(i=0; i < N; i++) file >> f[i];
	}

	else if(dir==1) {
		if(file.is_open()) {
			for(i=0; i < N; i++) {
				file >> Fr[i];
				file >> Fi[i];
			}
		}
	}

	ofstream myfile;
	myfile.open(out);
	if(dir==0) {
		for(u=0; u<N; u++) {
			real = imag = 0;
			for(x=0; x<N; x++) {
				real += (f[x]*cos(-2*PI*u*x/N));
				imag += (f[x]*sin(-2*PI*u*x/N));
			}
			Fr[u] = real / N;
			Fi[u] = imag / N;
			myfile << Fr[u] << " " << Fi[u] << "\n";
		}
	}

	else if(dir==1) {
		double c, s, fr[N];
		for(x=0; x<N; x++) {
			real = imag = 0;
			for(u=0; u<N; u++) {
				c = cos(2*PI*u*x/N);
				s = sin(2*PI*u*x/N);
				real += (Fr[u]*c-Fi[u]*s);
				imag += (Fr[u]*s+Fi[u]*c);
			}
			fr[x] = real;
			myfile << fr[x] << "\n";
		}
	}
	myfile.close();
}