#ifndef __BT_HC05_H__
#define __BT_HC05_H__
#include <Arduino.h>


class bt_hc05
{
    private:
        
    public:
        bt_hc05();
        void init(const uint32_t& baudrate);
        void write_bt(const String& s);
        ~bt_hc05();
};




#endif
