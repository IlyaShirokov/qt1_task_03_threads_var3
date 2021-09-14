#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pImage = new QImage;
    m_pImageProcess = new ImageManipulator;

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::actionOpenFile);
    connect(ui->actionExit,  &QAction::triggered, this, &MainWindow::close);

    connect(m_pImageProcess, &ImageManipulator::signal_percentPassed, this, &MainWindow::updateProgressBar);
    connect(m_pImageProcess, &ImageManipulator::signal_processFinished, this, &MainWindow::slot_showProcessedImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonApply_clicked()
{
    m_pImageProcess->startMedianBlur(m_pImage);
}


void MainWindow::on_buttonCancel_clicked()
{
    m_pImageProcess->stopProcessing();
}

void MainWindow::actionOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isEmpty())
    {
        m_pImage->load(fileName);
        ui->label->setScaledContents(true);
        ui->label->setPixmap(QPixmap::fromImage(*m_pImage).scaled(ui->label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
}

void MainWindow::updateProgressBar(int percent)
{
    ui->progressBar->setValue(percent);
}

void MainWindow::slot_showProcessedImage(QImage *img)
{
    ui->label->setPixmap(QPixmap::fromImage(*img).scaled(ui->label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

