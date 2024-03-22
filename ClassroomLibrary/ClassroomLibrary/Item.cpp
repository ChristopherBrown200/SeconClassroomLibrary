#include "Arduino.h"
#include "Item.h"

Item::Item(String title, String id)
{
  title = title;
  id = id;
  checkedOut = false;
}