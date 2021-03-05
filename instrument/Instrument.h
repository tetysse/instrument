#pragma once

#include <iostream>
#include <string>

enum class Position : bool { On, Off };

enum class Instrument_type : int { Door, Light, Coffe_Machine, Heater};
class Instrument
{
protected:
	std::string i_name;
	Instrument_type i_type;
	Position i_pos;
	int i_id;
public:
	Instrument(std::string name, int id, Position pos) : i_name{ name }, i_id{ id }, i_pos{pos}{};
	virtual std::string print_out() = 0;
	std::string get_name() { return i_name; };
	bool get_pos() {
		if (i_pos == Position::On) { return true; }
		else { return false; }
	}
};

class Door : public Instrument
{
protected:
public:
	Door(std::string name, int id, Position pos) : Instrument(name, id, pos){};
	std::string print_out();
};

class Light : public Instrument
{
protected:
	int l_val;
	bool l_dig;
public:
	Light(std::string name, int id, int status, Position pos, bool dig) : Instrument(name, id, pos)
	{	l_val = status, l_dig = dig;	};
	std::string print_out();
	int l_get_status() { return l_val; };
	bool l_get_dig() { return l_dig; };
};

class Heater : public Instrument
{
protected:
	int h_val;
public:
	Heater(std::string name, int id, int status, Position pos) : Instrument(name, id, pos)
	{	h_val = status; };
	std::string print_out();
};

class Coffe_Machine : public Instrument
{
protected:
	int c_val;
public:
	Coffe_Machine(std::string name, int id, int status, Position pos) : Instrument(name, id, pos)
	{	c_val = status; };
	std::string print_out();
};