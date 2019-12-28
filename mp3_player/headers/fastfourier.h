#ifndef FASTFOURIER_H
#define FASTFOURIER_H

#include <iostream>
#include <QVector>
#include <fftw3.h>
#include <math.h>

#define REAL    0
#define IMAG    1

class FastFourier
{

public:
    FastFourier(int length, double* inputArray);
    ~FastFourier();
    void Calculate();
    fftw_complex* getResult();
    void printResults();
    void showSpectrum( int sampleRate );
    void fftshift();


private:
    int length;
    fftw_complex* inputArray;
    fftw_complex* outputArray;
};

#endif // FASTFOURIER_H
