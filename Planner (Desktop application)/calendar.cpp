#include "calendar.h"
#include "ui_calendar.h"
#include <QFile>
#include <QDate>
#include <QMessageBox>
#include <QSet>
Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    this->setWindowTitle("Ежедневник");
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_pushButton_clicked()
{
    QString taskclr = ui->taskcl->text();
    QString descriptionclr = ui->descriptioncl->text();

    // Проверяем, что пользователь ввел данные
    if (taskclr.isEmpty() || descriptionclr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля.");
        return;
    }

    QFile file("Task.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.contains(taskclr)) {
                QMessageBox::warning(this, "Ошибка", "Задача с таким названием уже существует!");
                return;
            }
        }
        file.close();
    }
    // Проверяем, что файл успешно открыт для записи
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }



    QTextStream out(&file);
    QDate currentDate = QDate::currentDate();
    // Записываем данные в файл
    out << "\nЗадача: "
        << taskclr << " \nОписание: " << descriptionclr << "\n"<< "Дата: "<< currentDate.toString("dd.MM.yyyy") <<"\n";
    file.close();

    hide();
}
