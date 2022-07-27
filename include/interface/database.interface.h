#ifndef _IDB_H_
#define _IDB_H_

#include <json/json.h>

#include "card.interface.h"

class IDatabase
{
public:
  virtual bool validateCardInfo(ICard &card) = 0;

  virtual Json::Value& read(std::string key) const = 0;
  virtual bool writeToContextObject(std::string key, Json::Value &value) = 0;
  virtual bool writeToFile() = 0;

  virtual bool openConnection(std::string dbfile) = 0;
  virtual bool closeConnection() = 0;

  virtual bool isAuthenticated() const = 0;

  virtual inline void setIndex(uint32_t &index) = 0;
  virtual inline uint32_t &getIndex() const = 0;

  virtual void createAccount() = 0;
  virtual bool deleteAccount() = 0;
};

#endif // _IDB_H_
