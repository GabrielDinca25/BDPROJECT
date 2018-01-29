#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include<QSqlDatabase>
#include <QSqlQuery>
#include "Player.h"
#include "Database.h"
#include "Ranking.h"


class PlayerManager
{
public:
    PlayerManager();
    void CreateTable(QSqlDatabase db);
    void InsertPlayer(QSqlDatabase db, Player*);
    void ShowPlayers(QSqlDatabase db);
    Ranking *ranking;
};

#endif // PLAYERMANAGER_H
