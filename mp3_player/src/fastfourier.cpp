#include "headers/fastfourier.h"
#include <QDebug>


FastFourier::FastFourier(int length, double* inputArray)
{
    this->length = length;
    this->inputArray = (fftw_complex*)calloc(length, sizeof(fftw_complex));
    outputArray = (fftw_complex*)calloc(length, sizeof(fftw_complex));
    for (int i = 0; i < this->length; i++)
        this->inputArray[i][REAL] = inputArray[i];
        // this->inputArray[i][IMAG] jest już wyzerowane przez calloc
}

FastFourier::~FastFourier()
{
    free(inputArray);
    fftw_free(outputArray);
}

void FastFourier::Calculate()
{
    fftw_plan plan = fftw_plan_dft_1d( length, inputArray, outputArray, FFTW_FORWARD, FFTW_ESTIMATE );
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    fftw_cleanup();
}

fftw_complex* FastFourier::getResult()
{
    return outputArray;
}

void FastFourier::printResults()
{
    for (int i = 0; i < this->length ; i++)
    {
        qDebug() << "Real: " <<outputArray[i][REAL] << " Imag: " << outputArray[i][IMAG];
    }
}

void FastFourier::showSpectrum( int sampleRate )
{
    for(int i = 0; i < length; i++)
    {
        qDebug() << "Frequency: " << i * (sampleRate)/length <<" val: "
                 << sqrt( outputArray[i][REAL] * outputArray[i][REAL] + outputArray[i][IMAG] * outputArray[i][IMAG]);
    }
}

void FastFourier::fftshift()
{
    if( length % 2 )    // dla nieparzystej ilości elementów
        std::rotate( outputArray[0], outputArray[length/2 + 1], outputArray[length] );
    else                // dla parzystej ilości elementów
        std::rotate( outputArray[0], outputArray[length/2], outputArray[length] );
}

