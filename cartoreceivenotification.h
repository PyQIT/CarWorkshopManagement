#ifndef CARTORECEIVENOTIFICATION_H
#define CARTORECEIVENOTIFICATION_H

#include <QDialog>

namespace Ui {
class carToReceiveNotification;
}

class carToReceiveNotification : public QDialog
{
    Q_OBJECT

public:
    explicit carToReceiveNotification(QWidget *parent = nullptr);
    ~carToReceiveNotification();

private slots:
    void on_pushButton_clicked();

private:
    Ui::carToReceiveNotification *ui;
};

#endif // CARTORECEIVENOTIFICATION_H
