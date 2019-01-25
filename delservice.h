#ifndef DELSERVICE_H
#define DELSERVICE_H

#include <QDialog>
#include "addservice.h"
#include "printservice.h"
#include "searchservice.h"

namespace Ui {
class delService;
}

class delService : public QDialog
{
    Q_OBJECT

public:
    explicit delService(QWidget *parent = nullptr);
    ~delService();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::delService *ui;
};

#endif // DELSERVICE_H
