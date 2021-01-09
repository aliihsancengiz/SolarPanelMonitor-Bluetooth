#ifndef __MOBILAPP_H__
#define __MOBILAPP_H__

#include <Arduino.h>
#include <stdint.h>

class MobileAppProtocolWrapper
{
    private:
        String startTag,Seperator,endTag;

    public:
        MobileAppProtocolWrapper();
        String getSerializedString(float voltage,float current,float humidity);

};

#endif
