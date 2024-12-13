#include "String.h"

//default constructor
String::String(){
  capacity_ = 20;
  size_ = 7;
  char phrase[size_+1] = {'H', 'e', 'l', 'l', 'o', ' ', '!'};
  string_ptr_ = new char [capacity_];
  string_ptr_ = phrase;
  string_ptr_[size_] = '\0';
}
