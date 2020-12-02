#include "menue.h"
#include "ui_main_menue.h"
#include "moc_menue.cpp"
#include <QMessageBox>
#include <QLineEdit>
#include <QInputDialog>


menue::menue(QWidget *parent) : QWidget(parent), ui(new Ui::main_menue)
{
    ui->setupUi(this);
    connect(ui->b_vis_start, SIGNAL (released()), this, SLOT (handle_visualization_pressed()));
    connect(ui->b_theory_start, SIGNAL (released()), this, SLOT (handle_theory_pressed()));
    connect(ui->b_test_start, SIGNAL (released()), this, SLOT (handle_test_pressed()));
}

void menue::handle_visualization_pressed()
{
    mVis = new visualization_window(this);
    mVis->show();
}

void menue::handle_theory_pressed()
{

    mTheory = new theory_window(this);
    mTheory->show();
}

void menue::handle_test_pressed()
{
    QMessageBox::StandardButton reply;
    bool ok;
    QString username = QInputDialog::getText(this, tr("Введите имя"),
                        tr("Имя пользователя:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
    if (ok)
    {
        reply = QMessageBox::question(this, "Режим обучения", "Запустить тест в режиме обучения?",
                       QMessageBox::Yes|QMessageBox::No);
        mTest = new test_window(reply == QMessageBox::Yes,username,this);
        mTest->show();
    }
}

menue::~menue()
{
    delete ui;
}
