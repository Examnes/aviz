#include "theory.h"
#include "ui_theory.h"
#include "moc_theory.cpp"
#include <sstream>

theory_window::theory_window(QWidget *parent) : QWidget(parent, Qt::Window), ui(new Ui::f_theory)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    parentWidget()->hide();
    connect(ui->b_forward, SIGNAL (released()), this, SLOT (handle_forward_pressed()));
    connect(ui->b_backward, SIGNAL (released()), this, SLOT (handle_backward_pressed()));
}

void theory_window::handle_forward_pressed()
{
    
}

void theory_window::handle_backward_pressed()
{
    
}


void theory_window::closeEvent(QCloseEvent *)
{
    parentWidget()->show();
}

theory_window::~theory_window()
{
    delete ui;
}
