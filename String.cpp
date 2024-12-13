/**
Groupe 4BIM - B
Student A : Paulène RIOU
Student B : Albane WEBER
Student C : Camille RIMAUD
**/

#include "String.h"

//default constructor
string::string(){
  capacity_ = 20;
  size_ = 15;
  char phrase[size_+1] = "Hello world !";
  string_ptr_ = new char [capacity_];
  for (int i=0; i<size_;i++){
    string_ptr_[i]=phrase[i];
  }
  string_ptr_[size_] = '\0';
}

//destructor
string::~string(){
  delete[] string_ptr_;
}

//copy constructor
string::string(const string &str){
  size_ = str.size_;
  capacity_ = str.capacity_;
  string_ptr_ = new char [size_+1];
  *string_ptr_ = *str.string_ptr_;
}

//constructor from a c-string
string::string(const char* cstring){
  int len_cstring = 0;
  while (cstring[len_cstring]!='\0'){len_cstring++;};
  this->size_ = len_cstring;
  this->capacity_ = this-> size_;
  this->string_ptr_ = new char [this->capacity_];
  for (int i=0 ; i<size_ ; i++){
    this->string_ptr_[i] = cstring[i];
  }
  this->string_ptr_[size_] = '\0';
}

//max_size_ accessor
int string::max_size(){
  return max_size_;
}

// length_accessor
int string::length(){
  return size_;
}
