#include "PlayerManager.h"
#include <QVariant>


PlayerManager::PlayerManager()
{
       ranking  = new Ranking();
}

void PlayerManager::CreateTable(QSqlDatabase db)
{
    QSqlQuery query(db);
    bool tableCreated = query.exec("CREATE TABLE IF NOT EXISTS Players ( Id int PRIMARY KEY, Age int, Weight int, Team text, Points int);");
    if(tableCreated)
    {
        qDebug() << "Table created";
    }
    else
    {
        qDebug() << "Table already exists";
    }
}

void PlayerManager::InsertPlayer(QSqlDatabase db, Player* player)
{

     //ranking->UpdateTable(player);// trebuie sa intoarca o buleana ceva ca sa nu poata sa fie inscris dupa in baza
     QSqlQuery query(db);
     query.prepare("INSERT INTO"
                   "     Players(id, age, weight, team, points)"
                   "VALUES (:id, :age, :weight, :team, :points)");
         query.bindValue(":id", player->m_id);
         query.bindValue(":age", player->m_age);
         query.bindValue(":weight", player->m_weight);
         query.bindValue(":team", player->m_team);
         query.bindValue(":points", player->m_points);

         query.exec();




}

Player PlayerManager::ShowPlayers(QSqlDatabase db)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Players");
    query.exec();


    int id = query.value("id").toInt();
    int age = query.value("age").toInt();
    int weight = query.value("weight").toInt();
    QString team = query.value("team").toString();
    int points = query.value("points").toInt();

    Player player(id, age, weight, team, points);

    return player;

}

std::vector<Player> GetPlayers(QSqlDatabase db)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Players");
    query.exec();

    std::vector<Player> players;
    while(query.next()) {

        int id = query.value("Id").toInt();
        int age = query.value("Age").toInt();
        int weight = query.value("Weight").toInt();
        QString team = query.value("Team").toString();
        int points = query.value("Points").toInt();

        Player player(id, age, weight, team, points);


        players.push_back(player);
    }

    return players;

}

