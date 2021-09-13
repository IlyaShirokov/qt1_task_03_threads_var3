#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::actionOpenFile);
    connect(ui->actionExit,  &QAction::triggered, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonApply_clicked()
{

}


void MainWindow::on_buttonCancel_clicked()
{

}

void MainWindow::actionOpenFile()
{

}

