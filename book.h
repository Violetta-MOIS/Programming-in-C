#ifndef BOOK_H // Защита от повторного (проверяет есть ли BOOK.H)
#define BOOK_H // компилирования файла. (если нет, то добовляет)

#include <QDialog> //Диалоговое окно.

namespace Ui {
class Book;
}

class Book : public QDialog
{
    Q_OBJECT // для работы с графическим интерфейсом.Макрос, используемый для работы с сигналами и слотами Qt.

public:
    explicit Book(QWidget *parent = nullptr); // Конструктор класса Book
    ~Book(); // освобождение памяти

private slots: // Обработка нажатия.
    void on_checkBox_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_But_clicked();

private:
    Ui::Book *ui; //указатель на объект
};

#endif
