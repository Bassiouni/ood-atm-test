#include <iostream>

#include "visa.card.h"
#include "master.card.h"
#include "nationalbank.atm.h"
#include "nationalbank.db.h"

int main(int, char **argv)
{
  std::string dbfile = argv[1];
  std::string _16_digitNumber;
  uint16_t passCode;
  CardType cardType;

  std::cout << "Welcome to ATM program\n\n"
               "Please enter your card info\n"
               "Card type (1. Visa | 2. Mastercard): ";

  short c;
  std::cin >> c;

  switch (c)
  {
  case 1:
    cardType = CardType::Visa;
    break;
  case 2:
    cardType = CardType::MasterCard;
    break;
  default:
    std::cout << "Unknown choice" << std::endl;
    exit(1);
  }

  std::cout << "16 digit serial number: ";
  std::cin >> _16_digitNumber;

  std::cout << "End date (separated with \"/\" [12/24]): ";
  std::string endDate;
  std::cin >> endDate;

  std::cout << "Password: ";
  std::cin >> passCode;

  NationalBankATM nbAtm;
  bool result;
  if (cardType == CardType::Visa)
    result = nbAtm.connectToDB(dbfile, VisaCard(_16_digitNumber, passCode, endDate));
  else if (cardType == CardType::MasterCard)
    result = nbAtm.connectToDB(dbfile, MasterCard(_16_digitNumber, passCode, endDate));

  if (!result)
  {
    std::cerr << "Wrong credintials" << std::endl;
    exit(2);
  }

  nbAtm.displayInfo();

  std::cout << "How much do you wanna take? ";
  int amount;
  std::cin >> amount;

  nbAtm.withdraw(amount);
  std::cout << "How much do you wanna put? ";
  

  return 0;
}
