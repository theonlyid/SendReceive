#ifndef SERIALREADWRITE_H
#define SERIALREADWRITE_H
#include <QByteArray>
#include <QSerialPort>


class SerialReadWrite
{
public:

    SerialReadWrite();
    void write(QSerialPort serial, QByteArray dataFrame);

protected:


private:


};

#endif // SERIALREADWRITE_H
