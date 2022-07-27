#include "card/master.card.h"
#include "bank.db.h"

inline CardType MasterCard::cardType() const { return CardType::MasterCard; }

MasterCard::MasterCard(std::string cardNumber, uint16_t &passCode, std::string endDate)
{
    this->cardNumber = cardNumber;
    this->passCode = passCode;
    this->endDate = endDate;
}

MasterCard::MasterCard(ICard &&card)
{
    MasterCard(card.getSerialNumber(), card.getPinCodeSecret(), card.getEndDate());
}

inline void MasterCard::operator=(ICard &&card)
{
    MasterCard(card.getSerialNumber(), card.getPinCodeSecret(), card.getEndDate());
}

void MasterCard::operator=(ICard &card)
{
    MasterCard(card.getSerialNumber(), card.getPinCodeSecret(), card.getEndDate());
}

inline std::string MasterCard::getSerialNumber() const
{
    return this->cardNumber;
}

inline bool MasterCard::setSerialNumber(uint64_t &n)
{
    this->cardNumber = n;
    return true;
}

inline uint16_t &MasterCard::getPinCodeSecret() const
{
    return (uint16_t &)this->passCode;
}

inline bool MasterCard::setPinCodeSecret(uint16_t &secretPin)
{
    this->passCode = secretPin;
    return true;
}

inline std::string MasterCard::getEndDate() const
{
    return this->endDate;
}

inline bool MasterCard::setEndDate(std::string endDate)
{
    // TODO: Setter
    this->endDate = endDate;
    return true;
}
