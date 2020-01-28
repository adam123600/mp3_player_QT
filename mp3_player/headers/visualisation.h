#ifndef VISUALISATION_H
#define VISUALISATION_H

#include <QWidget>
#include <QtCharts>
#include "fastfourier.h"


#define M_2PI (3.1415926535897932384626433 * 2.0)

enum Spectrum {amplitude, phase};


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
    void on_cbFFTShift_clicked( bool checked );
    void on_cbUnwrap_clicked( bool checked );
    void on_pbChangeSpectrum_clicked();

private:
    bool shifted;
    bool unwrapped;
    enum Spectrum spectrum;

    Ui::Visualisation *ui;
    QChart* chart;
    QChartView* chartView;
    QLineSeries* series;
    QXYSeries* qxyseries;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QVBoxLayout* mainLayout;

    QVector<qreal> yData;
    QVector<qreal> yDataUnwrapped;
    QVector<QPointF> buffer;        // vector punktów (x,y)

    void unwrap(QVector<qreal> &inputBuffer, QVector<qreal> &outputBuffer, int length);
    inline double angle_norm(qreal x);
};

#endif // VISUALISATION_H
