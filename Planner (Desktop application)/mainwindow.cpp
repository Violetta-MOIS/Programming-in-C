#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Ежедневник");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton Exit = QMessageBox::question(this, "Ежедневник", "Нажмите да, если хотите выйти",QMessageBox::Yes | QMessageBox::No);
        if(Exit == QMessageBox::Yes){
            QApplication::quit();
        } else {
            qDebug() << "";
        }
}


void MainWindow::on_pushButton_clicked()
{
        Dialog planner;
        hide();
        planner.setModal(true);
        planner.exec();
}


