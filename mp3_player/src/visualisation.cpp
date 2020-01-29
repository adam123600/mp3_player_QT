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
    spectrum = amplitude;
    unwrapped = false;

    ui->sliderSamplesCount->setMinimum(MIN_SAMPLES);
    ui->sliderSamplesCount->setMaximum(MAX_SAMPLES);
    ui->sliderSamplesCount->setValue(DEFAULT_SAMPLES);

    ui->leSamplesCount->setText( QString::number(DEFAULT_SAMPLES) );
    samplesPerSecond = DEFAULT_SAMPLES_PER_SEC;
    ui->labelWindowTime->setText( QString::number((double)DEFAULT_SAMPLES/DEFAULT_SAMPLES_PER_SEC, 'g', 2) + " s" );
    // ******************************************************************************


    //************* ustawienie parametrów wykresu *******************
    chart = new QChart();
    chartView = new QChartView(chart);
    chartView->setMaximumSize(800, 600);

    series = new QLineSeries();

    chart->addSeries(series);

    axisX = new QValueAxis;
    axisX->setRange(0, DEFAULT_SAMPLES);
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

void Visualisation::setSamplesPerSecond( int sps )
{
    samplesPerSecond = sps;
}

Visualisation::~Visualisation()
{
    delete ui;
}

void Visualisation::prepareData(int length, fftw_complex *data)
{
    if( buffer.size() != length )
        buffer.reserve(length);
    buffer.clear();

    if( yData.size() != length )
        yData.reserve(length);
    yData.clear();

    if( spectrum == amplitude )
    {
        for( int i = 0; i < length; i++ )
            yData.append( sqrt(data[i][REAL]*data[i][REAL]+data[i][IMAG]*data[i][IMAG]) );

        axisY->setRange( 0, 3000 );
    }
    else        // spectrum == phase
    {
        for( int i = 0; i< length; i++ )
            yData.append( atan2(data[i][REAL], data[i][IMAG]) );
        if( unwrapped )
        {
            yDataUnwrapped.clear();
            if( yDataUnwrapped.size() != length )
                yDataUnwrapped.reserve(length);

            unwrap( yData, yDataUnwrapped, length );
            yData = yDataUnwrapped;
            axisY->setRange( -3500, 3500 );
        }
        else
            axisY->setRange( -4, 4 );
    }

    if( shifted )
    {
        for( int i = 0; i < length; i++ )
            buffer.append( QPointF(i+1 - length/2, yData[i]) );

        axisX->setRange( -length/2, length/2 );
    }
    else
    {
        for( int i = 0; i < length; i++ )
            buffer.append( QPointF(i+1, yData[i]) );

        axisX->setRange( 0, length );
    }

    series->replace(buffer);        // podmiana danych do wyświetlania na wykresie*/
}

void Visualisation::on_cbFFTShift_clicked(bool checked)
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

void Visualisation::on_cbUnwrap_clicked(bool checked)
{
    if( checked )
        unwrapped = true;
    else
        unwrapped = false;
}



void Visualisation::on_pbChangeSpectrum_clicked()
{
    if( spectrum == amplitude )
    {
        spectrum = phase;
        ui->labelSpectrum->setText("Widmo fazowe");
    }
    else
    {
        spectrum = amplitude;
        ui->labelSpectrum->setText("Widmo amplitudowe");
    }
}

void Visualisation::on_sliderSamplesCount_sliderMoved(int v)
{

    ui->leSamplesCount->setText( QString::number(v) );
}

void Visualisation::on_leSamplesCount_textChanged(const QString &s)
{
    int v = s.toInt();
    if( v < MIN_SAMPLES ) v = MIN_SAMPLES;
    if( v > MAX_SAMPLES ) v = MAX_SAMPLES;
    ui->sliderSamplesCount->setValue( v );
    ui->labelWindowTime->setText( QString::number((double)v/samplesPerSecond, 'g', 2) + " s" );
    emit samplesCountChanged( v );
}

void Visualisation::displayDB(qreal dbValue)
{
    ui->lcdDBNumber->display(dbValue);
}

void Visualisation::unwrap(QVector<qreal> &in, QVector<qreal> &out, int length) {
    if( out.size() != length )
        out.resize(length);
    out[0] = in[0];
    for (int i = 1; i < length; i++) {
        qreal d = in[i] - in[i-1];
        d = d > M_PI ? d - 2 * M_PI : (d < -M_PI ? d + 2 * M_PI : d);
        out[i] = out[i-1] + d;
    }
}
