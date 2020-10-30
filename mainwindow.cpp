#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <math.h>

const int OP_PLU = 1;
const int OP_MIN = 2;
const int OP_MUL = 3;
const int OP_DIV = 4;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextStream stream(stdout);

    stream << "Initiate new MainWindow" << endl;

    ui->setupUi(this);
    MainWindow::firstInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::firstInit() {
    MainWindow::ClearTime = false;
    MainWindow::LcdStringFirst = "";
    MainWindow::LcdStringSecond = "";
    MainWindow::Operator = 0;
    MainWindow::LcdDisplay = 0;
}

void MainWindow::showStatus() {
    QTextStream stream(stdout);

    stream << "MainWindow::ClearTime : " << MainWindow::ClearTime << endl;
    stream << "MainWindow::LcdStringFirst : " << MainWindow::LcdStringFirst << endl;
    stream << "MainWindow::LcdStringSecond : " << MainWindow::LcdStringSecond << endl;
    stream << "MainWindow::Operator : " << MainWindow::Operator << endl;
    stream << "MainWindow::LcdDisplay : " << MainWindow::LcdDisplay << endl;
}

/**
 * @brief MainWindow::setNumber
 * @param Number
 *
 * This part need to modify to make it able to add more complex number to calculate.
 */
void MainWindow::setNumber(double Number) {
    Q_UNUSED(Number);
}
//void MainWindow::setNumber(double Number) {
//    QTextStream stream(stdout);

//    stream << "isnan(MainWindow::FirstNum) " << isnan(MainWindow::FirstNum) << endl;
//    stream << "isnan(MainWindow::SecondNum) " << isnan(MainWindow::SecondNum) << endl;

//    if (MainWindow::ClearTime) {
//        MainWindow::FirstNum = 0;
//        MainWindow::SecondNum = 0;
//        MainWindow::ClearTime = false;
//    }

//    if (MainWindow::FirstNum == 0) {
//        stream << "Setting first num to " << Number << endl;
//        MainWindow::FirstNum = Number;
//    } else if (MainWindow::SecondNum == 0) {
//        stream << "Setting second num to " << Number << endl;
//        MainWindow::SecondNum = Number;
//        MainWindow::ClearTime = true;
//    }

//    stream << "MainWindow::FirstNum " << MainWindow::FirstNum << endl;
//    stream << "MainWindow::SecondNum " << MainWindow::SecondNum << endl;
//    stream << "MainWindow::ClearTime " << MainWindow::ClearTime << endl;
//}

void MainWindow::setOperator(char Op) {
    if ((Op == OP_PLU) || (Op == OP_MIN) || (Op == OP_MUL) || (Op == OP_DIV)) {
//       MainWindow->Operator = Operator;
       MainWindow::Operator = Op;
    }
}

void MainWindow::clearLcd() {
    QTextStream stream(stdout);

    stream << "lcd Cleared" << endl;
    LcdDisplay = 0;
    ui->lcdPanel->display(LcdDisplay);
}

// kalau operator masih belum ditekan, selalu append di sebelah kanannya string pertama
// kalau operator ditekan, lcdPanel dibersihkan, append di sebelah kanannya string kedua
void MainWindow::setLcd(double NumberButton) {
    bool ok = false;

    MainWindow::showStatus();

    if (ClearTime) {
        LcdStringFirst = "";
        LcdStringSecond = "";
    }
    if (Operator == 0) {                      // operator masih belum ditekan
        LcdStringFirst += QString::number(NumberButton);    // append di sebelah kanan string pertama
        LcdDisplay = LcdStringFirst.toDouble(&ok);
    } else {                                                // operator sudah ditekan
        clearLcd();                                         // lcdPanel dibersihkan
        LcdStringSecond += QString::number(NumberButton);   // append di sebelah kanan string kedua
        LcdDisplay = LcdStringSecond.toDouble(&ok);
    }

    ui->lcdPanel->display(LcdDisplay);
    if (ClearTime) {
        MainWindow::firstInit();
        ClearTime = false;
    }

    MainWindow::showStatus();
}

double MainWindow::calculate() {
    bool ok;
    double first = LcdStringFirst.toDouble(&ok);
    double second = LcdStringSecond.toDouble(&ok);
    double result;

    switch (Operator) {
    case OP_PLU:
        result = first + second;
        break;
    case OP_MIN:
        result = first - second;
        break;
    case OP_MUL:
        result = first * second;
        break;
    case OP_DIV:
        result = first / second;
        break;
    default:
        result = 0;
        break;
    }

    return result;
}

void MainWindow::on_button1_clicked()
{
    QTextStream stream(stdout);
    stream << "button 1 clicked" << endl;

    MainWindow::setLcd(1);
}

void MainWindow::on_button2_clicked()
{
    QTextStream stream(stdout);
    stream << "button 2 clicked" << endl;
    MainWindow::setLcd(2);
}

void MainWindow::on_button3_clicked()
{
    QTextStream stream(stdout);
    stream << "button 3 clicked" << endl;
    MainWindow::setLcd(3);
}

void MainWindow::on_button4_clicked()
{
    QTextStream stream(stdout);
    stream << "button 4 clicked" << endl;
    MainWindow::setLcd(4);
}

void MainWindow::on_button5_clicked()
{
    QTextStream stream(stdout);
    stream << "button 5 clicked" << endl;
    MainWindow::setLcd(5);
}

void MainWindow::on_button6_clicked()
{
    QTextStream stream(stdout);
    stream << "button 6 clicked" << endl;
    MainWindow::setLcd(6);
}

void MainWindow::on_button7_clicked()
{
    QTextStream stream(stdout);
    stream << "button 7 clicked" << endl;
    MainWindow::setLcd(7);
}

void MainWindow::on_button8_clicked()
{
    QTextStream stream(stdout);
    stream << "button 8 clicked" << endl;
    MainWindow::setLcd(8);
}

void MainWindow::on_button9_clicked()
{
    QTextStream stream(stdout);
    stream << "button 9 clicked" << endl;
    MainWindow::setLcd(9);
}

void MainWindow::on_pushButton_10_clicked()
{
    QTextStream stream(stdout);
    stream << "button 0 clicked" << endl;
    MainWindow::setLcd(0);
}

void MainWindow::on_buttonEqual_clicked()
{
    double result;
    QTextStream stream(stdout);
    result = MainWindow::calculate();
    stream << "Calculation result is " << result << endl;

    MainWindow::firstInit();
    ClearTime = true;
    MainWindow::showStatus();

    MainWindow::clearLcd();
    MainWindow::setLcd(result);
}

void MainWindow::on_buttonDivide_clicked()
{
    QTextStream stream(stdout);
    stream << "button divide clicked" << endl;
    MainWindow::setOperator(OP_DIV);
}

void MainWindow::on_buttonMultiply_clicked()
{
    QTextStream stream(stdout);
    stream << "button multiply clicked" << endl;
    MainWindow::setOperator(OP_MUL);
}

void MainWindow::on_buttonMinus_clicked()
{
    QTextStream stream(stdout);
    stream << "button minus clicked" << endl;
    MainWindow::setOperator(OP_MIN);
}

void MainWindow::on_buttonPlus_clicked()
{
    QTextStream stream(stdout);
    stream << "button plus clicked" << endl;
    MainWindow::setOperator(OP_PLU);
}
