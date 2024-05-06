#include "pch.h"
#include "Kontakt.h"

Kontakt::Kontakt(System::String^ anrede, System::String^ titel1, System::String^ titel2, System::String^ vorname, System::String^ nachname, System::String^ geschlecht, System::String^ briefAnrede)
{
	this->anrede = anrede;
	this->titel1 = titel1;
	this->titel2 = titel2;
	this->vorname = vorname;
	this->nachname = nachname;
	this->geschlecht = geschlecht;
	this->briefAnrede = briefAnrede;
}

System::String^ Kontakt::getAnrede()
{
	return anrede;
}

System::String^ Kontakt::getTitel1()
{
	return titel1;
}

System::String^ Kontakt::getTitel2()
{
	return titel2;
}

System::String^ Kontakt::getVorname()
{
	return vorname;
}

System::String^ Kontakt::getNachname()
{
	return nachname;
}

System::String^ Kontakt::getGeschlecht()
{
	return geschlecht;
}

System::String^ Kontakt::getBriefAnrede()
{
	return briefAnrede;
}
