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

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_pushButton_10_clicked();

    void on_buttonMultiply_clicked();

    void on_buttonMinus_clicked();

    void on_buttonPlus_clicked();

private:
    double LcdDisplay;
    bool ClearTime;
    int Operator;
    QString LcdStringFirst;
    QString LcdStringSecond;
    Ui::MainWindow *ui;

    void setFirst(double FirstNumber);
    void setSecond(double SecondNumber);
    void setLcd(double NumberButton);
    void clearLcd();
    double calculate();
    void firstInit();
    void showStatus();
};

#endif // MAINWINDOW_H
