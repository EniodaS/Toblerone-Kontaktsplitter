#pragma once
ref class Kontakt
{
private:

	System::String^ anrede = "";
	System::String^ titel1 = "";
	System::String^ titel2 = "";
	System::String^ vorname1 = "";
	System::String^ vorname2 = "";
	System::String^ nachname1 = "";
	System::String^ nachname2 = "";
	System::String^ geschlecht = "";

public:

	Kontakt(System::String^ anrede, System::String^ titel1, System::String^ titel2, System::String^ vorname1, System::String^ vorname2, System::String^ nachname1, System::String^ nachname2, System::String^ geschlecht);
	Kontakt();

	System::String^ getAnrede();
	System::String^ getTitel1();
	System::String^ getTitel2();
	System::String^ getVorname1();
	System::String^ getVorname2();
	System::String^ getNachname1();
	System::String^ getNachname2();
	System::String^ getGeschlecht();

	void setAnrede(System::String^ anrede);
	void setTitel1(System::String^ titel1);
	void setTitel2(System::String^ titel2);
	void setVorname1(System::String^ vorname1);
	void setVorname2(System::String^ vorname2);
	void setNachname1(System::String^ nachname1);
	void setNachname2(System::String^ nachname2);
	void setGeschlecht(System::String^ geschlecht);
};

