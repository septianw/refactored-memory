#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextStream stream(stdout);

    stream << "Initiate new MainWindow" << endl;

    ui->setupUi(this);
    MainWindow::ClearTime = false;
    MainWindow::FirstNum = 0;
    MainWindow::SecondNum = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFirst(double FirstNumber) {
    MainWindow::FirstNum = FirstNumber;
}

void MainWindow::setSecond(double SecondNumber) {
    MainWindow::SecondNum = SecondNumber;
}

void MainWindow::setNumber(double Number) {
    QTextStream stream(stdout);

    stream << "isnan(MainWindow::FirstNum) " << isnan(MainWindow::FirstNum) << endl;
    stream << "isnan(MainWindow::SecondNum) " << isnan(MainWindow::SecondNum) << endl;

    if (MainWindow::ClearTime) {
        MainWindow::FirstNum = 0;
        MainWindow::SecondNum = 0;
        MainWindow::ClearTime = false;
    }

    if (MainWindow::FirstNum == 0) {
        stream << "Setting first num to " << Number << endl;
        MainWindow::FirstNum = Number;
    } else if (MainWindow::SecondNum == 0) {
        stream << "Setting second num to " << Number << endl;
        MainWindow::SecondNum = Number;
        MainWindow::ClearTime = true;
    }

//    if (MainWindow::ClearTime) {
//        MainWindow::FirstNum = Number;
//        MainWindow::SecondNum = 0; // square root of 30 is imaginary number, this will trigger NaN value.
//    }

    stream << "MainWindow::FirstNum " << MainWindow::FirstNum << endl;
    stream << "MainWindow::SecondNum " << MainWindow::SecondNum << endl;
    stream << "MainWindow::ClearTime " << MainWindow::ClearTime << endl;
}

void MainWindow::setOperator(char Op) {
    if ((Op == '+') || (Op == '-') || (Op == '*') || (Op == '/')) {
//       MainWindow->Operator = Operator;
       Operator = Op;
    }
}

double MainWindow::calculate() {
    double result = 0;
    QTextStream stream(stdout);

    stream << "MainWindow::FirstNum " << MainWindow::FirstNum << endl;
    stream << "MainWindow::SecondNum " << MainWindow::SecondNum << endl;
    stream << "MainWindow::Operator " << MainWindow::Operator << endl;

    switch (MainWindow::Operator) {
    case '+':
        result = MainWindow::FirstNum + MainWindow::SecondNum;
        stream << "result = MainWindow::FirstNum + MainWindow::SecondNum; result.. " << result << endl;
        break;
    case '-':
        result = MainWindow::FirstNum - MainWindow::SecondNum;
        stream << "result = MainWindow::FirstNum - MainWindow::SecondNum; result.. " << result << endl;
        break;
    case '*':
        result = MainWindow::FirstNum * MainWindow::SecondNum;
        stream << "result = MainWindow::FirstNum * MainWindow::SecondNum; result.. " << result << endl;
        break;
    case '/':
        result = MainWindow::FirstNum / MainWindow::SecondNum;
        stream << "result = MainWindow::FirstNum / MainWindow::SecondNum; result.. " << result << endl;
        break;
    default:
        break;
    }

    stream << "Result" << result << endl;

    return result;
}

void MainWindow::on_button1_clicked()
{
    QTextStream stream(stdout);
    stream << "button 1 clicked" << endl;
    ui->lcdPanel->display(1);
    MainWindow::setNumber(1);
}

void MainWindow::on_button2_clicked()
{
    QTextStream stream(stdout);
    stream << "button 2 clicked" << endl;
    ui->lcdPanel->display(2);
    MainWindow::setNumber(2);
}

void MainWindow::on_button3_clicked()
{
    QTextStream stream(stdout);
    stream << "button 3 clicked" << endl;
    ui->lcdPanel->display(3);
    MainWindow::setNumber(3);
}

void MainWindow::on_button4_clicked()
{
    QTextStream stream(stdout);
    stream << "button 4 clicked" << endl;
    ui->lcdPanel->display(4);
    MainWindow::setNumber(4);
}

void MainWindow::on_button5_clicked()
{
    QTextStream stream(stdout);
    stream << "button 5 clicked" << endl;
    ui->lcdPanel->display(5);
    MainWindow::setNumber(5);
}

void MainWindow::on_button6_clicked()
{
    QTextStream stream(stdout);
    stream << "button 6 clicked" << endl;
    ui->lcdPanel->display(6);
    MainWindow::setNumber(6);
}

void MainWindow::on_button7_clicked()
{
    QTextStream stream(stdout);
    stream << "button 7 clicked" << endl;
    ui->lcdPanel->display(7);
    MainWindow::setNumber(7);
}

void MainWindow::on_button8_clicked()
{
    QTextStream stream(stdout);
    stream << "button 8 clicked" << endl;
    ui->lcdPanel->display(8);
    MainWindow::setNumber(8);
}

void MainWindow::on_button9_clicked()
{
    QTextStream stream(stdout);
    stream << "button 9 clicked" << endl;
    ui->lcdPanel->display(9);
    MainWindow::setNumber(9);
}

void MainWindow::on_pushButton_10_clicked()
{
    QTextStream stream(stdout);
    stream << "button 0 clicked" << endl;
    ui->lcdPanel->display(0);
    MainWindow::setNumber(0);
}

void MainWindow::on_buttonEqual_clicked()
{
    double result;
    QTextStream stream(stdout);
    result = MainWindow::calculate();
    stream << "Calculation result is " << result << endl;
    ui->lcdPanel->display(result);
}

void MainWindow::on_buttonDivide_clicked()
{
    QTextStream stream(stdout);
    stream << "button divide clicked" << endl;
    MainWindow::setOperator('/');
}

void MainWindow::on_buttonMultiply_clicked()
{
    QTextStream stream(stdout);
    stream << "button multiply clicked" << endl;
    MainWindow::setOperator('*');
}

void MainWindow::on_buttonMinus_clicked()
{
    QTextStream stream(stdout);
    stream << "button minus clicked" << endl;
    MainWindow::setOperator('-');
}

void MainWindow::on_buttonPlus_clicked()
{
    QTextStream stream(stdout);
    stream << "button plus clicked" << endl;
    MainWindow::setOperator('+');
}
