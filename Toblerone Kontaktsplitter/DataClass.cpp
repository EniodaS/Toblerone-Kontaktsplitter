#include "pch.h"
#include "DataClass.h"

DataClass::DataClass()
{
	listeAnrede = gcnew List<String^>();
	listeAnrede->Add("Herr");
	listeAnrede->Add("Frau");
	listeAnrede->Add("X");
	listeBriefAnrede = gcnew List<String^>();
	listeAnrede->Add("Sehr geehrter");
	listeAnrede->Add("Sehr geehrte");
	listeAnrede->Add("Sehr geehrte*r");
	listeTitel = gcnew List<String^>();
	listeAnrede->Add("Dr.");
	listeAnrede->Add("Prof.");
	listeGeschlecht = gcnew List<String^>();
	listeAnrede->Add("männlich");
	listeAnrede->Add("weiblich");
	listeAnrede->Add("divers");
	listeNachnamenZusatz = gcnew List<String^>();
	listeAnrede->Add("van");
	listeAnrede->Add("de");
	listeAnrede->Add("hof");


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
