#ifndef RANKING_H
#define RANKING_H

#include <QDialog>
#include "Player.h"
namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = 0);
    ~Ranking();
    Ui::Ranking *ui;
    void on_buttonBox_accepted();
    void UpdateTable(Player* player);


};

#endif // RANKING_H
