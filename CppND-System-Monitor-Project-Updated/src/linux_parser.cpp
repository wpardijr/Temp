#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

#include <iostream>

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() 
{
	string line;
	string key;
	string value;
  
	std::ifstream filestream(kOSPath);
  
	if(filestream.is_open()) 
	{
		while(std::getline(filestream, line)) 
		{
			std::replace(line.begin(), line.end(), ' ', '_');
			std::replace(line.begin(), line.end(), '=', ' ');
			std::replace(line.begin(), line.end(), '"', ' ');
			std::istringstream linestream(line);
      
			while(linestream >> key >> value) 
			{
				if(key == "PRETTY_NAME") 
				{
					std::replace(value.begin(), value.end(), '_', ' ');
          
					return value;
				}
			}
		}
	}
	
	return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() 
{
	string os, version, kernel;
	string line;
  
	std::ifstream stream(kProcDirectory + kVersionFilename);
  
	if(stream.is_open()) 
	{
		std::getline(stream, line);
		std::istringstream linestream(line);
    
		linestream >> os >> version >> kernel;
	}
  
	return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() 
{
	vector<int> pids;
  
	DIR* directory = opendir(kProcDirectory.c_str());
  
	struct dirent* file;
  
	while((file = readdir(directory)) != nullptr) 
	{
		// Is this a directory?
		if(file->d_type == DT_DIR) 
		{
			// Is every character of the name a digit?
			string filename(file->d_name);
      
			if(std::all_of(filename.begin(), filename.end(), isdigit)) 
			{
				int pid = stoi(filename);
        
				pids.push_back(pid);
			}
		}
	}
  
	closedir(directory);
  
	return pids;
}

string LinuxParser::ProcessesStatistics(string keyword)
{
	string line;
	string key;
	string value;
  
	std::ifstream filestream(kProcDirectory + kStatFilename);
  
	if(filestream.is_open()) 
	{
		while(std::getline(filestream, line)) 
		{	
			std::istringstream linestream(line);
				
			while(linestream >> key >> value) 
			{
				if(key == keyword)
					return value;
			}
		}
	}
	
	return value;
}

vector<string> LinuxParser::CpuStatistics(string keyword)
{ 
	string line;
	string value;
	vector<string> cpu_usage(10);
  
	std::ifstream filestream(kProcDirectory + kStatFilename);
  
	if(filestream.is_open()) 
	{
		while(std::getline(filestream, line)) 
		{	
			std::istringstream linestream(line);
			
			linestream >> value;
			
			if(value == keyword)
			{
				linestream >> cpu_usage[LinuxParser::kUser_] >> cpu_usage[LinuxParser::kNice_] >> cpu_usage[LinuxParser::kSystem_] >>
				cpu_usage[LinuxParser::kIdle_] >> cpu_usage[LinuxParser::kIOwait_] >> cpu_usage[LinuxParser::kIRQ_] >> cpu_usage[LinuxParser::kSoftIRQ_] >>
				cpu_usage[LinuxParser::kSteal_] >> cpu_usage[LinuxParser::kGuest_] >> cpu_usage[LinuxParser::kGuestNice_];
				
				//std::cout << "kUser_ = " << cpu_usage[LinuxParser::kUser_] << "\n";
				//std::cout << "kNice_ = " << cpu_usage[LinuxParser::kNice_] << "\n";
				//std::cout << "kSystem_ = " << cpu_usage[LinuxParser::kSystem_] << "\n";
				//std::cout << "kIdle_ = " << cpu_usage[LinuxParser::kIdle_] << "\n";
				//std::cout << "kIOwait_ = " << cpu_usage[LinuxParser::kIOwait_] << "\n";
				//std::cout << "kIRQ_ = " << cpu_usage[LinuxParser::kIRQ_] << "\n";
				//std::cout << "kSoftIRQ_ = " << cpu_usage[LinuxParser::kSoftIRQ_] << "\n";
				//std::cout << "kSteal_ = " << cpu_usage[LinuxParser::kSteal_] << "\n";
				//std::cout << "kGuest_ = " << cpu_usage[LinuxParser::kGuest_] << "\n";
				//std::cout << "kGuestNice_ = " << cpu_usage[LinuxParser::kGuestNice_] << "\n";
				
				return cpu_usage;
			} 
		}
	}
	
	return cpu_usage;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { return 0.0; }

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { return 0; }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization(int cpuNumber)
{ 
	vector<string> cpu_statistics(10);
	
	switch(cpuNumber)
	{
		case 0:
		{
			cpu_statistics = LinuxParser::CpuStatistics("cpu0");
			
			break;
		}
		case 1:
		{
			cpu_statistics = LinuxParser::CpuStatistics("cpu1");
			
			break;
		}
		case 2:
		{
			cpu_statistics = LinuxParser::CpuStatistics("cpu2");
			
			break;
		}	
		case 3:
		{
			cpu_statistics = LinuxParser::CpuStatistics("cpu3");
			
			break;
		}
		default:
		{
			cpu_statistics = LinuxParser::CpuStatistics("cpu");
			
			break;
		}
	}
	
	//std::cout << "kUser_statistics = " << cpu_statistics[0] << "\n";
	//std::cout << "kNice_statistics = " << cpu_statistics[1] << "\n";
	//std::cout << "kSystem_statistics = " << cpu_statistics[2] << "\n";
	//std::cout << "kIdle_statistics = " << cpu_statistics[3] << "\n";
	//std::cout << "kIOwait_statistics = " << cpu_statistics[4] << "\n";
	//std::cout << "kIRQ_statistics = " << cpu_statistics[5] << "\n";
	//std::cout << "kSoftIRQ_statistics = " << cpu_statistics[6] << "\n";
	//std::cout << "kSteal_statistics = " << cpu_statistics[7] << "\n";
	//std::cout << "kGuest_statistics = " << cpu_statistics[8] << "\n";
	//std::cout << "kGuestNice_statistics = " << cpu_statistics[9] << "\n";
	
	//return {};
	return cpu_statistics;
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() 
{ 
	int number = stoi(LinuxParser::ProcessesStatistics("processes"));
	
	return number;
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() 
{
	int number = stoi(LinuxParser::ProcessesStatistics("procs_running"));
	
	return number;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid[[maybe_unused]]) { return 0; }
