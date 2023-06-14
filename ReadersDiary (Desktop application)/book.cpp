#include "book.h"
#include "ui_book.h"
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

// Конструктор класса Book
Book::Book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Book)
{
// Установка интерфейса из файла book.ui
    ui->setupUi(this);
    this->setWindowTitle("Читательский дневник"); //название окошка

}

Book::~Book() // освобождение памяти
{
    delete ui; //освобождение памяти под интерфейс
}

void Book::on_pushButton_clicked()
{
    const QString bookTitle = ui->namebook->text(); //объявление переменной для кнопок
    const QString authorName = ui->authorbook->text(); // Получение данных из полей ввода интерфейса
    const QString bookGradeString = ui->gradebook->text();

    // Проверяем корректность ввода данных. Ввели цифры а не буквы
    bool isBookGradeValid = false;
    const int bookGrade = bookGradeString.toInt(&isBookGradeValid);
    if (!isBookGradeValid || bookGrade < 1 || bookGrade > 10) {
        QMessageBox::warning(this, "Ошибка", "Введите корректную оценку книги (число от 1 до 10)");
        return;
    }

    // Проверяем, что пользователь ввел Название и Автор книги
    if (bookTitle.isEmpty() || authorName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название и автора книги");
        return;
    }

    QFile file("books.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", QString("Не удалось открыть файл %1 для записи").arg(file.fileName()));
        return;
    }

    QTextStream out(&file); // Запись данных о книге в файл
    out << "BOOK\n"
        << "Название: " << bookTitle << "\n"
        << "Автор: " << authorName << "\n"
        << "Оценка: " << bookGrade << "\n";

        if (!file.flush()) {
        QMessageBox::critical(this, "Ошибка", QString("Не удалось записать данные в файл %1").arg(file.fileName()));
    } else {
        hide(); //спрятать окно
    }
}


