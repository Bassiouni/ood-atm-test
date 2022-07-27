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
  auto accountDetails = NationalBankDB::instance().read("database")[NationalBankDB::instance().getIndex()]["account details"];
  std::cout << "Your cash in account is $" << accountDetails["cash"] << std::endl;
}

void NationalBankATM::greetings()
{
  auto accountDetails = NationalBankDB::instance().read("database")[NationalBankDB::instance().getIndex()]["account details"];
  std::cout << "\n\nWelcome " << accountDetails["name"].asString() << std::endl << std::endl;
}

void NationalBankATM::withdraw(int &amount)
{
  this->getAccountInfo()["cash"] = this->getAccountInfo()["cash"].asInt() - amount;
  NationalBankDB::instance().writeToFile();
}

void NationalBankATM::withdraw(int &&amount)
{
  this->withdraw(amount);
}

inline Json::Value &NationalBankATM::getAccountInfo() const
{
  return NationalBankDB::instance().read("database")[NationalBankDB::instance().getIndex()]["account details"];
}

void NationalBankATM::addMoney(int &&amount)
{
  this->addMoney(amount);
}

void NationalBankATM::addMoney(int &amount)
{
  this->withdraw(-amount);
}
