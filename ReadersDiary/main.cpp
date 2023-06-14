#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Создание приложения Qt
    MainWindow w; // Создание главного окна приложения
    w.show(); // Отображение главного окна приложения

    return a.exec(); // Запуск главного цикла обработки событий приложения
}
