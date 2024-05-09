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
	// Bereitstellen von Vergleichs-Titeln und -Pr�fixen, um eingelesene W�rter damit zu vergleichen
	listeTitel = dataClass->getTitel();
	listePraefixe = dataClass->getPraefixe();
}

Kontakt^ Parser::parseEingabe(String^ eingabeString)
{
	// Leeres Kontakt-Objekt, das w�hrend dem Iterieren �ber die W�rter des Eingabestrings bef�llt wird
	Kontakt^ kontakt = gcnew Kontakt();

	// Zerlegt Eingabe-String in Liste von W�rtern, getrennt nach Leerzeichen
	List<String^>^ worte = gcnew List<String^>(eingabeString->Split(' '));

	// Aussenstehende Variablen, um schleifen-�bergreifend vorherige, bereits erkannte W�rter zu merken
	bool wasLastMatchTitel = false;
	bool wasLastMatchPraefix = false;
	bool wasLastCommaSeparated = false;

	// Schleife f�r jedes Wort des Eingabe-Strings
	for each (String^ wort in worte) 
	{
		// Schleifen-Variable zum Pr�fen, ob eine �bereinstimmung des Wortes bereits gefunden wurde
		bool wordMatchFound = false;

		// Check, ob Wort eine Anrede ist
		// Wenn Wort gleich "Herr" oder "Frau", dann ist Wort eine Anrede
		if (wort == "Herr" || wort == "Frau")
		{
			kontakt->setAnrede(wort);

			// Wenn Wort gleich "Herr", dann setze Geschlecht auf M�nnlich
			if (wort == "Herr")
			{
				kontakt->setGeschlecht("M�nnlich");
				Debug::WriteLine(wort + " set as Anrede, M�nnlich set as Geschlecht");
			}
			// Sonst Wort gleich "Frau", setze Geschlecht auf "Weiblich"
			else
			{
				kontakt->setGeschlecht("Weiblich");
				Debug::WriteLine(wort + " set as Anrede, Weiblich set as Geschlecht");
			}

			wordMatchFound = true;
			wasLastMatchTitel = false;
			wasLastMatchPraefix = false;
		}

		// Check, ob Wort zum vorherigen Titel geh�rt
		// Wenn letztes Wort ein Titel war UND mit einem Punkt endet UND der erste Character klein-geschrieben ist
		// Dann ist Wort weiterer Titel des vorherigen Titels
		if (wasLastMatchTitel && wort[wort->Length - 1] == '.' && Char::IsLower(wort[0]))
		{
			// Wenn Titel2 nicht leer, dann war vorheriger Titel Titel2
			if (kontakt->getTitel2() != "") 
			{
				kontakt->addTitel2(wort);
				Debug::WriteLine(wort + " added to Titel2");
			}
			// Sonst war vorheriger Titel Titel1
			else
			{
				kontakt->addTitel1(wort);
				Debug::WriteLine(wort + " added to Titel1");
			}

			wordMatchFound = true;
			wasLastMatchTitel = true;
			wasLastMatchPraefix = false;
		}
		// Check, ob Wort ein Titel ist
		else for each (String^ titelItem in listeTitel) 
		{
			if (wort == titelItem) 
			{
				// Wenn Titel1 leer ist, dann ist das Wort Titel1
				if (kontakt->getTitel1() == "")
				{
					kontakt->setTitel1(wort);
					Debug::WriteLine(wort + " set as Titel1");
				}
				// Sonst wenn Titel2 leer ist, dann ist das Wort Titel2
				else if (kontakt->getTitel2() == "")
				{
					kontakt->setTitel2(wort);
					Debug::WriteLine(wort + " set as Titel2");
				}
				else 
				{
					// Eingabe invalid, da mehr als zwei Titel erkannt wurden
					// -> Erkannter Titel wird an Titel2 angef�gt
					kontakt->setValid(false);
					kontakt->addTitel2(wort);
					Debug::WriteLine(wort + " recognized as title but two titles are set already, inputstring is invalid");
					Debug::WriteLine(wort + " added to Titel2");
				}

				wordMatchFound = true;
				wasLastMatchTitel = true;
				wasLastMatchPraefix = false;
			}
		}

		// Check, ob Wort ein Pr�fix ist
		for each (String ^ praefixItem in listePraefixe) 
		{
			if (wort == praefixItem) 
			{
				// Wenn letztes Wort ein Pr�fix war und Nachname2 bereits gesetzt wurde
				// Dann ist Wort weiterer Pr�fix von Nachname2
				if (wasLastMatchPraefix && kontakt->getNachname2() != "")
				{
					kontakt->addNachname2(wort);
					Debug::WriteLine(wort + " added to Nachname2");

				}
				// Sonst wenn letztes Wort ein Pr�fix war und Nachname1 bereits gesetzt wurde
				// Dann ist Wort weiterer Pr�fix von Nachname1
				if (wasLastMatchPraefix && kontakt->getNachname1() != "")
				{
					kontakt->addNachname1(wort);
					Debug::WriteLine(wort + " added to Nachname1");
				}
				// Sonst wenn letztes Wort kein Pr�fix war und Nachname1 leer ist
				// Dann ist Wort der Pr�fix von Nachname1
				else if (kontakt->getNachname1() == "")
				{
					kontakt->setNachname1(wort);
					Debug::WriteLine(wort + " set as Nachname1 Pr�fix");
				}
				// Sonst wenn letztes Wort kein Pr�fix war und Nachname2 leer ist
				// Dann ist Wort der Pr�fix von Nachname2
				else if (kontakt->getNachname2() == "")
				{
					kontakt->setNachname2(wort);
					Debug::WriteLine(wort + " set as Nachname2 Pr�fix");
				}
				else 
				{
					// Eingabe invalid, da Pr�fix zu keinem der zwei Nachnamen geh�rt
					// -> Wort wird verworfen
					kontakt->setValid(false);
					Debug::WriteLine(praefixItem + " recognized as praefix but two last names are set already, inputstring is invalid");
				}

				wordMatchFound = true;
				wasLastMatchTitel = false;
				wasLastMatchPraefix = true;
			}
		}

		// Wenn keine �bereinstimmung des Wortes gefunden wurde, dann muss Wort ein Vor- oder Nachname sein
		if (!wordMatchFound) 
		{
			// Wenn der letzte Character des Wortes ein Komma ist
			// Dann ist das Wort ein Nachname und das n�chste Wort ist ein Vorname
			if (wort[wort->Length - 1] == ',')
			{
				// Entfernen des Kommas
				wort = wort->Substring(0, wort->Length - 1);

				// Wenn Wort ein Bindestrich enth�lt, dann ist es ein doppelter Nachname
				if (wort->IndexOf('-') != -1)
				{
					// Trennen der Nachnamen am ersten Bindestrich
					System::String^ name1 = wort->Substring(0, wort->IndexOf('-'));
					System::String^ name2 = wort->Substring(wort->IndexOf('-') + 1);

					// Wenn letztes Wort ein Pr�fix war, dann wird Nachname an Nachname1 angeh�ngt
					if (wasLastMatchPraefix)
					{
						kontakt->addNachname1(name1);
						Debug::WriteLine(name1 + " added to Nachname1");
					}
					// Sonst ist der Name Nachname1 und wird gesetzt
					else
					{
						kontakt->setNachname1(name1);
						Debug::WriteLine(name1 + " set as Nachname1");
					}

					kontakt->setNachname2(name2);
					Debug::WriteLine(name2 + " set as Nachname2");

					// Wenn zweiter Name einen Bindestrich enth�lt, dann ist der Name mehr als Doppelname
					if (name2->IndexOf('-') != -1)
					{
						// Eingabe invalid, Multiname mit mehr als zwei Namen erkannt
						// -> Erkannter Multi-Name wird als Nachname2 gesetzt
						kontakt->setValid(false);
						Debug::WriteLine(name2 + " recognized as multiple last names with more than two, inputstring is invalid");
					}
				}
				// Sonst ist der Name ein einzelner Nachname
				else
				{
					if (wasLastMatchPraefix)
					{
						// Wenn vorheriger Pr�fix erkannt wurde und Nachname2 nicht leer ist
						// Dann muss Nachname zu Pr�fix in Nachname2 geh�ren
						if (kontakt->getNachname2() != "") 
						{
							kontakt->addNachname2(wort);
							Debug::WriteLine(wort + " added to Nachname2");
						}
						// Sonst muss Nachname zu Pr�fix in Nachname1 geh�ren
						else
						{
							kontakt->setNachname1(kontakt->getNachname1() + " " + wort);
							Debug::WriteLine(wort + " added to Nachname1");
						}
					}
					// Sonst ist Nachname einzelner Nachname
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
			//		Das letzte Wort war ein Pr�fix
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

					// Vorl�ufiger Pr�fix erkannt: erster Nachname wird angeh�ngt statt gesetzt
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
					// Vorl�ufiger Pr�fix erkannt: Nachname wird ans zuletzt gesetzte Feld angeh�ngt statt gesetzt
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
	if (kontakt->getGeschlecht() == "M�nnlich")
	{
		ausgabeString += "Sehr geehrter";
	}
	else if (kontakt->getGeschlecht() == "Weiblich")
	{
		ausgabeString += "Sehr geehrte";
	}
	else
	{
		ausgabeString += "Sehr geehrte*r";
	}

	if (kontakt->getAnrede() != "")
	{
		ausgabeString += " " + kontakt->getAnrede();
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