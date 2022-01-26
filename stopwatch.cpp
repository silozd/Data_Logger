#include "stopwatch.h"

stopwatch::stopwatch() :
    mRunning(false),
    mTotalTime(0),
    mTempTime(0)
{
}

void stopwatch::start()
{
    mStartTime = QDateTime::currentDateTime();
    mRunning = true;
}
void stopwatch::pause()
{
    mTotalTime += mTempTime;
    mRunning = false;
}
void stopwatch::resume()
{
    mRunning = true;
}
void stopwatch::reset()
{
    mTotalTime = 0;
    mRunning = false;
}
bool stopwatch::isRunning()
{
    return mRunning;
}
void stopwatch::setRunning(bool running)
{
    mRunning = running;
}
qint64 stopwatch::getTime()
{
    mTempTime = mStartTime.msecsTo(QDateTime::currentDateTime());
    qint64 time = mTotalTime + mTempTime;
    return time;
}
