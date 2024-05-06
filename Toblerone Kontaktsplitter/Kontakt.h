#pragma once
ref class Kontakt
{
private:

	System::String^ anrede = "";
	System::String^ titel1 = "";
	System::String^ titel2 = "";
	System::String^ vorname = "";
	System::String^ nachname = "";
	System::String^ geschlecht = "";
	System::String^ briefAnrede = "";

public:
	Kontakt(System::String^ anrede, System::String^ titel1, System::String^ titel2, System::String^ vorname, System::String^ nachname, System::String^ geschlecht, System::String^ briefAnrede );

	System::String^ getAnrede();
	System::String^ getTitel1();
	System::String^ getTitel2();
	System::String^ getVorname();
	System::String^ getNachname();
	System::String^ getGeschlecht();
	System::String^ getBriefAnrede();
};

