README.txt
Homework 3
Authors: Donald Villarreal & Joseph Wagner
Class: CSC470

dft in dir out
Function dft computes the discrete Fourier transform of a 1-D list of complex numbers in file in. If dir = 0, the forward
DFT is computed. If dir = 1, the inverse DFT is computed. The result is another list of complex numbers
stored in file out. Note that the complex numbers are stored in the files as two columns of numbers (real and imaginary)
in ASCII format. The first line of the file consists of two numbers: the width and height of the file data, i.e., 2
and N, respectively. N refers to the number of complex numbers in the file. Since this is the straightforward implementation
of Eqs. (1) and (2), there are no restrictions on N, i.e., it does not have to be a power of 2 as in the case of
the FFT.

fft in dir out
Implement the 1D fast Fourier transform using the recursive Danielson-Lanczos solution. Repeat Prob. (3) using the
FFT instead of the straightforward DFT algorithm implemented above. Note that the length of the list must be a
power of two to make the comparison with Prob. (3) (e.g., run dft on the same list to compare results).

spectrum in mag phase
Implement the 2-D fast Fourier transform. Use a separable implementation that first calls fft upon all the rows, and
then takes that result and computes fft on all the columns. The input image in file in consists of pixels of type
unsigned char. Be sure to append an imaginary channel of 0’s to convert the input into a complex image. Convert
the magnitude and phase spectrums into the range [0,255] for display purposes by scaling their maximum and minimum
values to the [0,255] range. Save the scaled results in files mag and phase, respectively.

swapPhase in1 in2 out1 out2
Read two input images in1 and in2 of identical dimensions. Both images consist of pixels of type unsigned char.
Compute their respective magnitude and phase spectra. Let mag() and phase() refer to the magnitude and phase
spectra of image I, respectively. Let out1 be the image produced as a result of the inverse Fourier transform of
mag(in1) and phase(in2). Let out2 be the image produced as a result of the inverse Fourier transform of mag(in2)
and phase(in1). Save the output as images of unsigned char by saving the magnitudes of the resulting complex
numbers. According to the results you obtained, what proves to be more important to the preservation of the image:
the magnitude or the phase spectra?