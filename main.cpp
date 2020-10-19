#include <QCoreApplication>
#include <QtCore>

QTextStream cout (stdout, QIODevice::WriteOnly);

int main(int argc, char *argv[])
{
    // Avoid compiler warning
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    QList<QStringList> data;
    // File
    QFile file("source.csv");
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        // Loop forever macro
        forever {
            QString line = stream.readLine();
            // Test for null string 'string()'
            if (line.isNull()) {
                break;
            }

            // Test for empty string 'QString("")'
            if (line.isEmpty()) {
                continue;
            }
            QStringList row;
            // for each loop for iterate over containers
            foreach (const QString& cell, line.split(",")) {
                row.append(cell.trimmed());
            }
            data.append(row);
        }
    }

//    QCoreApplication a(argc, argv);

//    return a.exec();

//    QString s1("Paris");
//    QString s2("London");

//    // Convenient container classes
//    QStringList list;
//    list << s1 << s2;
//    // Join strings
//    QString s = list.join(" ") + "!";
//    cout<< s << endl;
}
