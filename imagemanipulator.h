#ifndef IMAGEMANIPULATOR_H
#define IMAGEMANIPULATOR_H

#include <QThread>
#include <QImage>

#include "asmOpenCV.h"

class ImageManipulator : public QThread
{
    Q_OBJECT
public:
    ImageManipulator();
    ~ImageManipulator();

    void startMedianBlur(QImage* img);
    void stopProcessing();

signals:
    void signal_percentPassed(int percent);
    void signal_processFinished(QImage *img);

private:
    void run() override;

    QImage* m_pImageSource;
    QImage* m_pImageModified;

    cv::Mat* m_pMatSource;
    cv::Mat* m_pMatMedianBlur;
};

#endif // IMAGEMANIPULATOR_H
