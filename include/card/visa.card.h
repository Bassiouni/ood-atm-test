#ifndef _VISA_CARD_INTERFACE_H_
#define _VISA_CARD_INTERFACE_H_

#include "interface/card.interface.h"

class VisaCard : public ICard
{
public:

  inline CardType cardType() const override;

  inline std::string getSerialNumber() const override;
  inline bool setSerialNumber(uint64_t &serialNumber) override;

  inline uint16_t &getPinCodeSecret() const override;
  inline bool setPinCodeSecret(uint16_t &secretPin) override;

  inline std::string getEndDate() const override;
  inline bool setEndDate(std::string endDate) override;

  VisaCard(std::string cardNumber, uint16_t &passCode, std::string endDate);
  VisaCard(ICard &&card);
  VisaCard(ICard &card);
  VisaCard(const ICard &card) = delete;
  VisaCard() = default;

  void operator=(ICard &&card);
  void operator=(const ICard &card) = delete;
  void operator=(ICard &card);
};

#endif // _VISA_CARD_INTERFACE_H_
