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
#include <memory>

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
    bool loadPlaylists();

signals:
    void sigError();
    void sigOpen();
    void sigStopMusic();
    void sigHasPlaylist();
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

    void on_pbNewPlaylist_clicked();
    void on_listSongs_itemDoubleClicked();
    void on_listPlaylists_itemDoubleClicked();

private:
    Ui::MainWindow *ui;

    QString songName;
    QMediaPlayer* player;
    std::unique_ptr<QMediaPlaylist> playlist;

    int levelVolume;
    struct time curTime;        // aktualna pozycja odtwarzanej piosenki w minutach i sekundach
};

#endif // MAINWINDOW_H
