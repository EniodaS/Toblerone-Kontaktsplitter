#pragma once
public ref class Kontakt
{
private:

	System::String^ anrede;
	System::String^ geschlecht;
	System::String^ titel1;
	System::String^ titel2;
	System::String^ vorname1;
	System::String^ vorname2;
	System::String^ nachname1;
	System::String^ nachname2;

	bool valid;

public:

	Kontakt(System::String^ anrede, System::String^ geschlecht, System::String^ titel1, System::String^ titel2, System::String^ vorname1, System::String^ vorname2, System::String^ nachname1, System::String^ nachname2);
	Kontakt(System::String^ anrede, System::String^ geschlecht, System::String^ titel1, System::String^ titel2, System::String^ vorname1, System::String^ vorname2, System::String^ nachname1, System::String^ nachname2, bool valid);
	Kontakt();

	void addTitel1(System::String^ titel1);
	void addTitel2(System::String^ titel2);
	void addVorname1(System::String^ vorname1);
	void addVorname2(System::String^ vorname2);
	void addNachname1(System::String^ nachname1);
	void addNachname2(System::String^ nachname2);

	void setAnrede(System::String^ anrede);
	void setGeschlecht(System::String^ geschlecht);
	void setTitel1(System::String^ titel1);
	void setTitel2(System::String^ titel2);
	void setVorname1(System::String^ vorname1);
	void setVorname2(System::String^ vorname2);
	void setNachname1(System::String^ nachname1);
	void setNachname2(System::String^ nachname2);
	void setValid(bool valid);

	System::String^ getAnrede();
	System::String^ getGeschlecht();
	System::String^ getTitel1();
	System::String^ getTitel2();
	System::String^ getVorname1();
	System::String^ getVorname2();
	System::String^ getNachname1();
	System::String^ getNachname2();
	bool isValid();
};