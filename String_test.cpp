#include "String.h"
#include <iostream>
#include <cstdlib>

void display(const string str);


int main(){
  //test default constructor
  string str;
  std::cout<<*str.string_ptr_<<std::endl;
  str.display();
  //test constructor from c-string
  char cstr[51] = " "; 
  std::cout << "Please write a word of maximum 50 characters, with no space in between the letters, right here :" << std::endl;
  std::cin >> cstr;
  string str_bis(cstr);
  str_bis.display();
  //test length accessor
  std::cout<<str.length()<<std::endl;
  //test maximum size accessor
  std::cout<<str.max_size()<<std::endl;
  //test copy constructor
  string copy_str(str);
  std::cout<<*copy_str.string_ptr_<<std::endl;
  /**
  //test resize function
  string str1;
  display(str1);
  str1.resize(30,'c');
  display(str1);
  str1.resize(3,'c');
  display(str1);
  str1.resize(130,'c');
  display(str1);
  //test operator= from a string
  string str2;
  str2.resize(4,'c');
  string str3;
  display(str2);
  display(str3);
  str3.operator=(str2);
  display(str3);
  //test operator+ from a string and a char
  str3 = operator+(str3,'g');
  display(str3);
  **/
}


