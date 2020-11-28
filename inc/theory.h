#if !defined(THEORY_H)
#define THEORY_H

#include <QWidget>
#include <QFileSystemModel>
#include <QItemSelection>
#include <QCloseEvent>

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
    QFileSystemModel* model;
private slots:
    void user_selected(const QItemSelection&,const QItemSelection&);
};

#endif // THEORY_H
