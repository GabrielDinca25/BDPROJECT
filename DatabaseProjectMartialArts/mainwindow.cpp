#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additemdialog.h"
#include "Database.h"
#include<QSqlError>
#include "Ranking.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_addItem = new AddItemDialog(this);
    connect(ui->actionAddItems, &QAction::triggered, this, &MainWindow::onAddItem);

    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("horton.elephantsql.com");
    m_db.setDatabaseName("jnzdnjdu");
    m_db.setUserName("jnzdnjdu");
    m_db.setPassword("e3aDPhYnK4OQLGM4Bgh4h4zzeY0DdGm_");

    m_db.open();

    qDebug() << "status" << m_db.isOpen();
    if(isConnected == m_db.open())
    {
        ui->connectionStatus->setText("Status: Connected");
    }
    qDebug()<< "last error" << m_db.lastError();
    m_playerManager = new PlayerManager();
    m_playerManager->CreateTable(m_db);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddItem()
{
    int res = m_addItem->exec();

    if(res == QDialog::Accepted)
    {
        m_playerManager->InsertPlayer(m_db, m_addItem->CreatePlayer());
        qDebug() << "Player Inserted";
    }
    else
    {
        qDebug() << "Dialog Not Accepted";
    }

    /*if(res == QDialog::Accepted)
    {
        QString id, age, weight, team, points;
        m_addItem->PlayerData(id, age, weight, team, points);
        int rowCount = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowCount);
        ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(age));
        ui->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(weight));
        ui->tableWidget->setItem(rowCount, 3, new QTableWidgetItem(team));
        ui->tableWidget->setItem(rowCount, 4, new QTableWidgetItem(points));
    }*/
}

void MainWindow::on_AddPlayer_clicked()
{
    int res = m_addItem->exec();

    if(res == QDialog::Accepted)
    {
        m_playerManager->InsertPlayer(m_db, m_addItem->CreatePlayer());
        qDebug() << "Player Inserted";

    }
    else
    {
        qDebug() << "Insert canceled";
    }

}

void MainWindow::on_ShowRanks_clicked()
{
    m_playerManager->ranking->exec();

}

