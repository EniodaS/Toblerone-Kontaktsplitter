#pragma once
#include "Parser.h"

public ref class UiService
{
private:

	Parser^ parser;

	DataClass^ dataClass; 

	Kontakt^ kontakt = gcnew Kontakt();

	System::String^ ausgabeString;

public:

	UiService(DataClass^ data);

	void scan(System::String^ eingabeString);

	void update();

	void save();

	bool getValidity();

	System::String^ getAusgabe();

	// Getter- und Setter-Methoden für Kontakt
	System::String^ getAnrede();
	System::String^ getGeschlecht();
	System::String^ getTitel1();
	System::String^ getTitel2();
	System::String^ getVorname1();
	System::String^ getVorname2();
	System::String^ getNachname1();
	System::String^ getNachname2();

	void setAnrede(System::String^ anrede);
	void setGeschlecht(System::String^ geschlecht);
	void setTitel1(System::String^ titel1);
	void setTitel2(System::String^ titel2);
	void setVorname1(System::String^ vorname1);
	void setVorname2(System::String^ vorname2);
	void setNachname1(System::String^ nachname1);
	void setNachname2(System::String^ nachname2);
};