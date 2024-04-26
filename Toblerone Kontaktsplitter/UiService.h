#pragma once
#include "Parser.h"


ref class UiService
{
private:
	Parser^ parser;
	DataClass^ dataClass;

public:

	UiService(DataClass^ data);

	void scan(System::String^ eingabeString);

	Parser^ getParser();

	void update();

	void save();

};


