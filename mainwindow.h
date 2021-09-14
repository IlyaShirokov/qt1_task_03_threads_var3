#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "imagemanipulator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonApply_clicked();
    void on_buttonCancel_clicked();
    void actionOpenFile();
    void updateProgressBar(int percent);
    void slot_showProcessedImage(QImage* img);

private:
    Ui::MainWindow *ui;

    ImageManipulator* m_pImageProcess;
    QImage* m_pImage;
};
#endif // MAINWINDOW_H
