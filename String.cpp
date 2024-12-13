/**
Groupe 4BIM - B
Student A : Paulène RIOU
Student B : Albane WEBER
Student C : Camille RIMAUD
**/

#include "String.h"

//default constructor
String::String(){
  capacity_ = 20;
  size_ = 7;
  char phrase[size_+1] = "Hello world !";
  string_ptr_ = new char [capacity_];
  string_ptr_ = phrase;
  string_ptr_[size_] = '\0';
}

// constructor from a c_string
String::String(const char* cstring){
  int len_cstring = 0;
  while (cstring[len_cstring]!='\0'){len_cstring++;}
  this->size_ = len_cstring;
  this->capacity_ = this-> size_;
  this->string_ptr_ = new char [this->capacity_];
  for (int i=0 ; i<size_; i++){
    this->string_ptr_[i] = cstring[i];
  }
  this->string_ptr_[size_] = '\0';
}

// length accessor
int String::length(){
  return size_;
}
