#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt lib import
#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>

// UI import
#include "ui_MainWindow.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *m_ui;

public:
    explicit MainWindow(QWidget *parent = NULL);

    ~MainWindow();

public slots:
    void choosePng();
};

#endif // MAINWINDOW_H
