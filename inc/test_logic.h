#ifndef TEST_LOGIC_H
#define TEST_LOGIC_H
#include <QVector>
#include <QString>

class test_logic
{
private:
    struct question_t
    {
        QString question;
        QVector<QString> options;
        int right_answer;
        int price;
    };
    QVector<question_t> questions;
    QVector<bool> passed;
    QString decode(QString filename);
    void parse(QString content);
    char decode_key;
    int score;
public:
    test_logic(char key);
    test_logic() = default;
};

#endif // TEST_LOGIC_H
