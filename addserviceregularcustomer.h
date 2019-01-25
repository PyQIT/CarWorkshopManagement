#ifndef ADDSERVICEREGULARCUSTOMER_H
#define ADDSERVICEREGULARCUSTOMER_H

#include <QDialog>
#include "addservice.h"
#include "delservice.h"
#include "printservice.h"
#include "searchservice.h"

namespace Ui {
class addServiceRegularCustomer;
}

class addServiceRegularCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit addServiceRegularCustomer(QWidget *parent = nullptr);
    ~addServiceRegularCustomer();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_2_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::addServiceRegularCustomer *ui;
};

#endif // ADDSERVICEREGULARCUSTOMER_H
