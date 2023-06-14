#include "task.h"
#include "ui_task.h"
#include <QFile>
#include <QMessageBox>

Task::Task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    this->setWindowTitle("Ежедневник");
}

Task::~Task()
{
    delete ui;
}

void Task::on_pushButton_clicked()
{
    QString taskpl = ui->lineEdit->text();
    QString descriptionpl = ui->lineEdit_2->text();

    if (taskpl.isEmpty() || descriptionpl.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Необходимо заполнить все поля!");
        return;
    }

    QFile file("Task.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.contains(taskpl)) {
                QMessageBox::warning(this, "Ошибка", "Задача с таким названием уже существует!");
                return;
            }
        }
        file.close();
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);
        // Записываем данные в файл
        out << "***\n" << "Задача: " << taskpl << " \nОписание: " << descriptionpl << "\n";
        file.close();
    }
    hide();
}
