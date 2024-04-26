#pragma once
#include "Parser.h"
ref class Service
{
private: 
	Parser^ parser;
public:

	Service() 
	{
		parser = gcnew Parser();
	}

	void scan();

	void update();

	void save();
};

