#ifndef NICANDRIVER_H
#define NICANDRIVER_H

#include <QStringList>
#include <stdint.h>

extern "C"
{
#include "nican.h"
}

class NiCanDriver
{
public:
    NiCanDriver();
    ~NiCanDriver();

    static QStringList GetListOfInterfaces(void);

    void Open(QString interfaceName);
    void Close(void);
    void Write(void);
private:
    NCTYPE_OBJH canHandle;
    bool isOpen;
};

#endif // NICANDRIVER_H
