#pragma once
#include "Parser.h"
#include "Kontakt.h"


public ref class UiService
{
private:
	Parser^ parser;
	DataClass^ dataClass;
	Kontakt^ kontakt;

public:

	UiService(DataClass^ data);

	void scan(System::String^ eingabeString);

	Parser^ getParser();

	void update();

	void save();

	Kontakt^ getKontakt();

};


