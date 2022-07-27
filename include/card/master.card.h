#ifndef _MASTER_CARD_INTERFACE_H_
#define _MASTER_CARD_INTERFACE_H_

#include "interface/card.interface.h"

class MasterCard : public ICard
{
public:
  inline CardType cardType() const override;

  inline std::string getSerialNumber() const override;
  inline bool setSerialNumber(uint64_t &serialNumber) override;

  inline uint16_t &getPinCodeSecret() const override;
  inline bool setPinCodeSecret(uint16_t &secretPin) override;

  inline std::string getEndDate() const override;
  inline bool setEndDate(std::string endDate) override;

  MasterCard(std::string cardNumber, uint16_t &passCode, std::string endDate);
  MasterCard(ICard &&card);
  MasterCard(ICard &card);
  MasterCard(const ICard &card) = delete;
  MasterCard() = default;

  void operator=(ICard &&card);
  void operator=(const ICard &card) = delete;
  void operator=(ICard &card);
};

#endif // _MASTER_CARD_INTERFACE_H_
