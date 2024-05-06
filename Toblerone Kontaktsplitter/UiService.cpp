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
	this->kontakt = gcnew Kontakt(parser->getAnrede(), parser->getTitel1(), parser->getTitel2(), parser->getVorname(), parser->getNachname(), parser->getGeschlecht(), parser->getBriefAnrede());
}

Kontakt^ UiService::getKontakt()
{
	return kontakt;
}
