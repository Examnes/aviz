#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QTimer>

namespace Ui
{
    class f_test;
}

class test_window : public QWidget
{
    Q_OBJECT
public:
    explicit test_window(QWidget *parent = 0);
    ~test_window();
    void closeEvent(QCloseEvent *);
private:
    Ui::f_test *ui;
    QTimer* timer;
    int last;
private slots:
    void handle_enter_pressed();
    void updateCountdown();
};

#endif // TEST_H
