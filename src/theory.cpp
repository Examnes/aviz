#include "theory.h"
#include "ui_theory.h"
#include "moc_theory.cpp"
#include <sstream>
#include <iostream>
#include <QStringList>

theory_window::theory_window(QWidget *parent) : QWidget(parent, Qt::Window), ui(new Ui::f_theory)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    parentWidget()->hide();
    model = new QFileSystemModel();
    model->setFilter(model->filter() | QDir::NoDotAndDotDot | QDir::Files);
    QDir dir("./sections");
    model->setRootPath(dir.absolutePath());
    ui->teory_file_tree->setModel(model);
    ui->teory_file_tree->setRootIndex(model->setRootPath(dir.absolutePath()));
    ui->teory_file_tree->hideColumn(1);
    ui->teory_file_tree->hideColumn(2);
    ui->teory_file_tree->hideColumn(3);
    ui->page->setSearchPaths(QStringList("./sections"));
    connect(ui->teory_file_tree->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)), this, SLOT(user_selected(const QItemSelection&,const QItemSelection&)));
    connect(ui->b_forward,SIGNAL (released()),ui->page,SLOT(forward()));
    connect(ui->b_backward,SIGNAL (released()),ui->page,SLOT(backward()));
}

void theory_window::user_selected(const QItemSelection& selected,const QItemSelection&)
{
    const QModelIndex index = ui->teory_file_tree->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    ui->page->setSource(selectedText);
}

void theory_window::closeEvent(QCloseEvent *)
{
    parentWidget()->show();
}

theory_window::~theory_window()
{
    delete ui;
}
