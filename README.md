# ood-atm-test

This project is inspired by <https://hackernoon.com/the-top-10-object-oriented-design-interview-questions-developers-should-know-c7fc2e13ce39>

## Deps

- jsoncpp


## JSON File Structure

```json
{
  "database": [
    {
      "account details": {
        "cash": NUMBER,
        "gender": STRING["male" || "female"],
        "name": STRING
      },
      "card type": NUMBER,
      "end date": STRING,
      "password": NUMBER(4 DIGITS),
      "serial number": NUMBER(16 DIGITS)
    }
  ]
}
```

## Compiling using G++

```sh
g++ \
  -g -Wall -Wextra \
  -Iinclude \
  -x c++ -std=c++17 \
  -l=jsoncpp \
  src/*.cc src/**/*.cc;
```
