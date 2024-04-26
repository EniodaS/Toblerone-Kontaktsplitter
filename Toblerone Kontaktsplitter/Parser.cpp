#include "pch.h"
#include "Parser.h"



Parser::Parser(DataClass dataClass)
{
	listeAnrede = dataClass.getAnrede();
	listeBriefAnrede = dataClass.getBriefAnrede();
	listeTitel = dataClass.getTitel();
	listeGeschlecht = dataClass.getGeschlecht();
	listeNachnamenZusatz = dataClass.getNachnamen();
}

void Parser::parseEingabe(String^ eingabeString)
{

}
