#pragma once

public ref class DataClass
{
private:

	System::Collections::Generic::List<System::String^>^ listeTitel;

	System::Collections::Generic::List<System::String^>^ listePraefixe;

public:

	DataClass();

	System::Collections::Generic::List<System::String^>^ getTitel();

	System::Collections::Generic::List<System::String^>^ getPraefixe();
};