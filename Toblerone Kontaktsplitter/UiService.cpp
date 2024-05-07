#include "pch.h"
#include "UiService.h"

using namespace System;
using namespace System::Collections::Generic;

UiService::UiService(DataClass^ data)
{
	dataClass = data; // TODO: data class hier sinnlos?
	parser = gcnew Parser(dataClass);
}

void UiService::scan(String^ eingabeString)
{
	// TODO: fix Eingabe mit vielen Leerzeichen führt zu Error
	kontakt = parser->parseEingabe(eingabeString);

	ausgabeString = parser->generateAusgabe(kontakt);
}

void UiService::update()
{
	// TODO: fix update leerer Angaben generiert nur Briefanrede
	ausgabeString = parser->generateAusgabe(kontakt);
}

void UiService::save()
{
	// TODO implement Speichern neue Titel
	kontakt = gcnew Kontakt();

	ausgabeString = "";
}

String^ UiService::getAusgabe()
{
	return ausgabeString;
}

// Getter- und Setter-Methoden für Kontakt-Objekt
System::String^ UiService::getAnrede()
{
	return kontakt->getAnrede();
}

System::String^ UiService::getGeschlecht()
{
	return kontakt->getGeschlecht();
}

System::String^ UiService::getTitel1()
{
	return kontakt->getTitel1();
}

System::String^ UiService::getTitel2()
{
	return kontakt->getTitel2();
}

System::String^ UiService::getVorname1()
{
	return kontakt->getVorname1();
}

System::String^ UiService::getVorname2()
{
	return kontakt->getVorname2();
}

System::String^ UiService::getNachname1()
{
	return kontakt->getNachname1();
}

System::String^ UiService::getNachname2()
{
	return kontakt->getNachname2();
}

void UiService::setAnrede(System::String^ anrede)
{
	kontakt->setAnrede(anrede);
}

void UiService::setGeschlecht(System::String^ geschlecht)
{
	kontakt->setGeschlecht(geschlecht);
}

void UiService::setTitel1(System::String^ titel1)
{
	kontakt->setTitel1(titel1);
}

void UiService::setTitel2(System::String^ titel2)
{
	kontakt->setTitel2(titel2);
}

void UiService::setVorname1(System::String^ vorname1)
{
	kontakt->setVorname1(vorname1);
}

void UiService::setVorname2(System::String^ vorname2)
{
	kontakt->setVorname2(vorname2);
}

void UiService::setNachname1(System::String^ nachname1)
{
	kontakt->setNachname1(nachname1);
}

void UiService::setNachname2(System::String^ nachname2)
{
	kontakt->setNachname2(nachname2);
}