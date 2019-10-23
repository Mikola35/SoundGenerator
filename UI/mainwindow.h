/*
 * Copyright 2019 Benoit Pelletier
 *
 * This file is part of Sound Generator.
 *
 * Sound Generator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sound Generator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Sound Generator.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include "Signal.h"

//class Component;
class NodeItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

    QMenu* getMenu(QString name);
    QString fileName() { return m_fileName; }
    void setFileName(QString fileName);

    void readSettings();
    

protected:
    virtual void closeEvent(QCloseEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;

public slots:
    // actions
    void newFile();
    void save();
    void saveAs();
    void open();
    void about();
    void exportWAV();
    void quit();
    // other
    void setDirty();
    void changeVolume(int value);
    void changeDuration(qreal value);

private:
    void createActions();
    void createMenus();
    void saveFile(QString fileName);
    QMessageBox::StandardButton askSaveChanges(QString action);
    void updateWindowTitle();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    Signal m_signal;

    QString m_fileName;
    bool m_dirty;
    bool m_dirtyable;

    QString m_windowTitle;
};

#endif // MAINWINDOW_H
