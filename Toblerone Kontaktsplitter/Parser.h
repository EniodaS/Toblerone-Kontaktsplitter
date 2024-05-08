#pragma once
#include "DataClass.h"
#include "Kontakt.h"

public ref class Parser
{
private:

	// Vergleichsdaten für Erkennung der Eingabe-Bestandteile
	System::Collections::Generic::List<System::String^>^ listeBriefAnrede;
	System::Collections::Generic::List<System::String^>^ listeAnrede;
	System::Collections::Generic::List<System::String^>^ listeTitel;
	System::Collections::Generic::List<System::String^>^ listeGeschlecht;
	System::Collections::Generic::List<System::String^>^ listePraefixe;

public:

	Parser(DataClass^ dataClass);

	Kontakt^ parseEingabe(System::String^ eingabeString);

	System::String^ generateAusgabe(Kontakt^ kontakt);
};