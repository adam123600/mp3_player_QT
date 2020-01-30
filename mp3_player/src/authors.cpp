#include "headers/authors.h"
#include "ui_authors.h"

Authors::Authors(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authors)
{
    ui->setupUi(this);
    QPixmap pix("/home/student/Pobrane/autorzy.png");
    ui->label->setPixmap(pix);
}

Authors::~Authors()
{
    delete ui;
}
