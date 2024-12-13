#include "String.h"
#include <iostream>
#include <cstdlib>

int main(){
  //test default constructor
  String str;
  std::cout<<*str.string_ptr_<<std::endl;

  //test copy constructor
  String copy_str(str);
  std::cout<<*copy_str.string_ptr_<<std::endl;

}
