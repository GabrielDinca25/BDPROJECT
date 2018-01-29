#include "Ranking.h"
#include "ui_ranking.h"
#include <QDebug>
#include "QMessageBox"

Ranking::Ranking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
}

Ranking::~Ranking()
{
    delete ui;
}


void Ranking::on_buttonBox_accepted()
{

}

void Ranking::UpdateTable(Player* player)
{

    int id = player->m_id;
    QString _id = QString::number(id);
    int age = player->m_age;
    QString _age = QString::number(age);
    int weight = player->m_weight;
    QString _weight = QString::number(weight);
    int points = player->m_points;
    QString _points = QString::number(points);

    if(player->m_age >= 12 && player->m_age < 16 ){
        if(player->m_weight >= 40 && player->m_weight < 60){
            int rowCount = ui->table1_1->rowCount();
            ui->table1_1->insertRow(rowCount);
            ui->table1_1->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table1_1->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table1_1->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table1_1->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table1_1->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else if(player->m_weight >= 60 && player->m_weight < 80){
            int rowCount = ui->table1_2->rowCount();
            ui->table1_2->insertRow(rowCount);
            ui->table1_2->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table1_2->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table1_2->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table1_2->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table1_2->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else if(player->m_weight >= 80 && player->m_weight < 100){
            int rowCount = ui->table1_3->rowCount();
            ui->table1_3->insertRow(rowCount);
            ui->table1_3->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table1_3->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table1_3->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table1_3->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table1_3->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else  {
            QMessageBox::warning(this, tr("There is not category for this person"), tr("Try another year"));
        }
    }
    else if(player->m_age >= 16 && player->m_age < 20){
        if(player->m_weight >= 40 && player->m_weight < 60){
            int rowCount = ui->table2_1->rowCount();
            ui->table2_1->insertRow(rowCount);
            ui->table2_1->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table2_1->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table2_1->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table2_1->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table2_1->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else if(player->m_weight >= 60 && player->m_weight < 80){
            int rowCount = ui->table2_2->rowCount();
            ui->table2_2->insertRow(rowCount);
            ui->table2_2->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table2_2->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table2_2->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table2_2->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table2_2->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else if(player->m_weight >= 80 && player->m_weight < 100){
            int rowCount = ui->table2_3->rowCount();
            ui->table2_3->insertRow(rowCount);
            ui->table2_3->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table2_3->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table2_3->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table2_3->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table2_3->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else  {
            QMessageBox::warning(this, tr("There is not category for this person"), tr("Try another year"));
        }
    }else if(player->m_age >= 20 && player->m_age < 24){
        if(player->m_weight >= 40 && player->m_weight < 60){
            int rowCount = ui->table3_1->rowCount();
            ui->table3_1->insertRow(rowCount);
            ui->table3_1->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table3_1->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table3_1->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table3_1->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table3_1->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else if(player->m_weight >= 60 && player->m_weight < 80){
            int rowCount = ui->table3_2->rowCount();
            ui->table3_2->insertRow(rowCount);
            ui->table3_2->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table3_2->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table3_2->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table3_2->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table3_2->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else if(player->m_weight >= 80 && player->m_weight < 100){
            int rowCount = ui->table3_3->rowCount();
            ui->table3_3->insertRow(rowCount);
            ui->table3_3->setItem(rowCount, 0, new QTableWidgetItem(_id));
            ui->table3_3->setItem(rowCount, 1, new QTableWidgetItem(_age));
            ui->table3_3->setItem(rowCount, 2, new QTableWidgetItem(_weight));
            ui->table3_3->setItem(rowCount, 3, new QTableWidgetItem(player->m_team));
            ui->table3_3->setItem(rowCount, 4, new QTableWidgetItem(_points));
        }else  {
            QMessageBox::warning(this, tr("There is not category for this person"), tr("Try another year"));
        }
    }else {
        QMessageBox::warning(this, tr("Error"), tr("No category for this person"));
    }

//sortare sus

}
