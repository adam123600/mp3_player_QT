//#include "headers/mainwindow.h"
#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    playlist = std::make_unique<QMediaPlaylist>();
    levelVolume = 50; // domyslna wartosc dzwieku

    // stateMachine
    auto stateMachine = new QStateMachine(this);

    auto startState = new QState(stateMachine);
    auto withPlaylistState = new QState(stateMachine);
    auto openState = new QState(stateMachine);
    auto playState = new QState(stateMachine);
    auto errorState = new QState(stateMachine);
    auto stopState = new QState(stateMachine);
    auto pauseState = new QState(stateMachine);


    // assignProperty to states
    // startState
    startState->assignProperty(ui->pbAddSong, "enabled", "false");
    startState->assignProperty(ui->pbDeleteSong, "enabled", "false");
    startState->assignProperty(ui->pbVisualization, "enabled", "false");
    startState->assignProperty(ui->pbPlayMusic, "enabled", "false");
    startState->assignProperty(ui->pbStopMusic, "enabled", "false");
    startState->assignProperty(ui->pbPauseMusic, "enabled", "false");
    startState->assignProperty(ui->pbNewPlaylist, "enabled", "true");
    startState->assignProperty(ui->pbDeletePlaylist, "enabled", "false");

    // withPlaylistState
    withPlaylistState->assignProperty(ui->pbAddSong, "enabled", "true");
    withPlaylistState->assignProperty(ui->pbPlayMusic, "enabled", "true");
    withPlaylistState->assignProperty(ui->pbDeletePlaylist, "enabled", "true");

    // openState
    openState->assignProperty(ui->pbAddSong, "enabled", "true");
    openState->assignProperty(ui->pbDeleteSong, "enabled", "false");

    // playState
    playState->assignProperty(ui->pbPlayMusic, "enabled", "false");
    playState->assignProperty(ui->pbStopMusic, "enabled", "true");
    playState->assignProperty(ui->pbAddSong, "enabled", "true");
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
    startState->addTransition(this, SIGNAL(sigHasPlaylist()), withPlaylistState);
    startState->addTransition(this,SIGNAL(sigSongChange()), playState);
    connect(openState, SIGNAL(entered()), this, SLOT(slotOpen()));

    withPlaylistState->addTransition(ui->pbPlayMusic,SIGNAL(clicked()),playState);

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
    
    connect(this, SIGNAL(sigSongChange()), SLOT(slotPlay()));
    connect(ui->pbAddSong, SIGNAL(clicked()), SLOT(slotOpen()));

    if(loadPlaylists()){
        startState->assignProperty(ui->pbAddSong, "enabled", "true");
        startState->assignProperty(ui->pbDeletePlaylist, "enabled", "true");
    }

    // start machine
    stateMachine->setInitialState(startState);
    stateMachine->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loadPlaylists()
{
    QString playlistsPath = QDir::currentPath().append("/playlists/");
    QDirIterator iterator(playlistsPath,QDir::Files);
    bool hasPlaylist = false;
    while (iterator.hasNext()) {

        QFileInfo playlistFile(iterator.next());
        QString playlistName = playlistFile.baseName();

        ui->listPlaylists->addItem(playlistName);
        hasPlaylist = true;
    }
    return hasPlaylist;
}

void MainWindow::slotPlay()
{
      auto songName = ui->listSongs->currentItem()->text();
      ui->labelNowPlaySong->setText(songName);
      player->play();
}

void MainWindow::slotOpen()
{
    auto fileNames = QFileDialog::getOpenFileNames(this, tr("Choose songs"),
                                                  QDir::currentPath(),
                                                  tr("Sound files (*.mp3 *.wav)"));
    for(auto fileName: fileNames) {
        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(fileName)));
        ui->listSongs->addItem(QUrl(fileName).fileName());
    }

    auto playlistName = ui->listPlaylists->currentItem()->text();
    QString filePath = QDir::currentPath().append("/playlists/"+playlistName+".m3u");

    if(playlist->save(QUrl::fromLocalFile(filePath),"m3u")){
        qDebug() << "Playlist saved succesfully";
        emit sigHasPlaylist();
    } else {
        qDebug() << "Playlist not saved";
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
    playlist->next();
}

void MainWindow::on_pbPreviousSingiel_clicked()
{
    playlist->previous();
}


void MainWindow::on_pbNewPlaylist_clicked()
{
    std::unique_ptr<QInputDialog> addPlaylistDialog = std::make_unique<QInputDialog>();
    addPlaylistDialog->resize(300,300);
    addPlaylistDialog->setInputMode(QInputDialog::TextInput);
    addPlaylistDialog->setWindowTitle("Create Playlist");
    addPlaylistDialog->setOkButtonText("Choose songs");
    addPlaylistDialog->setLabelText("Name your playlist");
    addPlaylistDialog->setTextValue("new_playlist");

    playlist->clear();
    ui->listSongs->clear();

    auto ok = addPlaylistDialog->exec();
    auto playlistName = addPlaylistDialog->textValue();

    if (ok && !playlistName.isEmpty()) {
        ui->listPlaylists->addItem(playlistName);
        auto fileNames = QFileDialog::getOpenFileNames(this, tr("Choose songs"),
                                                      QDir::currentPath(),
                                                      tr("Sound files (*.mp3 *.wav)"));
        for(auto fileName: fileNames) {
            playlist->addMedia(QMediaContent(QUrl::fromLocalFile(fileName)));
            ui->listSongs->addItem(QUrl(fileName).fileName());
        }
        player->setPlaylist(playlist.get());

        QString filePath = QDir::currentPath().append("/playlists/"+playlistName+".m3u");

        if(playlist->save(QUrl::fromLocalFile(filePath),"m3u")){
            qDebug() << "Playlist saved succesfully";
            emit sigHasPlaylist();
        } else {
            qDebug() << "Playlist not saved";
        }
    }
}

void MainWindow::on_listSongs_itemDoubleClicked()
{
    auto currentIndex = ui->listSongs->currentRow();
    playlist->setCurrentIndex(currentIndex);
    emit sigSongChange();
}

void MainWindow::on_listPlaylists_itemDoubleClicked()
{
    ui->listSongs->clear();
    auto playlistName = ui->listPlaylists->currentItem()->text();
    QString filePath = QDir::currentPath().append("/playlists/"+playlistName+".m3u");
    playlist->clear();
    playlist->load(QUrl::fromLocalFile(filePath),"m3u");
    player->setPlaylist(playlist.get());

    QFile fileNames(filePath);
    fileNames.open(QIODevice::ReadOnly | QIODevice::Text); //zrobic errora

    ui->listSongs->clear();
    while (!fileNames.atEnd()) {
        auto fileName = QString(fileNames.readLine());
        fileName.remove("\n");
        fileName.remove("file://");

        ui->listSongs->addItem(QUrl(fileName).fileName());
    }
}
