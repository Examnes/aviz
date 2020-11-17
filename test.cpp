#include "test.h"
#include "ui_test.h"
#include "moc_test.cpp"
#include <sstream>

test_window::test_window(QWidget *parent) : QWidget(parent, Qt::Window), ui(new Ui::f_test)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    parentWidget()->hide();
    connect(ui->b_enter, SIGNAL (released()), this, SLOT (handle_enter_pressed()));
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    timer->start(1000);
    last = 5 * 60;
}

void test_window::handle_enter_pressed()
{
    
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
