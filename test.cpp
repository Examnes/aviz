#include "test.h"
#include "ui_test.h"
#include "moc_test.cpp"

test::test(QWidget *parent) : QWidget(parent), ui(new Ui::f_test)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->b_enter, SIGNAL (released()), this, SLOT (handle_enter_pressed()));
}

void menue::handle_enter_pressed()
{
    
}


menue::~menue()
{
    parent->show();
    delete ui;
}
