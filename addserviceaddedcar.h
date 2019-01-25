#ifndef ADDSERVICEADDEDCAR_H
#define ADDSERVICEADDEDCAR_H

#include <QDialog>
#include "addservice.h"
#include "delservice.h"
#include "printservice.h"
#include "searchservice.h"

namespace Ui {
class addServiceAddedCar;
}

class addServiceAddedCar : public QDialog
{
    Q_OBJECT

public:
    explicit addServiceAddedCar(QWidget *parent = nullptr);
    ~addServiceAddedCar();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::addServiceAddedCar *ui;
};

#endif // ADDSERVICEADDEDCAR_H
