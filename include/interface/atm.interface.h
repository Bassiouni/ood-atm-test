#ifndef _ATM_INTERFACE_H
#define _ATM_INTERFACE_H_

#include "card.interface.h"
#include "database.interface.h"

class IATM
{
public:
  virtual bool connectToDB(std::string db, ICard& card) = 0;
  virtual bool connectToDB(std::string db, ICard&& card) = 0;

  virtual void displayInfo() = 0;

  virtual void withdraw(int& amount) = 0;
  virtual void withdraw(int&& amount) = 0;

  virtual inline Json::Value& getAccountInfo() const = 0;
};

#endif // _ATM_INTERFACE_H_
