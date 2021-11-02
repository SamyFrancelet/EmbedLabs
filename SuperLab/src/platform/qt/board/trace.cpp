#include <config/trace-config.h>

#if (USE_PLATFORM_QT_TRACE != 0)

#include <QDebug>
#include <QTime>
#include "trace/trace.h"

#define ADD_CRLF_SEQU 	0

//static
void Trace::initialize()
{

}

void Trace::out(string str)
{
    QTime outTime = QTime::currentTime();
    string out = outTime.toString("HH:mm:ss.zzz").toStdString() + " : " + str;

    qDebug(out.data());
}

void Trace::out(const char * format, ...)
{
    char str[255];

    va_list args;

    va_start(args, format);
    vsprintf(str, format, args);
    va_end(args);

    QTime outTime = QTime::currentTime();
    string time = outTime.toString("HH:mm:ss.zzz").toStdString() + " : ";

    qDebug() << time.data() << str;
}

#endif // USE_PLATFORM_QT_TRACE
