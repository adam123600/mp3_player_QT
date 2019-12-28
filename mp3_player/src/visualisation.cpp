#include "headers/visualisation.h"
#include "ui_visualisation.h"

Visualisation::Visualisation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Visualisation)
{
    ui->setupUi(this);
    this->setMinimumSize(1024, 768);

    // ********** strefa domyślnych ustawień parametrów transformaty ****************
    shifted = false;                // czy zrobić fftshift
    // ******************************************************************************


    //************* ustawienie parametrów wykresu *******************
    chart = new QChart();
    chartView = new QChartView(chart);
    chartView->setMaximumSize(800, 600);

    series = new QLineSeries();

    chart->addSeries(series);

    axisX = new QValueAxis;
    axisX->setRange(0, 1<<14);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Samples");

    axisY = new QValueAxis;
    axisY->setRange(0, 2000);
    axisY->setTitleText("wartosc");

    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chart->legend()->hide();
    chart->setTitle("Transformata Fouriera");

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(chartView);
}

Visualisation::~Visualisation()
{
    delete ui;
}

void Visualisation::prepareData(int length, fftw_complex *data)
{
    buffer.reserve(length);

    if( shifted == true )           // jeśli jest ustawiony fftshift
    {
        for( int i = 0; i < length; i++ )
            buffer.append( QPointF(i+1 - length/2, sqrt(data[i][REAL]*data[i][REAL]+data[i][IMAG]*data[i][IMAG])) );
        axisX->setRange(-length/2, length/2);
    }
    else
    {
        for( int i = 0; i < length; i++ )
            buffer.append( QPointF(i+1, sqrt(data[i][REAL]*data[i][REAL]+data[i][IMAG]*data[i][IMAG])) );
        axisX->setRange( 0, length );
    }

    series->replace(buffer);        // podmiana danych do wyświetlania na wykresie
}

void Visualisation::on_radioFFTShift_clicked(bool checked)
{
    if( checked )
    {
        shifted = true;
        emit shift();       // sygnał zostanie odebrany przez MainWindow::shift(), gdzie zostanie ustawiona wartość shifted, aby funkcja procesBuffer wiedziała czy robić fftshit
    }
    else
    {
        shifted = false;
        emit noshift();     // jak wyżej, MainWindow::noshift()
    }
}


