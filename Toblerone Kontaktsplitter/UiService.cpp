#include "pch.h"
#include "UiService.h"

using namespace System;
using namespace System::Collections::Generic;

UiService::UiService(DataClass^ data)
{
	dataClass = data; 
	parser = gcnew Parser(dataClass);
}

void UiService::scan(String^ eingabeString)
{



	if (eingabeString == "") {
		return;
	}


	
	//wiederholte Leerzeichen, Kommas, Bindestriche und Punkte werden gekürzt
	System::Text::RegularExpressions::Regex^ regexSpace = gcnew System::Text::RegularExpressions::Regex("\\s+");
	System::Text::RegularExpressions::Regex^ regexDot = gcnew System::Text::RegularExpressions::Regex("\\.+");
	System::Text::RegularExpressions::Regex^ regexComma = gcnew System::Text::RegularExpressions::Regex(",+");
	System::Text::RegularExpressions::Regex^ regexHyphen = gcnew System::Text::RegularExpressions::Regex("-+");

	eingabeString = regexSpace->Replace(eingabeString, " ");
	eingabeString = regexDot->Replace(eingabeString, ".");
	eingabeString = regexComma->Replace(eingabeString, ",");
	eingabeString = regexHyphen->Replace(eingabeString, "-");



	// parse Eingabe
	kontakt = parser->parseEingabe(eingabeString);
	ausgabeString = parser->generateAusgabe(kontakt);

	//überprüfe ob ein Buchstabe vorhanden ist
	System::Text::RegularExpressions::Regex^ regexHasLetter = gcnew System::Text::RegularExpressions::Regex("[a-zA-Z]");
	if (!regexHasLetter->IsMatch(eingabeString))
	{
		kontakt->setValid(false);
	}

}

void UiService::update()
{

	ausgabeString = parser->generateAusgabe(kontakt);
}

void UiService::save()
{
	//neuen Titel hinzufügen
	if (!dataClass->getTitel()->Contains(kontakt->getTitel1()))
	{
		dataClass->addTitel(kontakt->getTitel1());
	}

	if (!dataClass->getTitel()->Contains(kontakt->getTitel2()))
	{
		dataClass->addTitel(kontakt->getTitel1());
	}


	//an dieser Stelle könnte die Datenbankanbindung sein

	kontakt = gcnew Kontakt();

	ausgabeString = "";
}

bool UiService::getValidity()
{
	return kontakt->isValid();
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