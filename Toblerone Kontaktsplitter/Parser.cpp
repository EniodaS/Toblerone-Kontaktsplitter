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

    List<String^>^ worte = gcnew List<String^>(eingabeString->Split(' '));

    int notFoundCount = 0;

    for each (String^ wort in worte) {
        Debug::WriteLine(wort);

        bool found = false;


        for each (String^ item in listeAnrede) {
            if (wort == item) {
                found = true;
                Debug::WriteLine(item + "found in listeAnrede");
                anrede = item;

                if (wort == "Herr")
                {
                    geschlecht = "Männlich";
                    briefAnrede = "Sehr geehrter";
                }
                else
                if (wort == "Frau")
                {
                    geschlecht = "Weiblich";
                    briefAnrede = "Sehr geehrte";
                }

            }
        }

        for each (String^ item in listeTitel) {
            if (wort == item) {
                found = true;
                Debug::WriteLine(item + " found in listeTitel");
                if (titel1 == "") 
                {
                    titel1 = item;
                }
                else {
                    titel2 = item;
                }

            }
        }

        for each (String^ item in listeNachnamenZusatz) {
            if (wort == item) {
                found = true;
                Debug::WriteLine(item + " found in listeNachnamenZusatz");
                nachname += item;

            }
        }


        if (!found) {
            Debug::WriteLine(wort + " not found in any list");
            if (notFoundCount == 0)
            {
                vorname = wort;
                notFoundCount++;
            }
            else
            {
                nachname = wort;
                notFoundCount++;
            }

        }
    }
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
