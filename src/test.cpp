#include "test.h"
#include "ui_test.h"
#include "moc_test.cpp"
#include <sstream>
#include <QTextStream>
#include <QMessageBox>
#include <QStringBuilder>

test_window::test_window(bool pretend,QString username,QWidget *parent) :name(username), QWidget(parent, Qt::Window), ui(new Ui::f_test),is_pretend(pretend)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    parentWidget()->hide();
    connect(ui->b_enter, SIGNAL (released()), this, SLOT (handle_enter_pressed()));
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    timer->start(1000);
    last = 5 * 60;
    if(is_pretend)
        this->setWindowTitle("Тест - обучающий режим (действия не записываются)");
    l = test_logic(42,2);
    update_placeholders();
}

void test_window::update_placeholders()
{
    ui->t_question->setPlainText(l.get_question());
    QString options;
    QVector<QString> a_options = l.get_options();
    for(int i = 0; i < a_options.size();i++)
    {
        QString s = a_options[i];
        options = options % QString::number(i + 1) % ". " % s % "\n";
    }
    ui->t_options->setPlainText(options);
    ui->completed_tracker->setValue(100 * l.get_progress());
}

void test_window::handle_enter_pressed()
{
    bool is_right = l.approve(ui->i_answer->toPlainText());
    if(is_pretend)
    {
        if(!is_right)
        {
            QMessageBox::warning(this, "Внимание","Вы ответили неправильно, верный ответ был: " + l.get_right_answer());
        }
    }
    if (!l.is_done())
    {
        update_placeholders();
    }else
    {
        QMessageBox::information(this, "Результат","Вы прошли тест, ваш результат: " + QString::number(l.get_score()));
        if(!is_pretend)
            l.save_result(name);
        this->close();
    }
}

void test_window::updateCountdown()
{
    last--;
    std::stringstream ss;
    ss << last / 60 << ": " << last % 60;
    ui->time_left->setText(ss.str().c_str());
    timer->start(1000);
}

void test_window::closeEvent(QCloseEvent *)
{
    parentWidget()->show();
}

test_window::~test_window()
{
    delete ui;
}
