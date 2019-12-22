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


    // assignProperty to states
    // startState
    startState->assignProperty(ui->pbAddSong, "enabled", "true");
    startState->assignProperty(ui->pbDeleteSong, "enabled", "false");
    startState->assignProperty(ui->pbVisualization, "enabled", "false");
    startState->assignProperty(ui->pbPlayMusic, "enabled", "false");
    startState->assignProperty(ui->pbStopMusic, "enabled", "false");

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

    // errorState
    errorState->assignProperty(ui->pbAddSong, "enabled", "true");
    errorState->assignProperty(ui->pbDeleteSong, "enabled", "false");
    errorState->assignProperty(ui->pbPlayMusic, "enabled", "false");
    errorState->assignProperty(ui->pbStopMusic, "enabled", "false");


    // stopState
    stopState->assignProperty(ui->pbStopMusic, "enabled", "false");
    stopState->assignProperty(ui->pbPlayMusic, "enabled", "true");

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
      player->setMedia(QUrl::fromLocalFile(songName));
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
