//#include "headers/mainwindow.h"
#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    levelVolume = 50; // domyslna wartosc dzwieku


    // stateMachine
    auto stateMachine = new QStateMachine(this);

    auto startState = new QState(stateMachine);
    auto openState = new QState(stateMachine);
    auto playState = new QState(stateMachine);
    auto errorState = new QState(stateMachine);
    auto stopState = new QState(stateMachine);
    auto pauseState = new QState(stateMachine);


    // assignProperty to states
    // startState
    startState->assignProperty(ui->pbAddSong, "enabled", "true");
    startState->assignProperty(ui->pbDeleteSong, "enabled", "false");
    startState->assignProperty(ui->pbVisualization, "enabled", "false");
    startState->assignProperty(ui->pbPlayMusic, "enabled", "false");
    startState->assignProperty(ui->pbStopMusic, "enabled", "false");
    startState->assignProperty(ui->pbPauseMusic, "enabled", "false");

    // przyblokowana playlista ---> odblokuj sobie!
    startState->assignProperty(ui->pbNewPlaylist, "enabled", "false");
    startState->assignProperty(ui->pbLoadPlaylist, "enabled", "false");
    startState->assignProperty(ui->pbDeletePlaylist, "enabled", "false");
    startState->assignProperty(ui->pbSavePlaylist, "enabled", "false");

    // openState
    openState->assignProperty(ui->pbAddSong, "enabled", "true");
    openState->assignProperty(ui->pbDeleteSong, "enabled", "false");

    // playState
    playState->assignProperty(ui->pbPlayMusic, "enabled", "false");
    playState->assignProperty(ui->pbStopMusic, "enabled", "true");
    playState->assignProperty(ui->pbAddSong, "enabled", "false");
    playState->assignProperty(ui->pbPauseMusic, "enabled", "true");

    // errorState
    errorState->assignProperty(ui->pbAddSong, "enabled", "true");
    errorState->assignProperty(ui->pbDeleteSong, "enabled", "false");
    errorState->assignProperty(ui->pbPlayMusic, "enabled", "false");
    errorState->assignProperty(ui->pbStopMusic, "enabled", "false");


    // stopState
    stopState->assignProperty(ui->pbStopMusic, "enabled", "false");
    stopState->assignProperty(ui->pbPlayMusic, "enabled", "true");
    stopState->assignProperty(ui->pbAddSong, "enabled", "true");

    // pauseState
    pauseState->assignProperty(ui->pbStopMusic, "enabled", "true");
    pauseState->assignProperty(ui->pbPlayMusic, "enabled", "true");
    pauseState->assignProperty(ui->pbPauseMusic, "enabled", "false");

    //////////////////////////////////////////////////////////////////


    // przejscia + connecty

    startState->addTransition(ui->pbAddSong, SIGNAL(clicked()), openState);
    connect(openState, SIGNAL(entered()), this, SLOT(slotOpen()));

    openState->addTransition(this, SIGNAL(sigOpen()), playState);
    openState->addTransition(this, SIGNAL(sigError()), errorState);

    errorState->addTransition(ui->pbAddSong, SIGNAL(clicked()), openState);

    connect(playState, SIGNAL(entered()), SLOT(slotPlay()));

    playState->addTransition(ui->pbStopMusic, SIGNAL(clicked()), stopState);

    connect(stopState, SIGNAL(entered()), SLOT(slotStopMusic()));

    stopState->addTransition(ui->pbAddSong, SIGNAL(clicked()), openState);
    stopState->addTransition(ui->pbPlayMusic, SIGNAL(clicked()), playState);

    playState->addTransition(ui->pbPauseMusic, SIGNAL(clicked()), pauseState);

    pauseState->addTransition(ui->pbPlayMusic, SIGNAL(clicked()), playState);
    pauseState->addTransition(ui->pbStopMusic, SIGNAL(clicked()), stopState);

    // progress bar, nie pytajcie czemu tak, inaczej nie działa
    connect( player, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged );        // gdy zmienia się pozycja w piosence to player wysyła sygnał positionChanged
    connect( player, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged );        // jak player wczyta z pliku piosenkę to ustawia swój parametr duration i wysyła sygnał durationChanged



    // start machine
    stateMachine->setInitialState(startState);
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotPlay()
{
//    player = new QMediaPlayer;
      //player->setMedia(QUrl::fromLocalFile(songName));
      player->play();
}

void MainWindow::slotOpen()
{
    songName = QFileDialog::getOpenFileName(this, "Open a File", "home/student");
    QFile song(songName);

    if (!song.open(QIODevice::ReadOnly) || !songName.endsWith(".mp3", Qt::CaseSensitive))
    {
        ui->labelNowPlaySong->setText("Nie udalo sie otworzyc mp3");

        emit sigError();
    }

    else
    {
        player->setMedia(QUrl::fromLocalFile(songName));
        ui->labelNowPlaySong->setText(QFileInfo(songName).fileName()); // wyswietli tylko nazwe, nie cala sciezke
        emit sigOpen();
    }
}

void MainWindow::slotStopMusic()
{
    player->stop();
    emit sigStopMusic();
}

void MainWindow::on_sliderLevelVolume_valueChanged(int value)
{
    levelVolume = value;
    player->setVolume(levelVolume);
}

void MainWindow::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::onPositionChanged(int position)
{
    ui->sliderProgress->setValue(position);
    curTime.min = position/(1000*60);            // pozycja przez 1000*60 milisekund = 60 sekund
    curTime.sec = (position/1000)%60;            // pozycja przez 1000 milisekund daje czyste sekundy, modulo 60 resetuje sekundy gdy dobiją do 59
    QString s;
    s.sprintf("%2d:%02d", curTime.min, curTime.sec);
    ui->labelProgress->setText(s);
}

void MainWindow::onDurationChanged(int duration)
{
    ui->sliderProgress->setMaximum(duration);
}

void MainWindow::on_pbPauseMusic_clicked()
{
    player->pause();
}

void MainWindow::on_pbNextSingiel_clicked()
{

}

void MainWindow::on_pbPreviousSingiel_clicked()
{

}
