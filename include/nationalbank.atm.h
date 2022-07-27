#ifndef _NB_ATM_H_
#define _NB_ATM_H_

#include "interface/atm.interface.h"
#include "interface/card.interface.h"

class NationalBankATM : public IATM
{
public:
  NationalBankATM() = default;

  bool connectToDB(std::string db, ICard &card) override;
  bool connectToDB(std::string db, ICard &&card) override;

  void displayInfo() override;
  void withdraw(int &amount) override;
  void withdraw(int &&amount) override;

  void addMoney(int &amount) override;
  void addMoney(int &&amount) override;

  inline Json::Value &getAccountInfo() const override;

  void greetings();

private:
  int index;
};

#endif // _NB_ATM_H_
