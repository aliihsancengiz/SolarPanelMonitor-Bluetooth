#include "MobilAppProtocol.h"


MobileAppProtocolWrapper::MobileAppProtocolWrapper()
{
    startTag="E";
    Seperator=",";
    endTag="\n";
}
String MobileAppProtocolWrapper::getSerializedString(float voltage,float current,float humidity)
{
    // char ss[40];

    // sprintf(ss,"E%f,%f,%f\r\n",5.2,4.1,2.3);
    String s;
    s+=startTag;
    s+=String(voltage,3);
    s+=Seperator;
    s+=String(current,3);
    s+=Seperator;
    s+=String(humidity,3);
    s+=endTag;
    return s;
}