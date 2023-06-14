#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include <QMessageBox>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QDesktopServices>
// Конструктор главного окна
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Установка пользовательского интерфейса для главного окна
    ui->setupUi(this);
    this->setWindowTitle("Читательский дневник"); // Установка названия главного окна

}

MainWindow::~MainWindow() //Освобождение памяти
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // Кнопка ДОБАВИТЬ КНИГУ
{
    Book book; // Создание экземпляра окна для добавления книги
   // hide();
    book.setModal(true); //Отображение окна в модальном режиме
    book.exec();
}

void MainWindow::on_pushButton_3_clicked() // Кнопка ВЫХОД
{ // Вывод диалога с вопросом о выходе из программы
    QMessageBox::StandardButton Exit = QMessageBox::question(this, "Читательский дневник", "Хотите выйти?",QMessageBox::Yes | QMessageBox::No);

    if(Exit == QMessageBox::Yes){
        QApplication::quit(); //метод выход
    } else {
        qDebug() << "Выход не был сделан";
    }
}

void MainWindow::on_pushButton_2_clicked() // Обработчик нажатия кнопки "Список книг"
{
    QUrl fileUrl = QUrl::fromLocalFile(QDir::currentPath() + "/books.txt"); // Создание ссылки на файл, содержащий записи о книгах
    QDesktopServices::openUrl(fileUrl); // Открытие файла с помощью стандартного приложения для просмотра текстовых файлов
}

