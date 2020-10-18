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

    // Convenient container classes
    QStringList list;
    list << s1 << s2;
    // Join strings
    QString s = list.join(" ") + "!";
    cout<< s << endl;
}
