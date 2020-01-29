#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>
#include <QFile>
#include <QDebug>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QInputDialog>
#include <QDirIterator>
#include <QMessageBox>
#include <memory>

#include <QAudioBuffer>
#include <QAudioProbe>
#include "headers/fastfourier.h"
#include <QtCharts>
#include "headers/visualisation.h"
#include "constants.h"

struct time
{
    int min;
    int sec;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool hasPlaylistsToLoad();


signals:
    void sigError();
    void sigOpen();
    void sigStopMusic();
    void sigHasPlaylist();
    void sigNoPlaylist();
    void sigSongChange();

private slots:

    void slotPlay();
    void slotOpen();
    void slotStopMusic();

    void on_sliderLevelVolume_valueChanged(int value);
    void on_sliderProgress_sliderMoved(int position);
    void onPositionChanged(int position);
    void onDurationChanged(int duration);

    void on_pbPauseMusic_clicked();

    void on_pbNextSingiel_clicked();

    void on_pbPreviousSingiel_clicked();

    void on_pbDeleteSong_clicked();
    void on_pbNewPlaylist_clicked();
    void on_pbDeletePlaylist_clicked();
    void on_listSongs_itemDoubleClicked();
    void on_listPlaylists_itemDoubleClicked();
    void on_currentMediaChanged(const QMediaContent &content);

    void on_radioButton_clicked(bool checked);

    void on_pbVisualisation_clicked(bool checked);
    void processBuffer(QAudioBuffer buffer);
    void shift();
    void noshift();
    void arraySizeChanged( int samplesCount );

private:
    Ui::MainWindow *ui;

    QString songName;
    QString actualPlaylistName;
    QMediaPlayer* player;
    std::unique_ptr<QMediaPlaylist> playlist;

    int levelVolume;
    struct time curTime;        // aktualna pozycja odtwarzanej piosenki w minutach i sekundach

    void savePlaylist(QMediaPlaylist& playlist);

    // ftt i wizualizacja
    QAudioProbe* probe;
    double* inputArray;         // tablica próbek, z której będzie liczona transformata Fouriera
    int curSize;                // aktualna ilość próbek w inputArray
    int samplesCount;              // żądana ilość próbek w inputArray
    int bufferSize;             // rozmiar bufora próbek, gotowy bufor jest zgłaszany przez "sondę" klasy QAudioProbe, która sama ustala jego rozmiar (empirycznie wychodzi zawsze 2304 próbki)
    int dataIndex;              // numer aktualnie przepisywanej próbki z bufora QAudioProbe do inputArray

    Visualisation* visualisation;       // instancja okna wizualizacji (widget)
    bool shifted;
};

#endif // MAINWINDOW_H
