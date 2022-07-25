#ifndef _CARD_INTERFACE_H_
#define _CARD_INTERFACE_H_

#include <inttypes.h>
#include <string>

enum class CardType
{
  Visa = 1,
  MasterCard
};

class ICard
{
public:
  virtual CardType cardType() const = 0;

  virtual inline std::string getSerialNumber() const = 0;
  virtual bool setSerialNumber(uint64_t &serialNumber) = 0;

  virtual inline uint16_t &getPinCodeSecret() const = 0;
  virtual bool setPinCodeSecret(uint16_t &serialNumber) = 0;

  virtual inline std::string getEndDate() const = 0;
  virtual bool setEndDate(std::string endDate) = 0;

protected:
  std::string cardNumber, endDate;
  uint16_t passCode;
};

#endif // _CARD_INTERFACE_H_
