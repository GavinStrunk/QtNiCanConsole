#ifndef NICANDRIVER_H
#define NICANDRIVER_H


extern "C"
{
#include "nican.h"
}

class NiCanDriver
{
public:
    NiCanDriver();
    ~NiCanDriver();

private:
    NCTYPE_OBJH canHandle;
};

#endif // NICANDRIVER_H
