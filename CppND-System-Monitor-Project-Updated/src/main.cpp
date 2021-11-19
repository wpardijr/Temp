#include "ncurses_display.h"
#include "system.h"

#include "linux_parser.h"
#include "processor.h"

#include <string>
#include <vector>
#include <iostream>

int main() 
{
	//Processor processor;
	
	//float processorUsage = processor.Utilization();
	
	System system;
	NCursesDisplay::Display(system);
	
	return 0;
}