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

void Parser::parseEingabe(String^ eingabeString)
{
    anrede = "";
    titel1 = "";
    titel2 = "";
    vorname = "";
    nachname = "";
    geschlecht = "";
    briefAnrede = "";

    //trenne eingabe in Liste an wörtern
    List<String^>^ worte = gcnew List<String^>(eingabeString->Split(' '));
    int notFoundCount = 0;


    //vergleiche gefundene Wörter mit Hilfslisten
    for each (String^ wort in worte) {
        Debug::WriteLine(wort);

        bool found = false;


        for each (String^ item in listeAnrede) {
            if (wort == item) {
                found = true;
                Debug::WriteLine(item + "found in listeAnrede");
                anrede = item + " ";

                if (wort == "Herr")
                {
                    geschlecht = "Männlich";
                    briefAnrede = "Sehr geehrter ";
                }
                else
                if (wort == "Frau")
                {
                    geschlecht = "Weiblich";
                    briefAnrede = "Sehr geehrte ";
                }

            }
        }

        for each (String^ item in listeTitel) {
            if (wort == item) {
                found = true;
                Debug::WriteLine(item + " found in listeTitel");
                if (titel1 == "") 
                {
                    titel1 = item + " ";
                }
                else {
                    titel2 = item + " ";
                }

            }
        }

        for each (String^ item in listeNachnamenZusatz) {
            if (wort == item) {
                found = true;
                Debug::WriteLine(item + " found in listeNachnamenZusatz");
                nachname += item + " ";

            }
        }


        if (!found) {
            Debug::WriteLine(wort + " not found in any list");
            if (notFoundCount == 0)
            {
                vorname = wort + " ";

            }
            else
            {
                nachname = wort + " ";
                notFoundCount++;
            }

        }
    }

    generiereAusgabe();

}

void Parser::generiereAusgabe()
{
    if (briefAnrede == "")
    {
        briefAnrede = "Sehr geehrte(r)* ";
    }

    ausgabe = briefAnrede + anrede + titel1 + titel2 + vo////rname + nachname;
}

System::String^ Parser::getAnrede()
{
    return anrede;
}

System::String^ Parser::getTitel1()
{
    return titel1;
}

System::String^ Parser::getTitel2()
{
    return titel2;
}

System::String^ Parser::getVorname()
{
    return vorname;
}

System::String^ Parser::getNachname()
{
    return nachname;
}

System::String^ Parser::getGeschlecht()
{
    return geschlecht;
}

System::String^ Parser::getBriefAnrede()
{
    return briefAnrede;
}

System::String^ Parser::getAusgabe()
{
    return ausgabe;
}

void Parser::setAnrede(System::String^ eingabe)
{
    anrede = eingabe;
}

void Parser::setTitel1(System::String^ eingabe)
{
    titel1 = eingabe;
}

void Parser::setTitel2(System::String^ eingabe)
{
    titel2 = eingabe;
}

void Parser::setVorname(System::String^ eingabe)
{
    vorname = eingabe;
}

void Parser::setNachname(System::String^ eingabe)
{
    nachname = eingabe;
}

void Parser::setGeschlecht(System::String^ eingabe)
{
    geschlecht = eingabe;
}

void Parser::setBriefAnrede(System::String^ eingabe)
{
    briefAnrede = eingabe;
}



