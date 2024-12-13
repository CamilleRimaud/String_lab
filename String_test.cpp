#include "String.h"
#include <iostream>
#include <cstdlib>

void display(const String str);


int main(){
  //test default constructor
  String str;
  std::cout<<*str.string_ptr_<<std::endl;
  display(str);
  //test constructor from c-string
  char cstr[10] = "Bonjour"; // a revoir : cstring char* et end by /0
  String str_bis(cstr);
  display(cstr);
  display(str_bis);
  //test length accessor
  std::cout<<str.length()<<std::endl;


}

// display whole string
void display(const String str){
  for (int i=0 ; i<str.size_ ; i++) {
    std::cout<<str.string_ptr_[i];
  }
  std::cout<<std::endl;
}
