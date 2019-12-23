#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>
#include <QFile>
#include <QDebug>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QFileDialog>

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

signals:
    void sigError();
    void sigOpen();
    void sigStopMusic();

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

private:
    Ui::MainWindow *ui;

    QString songName;
    QMediaPlayer* player;

    int levelVolume;
    struct time curTime;        // aktualna pozycja odtwarzanej piosenki w minutach i sekundach
};

#endif // MAINWINDOW_H
