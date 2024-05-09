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
	this->valid = true;
}

Kontakt::Kontakt(System::String^ anrede, System::String^ geschlecht, System::String^ titel1, System::String^ titel2, System::String^ vorname1, System::String^ vorname2, System::String^ nachname1, System::String^ nachname2, bool isValid)
{
	this->anrede = anrede;
	this->geschlecht = geschlecht;
	this->titel1 = titel1;
	this->titel2 = titel2;
	this->vorname1 = vorname1;
	this->vorname2 = vorname2;
	this->nachname1 = nachname1;
	this->nachname2 = nachname2;
	this->valid = valid;
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
	this->valid = true;
}

void Kontakt::addTitel1(System::String^ titel1)
{
	this->titel1 = this->titel1 + " " + titel1;
}

void Kontakt::addTitel2(System::String^ titel2)
{
	this->titel2 = this->titel2 + " " + titel2;
}

void Kontakt::addVorname1(System::String^ vorname1)
{
	this->vorname1 = this->vorname1 + " " + vorname1;
}

void Kontakt::addVorname2(System::String^ vorname2)
{
	this->vorname2 = this->vorname2 + " " + vorname2;
}

void Kontakt::addNachname1(System::String^ nachname1)
{
	this->nachname1 = this->nachname1 + " " + nachname1;
}

void Kontakt::addNachname2(System::String^ nachname2)
{
	this->nachname2 = this->nachname2 + " " + nachname2;
}

// Setters- und Getter-Methoden
void Kontakt::setAnrede(System::String^ anrede)
{
	if (this->anrede != "")
	{
		this->valid = false;
	}
	this->anrede = anrede;
}

void Kontakt::setGeschlecht(System::String^ geschlecht)
{
	this->geschlecht = geschlecht;
}

void Kontakt::setTitel1(System::String^ titel1)
{
	if (this->titel1 != "")
	{
		this->valid = false;
	}
	this->titel1 = titel1;
}

void Kontakt::setTitel2(System::String^ titel2)
{
	if (this->titel2 != "")
	{
		this->valid = false;
	}
	this->titel2 = titel2;
}

void Kontakt::setVorname1(System::String^ vorname1)
{
	if (this->vorname1 != "")
	{
		this->valid = false;
	}
	this->vorname1 = vorname1;
}

void Kontakt::setVorname2(System::String^ vorname2)
{
	if (this->vorname2 != "")
	{
		this->valid = false;
	}
	this->vorname2 = vorname2;
}

void Kontakt::setNachname1(System::String^ nachname1)
{
	if (this->nachname1 != "")
	{
		this->valid = false;
	}
	this->nachname1 = nachname1;
}

void Kontakt::setNachname2(System::String^ nachname2)
{
	if (this->nachname2 != "")
	{
		this->valid = false;
	}
	this->nachname2 = nachname2;
}

void Kontakt::setValid(bool valid)
{
	this->valid = valid;
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

bool Kontakt::isValid()
{
	return valid;
}