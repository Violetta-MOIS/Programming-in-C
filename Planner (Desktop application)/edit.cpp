#include "edit.h"
#include "ui_edit.h"

#include <QFile>
#include <QString>
#include <QMessageBox>


Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    this->setWindowTitle("Ежедневник");
}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_pushButton_clicked()
{
    QString fileName = "Task.txt"; // замените на имя вашего файла
    QString tempFileName = "Task1.txt"; // временное имя файла

    QFile file(fileName);
    QFile tempFile(tempFileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Не удалось открыть файл" << fileName;
        return;
    }

    if(!tempFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Не удалось создать временный файл";
        file.close();
        return;
    }

    QTextStream in(&file);
    QTextStream out(&tempFile);

    QString searchName = ui->lineEdit->text(); // получаем заданное название из поля ввода на форме

    if(searchName.isEmpty()) // проверяем, было ли введено заданное название
    {
        QMessageBox::warning(this, "Ошибка", "Введите название для удаления записи");
        return;
    }

    while(!in.atEnd())
    {
        QString line = in.readLine();

        if(line.contains(searchName)) // проверяем, содержит ли строка заданное название
        {
            QString description = in.readLine();  // считываем описание задачи и игнорируем
            QString date = in.readLine(); // считываем дату и игнорируем
            continue; // если содержит, пропускаем эту строку и не записываем ее во временный файл
        }

        out <<  line << "\n"; // если не содержит, записываем строку во временный файл
    }

    file.close();
    tempFile.close();

    QFile::remove(fileName); // удаляем исходный файл
    QFile::rename(tempFileName, fileName); // переименовываем временный файл в имя исходного файла
    hide();

    qDebug() << "Запись с названием" << searchName << "удалена из файла" << fileName;
}
