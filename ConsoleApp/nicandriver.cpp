#include "nicandriver.h"
#include <QDebug>
NiCanDriver::NiCanDriver()
{


    NCTYPE_UINT32 serialNumber;
    NCTYPE_UINT32 numberOfCards;

    NCTYPE_STATUS retval = ncGetHardwareInfo(1,1,NC_ATTR_NUM_CARDS, \
                                             4, (NCTYPE_ANY_P)&numberOfCards);
    retval = ncGetHardwareInfo(1, 1, NC_ATTR_HW_SERIAL_NUM, \
                                             4, (NCTYPE_ANY_P)&serialNumber);

    qDebug() << "Number of cards = " << numberOfCards;
    qDebug() << "Serial Number" << QString::number(serialNumber, 16);
    qDebug() << "Return Value = " << retval;

}

NiCanDriver::~NiCanDriver()
{

}
