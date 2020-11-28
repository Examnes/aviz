#include "test_logic.h"
#include <QFile>
#include <QTextStream>

test_logic::test_logic(char key): decode_key(key)
{
    parse(decode("./test/main.e"));

}

QString test_logic::decode(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) return "";
    QByteArray blob = file.readAll();
    for (int i = 0; i < blob.size(); ++i)
    {
        blob[i] = blob[i] ^ decode_key;
    }
    QString decoded = QString(blob);
    return decoded;
}

void test_logic::parse(QString content)
{
    QTextStream ss(&content);
    while (!ss.atEnd())
    {
        question_t q;
        q.question = ss.readLine();
        QString line = ss.readLine();
        while(line != "#" && !ss.atEnd())
        {
            q.options.push_back(line);
        }
        ss >> q.right_answer >> q.price;
    };
}
