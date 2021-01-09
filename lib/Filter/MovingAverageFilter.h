#ifndef __MOVING_AVERAGE_H__
#define __MOVING_AVERAGE_H__

#include <Measurement.h>

#define FILTER_ORDER 10

class Filter
{
	private:
		float Voltage[FILTER_ORDER],Temprature[FILTER_ORDER],Humudity[FILTER_ORDER];
		int index;
	public:
		Filter();
		void push_measurementValue(const Measurement_t& val);
		Measurement_t getSample();
		
};

#endif