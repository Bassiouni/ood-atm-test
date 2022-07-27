#ifndef _DB_H_
#define _DB_H_

#include "interface/database.interface.h"

class BankDB : public IDatabase
{
public:
  bool validateCardInfo(ICard &card) override;

  inline Json::Value &read(std::string key) const override;
  inline bool writeToContextObject(std::string key, Json::Value &value) override;
  inline bool writeToContextObject(std::string key, Json::Value &&value);

  inline bool writeToFile() override;

  inline bool openConnection(std::string dbfile) override;
  inline bool closeConnection() override;

  inline bool isAuthenticated() const override;

  inline void setIndex(uint32_t &index) override;
  inline uint32_t &getIndex() const override;

  void createAccount() override;
  bool deleteAccount() override;

protected:
  BankDB() = default;

private:
  std::string pathToDB = "";
  Json::Value context;
  bool authenticated = false;
  uint32_t index;

public: // impl Singleton
  static BankDB &instance()
  {
    static BankDB BankDB;
    return BankDB;
  }

  BankDB(const BankDB &) = delete;
  BankDB &operator=(const BankDB &) = delete;

  BankDB(BankDB &&) = delete;
  BankDB &operator=(BankDB &&) = delete;

  BankDB(BankDB &) = delete;
  BankDB &operator=(BankDB &) = delete;
};

#endif // _BANK_DB_H_
