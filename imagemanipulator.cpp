#include "imagemanipulator.h"

ImageManipulator::ImageManipulator()
{
    m_pImageSource = new QImage;
    m_pImageModified = new QImage;

    m_pMatSource = new cv::Mat;
    m_pMatMedianBlur = new cv::Mat;
}

ImageManipulator::~ImageManipulator()
{
    delete m_pImageSource;
    delete m_pImageModified;

    delete m_pMatSource;
    delete m_pMatMedianBlur;
}

void ImageManipulator::startMedianBlur(QImage *img)
{
    m_pImageSource = img;
    QThread::start();
}

void ImageManipulator::stopProcessing()
{
    requestInterruption();
}

void ImageManipulator::run()
{
    *m_pMatSource = ASM::QImageToCvMat(*m_pImageSource);
    emit signal_percentPassed(10);

    cv::medianBlur(*m_pMatSource, *m_pMatMedianBlur, 21);
    emit signal_percentPassed(50);

    msleep(2000);
    if (!isInterruptionRequested())
    {
        *m_pImageModified = ASM::cvMatToQImage(*m_pMatMedianBlur);
        emit signal_percentPassed(100);
        emit signal_processFinished(m_pImageModified);
    }
}
