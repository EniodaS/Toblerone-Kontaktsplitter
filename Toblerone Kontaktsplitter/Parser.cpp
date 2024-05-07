#include "pch.h"
#include "Parser.h"

#include <string>        
#include <vector>        
#include <sstream>       
#include <msclr/marshal_cppstd.h> 


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

Parser::Parser(DataClass^ dataClass)
{
	listeAnrede = dataClass->getAnrede();
	listeBriefAnrede = dataClass->getBriefAnrede();
	listeTitel = dataClass->getTitel();
	listeGeschlecht = dataClass->getGeschlecht();
	listeNachnamenZusatz = dataClass->getNachnamen();
}

Kontakt^ Parser::parseEingabe(String^ eingabeString)
{
	Kontakt^ kontakt = gcnew Kontakt();

	// Zerlege eingabeString in Liste von Wörtern, getrennt nach Leerzeichen
	List<String^>^ worte = gcnew List<String^>(eingabeString->Split(' '));

	// Schleife für jedes Wort des eingabeStrings
	for each (String ^ wort in worte) {

		bool matchFound = false;

		// Check, ob Wort eine Anrede ist
		for each (String ^ anredeItem in listeAnrede) { // sinnlos? xD sind halt zwei Werte
			if (wort == anredeItem) {

				matchFound = true;
				kontakt->setAnrede(wort);

				// Setzen des Geschlechts auf Basis der Anrede
				if (wort == "Herr")
				{
					kontakt->setGeschlecht("Männlich");
					Debug::WriteLine(anredeItem + " set as Anrede, Geschlecht set to Männlich");
				}
				else if (wort == "Frau")
				{
					kontakt->setGeschlecht("Weiblich");
					Debug::WriteLine(anredeItem + " set as Anrede, Geschlecht set to Weiblich");
				}
				else {
					kontakt->setGeschlecht("X"); // TODO: wird nie ausgeführt?
				}
			}
		}

		// Check, ob Wort ein Titel ist
		for each (String ^ titelItem in listeTitel) {
			if (wort == titelItem) {

				matchFound = true;

				if (kontakt->getTitel1() == "")
				{
					kontakt->setTitel1(titelItem);
					Debug::WriteLine(titelItem + " set as Titel1");
				}
				else if (kontakt->getTitel2() == "")
				{
					kontakt->setTitel2(titelItem);
					Debug::WriteLine(titelItem + " set as Titel2");
				}
				else {
					// Eingabestring ist invalid, da mehr als zwei Titel erkannt
					// TODO: set invalid
				}
			}
		}

		// Check, ob Wort ein Präfix ist
		for each (String ^ praefixItem in listeNachnamenZusatz) {
			if (wort == praefixItem) {

				matchFound = true; // TODO: remember last match was nachname präfix

				if (kontakt->getNachname1() == "")
				{
					kontakt->setNachname1(praefixItem);
					Debug::WriteLine(praefixItem + " set as Nachname1 Präfix");
				}
				else if (kontakt->getNachname2() == "")
				{
					kontakt->setNachname2(praefixItem);
					Debug::WriteLine(praefixItem + " set as Nachname2 Präfix");
				}
				else {
					// Eingabestring ist invalid, da Präfix bei bereits zwei gesetzten Nachnamen erkannt wurde
					// TODO: set invalid
				}
			}
		}

		// Wenn keine Übereinstimmung des Wortes gefunden wurde, muss es sich um einen Vor- oder Nachnamen handeln
		if (!matchFound) {

			if (wort[wort->Length - 1] == ',')
			{
				// TODO: check if nachname is already set
				// Ist der letzte Character des Worts ein Komma, handelt es sich um den Nachnamen
				System::String^ wortOhneKomma = wort->Substring(0, wort->Length - 1);
				kontakt->setNachname1(wortOhneKomma); // TODO: check if double name
				Debug::WriteLine(wort + " set as Nachname1");
			}
			else if (kontakt->getVorname1() == "")
			{
				// Ist bisher kein Vorname gesetzt, handelt es sich um den Vornamen
				kontakt->setVorname1(wort); // TODO: check for double name
				Debug::WriteLine(wort + " set as Vorname1");
			}
			else if (kontakt->getNachname1() == "")
			{
				// Ist bereits ein Vorname aber kein Nachname gesetzt, handelt es sich um den Nachnamen
				kontakt->setNachname1(wort); // TODO: check for double name
				Debug::WriteLine(wort + " set as Nachname1");
			}
			else
			{
				// Eingabestring ist invalid, da mehrere, nicht durch Bindestrich getrennte Namen gefunden wurden
				// TODO: set invalid           
			}
		}
	}

	Debug::WriteLine("Scanned eingabeString as " + kontakt);
	return kontakt;
}

String^ Parser::generateAusgabe(Kontakt^ kontakt)
{
	String^ ausgabeString = "";

	// Setzen des Anrede im ausgabeString
	if (kontakt->getGeschlecht() == "Männlich")
	{
		ausgabeString += "Sehr geehrter Herr";
	}
	else if (kontakt->getGeschlecht() == "Weiblich")
	{
		ausgabeString += "Sehr geehrte Frau";
	}
	else
	{
		ausgabeString += "Sehr geehrte*r";
	}

	// Setzen der Titel im ausgabeString
	if (kontakt->getTitel1() != "")
	{
		if (kontakt->getTitel2() != "")
		{
			ausgabeString += " " + kontakt->getTitel1() + " " + kontakt->getTitel2();
		}
		else
		{
			ausgabeString += " " + kontakt->getTitel1();
		}
	}

	// Setzen des Vornamens im ausgabeString
	if (kontakt->getVorname1() != "")
	{
		if (kontakt->getVorname2() != "")
		{
			ausgabeString += " " + kontakt->getVorname1() + "-" + kontakt->getVorname2();
		}
		else
		{
			ausgabeString += " " + kontakt->getVorname1();
		}
	}

	// Setzen des Nachnamens im ausgabeString
	if (kontakt->getNachname1() != "")
	{
		if (kontakt->getNachname2() != "")
		{
			ausgabeString += " " + kontakt->getNachname1() + "-" + kontakt->getNachname2();
		}
		else
		{
			ausgabeString += " " + kontakt->getNachname1();
		}
	}

	Debug::WriteLine("Generated AusgabeString as " + ausgabeString);
	return ausgabeString;
}