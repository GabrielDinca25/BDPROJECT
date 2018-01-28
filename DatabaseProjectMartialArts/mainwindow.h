#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "PlayerManager.h"

class AddItemDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onAddItem();

private:
    Ui::MainWindow *ui;
    AddItemDialog *m_addItem;
    QSqlDatabase m_db;
    bool isConnected;
    PlayerManager *m_playerManager;
};

#endif // MAINWINDOW_H
