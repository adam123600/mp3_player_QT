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
    withPlaylistState->addTransition(this,SIGNAL(sigNoPlaylist()),startState);

    openState->addTransition(this, SIGNAL(sigOpen()), playState);
    openState->addTransition(this, SIGNAL(sigError()), errorState);
    openState->addTransition(this,SIGNAL(sigNoPlaylist()),startState);

    errorState->addTransition(ui->pbAddSong, SIGNAL(clicked()), openState);

    connect(playState, SIGNAL(entered()), SLOT(slotPlay()));

    playState->addTransition(ui->pbStopMusic, SIGNAL(clicked()), stopState);
    playState->addTransition(this,SIGNAL(sigNoPlaylist()),startState);

    connect(stopState, SIGNAL(entered()), SLOT(slotStopMusic()));

    stopState->addTransition(ui->pbAddSong, SIGNAL(clicked()), openState);
    stopState->addTransition(ui->pbPlayMusic, SIGNAL(clicked()), playState);
    stopState->addTransition(this,SIGNAL(sigNoPlaylist()),startState);

    playState->addTransition(ui->pbPauseMusic, SIGNAL(clicked()), pauseState);

    pauseState->addTransition(ui->pbPlayMusic, SIGNAL(clicked()), playState);
    pauseState->addTransition(ui->pbStopMusic, SIGNAL(clicked()), stopState);
    pauseState->addTransition(this,SIGNAL(sigNoPlaylist()),startState);

    connect(this, SIGNAL(sigSongChange()), SLOT(slotPlay()));
    connect(ui->pbAddSong, SIGNAL(clicked()), SLOT(slotOpen()));


    if(hasPlaylistsToLoad()){
        startState->assignProperty(ui->pbAddSong, "enabled", "true");
        startState->assignProperty(ui->pbDeletePlaylist, "enabled", "true");
        ui->listPlaylists->setCurrentRow(0);
    }

    // start machine
    stateMachine->setInitialState(startState);
    stateMachine->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::hasPlaylistsToLoad()
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
    auto playlistName = ui->listPlaylists->currentItem()->text();


    auto fileNames = QFileDialog::getOpenFileNames(this, tr("Choose songs"),
                                                  QDir::currentPath(),
                                                  tr("MP3 files (*.mp3)"));
    for(auto fileName: fileNames) {
        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(fileName)));
        ui->listSongs->addItem(QUrl(fileName).fileName());
    }

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

void MainWindow::on_pbPauseMusic_clicked()
{
    player->pause();
}

void MainWindow::on_pbNextSingiel_clicked()
{
    playlist->next();
    auto currentIndex = playlist->currentIndex();
    ui->listSongs->setCurrentRow(currentIndex);
    emit sigSongChange();
}

void MainWindow::on_pbPreviousSingiel_clicked()
{

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

    auto ok = addPlaylistDialog->exec();
    auto playlistName = addPlaylistDialog->textValue();

    if (ok && !playlistName.isEmpty()) {
        playlist->clear();
        ui->listSongs->clear();
        ui->listPlaylists->addItem(playlistName);
        auto fileNames = QFileDialog::getOpenFileNames(this, tr("Choose songs"),
                                                      QDir::currentPath(),
                                                      tr("MP3 files (*.mp3)"));
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
        auto playlistRow = ui->listPlaylists->count()-1;
        ui->listPlaylists->setCurrentRow(playlistRow);
        ui->listSongs->setCurrentRow(0);
    }
}

void MainWindow::on_pbDeletePlaylist_clicked()
{
    auto playlistItem = ui->listPlaylists->currentItem();
    auto playlistRow = ui->listPlaylists->currentRow();
    auto playlistName = playlistItem->text();
    QString filePath = QDir::currentPath().append("/playlists/"+playlistName+".m3u");
    playlist->clear();
    QFile playlistFile(filePath);
    playlistFile.remove();
    ui->listSongs->clear();
    ui->listPlaylists->removeItemWidget(playlistItem);
    auto it = ui->listPlaylists->takeItem(playlistRow);
    delete it;

    if(ui->listPlaylists->count()) {
        ui->listPlaylists->setCurrentRow(0);
    } else {
        ui->listPlaylists->clear();
        emit sigNoPlaylist();
    }
}

void MainWindow::on_listSongs_itemDoubleClicked()
{
    auto currentRow = ui->listSongs->currentRow();
    playlist->setCurrentIndex(currentRow);
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
    ui->listSongs->setCurrentRow(0);
    emit sigSongChange();
}
