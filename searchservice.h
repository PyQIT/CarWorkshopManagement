#ifndef SEARCHSERVICE_H
#define SEARCHSERVICE_H

#include <QDialog>
#include "addservice.h"
#include "delservice.h"
#include "printservice.h"

namespace Ui {
class searchService;
}

class searchService : public QDialog
{
    Q_OBJECT

public:
    explicit searchService(QWidget *parent = nullptr);
    void printDatabase(void *p_data, int num_fields, char **p_fields, char **p_col_names);
    ~searchService();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

protected:
    Ui::searchService *ui;
};

#endif // SEARCHSERVICE_H
