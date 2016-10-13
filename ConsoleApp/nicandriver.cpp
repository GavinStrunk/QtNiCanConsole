#include "nicandriver.h"
#include <QDebug>
NiCanDriver::NiCanDriver()
{
    isOpen = false;
}

NiCanDriver::~NiCanDriver()
{
    if(isOpen)
    {
        this->Close();
    }
}

QStringList NiCanDriver::GetListOfInterfaces()
{
    QStringList interfaces;
    NCTYPE_UINT32 numberOfCards, numberOfPorts, interfaceNumber;

    NCTYPE_STATUS retval = ncGetHardwareInfo(1,1,NC_ATTR_NUM_CARDS, \
                                             4, (NCTYPE_ANY_P)&numberOfCards);
    if(retval == 0)
    {
        for(uint32_t i = 1; i < (numberOfCards + 1); i++)
        {
            retval = ncGetHardwareInfo(i, 1, NC_ATTR_NUM_PORTS, \
                                       4, (NCTYPE_ANY_P)&numberOfPorts);
            for(uint32_t j = 1; j < (numberOfPorts + 1); j++)
            {
                retval = ncGetHardwareInfo(i,j,NC_ATTR_INTERFACE_NUM, \
                                           4, (NCTYPE_ANY_P)&interfaceNumber);
                interfaces << QString("CAN" + QString::number(interfaceNumber));
            }
        }
    }

    return interfaces;
}

void NiCanDriver::Open(QString interfaceName)
{
    NCTYPE_ATTRID attrList[8];
    NCTYPE_UINT32 attrValue[8];

    attrList[0]  = NC_ATTR_BAUD_RATE;
    attrValue[0] = 1000000;
    attrList[1]  = NC_ATTR_START_ON_OPEN;
    attrValue[1] = NC_TRUE;
    attrList[2]  = NC_ATTR_READ_Q_LEN;
    attrValue[2] = 150;
    attrList[3]  = NC_ATTR_WRITE_Q_LEN;
    attrValue[3] = 10;
    attrList[4]  = NC_ATTR_CAN_COMP_STD;
    attrValue[4] = 0;
    attrList[5]  = NC_ATTR_CAN_MASK_STD;
    attrValue[5] = NC_CAN_MASK_STD_DONTCARE;
    attrList[6]  = NC_ATTR_CAN_COMP_XTD;
    attrValue[6] = 0;
    attrList[7]  = NC_ATTR_CAN_MASK_XTD;
    attrValue[7] = NC_CAN_MASK_XTD_DONTCARE;

    QByteArray comName = interfaceName.toLatin1();
    char *pcomName = comName.data();

    NCTYPE_STATUS retval = ncConfig(pcomName, 8, attrList, attrValue);
    if(retval)
    {
        qDebug() << "Failed to configure the can port";
    }

    retval = ncOpenObject(pcomName, &canHandle);
    if(retval)
    {
        qDebug() << "Failed to open the can port";
    }
    else
    {
        isOpen = true;
    }
}

void NiCanDriver::Close()
{
    ncCloseObject(canHandle);
    isOpen = false;
}

void NiCanDriver::Write()
{
    if(!isOpen)
    {
        qDebug() << "Isn't open";
        return;
    }

    NCTYPE_CAN_FRAME frame;
    frame.ArbitrationId = 0x123456 | NC_FL_CAN_ARBID_XTD;
    frame.DataLength = 8;
    frame.IsRemote = NC_FALSE;
    frame.Data[0] = 0x12;
    frame.Data[1] = 0x23;
    frame.Data[2] = 0x34;
    frame.Data[3] = 0x35;
    frame.Data[4] = 0x36;
    frame.Data[5] = 0x37;
    frame.Data[6] = 0x38;
    frame.Data[7] = 0x39;

    long int success = ncWrite(canHandle, sizeof(NCTYPE_CAN_FRAME), &frame);
    if(success != 0)
    {
        qDebug() << "Can write failed";
    }
}
