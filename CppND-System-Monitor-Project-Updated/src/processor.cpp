#include "processor.h"

#include "linux_parser.h"

#include <string>
#include <vector>
#include <iostream>

long Processor::Idle(long idleTime, long ioWait)
{
	return idleTime + ioWait;
}

long Processor::NoIdle(long userTime, long niceTime, long systemTime, long irqTime, long soft_irqTime, long stealTime, long guestTime, long guestNiceTime)
{
	userTime = userTime - guestTime;
	niceTime = niceTime - guestNiceTime;
	
	return userTime + niceTime + systemTime + irqTime + soft_irqTime + stealTime;
}

// TODO: Return the aggregate CPU utilization
float Processor::Utilization(int number)
{	
	//long previous_totalNoIdleTime = 0;
	//long previous_totalIdleTime = 0;
	
	//std::vector<std::string> times = LinuxParser::CpuUtilization();
	//std::vector<std::string> times = LinuxParser::CpuUtilization(0);
	
	std::vector<std::string> times = LinuxParser::CpuUtilization(number);
	
	//float cpuPercentage;
	
	switch(number)
	{
		case 0:
		{
			long totalIdleTime0 = Idle(stol(times[LinuxParser::kIdle_]), stol(times[LinuxParser::kIOwait_]));	
			long totalNoIdleTime0 = NoIdle(stol(times[LinuxParser::kUser_]),stol(times[LinuxParser::kNice_]),stol(times[LinuxParser::kSystem_]),stol(times[LinuxParser::kIRQ_]),stol(times[LinuxParser::kSoftIRQ_]),stol(times[LinuxParser::kSteal_]),stol(times[LinuxParser::kGuest_]),stol(times[LinuxParser::kGuestNice_]));
	
			long totalTime0 = totalNoIdleTime0 + totalIdleTime0;
	
			long previous_totalTime0 = previous_totalIdleTime0 + previous_totalNoIdleTime0;
	
			long deltaIdleTime0 = totalIdleTime0 - previous_totalIdleTime0;
			long deltaTotalTime0 = totalTime0 - previous_totalTime0;
	
			float cpuPercentage0 = float(deltaTotalTime0 - deltaIdleTime0)/deltaTotalTime0;
	
			//std::cout << "cpuPercentage = " << cpuPercentage << "%\n";

			previous_totalNoIdleTime0 = totalNoIdleTime0;
			previous_totalIdleTime0 = totalIdleTime0;

			//return 0.0;
			return cpuPercentage0;
			
			break;
		}	
		case 1:
		{
			long totalIdleTime1 = Idle(stol(times[LinuxParser::kIdle_]), stol(times[LinuxParser::kIOwait_]));	
			long totalNoIdleTime1 = NoIdle(stol(times[LinuxParser::kUser_]),stol(times[LinuxParser::kNice_]),stol(times[LinuxParser::kSystem_]),stol(times[LinuxParser::kIRQ_]),stol(times[LinuxParser::kSoftIRQ_]),stol(times[LinuxParser::kSteal_]),stol(times[LinuxParser::kGuest_]),stol(times[LinuxParser::kGuestNice_]));
	
			long totalTime1 = totalNoIdleTime1 + totalIdleTime1;
	
			long previous_totalTime1 = previous_totalIdleTime1 + previous_totalNoIdleTime1;
	
			long deltaIdleTime1 = totalIdleTime1 - previous_totalIdleTime1;
			long deltaTotalTime1 = totalTime1 - previous_totalTime1;
	
			float cpuPercentage1 = float(deltaTotalTime1 - deltaIdleTime1)/deltaTotalTime1;
	
			//std::cout << "cpuPercentage = " << cpuPercentage << "%\n";

			previous_totalNoIdleTime1 = totalNoIdleTime1;
			previous_totalIdleTime1 = totalIdleTime1;

			//return 0.0;
			return cpuPercentage1;
		
			break;
		}
		case 2:
		{
			long totalIdleTime2 = Idle(stol(times[LinuxParser::kIdle_]), stol(times[LinuxParser::kIOwait_]));	
			long totalNoIdleTime2 = NoIdle(stol(times[LinuxParser::kUser_]),stol(times[LinuxParser::kNice_]),stol(times[LinuxParser::kSystem_]),stol(times[LinuxParser::kIRQ_]),stol(times[LinuxParser::kSoftIRQ_]),stol(times[LinuxParser::kSteal_]),stol(times[LinuxParser::kGuest_]),stol(times[LinuxParser::kGuestNice_]));
	
			long totalTime2 = totalNoIdleTime2 + totalIdleTime2;
	
			long previous_totalTime2 = previous_totalIdleTime2 + previous_totalNoIdleTime2;
	
			long deltaIdleTime2 = totalIdleTime2 - previous_totalIdleTime2;
			long deltaTotalTime2 = totalTime2 - previous_totalTime2;
	
			float cpuPercentage2 = float(deltaTotalTime2 - deltaIdleTime2)/deltaTotalTime2;
	
			//std::cout << "cpuPercentage = " << cpuPercentage << "%\n";

			previous_totalNoIdleTime2 = totalNoIdleTime2;
			previous_totalIdleTime2 = totalIdleTime2;

			//return 0.0;
			return cpuPercentage2;
		
			break;
		}
		case 3:
		{
			long totalIdleTime3 = Idle(stol(times[LinuxParser::kIdle_]), stol(times[LinuxParser::kIOwait_]));	
			long totalNoIdleTime3 = NoIdle(stol(times[LinuxParser::kUser_]),stol(times[LinuxParser::kNice_]),stol(times[LinuxParser::kSystem_]),stol(times[LinuxParser::kIRQ_]),stol(times[LinuxParser::kSoftIRQ_]),stol(times[LinuxParser::kSteal_]),stol(times[LinuxParser::kGuest_]),stol(times[LinuxParser::kGuestNice_]));
	
			long totalTime3 = totalNoIdleTime3 + totalIdleTime3;
	
			long previous_totalTime3 = previous_totalIdleTime3 + previous_totalNoIdleTime3;
	
			long deltaIdleTime3 = totalIdleTime3 - previous_totalIdleTime3;
			long deltaTotalTime3 = totalTime3 - previous_totalTime3;
	
			float cpuPercentage3 = float(deltaTotalTime3 - deltaIdleTime3)/deltaTotalTime3;
	
			//std::cout << "cpuPercentage = " << cpuPercentage << "%\n";

			previous_totalNoIdleTime3 = totalNoIdleTime3;
			previous_totalIdleTime3 = totalIdleTime3;

			//return 0.0;
			return cpuPercentage3;
		
			break;
		}
		default:
		{
			long totalIdleTime = Idle(stol(times[LinuxParser::kIdle_]), stol(times[LinuxParser::kIOwait_]));	
			long totalNoIdleTime = NoIdle(stol(times[LinuxParser::kUser_]),stol(times[LinuxParser::kNice_]),stol(times[LinuxParser::kSystem_]),stol(times[LinuxParser::kIRQ_]),stol(times[LinuxParser::kSoftIRQ_]),stol(times[LinuxParser::kSteal_]),stol(times[LinuxParser::kGuest_]),stol(times[LinuxParser::kGuestNice_]));
	
			long totalTime = totalNoIdleTime + totalIdleTime;
	
			long previous_totalTime = previous_totalIdleTime + previous_totalNoIdleTime;
	
			long deltaIdleTime = totalIdleTime - previous_totalIdleTime;
			long deltaTotalTime = totalTime - previous_totalTime;
	
			float cpuPercentage = float(deltaTotalTime - deltaIdleTime)/deltaTotalTime;
	
			//std::cout << "cpuPercentage = " << cpuPercentage << "%\n";

			previous_totalNoIdleTime = totalNoIdleTime;
			previous_totalIdleTime = totalIdleTime;

			//return 0.0;
			return cpuPercentage;
		
			break;
		}
	}
}