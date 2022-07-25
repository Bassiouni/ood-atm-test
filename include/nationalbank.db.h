#ifndef _DB_H_
#define _DB_H_

#include "interface/database.interface.h"

class NationalBankDB : public IDatabase
{
public:
  bool validateCardInfo(ICard &card) override;

  inline Json::Value& read(std::string key) const override;
  inline bool writeToContextObject(std::string key, Json::Value &value) override;
  inline bool writeToContextObject(std::string key, Json::Value &&value);

  inline bool writeToFile() override;

  inline bool openConnection(std::string dbfile) override;
  inline bool closeConnection() override;

  inline bool isAuthenticated() const override;

  inline void setIndex(uint32_t &index) override;
  inline uint32_t &getIndex() const override;

protected:
  NationalBankDB() = default;

private:
  std::string pathToDB = "";
  Json::Value context;
  bool authenticated = false;
  uint32_t index;

public: // impl Singleton
  static NationalBankDB &instance()
  {
    static NationalBankDB NationalBankDB;
    return NationalBankDB;
  }

  NationalBankDB(const NationalBankDB &) = delete;
  NationalBankDB &operator=(const NationalBankDB &) = delete;

  NationalBankDB(NationalBankDB &&) = delete;
  NationalBankDB &operator=(NationalBankDB &&) = delete;

  NationalBankDB(NationalBankDB &) = delete;
  NationalBankDB &operator=(NationalBankDB &) = delete;
};

#endif // _BANK_DB_H_
