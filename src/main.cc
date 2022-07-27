#include <iostream>

#include "card/visa.card.h"
#include "card/master.card.h"
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
  {
    result = nbAtm.connectToDB(dbfile, VisaCard(_16_digitNumber, passCode, endDate));
  }
  else if (cardType == CardType::MasterCard)
  {
    result = nbAtm.connectToDB(dbfile, MasterCard(_16_digitNumber, passCode, endDate));
  }

  if (!result)
  {
    std::cerr << "Wrong credintials" << std::endl;
    exit(2);
  }

  nbAtm.greetings();

  std::cout << "What do you want to do?\n"
               "1. Show account cash\n"
               "2. Withdraw money\n"
               "3. Put money into your account\n"
               "(-1 to close the program)\n"
            << std::endl;

  std::cout << "Your choice: ";
  std::cin >> c;

  int amount;
  while (c != -1)
  {
    switch (c)
    {
    case 1:
      nbAtm.displayInfo();
      break;
    case 2:
      std::cout << "How much do you wanna take? ";
      std::cin >> amount;
      nbAtm.withdraw(amount);
      nbAtm.displayInfo();
      break;
    case 3:
      std::cout << "How much do you wanna put? ";
      std::cin >> amount;
      nbAtm.addMoney(amount);
      nbAtm.displayInfo();
      break;
    default:
      std::cerr << "\nInvalid Option\ntry again\n"
                << std::endl;
    }
    std::cout << "Your choice: ";
    std::cin >> c;
  }

  std::cout << "Bye!!!" << std::endl;

  return 0;
}
