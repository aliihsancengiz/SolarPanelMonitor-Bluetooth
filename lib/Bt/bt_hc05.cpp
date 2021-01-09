#include "bt_hc05.h"


bt_hc05::bt_hc05()
{
   
}

bt_hc05::~bt_hc05()
{
}
void bt_hc05::write_bt(const String& s)
{
    Serial.print(s);
}
void bt_hc05::init(const uint32_t& baudrate)
{
    Serial.begin(baudrate);
}

