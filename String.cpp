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
  size_ = 15;
  char phrase[size_+1] = "Hello world !";
  string_ptr_ = new char [capacity_];
  for (int i=0; i<size_;i++){
    string_ptr_[i]=phrase[i];
  }
  string_ptr_[size_] = '\0';
}

//copy constructor
String::String(const String &str){
  size_ = str.size_;
  capacity_ = str.capacity_;
  string_ptr_ = new char [size_+1];
  *string_ptr_ = *str.string_ptr_;
}
