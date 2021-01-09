#ifndef __MEASUREMENT_H__
#define __MEASUREMENT_H__

#include <Arduino.h>
#include "DHT.h"

struct Measurement_t
{
    float voltage,temprature,humudity;
};



class Measurement
{
    private:
    public:
        Measurement(){  }
        ~Measurement(){}
        Measurement_t getData();

};



#endif