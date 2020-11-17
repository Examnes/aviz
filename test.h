#ifndef MENUE_H
#define MENUE_H

#include <QWidget>

namespace Ui
{
    class f_test;
}

class test : public QWidget
{
    Q_OBJECT
public:
    explicit test(QWidget *parent = 0);
    ~test();

private:
    Ui::f_test *ui;
private slots:
    void handle_enter_pressed();
};

#endif // MENUE_H
