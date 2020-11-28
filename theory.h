#if !defined(THEORY_H)
#define THEORY_H

#include <QWidget>

namespace Ui
{
    class f_theory;
}

class theory_window : public QWidget
{
    Q_OBJECT
public:
    explicit theory_window(QWidget *parent = 0);
    ~theory_window();
    void closeEvent(QCloseEvent *);
private:
    Ui::f_theory *ui;
private slots:
    void handle_forward_pressed();
    void handle_backward_pressed();
};

#endif // THEORY_H
