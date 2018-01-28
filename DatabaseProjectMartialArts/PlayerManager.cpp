#include "PlayerManager.h"
#include <QVariant>


PlayerManager::PlayerManager()
{

}

void PlayerManager::CreateTable(QSqlDatabase db)
{
    QSqlQuery query(db);
    query.prepare("CREATE TABLE Players ( Id int PRIMARY KEY, Age int, Weight int, Team text, Points int);");
}

void PlayerManager::InsertPlayer(QSqlDatabase db, Player* player)
{
     QSqlQuery query(db);
     query.prepare("INSERT INTO"
                   "     Players"
                   "(id, age, weight, team, points)"
                   "VALUES (:id, :age, :weight, :team, :points)");
         query.bindValue(":id", player->m_id);
         query.bindValue(":age", player->m_age);
         query.bindValue(":weight", player->m_weight);
         query.bindValue(":team", player->m_team);
         query.bindValue(":points", player->m_points);
         query.exec();
}
