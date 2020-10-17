#include <QCoreApplication>
#include <QtCore>

QTextStream cout (stdout, QIODevice::WriteOnly);

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

//    return a.exec();

    // Avoid compiler warning
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QString s1("Paris");
    QString s2("London");

    QString s = s1 + " " + s2 + "!";
    cout << s << endl;
}
