#ifndef VISUALISATION_H
#define VISUALISATION_H

#include <QWidget>
#include <QtCharts>
#include "fastfourier.h"


#define M_2PI (3.1415926535897932384626433 * 2.0)


namespace Ui {
class Visualisation;
}

class Visualisation : public QWidget
{
    Q_OBJECT

public:
    explicit Visualisation(QWidget *parent = nullptr);
    ~Visualisation();

signals:
    void shift();
    void noshift();

public slots:
    void prepareData(int length, fftw_complex* data);
    void on_radioFFTShift_clicked( bool checked );

private:
    bool shifted;

    Ui::Visualisation *ui;
    QChart* chart;
    QChartView* chartView;
    QLineSeries* series;
    QXYSeries* qxyseries;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QVBoxLayout* mainLayout;

    QVector<QPointF> buffer;        // vector punktów (x,y)
    QVector<double> radBuffer;
    QVector<double> unwrappedBuffer;

    double angle(double x, double y);
    void unwrap(QVector<double> inputBuffer, QVector<double> outputBuffer, int length);
    inline double angle_norm(double x);
};

#endif // VISUALISATION_H
