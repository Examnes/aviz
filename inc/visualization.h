#if !defined(VIS_HH)
#define VIS_HH

#include <QWidget>
#include <QGraphicsScene>
#include <QCloseEvent>
#include "graph.h"
#include <QGVCore/QGVScene.h>

namespace Ui
{
    class f_vis;
}

class visualization_window : public QWidget
{
    Q_OBJECT
public:
    explicit visualization_window(QWidget *parent = 0);
    ~visualization_window();
    void closeEvent(QCloseEvent *);

private:
    Ui::f_vis *ui;
    vis v;
    int last_step;
    int current_step;
    void save_frame();
    void load_frame(int n);
    QGVScene* scene;
    void update_visualization();
private slots:
    void vis_forward_pressed();
    void vis_backward_pressed();
};

#endif // VIS_HH
