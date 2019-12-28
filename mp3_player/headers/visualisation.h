#ifndef VISUALISATION_H
#define VISUALISATION_H

#include <QWidget>
#include <QtCharts>
#include "fastfourier.h"

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
};

#endif // VISUALISATION_H
