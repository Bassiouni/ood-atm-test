#include <iostream>

#include "bank.atm.h"
#include "bank.db.h"

bool BankATM::connectToDB(std::string dbfile, ICard &card)
{
  BankDB::instance().openConnection(dbfile);
  return BankDB::instance().validateCardInfo(card);
}

bool BankATM::connectToDB(std::string dbfile, ICard &&card)
{
  return this->connectToDB(dbfile, card);
}

void BankATM::displayInfo()
{
  auto accountDetails = BankDB::instance().read("database")[BankDB::instance().getIndex()]["account details"];
  std::cout << "Your cash in account is $" << accountDetails["cash"] << std::endl;
}

void BankATM::greetings()
{
  auto accountDetails = BankDB::instance().read("database")[BankDB::instance().getIndex()]["account details"];
  std::cout << "\n\nWelcome " << accountDetails["name"].asString() << std::endl
            << std::endl;
}

void BankATM::withdraw(int &amount)
{
  this->getAccountInfo()["cash"] = this->getAccountInfo()["cash"].asInt() - amount;
  BankDB::instance().writeToFile();
}

void BankATM::withdraw(int &&amount)
{
  this->withdraw(amount);
}

inline Json::Value &BankATM::getAccountInfo() const
{
  return BankDB::instance().read("database")[BankDB::instance().getIndex()]["account details"];
}

void BankATM::addMoney(int &&amount)
{
  this->addMoney(amount);
}

void BankATM::addMoney(int &amount)
{
  this->withdraw(-amount);
}
