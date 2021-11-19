#ifndef PROCESSOR_H
	#define PROCESSOR_H
	
	#include <string>
	#include <vector>
	
	#include "linux_parser.h"

	class Processor 
	{
		public:
			float Utilization(int number);  				// TODO: See src/processor.cpp
			long Idle(long idle, long io_wait);
			long NoIdle(long user, long nice, long system, long irq, long soft_irq, long steal, long guest, long guest_nice);

		// TODO: Declare any necessary private members
		private:
			long user;
			long nice;
			long system;
			long idle;
			long io_wait;
			long irq;
			long soft_irq;
			long steal;
			long guest;
			long guest_nice;
			
			long previous_totalNoIdleTime;
			long previous_totalIdleTime;
			
			long previous_totalNoIdleTime0;
			long previous_totalIdleTime0;
			
			long previous_totalNoIdleTime1;
			long previous_totalIdleTime1;
			
			long previous_totalNoIdleTime2;
			long previous_totalIdleTime2;
			
			long previous_totalNoIdleTime3;
			long previous_totalIdleTime3;
		
			int number;
	};
#endif