#ifndef MENUE_H
#define MENUE_H

#include <QWidget>
#include "test.h"

namespace Ui
{
    class main_menue;
}

class menue : public QWidget
{
    Q_OBJECT
public:
    explicit menue(QWidget *parent = 0);
    ~menue();

private:
    Ui::main_menue *ui;
    test_window *mTest;
private slots:
    void handle_visualization_pressed();
    void handle_theory_pressed();
    void handle_test_pressed();
    
};

#endif // MENUE_H
