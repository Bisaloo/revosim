/**
 * @file
 * Header: MainWindow
 *
 * All REvoSim code is released under the GNU General Public License.
 * See LICENSE.md files in the programme directory.
 *
 * All REvoSim code is Copyright 2008-2019 by Mark Sutton, Russell Garwood,
 * and Alan R.T. Spencer.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version. This program is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY.
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QPixmap>
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QStatusBar>
#include <QColor>

#include "environmentclass.h"
#include "environmentscene.h"
#include "markenvironment.h"
#include "noiseenvironment.h"
#include "combine.h"
#include "colour.h"
#include "makestack.h"
#include "russellenvironment.h"
#include "about.h"
#include "globals.h"
#include "randoms.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    int currentGeneration;
    randoms *simulationRandoms;

private slots:
    void generateEnvironment();
    void on_pushButtonStackOne_clicked();
    void on_pushButtonStackTwo_clicked();
    void on_selectColour_clicked();
    void on_sFromImPushbutton_clicked();
    void about();
    void stop();
    void pause();
    void settings();
    void change_path();
    void tab_changed(int index);

private:

    QDockWidget *envOptions;
    environmentclass *environmentobject;
    EnvironmentScene *envscene;
    QDir Directory;
    QGraphicsPixmapItem *env_item;
    QImage *env_image;
    int generations, stackOneSize, stackTwoSize;
    QAction *startButton, *stopButton, *aboutButton, *pauseButton, *settingsButton;
    bool stop_flag, pause_flag;

    void RefreshEnvironment();
    void newEnvironmentImage();
    void reset_gui();
};

extern MainWindow *MainWin;
#endif // MAINWINDOW_H

