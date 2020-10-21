#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setNumber(double Number);
    void setOperator(char Operator);

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_buttonDivide_clicked();

    void on_buttonEqual_clicked();

private:
    double FirstNum;
    double SecondNum;
    bool ClearTime;
    char Operator;
    Ui::MainWindow *ui;
    void setFirst(double FirstNumber);
    void setSecond(double SecondNumber);
    double calculate();
};

#endif // MAINWINDOW_H
