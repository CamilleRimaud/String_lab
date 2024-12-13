#include "String.h"
#include <iostream>
#include <cstdlib>

void display(const string str);


int main(){
  //test default constructor
  string str;
  std::cout<<*str.string_ptr_<<std::endl;
  display(str);
  //test constructor from c-string
  char cstr[10] = "Bonjour"; // a revoir : cstring char* et end by /0
  string str_bis(cstr);
  display(cstr);
  display(str_bis);
  //test length accessor
  std::cout<<str.length()<<std::endl;
  //test maximum size accessor
  std::cout<<str.max_size()<<std::endl;
  //test copy constructor
  string copy_str(str);
  std::cout<<*copy_str.string_ptr_<<std::endl;


}


// display whole string
void display(const String str){
  for (int i=0 ; i<str.size_ ; i++) {
    std::cout<<str.string_ptr_[i];
  }
  std::cout<<std::endl;
}
