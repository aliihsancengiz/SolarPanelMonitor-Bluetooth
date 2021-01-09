#include "MovingAverageFilter.h"



Filter::Filter()
{
	for(int i=0;i<FILTER_ORDER;i++)
	{
		Voltage[i]=0.0f;
        Temprature[i]=0.0f;
        Humudity[i]=0.0f;
	}
	this->index=0;	
}
void Filter::push_measurementValue(const Measurement_t& val)
{
	Voltage[index]=val.voltage;
    Temprature[index]=val.temprature;
    Humudity[index]=val.humudity;
	index++;
	index=index%FILTER_ORDER;
}

Measurement_t Filter::getSample()
{
	float sumV{0},sumC{0},sumH{0};
    Measurement_t newSample;
	for(int i=0;i<FILTER_ORDER;i++)
	{
		sumV+=Voltage[i];
		sumC+=Temprature[i];
		sumH+=Humudity[i];
	}
	newSample.voltage =sumV/(float)(FILTER_ORDER);
	newSample.temprature =sumC/(float)(FILTER_ORDER);
	newSample.humudity =sumH/(float)(FILTER_ORDER);
    return newSample;
}