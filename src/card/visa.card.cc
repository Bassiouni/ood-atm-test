#include "card/visa.card.h"
#include "nationalbank.db.h"

inline CardType VisaCard::cardType() const { return CardType::Visa; }

VisaCard::VisaCard(std::string cardNumber, uint16_t &passCode, std::string endDate)
{
  this->cardNumber = cardNumber;
  this->passCode = passCode;
  this->endDate = endDate;
}

VisaCard::VisaCard(ICard &&card)
{
  VisaCard(card.getSerialNumber(), card.getPinCodeSecret(), card.getEndDate());
}

inline void VisaCard::operator=(ICard &&card)
{
  VisaCard(card.getSerialNumber(), card.getPinCodeSecret(), card.getEndDate());
}

void VisaCard::operator=(ICard &card)
{
  VisaCard(card.getSerialNumber(), card.getPinCodeSecret(), card.getEndDate());
}

inline std::string VisaCard::getSerialNumber() const
{
  return this->cardNumber;
}

inline bool VisaCard::setSerialNumber(uint64_t &n)
{
  // TODO: Setter
  this->cardNumber = n;
  return true;
}

inline uint16_t &VisaCard::getPinCodeSecret() const
{
  return (uint16_t &)this->passCode;
}

inline bool VisaCard::setPinCodeSecret(uint16_t &secretPin)
{
  // TODO: Setter
  this->passCode = secretPin;
  return true;
}

inline std::string VisaCard::getEndDate() const
{
  return this->endDate;
}

inline bool VisaCard::setEndDate(std::string endDate)
{
  // TODO: Setter
  this->endDate = endDate;
  return true;
}
