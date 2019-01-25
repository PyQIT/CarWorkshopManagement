#ifndef PRINTSERVICE_H
#define PRINTSERVICE_H

#include <QDialog>
#include "addservice.h"
#include "delservice.h"
#include "searchservice.h"

namespace Ui {
class printService;
}

class printService : public QDialog
{
    Q_OBJECT

public:
    explicit printService(QWidget *parent = nullptr);
    ~printService();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::printService *ui;
};

#endif // PRINTSERVICE_H
