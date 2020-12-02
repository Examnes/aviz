#include "visualization.h"
#include "ui_vis.h"
#include "moc_visualization.cpp"
#include <QPixmap>
#include <QGraphicsPixmapItem>

visualization_window::visualization_window(QWidget *parent) : QWidget(parent, Qt::Window), ui(new Ui::f_vis)
{
    ui->setupUi(this);
    connect(ui->b_vis_forward, SIGNAL(released()), this, SLOT(vis_forward_pressed()));
    connect(ui->b_vis_backward, SIGNAL(released()), this, SLOT(vis_backward_pressed()));
    scene = new QGVScene("Визуализация",this);
    last_step = 1;
    current_step = 0;
    update_visualization();
    ui->v_vis->setScene(scene);
}

void visualization_window::update_visualization()
{
    scene->clear();
    scene->addText(QString::number(current_step));
}

void visualization_window::save_frame()
{
    QPixmap pixMap = ui->v_vis->grab(ui->v_vis->viewport()->rect());
    pixMap.save("./history/" + QString::number(last_step) + ".png");
}

void visualization_window::load_frame(int n)
{
    QPixmap p;
    p.load("./history/" + QString::number(n) + ".png");
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(p);
    scene->clear();
    scene->addItem(item);
    ui->v_vis->show();
}

void visualization_window::vis_forward_pressed()
{
    current_step++;
    if (current_step == last_step)
    {
        update_visualization();
        save_frame();
        last_step++;
    }
    else
    {
        load_frame(current_step);
    }
}

void visualization_window::vis_backward_pressed()
{
    if (current_step != 0)
    {
        current_step--;
        load_frame(current_step);
    }
}

void visualization_window::closeEvent(QCloseEvent *)
{
    parentWidget()->show();
}

visualization_window::~visualization_window()
{
    delete ui;
}
