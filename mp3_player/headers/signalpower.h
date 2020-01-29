#ifndef SIGNALPOWER_H
#define SIGNALPOWER_H

#include <QVector>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

class SignalPower
{
public:
   SignalPower(int length, double* inputArray);
   qreal getPower();
private:
   qreal decibels;
   qreal calcPowerOfSignal(QVector<qreal> data, int length);
   static qreal toSquare(qreal value);
   qreal convertToDecibels(qreal voltageValue);
};

#endif // SIGNALPOWER_H
