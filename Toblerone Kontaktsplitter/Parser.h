#pragma once
#include "DataClass.h"


ref class Parser
{
private:

	// Variabeln aus denen die Ausgabe generiert wird
	System::String^ anrede = "";
	System::String^ titel1 = "";
	System::String^ titel2 = "";
	System::String^ vorname = "";
	System::String^ nachname = "";
	System::String^ geschlecht = "";
	System::String^ briefAnrede = "";


	// Hilfsdaten für das Parsen
	System::Collections::Generic::List<System::String^>^ listeBriefAnrede;
	System::Collections::Generic::List<System::String^>^ listeAnrede;
	System::Collections::Generic::List<System::String^>^ listeTitel;
	System::Collections::Generic::List<System::String^>^ listeGeschlecht;
	System::Collections::Generic::List<System::String^>^ listeNachnamenZusatz;

public:

	Parser(DataClass^ dataClass);

	void parseEingabe(System::String^ eingabeString);

	System::String^ getAnrede();
	System::String^ getTitel1();
	System::String^ getTitel2();
	System::String^ getVorname();
	System::String^ getNachname();
	System::String^ getGeschlecht();
	System::String^ getBriefAnrede();

};

