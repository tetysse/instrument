#include "Instrument.h"

std::string Door::print_out() {
	std::cout << "Door name: " << i_name;
	std::string temp;
	if (i_pos == Position::On)
	{	temp = "Open"; }
	else	{	temp = "Closed"; }
	std::cout << "\tDoor status: " << temp << std::endl;
	return "Door";
}

std::string Light::print_out() {
	std::string temp;
	std::cout << "Light name: " << i_name;
	if (i_pos == Position::On)
	{	temp = "On";	}
	else	{	temp = "Off"; }
	std::cout << "\tCurrently: " << temp;
	std::cout << "\tLight: \%: " << (temp == "On" ? l_val : 0) << std::endl;
	return "Light";
}


std::string Coffe_Machine::print_out() {
	std::string temp;
	std::cout << "Light name: " << i_name;
	if (i_pos == Position::On)
	{	temp = "On"; }
	else { temp = "Off"; }
	std::cout << "\tCurrently: " << temp;
	std::cout << "\tDegree: " << (temp == "On" ? c_val : 0) << " \*C\n";
	return "Coffe Machine";
}

std::string Heater::print_out() {
	std::string temp;
	std::cout << "Heater name: " << i_name;
	if (i_pos == Position::On)
	{	temp = "On"; }
	else { temp = "Off"; }
	std::cout << "\tCurrently: " << temp;
	std::cout << "\tDegree: " << (temp == "On" ? h_val : 0) << "\*C\n";
	return "Heater";
}