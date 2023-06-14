#ifndef MAINWINDOW_H // Защита от повторного компилирования файла. Если MAINWINDOW_H не определен, то он будет определен.
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // Объявление класса MainWindow
QT_END_NAMESPACE

class MainWindow : public QMainWindow // Определение класса MainWindow
{
    Q_OBJECT // используемый для работы с сигналами и слотами Qt

public:
    MainWindow(QWidget *parent = nullptr); // Конструктор класса
    ~MainWindow(); // освобождает занимаемую память

private slots: // для обработки нажатия на кнопку
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui; // Указатель на объект класса
};
#endif
