#include "pch.h"
#include "Kontakt.h"

Kontakt::Kontakt(System::String^ anrede, System::String^ geschlecht, System::String^ titel1, System::String^ titel2, System::String^ vorname1, System::String^ vorname2, System::String^ nachname1, System::String^ nachname2)
{
	this->anrede = anrede;
	this->geschlecht = geschlecht;
	this->titel1 = titel1;
	this->titel2 = titel2;
	this->vorname1 = vorname1;
	this->vorname2 = vorname2;
	this->nachname1 = nachname1;
	this->nachname2 = nachname2;
}

Kontakt::Kontakt()
{
	this->anrede = "";
	this->geschlecht = "";
	this->titel1 = "";
	this->titel2 = "";
	this->vorname1 = "";
	this->vorname2 = "";
	this->nachname1 = "";
	this->nachname2 = "";
}

System::String^ Kontakt::getAnrede()
{
	return anrede;
}

System::String^ Kontakt::getGeschlecht()
{
	return geschlecht;
}

System::String^ Kontakt::getTitel1()
{
	return titel1;
}

System::String^ Kontakt::getTitel2()
{
	return titel2;
}

System::String^ Kontakt::getVorname1()
{
	return vorname1;
}

System::String^ Kontakt::getVorname2()
{
	return vorname2;
}

System::String^ Kontakt::getNachname1()
{
	return nachname1;
}

System::String^ Kontakt::getNachname2()
{
	return nachname2;
}

void Kontakt::setAnrede(System::String^ anrede)
{
	this->anrede = anrede;
}

void Kontakt::setGeschlecht(System::String^ geschlecht)
{
	this->geschlecht = geschlecht;
}

void Kontakt::setTitel1(System::String^ titel1)
{
	this->titel1 = titel1;
}

void Kontakt::setTitel2(System::String^ titel2)
{
	this->titel2 = titel2;
}

void Kontakt::setVorname1(System::String^ vorname1)
{
	this->vorname1 = vorname1;
}

void Kontakt::setVorname2(System::String^ vorname2)
{
	this->vorname2 = vorname2;
}

void Kontakt::setNachname1(System::String^ nachname1)
{
	this->nachname1 = nachname1;
}

void Kontakt::setNachname2(System::String^ nachname2)
{
	this->nachname2 = nachname2;
}