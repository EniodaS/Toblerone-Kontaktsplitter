#include "pch.h"
#include "DataClass.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

DataClass::DataClass()
{
	listeAnrede = gcnew List<String^>(); // TODO useless?
	listeAnrede->Add("Herr");
	listeAnrede->Add("Frau");
	listeAnrede->Add("X");

	listeBriefAnrede = gcnew List<String^>(); // TODO useless?
	listeBriefAnrede->Add("Sehr geehrter");
	listeBriefAnrede->Add("Sehr geehrte");
	listeBriefAnrede->Add("Sehr geehrte*r");

	listeTitel = gcnew List<String^>();
	listeTitel->Add("Dr.");
	listeTitel->Add("Doktor");
	listeTitel->Add("Prof.");
	listeTitel->Add("Professor");
	listeTitel->Add("Dipl.");
	listeTitel->Add("Ing.");
	listeTitel->Add("Dr.-Ing.");
	// TODO: add more, Quellenangaben bei Listen aus dem Internet!

	listeGeschlecht = gcnew List<String^>(); // TODO useless?
	listeGeschlecht->Add("männlich");
	listeGeschlecht->Add("weiblich");
	listeGeschlecht->Add("divers");

	listeNachnamenZusatz = gcnew List<String^>();
	listeNachnamenZusatz->Add("von");
	listeNachnamenZusatz->Add("vom");
	listeNachnamenZusatz->Add("van");
	listeNachnamenZusatz->Add("de");
	listeNachnamenZusatz->Add("der");
	listeNachnamenZusatz->Add("hof"); // ???
	// TODO: add more, Quellenangaben bei Listen aus dem Internet!
}

List<String^>^ DataClass::getAnrede()
{
	return listeAnrede;
}

List<String^>^ DataClass::getBriefAnrede()
{
	return listeBriefAnrede;
}

List<String^>^ DataClass::getTitel()
{
	return listeTitel;
}

List<String^>^ DataClass::getGeschlecht()
{
	return listeGeschlecht;
}

List<String^>^ DataClass::getNachnamen()
{
	return listeNachnamenZusatz;
}
