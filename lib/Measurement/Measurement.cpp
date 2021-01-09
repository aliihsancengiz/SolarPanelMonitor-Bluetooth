#include "Measurement.h"


Measurement_t Measurement::getData()
{
    Measurement_t mData;
    mData.voltage=analogRead(A0)/204.66f; // Convert it to Voltage
    
    return mData;
}
