#include <iostream>

#include "nationalbank.atm.h"
#include "nationalbank.db.h"

bool NationalBankATM::connectToDB(std::string dbfile, ICard &card)
{
  NationalBankDB::instance().openConnection(dbfile);
  return NationalBankDB::instance().validateCardInfo(card);
}

bool NationalBankATM::connectToDB(std::string dbfile, ICard &&card)
{
  return this->connectToDB(dbfile, card);
}

void NationalBankATM::displayInfo()
{
  std::cout << NationalBankDB::instance().read("database")[NationalBankDB::instance().getIndex()]["account details"] << std::endl;
}

void NationalBankATM::withdraw(int& amount)
{
  this->getAccountInfo()["cash"] = this->getAccountInfo()["cash"].asInt() - amount;
  NationalBankDB::instance().writeToFile();
}

void NationalBankATM::withdraw(int&& amount)
{
  this->withdraw(amount);
}

inline Json::Value& NationalBankATM::getAccountInfo() const
{
  return NationalBankDB::instance().read("database")[NationalBankDB::instance().getIndex()]["account details"];
}
