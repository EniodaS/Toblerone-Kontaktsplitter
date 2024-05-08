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
	listeTitel = dataClass->getTitel();
	listePraefixe = dataClass->getPraefixe();
}

Kontakt^ Parser::parseEingabe(String^ eingabeString)
{
	Kontakt^ kontakt = gcnew Kontakt();

	// Zerlege eingabeString in Liste von Wörtern, getrennt nach Leerzeichen
	List<String^>^ worte = gcnew List<String^>(eingabeString->Split(' '));

	// Aussenstehende Variablen, um schleifen-übergreifend vorausgegangene, erkannte Wörter zu merken
	bool wasLastMatchTitel = false;
	bool wasLastMatchPraefix = false;
	bool wasLastCommaSeparated = false;

	// Schleife für jedes Wort des eingabeStrings
	for each (String^ wort in worte) 
	{
		// Schleifen-Variable zur Erkennung, ob eine Übereinstimmung des Wortes bereits gefunden wurde
		bool wordMatchFound = false;

		// Check, ob Wort eine Anrede ist ("Herr" oder "Frau") und Setzen des Geschlechts
		// Ist bereits eine Anrede gesetzt, wird das Wort als Name angenommen und in der Schleife weitergereicht
		if ((wort == "Herr" || wort == "Frau") && kontakt->getAnrede() == "")
		{
			kontakt->setAnrede(wort);

			if (wort == "Herr")
			{
				kontakt->setGeschlecht("Männlich");
				Debug::WriteLine("Herr set as Anrede, Männlich set as Geschlecht");
			}
			else // Wurde eine Anrede erkannt, die nicht "Herr" ist, muss es "Frau" sein
			{
				kontakt->setGeschlecht("Weiblich");
				Debug::WriteLine("Frau set as Anrede, Weiblich set as Geschlecht");
			}

			wordMatchFound = true;
			wasLastMatchTitel = false;
			wasLastMatchPraefix = false;
		}

		// TODO add explanation lol
		if (wasLastMatchTitel && wort[wort->Length - 1] == '.' && Char::IsLower(wort[0]))
		{
			if (kontakt->getTitel2() != "") 
			{
				kontakt->setTitel2(kontakt->getTitel2() + " " + wort);
			}
			else
			{
				kontakt->setTitel1(kontakt->getTitel1() + " " + wort);
			}

			wordMatchFound = true;
			wasLastMatchTitel = true;
			wasLastMatchPraefix = false;
		}
		// Check, ob Wort mit einem vordefinierten Titel übereinstimmt
		else for each (String^ titelItem in listeTitel) 
		{
			if (wort == titelItem) 
			{
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
				else 
				{
					// Eingabestring ist invalid, da mehr als zwei Titel erkannt
					kontakt->setValid(false);
					Debug::WriteLine(titelItem + " recognized as title but two titles are set already, inputstring is invalid");
				}

				wordMatchFound = true;
				wasLastMatchTitel = true;
				wasLastMatchPraefix = false;
			}
		}

		// Check, ob Wort ein Präfix ist
		for each (String ^ praefixItem in listePraefixe) 
		{
			if (wort == praefixItem) 
			{
				// Wenn letztes Wort Präfix und Nachname2 bereits gesetzt: dann weiterer Präfix von Nachname2
				if (wasLastMatchPraefix && kontakt->getNachname2() != "")
				{
					kontakt->setNachname2(kontakt->getNachname2() + " " + praefixItem);
					Debug::WriteLine(praefixItem + " added to Nachname2");

				}
				// Wenn letztes Wort Präfix und Nachname1 bereits gesetzt: dann weiterer Präfix von Nachname1
				if (wasLastMatchPraefix && kontakt->getNachname1() != "")
				{
					kontakt->setNachname1(kontakt->getNachname1() + " " + praefixItem);
					Debug::WriteLine(praefixItem + " added to Nachname1");
				}
				// Wenn letztes Wort kein Präfix und Nachname1 leer: dann gehört Präfix zu Nachname1
				else if (kontakt->getNachname1() == "")
				{
					kontakt->setNachname1(praefixItem);
					Debug::WriteLine(praefixItem + " set as Nachname1 Präfix");
				}
				// Wenn letztes Wort kein Präfix und Nachname2 leer: dann gehört Präfix zu Nachname2
				else if (kontakt->getNachname2() == "")
				{
					kontakt->setNachname2(praefixItem);
					Debug::WriteLine(praefixItem + " set as Nachname2 Präfix");
				}
				else 
				{
					// Eingabestring invalid: Präfix mit bereits zwei gesetzten Nachnamen ohne vorherigen Präfix erkannt
					kontakt->setValid(false);
					Debug::WriteLine(praefixItem + " recognized as praefix but two last names are set already, inputstring is invalid");
				}

				wordMatchFound = true;
				wasLastMatchTitel = false;
				wasLastMatchPraefix = true;
			}
		}

		// Wenn keine Übereinstimmung des Wortes gefunden: dann muss Wort ein Vor- oder Nachname sein
		if (!wordMatchFound) 
		{
			// Ist der letzte Character des Worts ein Komma, handelt es sich um den Nachnamen
			if (wort[wort->Length - 1] == ',')
			{
				wort = wort->Substring(0, wort->Length - 1);

				// Doppel-Nachnamen-Check
				if (wort->IndexOf('-') != -1)
				{
					System::String^ name1 = wort->Substring(0, wort->IndexOf('-'));
					System::String^ name2 = wort->Substring(wort->IndexOf('-') + 1);

					if (name2->IndexOf('-') != -1)
					{
						// Multi-Nachnamen mit mehr als zwei Bezeichnungen erkannt, Eingabe ist invalid
						// Multi-Nachname wird als mehrfacher zweiter Nachname behandelt
						kontakt->setValid(false);
						Debug::WriteLine(name2 + " recognized as multiple last names with more than two, inputstring is invalid");
					}

					// Vorläufiger Präfix erkannt: erster Nachname wird angehängt statt gesetzt
					if (wasLastMatchPraefix)
					{
						kontakt->setNachname1(kontakt->getNachname1() + " " + name1);
						Debug::WriteLine(name1 + " appended at Praefix of Nachname1");
					}
					else
					{
						kontakt->setNachname1(name1);
						Debug::WriteLine(name1 + " set as Nachname1");
					}

					kontakt->setNachname2(name2);
					Debug::WriteLine(name2 + " set as Nachname2");
				}
				else
				{
					// Vorläufiger Präfix erkannt: Nachname wird ans zuletzt gesetzte Feld angehängt statt gesetzt
					if (wasLastMatchPraefix)
					{
						if (kontakt->getNachname2() != "") 
						{
							kontakt->setNachname2(kontakt->getNachname2() + " " + wort);
							Debug::WriteLine(wort + " appended at Praefix of Nachname2");
						}
						else
						{
							kontakt->setNachname1(kontakt->getNachname1() + " " + wort);
							Debug::WriteLine(wort + " appended at Praefix of Nachname1");
						}
					}
					else
					{
						kontakt->setNachname1(wort);
						Debug::WriteLine(wort + " set as Nachname1");
					}
				}

				wasLastCommaSeparated = true;
			}
			// Es handelt es sich um einen Vornamen, sofern:
			//		- Das vorausgegangene Wort durch ein Komma getrennt war ODER
			//		- Bisher kein Vorname gesetzt ist UND
			//		- Das Wort nicht am Ende des Eingabestrings steht 
			//		  (als letzter Name der Eingabe ohne Vornamen wird davon ausgegangen, dass es sich um den Nachnamen handelt)
			else if (wasLastCommaSeparated || kontakt->getVorname1() == "" && wort != worte[worte->Count-1])
			{
				// Doppel-Vornamen-Check
				if (wort->IndexOf('-') != -1)
				{
					System::String^ name1 = wort->Substring(0, wort->IndexOf('-'));
					System::String^ name2 = wort->Substring(wort->IndexOf('-') + 1);

					if (name2->IndexOf('-') != -1)
					{
						// Multi-Vornamen mit mehr als zwei Bezeichnungen erkannt, Eingabe ist invalid
						// Multi-Nachname wird als mehrfacher zweiter Nachname behandelt
						kontakt->setValid(false);
						Debug::WriteLine(wort + " recognized as multiple first names with more than two, inputstring is invalid");
					}

					kontakt->setVorname1(name1);
					kontakt->setVorname2(name2);
					Debug::WriteLine(name1 + " set as Vorname1, " + name2 + " set as Vorname2");
				}
				else
				{
					kontakt->setVorname1(wort);
					Debug::WriteLine(wort + " set as Vorname1");
				}

				wasLastCommaSeparated = false;
			}
			// Es handelt sich um den Nachnamen, wenn:
			//		Ein Vorname bereits gesetzt ist aber kein Nachname ORDER
			//		Das letzte Wort war ein Präfix
			else if (kontakt->getNachname1() == "" || wasLastMatchPraefix)
			{
				// Doppel-Nachnamen-Check
				if (wort->IndexOf('-') != -1)
				{
					System::String^ name1 = wort->Substring(0, wort->IndexOf('-'));
					System::String^ name2 = wort->Substring(wort->IndexOf('-') + 1);

					if (name2->IndexOf('-') != -1)
					{
						// Multi-Nachnamen mit mehr als zwei Bezeichnungen erkannt, Eingabe ist invalid
						// Multi-Nachname wird als mehrfacher zweiter Nachname behandelt
						kontakt->setValid(false);
						Debug::WriteLine(name2 + " recognized as multiple last names with more than two, inputstring is invalid");
					}

					// Vorläufiger Präfix erkannt: erster Nachname wird angehängt statt gesetzt
					if (wasLastMatchPraefix)
					{
						kontakt->setNachname1(kontakt->getNachname1() + " " + name1);
						Debug::WriteLine(name1 + " appended at Praefix of Nachname1");
					}
					else
					{
						kontakt->setNachname1(name1);
						Debug::WriteLine(name1 + " set as Nachname1");
					}

					kontakt->setNachname2(name2);
					Debug::WriteLine(name2 + " set as Nachname2");
				}
				else
				{
					// Vorläufiger Präfix erkannt: Nachname wird ans zuletzt gesetzte Feld angehängt statt gesetzt
					if (wasLastMatchPraefix)
					{
						if (kontakt->getNachname2() != "")
						{
							kontakt->setNachname2(kontakt->getNachname2() + " " + wort);
							Debug::WriteLine(wort + " appended at Praefix of Nachname2");
						}
						else
						{
							kontakt->setNachname1(kontakt->getNachname1() + " " + wort);
							Debug::WriteLine(wort + " appended at Praefix of Nachname1");
						}
					}
					else
					{
						kontakt->setNachname1(wort);
						Debug::WriteLine(wort + " set as Nachname1");
					}
				}
			}
			else
			{
				// Eingabestring ist invalid, da mehrere, nicht durch Bindestrich getrennte Namen gefunden wurden
				kontakt->setValid(false);
				Debug::WriteLine(wort + " recognized as name but first and last name are set already, no double name with '-'; inputstring is invalid");
			}

			wasLastMatchTitel = false;
			wasLastMatchPraefix = false;
		}
	}

	// Wenn nach Parsen des Strings kein Geschlecht gesetzt wurde, ist als Geschlecht "X" anzugeben
	if (kontakt->getGeschlecht() == "")
	{
		kontakt->setGeschlecht("X");
	}

	return kontakt;
}

String^ Parser::generateAusgabe(Kontakt^ kontakt)
{
	String^ ausgabeString = "";

	// Setzen des Anrede im Ausgabestring
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

	// Setzen der Titel im Ausgabestring
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

	// Setzen des Vornamens im Ausgabestring
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

	// Setzen des Nachnamens im Ausgabestring
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