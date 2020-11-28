#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QTimer>
#include <test_logic.h>

namespace Ui
{
    class f_test;
}

class test_window : public QWidget
{
    Q_OBJECT
public:
    explicit test_window(bool pretend,QWidget *parent = 0);
    ~test_window();
    void closeEvent(QCloseEvent *);
private:
    test_logic l;
    bool is_pretend;
    Ui::f_test *ui;
    QTimer* timer;
    int last;
private slots:
    void handle_enter_pressed();
    void updateCountdown();
};

#endif // TEST_H
