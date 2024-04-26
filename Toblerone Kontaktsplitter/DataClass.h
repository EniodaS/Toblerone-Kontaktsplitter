#pragma once
using namespace System;
using namespace System::Diagnostics; // nur für debug zwecke
using namespace System::Collections::Generic;


ref class DataClass
{

private:
	List<String^>^ listeAnrede;
	List<String^>^ listeBriefAnrede;
	List<String^>^ listeTitel;
	List<String^>^ listeGeschlecht;
	List<String^>^ listeNachnamenZusatz;

public:

	DataClass();
	List<String^>^ getAnrede();
	List<String^>^ getBriefAnrede();
	List<String^>^ getTitel();
	List<String^>^ getGeschlecht();
	List<String^>^ getNachnamen();
};

