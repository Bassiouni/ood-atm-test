#include <json/json.h>
#include <fstream>
#include <functional>

#include <iostream>

#include "bank.db.h"

inline void BankDB::setIndex(uint32_t &index)
{
  this->index = index;
}

inline uint32_t &BankDB::getIndex() const
{
  return (uint32_t &)this->index;
}

bool BankDB::validateCardInfo(ICard &card)
{
  this->openConnection(this->pathToDB);
  for (uint32_t i = 0; i < this->context["database"].size(); i++)
  {
    if (
        this->context["database"][i]["card type"].asUInt() == (uint32_t)card.cardType() &&
        this->context["database"][i]["end date"].asString() == std::string(card.getEndDate()) &&
        this->context["database"][i]["password"].asUInt() == card.getPinCodeSecret() &&
        this->context["database"][i]["serial number"].asString() == card.getSerialNumber())
    {
      this->setIndex(i);
      this->authenticated = true;
    }
  }

  this->closeConnection();
  return this->isAuthenticated();
}

inline Json::Value &BankDB::read(std::string key) const
{
  try
  {
    return (Json::Value &)this->context[key];
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

bool run(std::function<void()> f)
{
  try
  {
    f();
    return true;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return false;
  }
}

inline bool BankDB::writeToContextObject(std::string key, Json::Value &value)
{
  return run([this, key, value]()
             { this->context[std::string(key)] = value; });
}

inline bool BankDB::writeToContextObject(std::string key, Json::Value &&value)
{
  return this->writeToContextObject(key, value);
}

inline bool BankDB::writeToFile()
{
  return run([this]()
             {
        remove(this->pathToDB.c_str());
        std::ofstream f(this->pathToDB);
        f << Json::FastWriter().write(this->context);
        f.close(); });
}

inline bool BankDB::openConnection(std::string dbfile)
{
  return run([this, dbfile]()
             {
               this->pathToDB = dbfile;
               std::ifstream f(this->pathToDB);
               f >> this->context;
               f.close(); });
}

inline bool BankDB::closeConnection()
{
  return run([this]()
             { this->writeToFile(); });
}

inline bool BankDB::isAuthenticated() const
{
  return this->authenticated;
}

void BankDB::createAccount()
{
  // TODO: impl
}

bool BankDB::deleteAccount()
{
  return this->context["database"].removeIndex(this->getIndex(), nullptr);
  // Json::Value new_items;
  // int c = 0;
  // for (int i = 0; i < items.size(); i++)
  // {
  //   if (items[i] != selected_item)
  //   {
  //     new_items[c] = items[i];
  //     c++;
  //   }
  // }
}
