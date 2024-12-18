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
  copy_str.display();
  //test resize function
  string str1;
  str1.display();
  std::cout<<str1.length()<<std::endl;
  str1.resize(30,'c');
  std::cout<<str1.length()<<std::endl;
  str1.display();
  str1.resize(3,'c');
  std::cout<<str1.length()<<std::endl;
  str1.display();
  str1.resize(130,'c');
  std::cout<<str1.length()<<std::endl;
  str1.display();
  
  //test operator= from a string
  string str2;
  str2.resize(4,'c');
  string str3;
  str2.display();
  str3.display();
  str3.operator=(str2);
  str3.display();
  /**
  //test operator+ from a string and a char
  string str4
  str3 = operator+(str4,'g');
  str4.display();
 **/
}


