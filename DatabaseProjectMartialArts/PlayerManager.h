#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include<QSqlDatabase>
#include <QSqlQuery>
#include "Player.h"
#include "Database.h"


class PlayerManager
{
public:
    PlayerManager();
    void CreateTable(QSqlDatabase db);
    void InsertPlayer(QSqlDatabase db, Player*);
};

#endif // PLAYERMANAGER_H
