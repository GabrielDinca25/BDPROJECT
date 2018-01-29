#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include<QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <vector>

#include "Player.h"
#include "Database.h"
#include "Ranking.h"

class PlayerManager
{
public:
    PlayerManager();
    void CreateTable(QSqlDatabase db);
    void InsertPlayer(QSqlDatabase db, Player*);
    Player ShowPlayers(QSqlDatabase db);
    std::vector<Player> GetPlayers(QSqlDatabase db);
    Ranking *ranking;
};

#endif // PLAYERMANAGER_H
