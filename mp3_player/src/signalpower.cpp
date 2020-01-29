#include "headers/signalpower.h"

#include <QDebug>
SignalPower::SignalPower(int length, double* inputArray)
{
    decibels = 0;
    QVector<qreal> data;
    data.resize(length);

    for (int i = 0; i < length; i++)
        data[i]=abs(inputArray[i]);

    qreal val = calcPowerOfSignal(data, length);
    decibels = convertToDecibels(val);

    data.clear();
}

qreal SignalPower::getPower()
{
    return decibels;
}

qreal SignalPower::calcPowerOfSignal(QVector<qreal> data, int length)
{
    std::transform(data.begin(), data.end(), data.begin(), &toSquare);
    qreal rVal = 0;
    for (int i = 0 ; i < data.length(); i++)
    {
        rVal += data[i];
    }
    return (1/(qreal)length)*rVal;

}

qreal SignalPower::toSquare(qreal value)
{
    return value*value;
}

qreal SignalPower::convertToDecibels(qreal voltageValue)
{
    return 20*log10(voltageValue/1);
}
