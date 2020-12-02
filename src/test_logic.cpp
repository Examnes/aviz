#include "test_logic.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <qalgorithms.h>
#include <QDebug>

test_logic::test_logic(char key,int goal): decode_key(key)
{
    parse(decode("./test/main.e"));
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    get_new_question();
    score = 0;
    passed_count = 0;
    this->goal = goal;
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
            line = ss.readLine();
        }
        ss >> q.price; 
        ss.skipWhiteSpace();
        q.right_answer = ss.readLine();
        questions.push_back(q);
        passed.push_back(false);
    };
}

void test_logic::get_new_question()
{
    int index = qrand() % passed.size();
    while (passed[index])
    {
        index = qrand() % passed.size();
    }
    current_question = index;
}

bool test_logic::approve(QString answer)
{
    bool done = false;
    if(questions[current_question].options.size() == 0) // open question if 0 option aviable
    {
        if(answer == questions[current_question].right_answer)
        {
            done = true;
        }
    }
    else 
    {
        QTextStream ss;
        ss << answer;
        QVector<int> r_answer;
        while (!ss.atEnd())
        {
            int option;
            ss >> option;
            r_answer.push_back(option);
        }
        QTextStream rss; rss << questions[current_question].right_answer;
        QVector<int> r_right_answer;
        while (!ss.atEnd())
        {
            int option;
            rss >> option;
            r_right_answer.push_back(option);
        }
        qSort(r_answer);
        qSort(r_right_answer);
        if(r_answer == r_right_answer)
            done = true;
    }
    if(done)
        score += questions[current_question].price;
    passed[current_question] = true;
    get_new_question();
    passed_count++;
    return done;
}

QString test_logic::get_right_answer()
{
    return questions[current_question].right_answer;
}

QString test_logic::get_question()
{
    return questions[current_question].question;
}

QVector<QString> test_logic::get_options()
{
    return questions[current_question].options;
}

float test_logic::get_progress()
{
    return (float)passed_count / goal;
}

bool test_logic::is_done()
{
    return goal == passed_count;
}