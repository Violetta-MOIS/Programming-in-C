#include "dialog.h"
#include "ui_dialog.h"
#include "task.h"
#include "calendar.h"
#include "edit.h"

#include <QUrl>
#include <QDir>
#include <QDesktopServices>
#include <QMessageBox>
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Ежедневник");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked() //Кнопка ДОБАВИТЬ ЗАДАЧУ
{
    Task forma;
    //hide();
    forma.setModal(true);
    forma.exec();
}


void Dialog::on_pushButton_2_clicked() //Список задач
{
    QUrl fileUrl = QUrl::fromLocalFile(QDir::currentPath() + "/Task.txt");
    QDesktopServices::openUrl(fileUrl);
}


void Dialog::on_calendarWidget_clicked(const QDate &date) //ДОБАВИТЬ ЗАДАЧУ ПО КЛИКУ НА ДАТУ
{
    Calendar formacl;
    formacl.setModal(true);
    formacl.exec();
}


void Dialog::on_pushButton_4_clicked() //ВЫХОД
{
    QMessageBox::StandardButton Exit = QMessageBox::question(this, "Ежедневник", "Нажмите да, если хотите выйти",QMessageBox::Yes | QMessageBox::No);
        if(Exit == QMessageBox::Yes){
            QApplication::quit();
        } else {
            qDebug() << "";
        }
}


void Dialog::on_pushButton_3_clicked() //РЕДАКТИРОВАНИЕ
{
        Edit editmain;
        editmain.setModal(true);
        editmain.exec();
}

