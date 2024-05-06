#pragma once


public ref class DataClass
{

private:
	System::Collections::Generic::List<System::String^>^ listeAnrede;
	System::Collections::Generic::List<System::String^>^ listeBriefAnrede;
	System::Collections::Generic::List<System::String^>^ listeTitel;
	System::Collections::Generic::List<System::String^>^ listeGeschlecht;
	System::Collections::Generic::List<System::String^>^ listeNachnamenZusatz;

public:

	DataClass();
	System::Collections::Generic::List<System::String^>^ getAnrede();
	System::Collections::Generic::List<System::String^>^ getBriefAnrede();
	System::Collections::Generic::List<System::String^>^ getTitel();
	System::Collections::Generic::List<System::String^>^ getGeschlecht();
	System::Collections::Generic::List<System::String^>^ getNachnamen();
};

