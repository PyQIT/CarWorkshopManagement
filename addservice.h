#ifndef ADDSERVICE_H
#define ADDSERVICE_H

#include <QDialog>
#include "delservice.h"
#include "printservice.h"
#include "searchservice.h"
#include "addserviceaddedcar.h"
#include "addserviceregularcustomer.h"

namespace Ui {
class addService;
}

class addService : public QDialog
{
    Q_OBJECT

public:
    explicit addService(QWidget *parent = nullptr);
    ~addService();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_radioButton_2_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::addService *ui;
};

#endif // ADDSERVICE_H
