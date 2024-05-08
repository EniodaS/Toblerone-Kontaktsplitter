#include "pch.h"
#include "DataClass.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

DataClass::DataClass()
{
	listeTitel = gcnew List<String^>();
	listePraefixe = gcnew List<String^>();

	// Akademische Titel aus Beispielen
	listeTitel->Add("Dr.");
	listeTitel->Add("Doktor");
	listeTitel->Add("Prof.");
	listeTitel->Add("Professor");
	listeTitel->Add("Dipl.");
	listeTitel->Add("Ing.");
	listeTitel->Add("Dr.-Ing.");
	listeTitel->Add("Dipl.-Ing.");

	// Weitere akademische Titel
	// Quelle: https://www.tabellarischer-lebenslauf.net/beruf-arbeitsleben/akademische-titel/
	listeTitel->Add("B.A.");
	listeTitel->Add("B.MA.");
	listeTitel->Add("B.Sc.");
	listeTitel->Add("B.Eng.");
	listeTitel->Add("B.BA.");
	listeTitel->Add("B.Ed.");
	listeTitel->Add("B.B.");
	listeTitel->Add("M.A.");
	listeTitel->Add("M.MA.");
	listeTitel->Add("M.Sc.");
	listeTitel->Add("M.Eng.");
	listeTitel->Add("M.MBA.");
	listeTitel->Add("M.Ed.");
	listeTitel->Add("M.M.");
	listeTitel->Add("Dipl.-Kfm.");
	listeTitel->Add("Dipl.-Infor.");
	listeTitel->Add("Dipl.-Chem.");

	// Adelstitel
	// Quelle: https://www.rosepartner.de/adelsrecht.html
	listeTitel->Add("Kaiser");
	listeTitel->Add("König");
	listeTitel->Add("Herzog");
	listeTitel->Add("Fürst");
	listeTitel->Add("Graf");
	listeTitel->Add("Baron");
	listeTitel->Add("Freiherr");
	listeTitel->Add("Ritter");
	listeTitel->Add("Edler");
	listeTitel->Add("Junker");

	// Präfixe aus Beispielen 
	listePraefixe->Add("von");
	listePraefixe->Add("vom");
	listePraefixe->Add("van");
	listePraefixe->Add("de");
	listePraefixe->Add("der");
	listePraefixe->Add("den");
	listePraefixe->Add("zu");
}

List<String^>^ DataClass::getTitel()
{
	return listeTitel;
}

List<String^>^ DataClass::getPraefixe()
{
	return listePraefixe;
}
