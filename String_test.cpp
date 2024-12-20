#include "String.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>

void display(const string str);
//friend string operator_concat(const string &str, const char* ptr);


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
  //test size accessor
  std::cout<<"Début test size accessor"<<std::endl;
  std::cout<<str.size()<<std::endl;
  std::cout<<"Fin test size accessor"<<std::endl;
  
  //test copy constructor
  std::cout<<"Début test copy constructor"<<std::endl;
  std::cout<<"String copié : "<<str.string_ptr_<<", Size : "<<str.size()<<", Capacity : "<<str.capacity_<<std::endl;
  string copy_str(str);
  std::cout<<copy_str.string_ptr_<<std::endl;
  copy_str.display();
  std::cout<<"Fin test copy constructor"<<std::endl;
  
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

  //test c_str function
  std::cout<<"Début test c_str"<<std::endl;
  const char* c_str = str.c_str();
  std::cout<<*c_str<<std::endl;
  std::cout<<c_str<<std::endl;
  std::cout<<"Fin test c_str"<<std::endl;

  //test clear fonction
  std::cout<<"Début test clear"<<std::endl;
  string str_clear;
  std::cout<<*str_clear.string_ptr_<<std::endl;
  std::cout<<str_clear.string_ptr_<<std::endl;
  str_clear.clear();
  std::cout<<str_clear.size()<<std::endl;
  std::cout<<*str_clear.string_ptr_<<std::endl;
  std::cout<<str_clear.string_ptr_<<std::endl;
  std::cout<<"Fin test clear"<<std::endl;

  //test operator=(char) fonction
  std::cout<<"Début test operator=(char)"<<std::endl;
  string str_ope;
  std::cout<<*str_ope.string_ptr_<<std::endl;
  std::cout<<str_ope.string_ptr_<<std::endl;
  char v = 'v';
  str_ope.operator=(v);
  std::cout<<v<<std::endl;
  std::cout<<str_ope.size()<<std::endl;
  std::cout<<*str_ope.string_ptr_<<std::endl;
  std::cout<<str_ope.string_ptr_<<std::endl;
  std::cout<<&str_ope.string_ptr_<<std::endl;
  std::cout<<"Fin test operator=(char)"<<std::endl;

  //test operator+(const string&, const char*) fonction
  std::cout<<"Début test operator+(const string&, const char*)"<<std::endl;
  const char p = 'p';
  const char* p_ptr = &p;
  string str_ope_concat;
  std::cout<<"Ajout du caractére p à la fin du string : "<<str_ope_concat.string_ptr_<<std::endl;
  str_ope_concat.operator_concat(p_ptr);
  std::cout<<"Résultat : "<<str_ope_concat.string_ptr_<<std::endl;
  std::cout<<"Size de la chaine de caractéres : "<<str_ope_concat.size()<<std::endl;
  std::cout<<"Fin test operator+(const string&, const char*)"<<std::endl;


  //test operator= from a string
  string str2;
  str2.resize(4,'c');
  string str3;
  str2.display();
  str3.display();
  str3.operator=(str2);
  str3.display();
  //test operator+ from a string and a char
  string str4;
  str4.operator+('g');
  str4.display();
}

