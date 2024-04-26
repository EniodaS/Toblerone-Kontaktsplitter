#pragma once

using namespace System;
using namespace System::Diagnostics; // nur für debug zwecke
using namespace System::Collections::Generic;

#include "DataClass.h"

ref class Parser
{
private:

	// Variabeln aus denen die Ausgabe generiert wird
	String^ anrede;
	String^ titel1;
	String^ titel2;
	String^ vorname;
	String^ nachname;


	// Hilfsdaten für das Parsen
	List<String^>^ listeBriefAnrede; 
	List<String^>^ listeAnrede;
	List<String^>^ listeTitel;
	List<String^>^ listeGeschlecht;
	List<String^>^ listeNachnamenZusatz;

public:

	Parser(DataClass dataClass);

	void parseEingabe(String^ eingabeString);

};

