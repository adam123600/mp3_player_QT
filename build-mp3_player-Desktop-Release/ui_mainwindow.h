/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pbAddSong;
    QPushButton *pbDeleteSong;
    QPushButton *pbVisualisation;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pbNewPlaylist;
    QPushButton *pbDeletePlaylist;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QSlider *sliderLevelVolume;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *labelNowPlaySong;
    QLabel *labelProgress;
    QSlider *sliderProgress;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbPlayMusic;
    QPushButton *pbPauseMusic;
    QPushButton *pbStopMusic;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbPreviousSingiel;
    QPushButton *pbNextSingiel;
    QListWidget *listSongs;
    QListWidget *listPlaylists;
    QLabel *label_3;
    QRadioButton *radioButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 531);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 181, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 60, 141, 74));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pbAddSong = new QPushButton(layoutWidget);
        pbAddSong->setObjectName(QString::fromUtf8("pbAddSong"));

        verticalLayout->addWidget(pbAddSong);

        pbDeleteSong = new QPushButton(layoutWidget);
        pbDeleteSong->setObjectName(QString::fromUtf8("pbDeleteSong"));

        verticalLayout->addWidget(pbDeleteSong);

        pbVisualisation = new QPushButton(centralWidget);
        pbVisualisation->setObjectName(QString::fromUtf8("pbVisualisation"));
        pbVisualisation->setGeometry(QRect(820, 330, 191, 71));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(470, 60, 151, 74));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pbNewPlaylist = new QPushButton(layoutWidget1);
        pbNewPlaylist->setObjectName(QString::fromUtf8("pbNewPlaylist"));

        verticalLayout_3->addWidget(pbNewPlaylist);

        pbDeletePlaylist = new QPushButton(layoutWidget1);
        pbDeletePlaylist->setObjectName(QString::fromUtf8("pbDeletePlaylist"));

        verticalLayout_3->addWidget(pbDeletePlaylist);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(290, 180, 331, 241));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        sliderLevelVolume = new QSlider(layoutWidget2);
        sliderLevelVolume->setObjectName(QString::fromUtf8("sliderLevelVolume"));
        sliderLevelVolume->setValue(50);
        sliderLevelVolume->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(sliderLevelVolume);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        labelNowPlaySong = new QLabel(layoutWidget2);
        labelNowPlaySong->setObjectName(QString::fromUtf8("labelNowPlaySong"));

        verticalLayout_2->addWidget(labelNowPlaySong);

        labelProgress = new QLabel(layoutWidget2);
        labelProgress->setObjectName(QString::fromUtf8("labelProgress"));

        verticalLayout_2->addWidget(labelProgress);

        sliderProgress = new QSlider(layoutWidget2);
        sliderProgress->setObjectName(QString::fromUtf8("sliderProgress"));
        sliderProgress->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(sliderProgress);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbPlayMusic = new QPushButton(layoutWidget2);
        pbPlayMusic->setObjectName(QString::fromUtf8("pbPlayMusic"));

        horizontalLayout->addWidget(pbPlayMusic);

        pbPauseMusic = new QPushButton(layoutWidget2);
        pbPauseMusic->setObjectName(QString::fromUtf8("pbPauseMusic"));

        horizontalLayout->addWidget(pbPauseMusic);

        pbStopMusic = new QPushButton(layoutWidget2);
        pbStopMusic->setObjectName(QString::fromUtf8("pbStopMusic"));

        horizontalLayout->addWidget(pbStopMusic);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbPreviousSingiel = new QPushButton(layoutWidget2);
        pbPreviousSingiel->setObjectName(QString::fromUtf8("pbPreviousSingiel"));

        horizontalLayout_2->addWidget(pbPreviousSingiel);

        pbNextSingiel = new QPushButton(layoutWidget2);
        pbNextSingiel->setObjectName(QString::fromUtf8("pbNextSingiel"));

        horizontalLayout_2->addWidget(pbNextSingiel);


        verticalLayout_5->addLayout(horizontalLayout_2);

        listSongs = new QListWidget(centralWidget);
        listSongs->setObjectName(QString::fromUtf8("listSongs"));
        listSongs->setGeometry(QRect(20, 70, 241, 371));
        listPlaylists = new QListWidget(centralWidget);
        listPlaylists->setObjectName(QString::fromUtf8("listPlaylists"));
        listPlaylists->setGeometry(QRect(770, 70, 241, 141));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(860, 30, 61, 31));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(630, 230, 171, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1029, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Lista utwor\303\263w", nullptr));
        pbAddSong->setText(QApplication::translate("MainWindow", "Dodaj utw\303\263r", nullptr));
        pbDeleteSong->setText(QApplication::translate("MainWindow", "Usu\305\204 utw\303\263r", nullptr));
        pbVisualisation->setText(QApplication::translate("MainWindow", "Wizualizuj", nullptr));
        pbNewPlaylist->setText(QApplication::translate("MainWindow", "Nowa playlista", nullptr));
        pbDeletePlaylist->setText(QApplication::translate("MainWindow", "Usu\305\204 playliste", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Poziom g\305\202o\305\233no\305\233ci", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Aktualnie grane", nullptr));
        labelNowPlaySong->setText(QString());
        labelProgress->setText(QApplication::translate("MainWindow", " 0:00", nullptr));
        pbPlayMusic->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pbPauseMusic->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        pbStopMusic->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        pbPreviousSingiel->setText(QApplication::translate("MainWindow", "Poprzedni", nullptr));
        pbNextSingiel->setText(QApplication::translate("MainWindow", "Nast\304\231pny ", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Playlisty", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "Odtwarzanie losowe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
