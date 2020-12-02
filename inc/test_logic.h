#ifndef TEST_LOGIC_H
#define TEST_LOGIC_H
#include <QVector>
#include <QString>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

class test_logic
{
private:
    struct question_t
    {
        QString question;
        QVector<QString> options;
        QString right_answer;
        int price;
    };
    QVector<test_logic::question_t> questions;
    QVector<bool> passed;
    QString decode(QString filename);
    void parse(QString content);
    char decode_key;
    int score;
    int current_question;
    void get_new_question();
    int passed_count;
    int goal;
public:
    test_logic(char key,int goal);
    test_logic() = default;
    bool approve(QString answer);
    QString get_right_answer();
    QString get_question();
    QVector<QString> get_options();
    float get_progress();
    bool is_done();
    int get_score()
    {
        return score;
    }

    void save_result(QString username)
    {
        QFile result("./results/result.txt");
        result.open(QIODevice::Append);
        QTextStream ss(&result);
        ss << "[" << username << "]" << " прошел тест " 
        << QDateTime::currentDateTime().toString() << " с результатом " 
        << score << "\n";
    }
};

#endif // TEST_LOGIC_H
