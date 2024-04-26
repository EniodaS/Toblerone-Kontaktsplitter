#include "pch.h"
#include "UiService.h"


using namespace System;
using namespace System::Collections::Generic;

UiService::UiService(DataClass^ data)
{
	dataClass = data;
	parser = gcnew Parser(dataClass);

}

void UiService::scan(String^ eingabeString)
{
	parser->parseEingabe(eingabeString);


}

Parser^ UiService::getParser()
{
	return parser;
}

void UiService::update()
{

}

void UiService::save()
{

}