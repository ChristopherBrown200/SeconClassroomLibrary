#ifndef Item_h
#define Item_h

#include "Arduino.h"
#include <MFRC522.h>

class Item{
  public:
    String title;
    String id;
    bool checkedOut;
    Item(String Title, String id);
};

#endif