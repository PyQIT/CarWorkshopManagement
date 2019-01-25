#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system/menu.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap background("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/background.png");
    ui->picture->setPixmap(background);
    QPixmap logo("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/logo_final.png");
    ui->logo->setPixmap(logo);
    sqlite_connection();
    check_database_correct();
    qtsqliteConnection();
}

void MainWindow::qtsqliteConnection(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("SQLite_database.db");
    if(!mydb.open())
        ui->label->setText("Failed to open the database");
    else
        ui->label->setText("Connected...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_7_clicked()
{
   hide();
   addService addServiceObj;
   addServiceObj.setModal(true);
   addServiceObj.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    hide();
    delService delServiceObj;
    delServiceObj.setModal(true);
    delServiceObj.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    hide();
    printService printServiceObj;
    printServiceObj.setModal(true);
    printServiceObj.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    hide();
    searchService searchServiceObj;
    searchServiceObj.setModal(true);
    searchServiceObj.exec();
}
