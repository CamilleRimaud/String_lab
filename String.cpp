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
  while (cstring[len_cstring]!='\0'){len_cstring++;}; // determine the length of cstring
  if (len_cstring < this->max_size_) { // only process the following instructions if size < max_size_
    this->size_ = len_cstring;
    this->capacity_ = this-> size_;
    this->string_ptr_ = new char [this->capacity_]; // initialise a pointer to string in the heap with the size "capacity"
    for (int i=0 ; i<size_ ; i++){
      this->string_ptr_[i] = cstring[i]; // associate char values to the string pointed to (values = char values from cstring, in the same order)
    }
    this->string_ptr_[size_] = '\0'; // add the null char at the end of the string produced by the constructor
  }
}
// NB : we could send an error message when the size passed as a parameter exceeds max_size_, we won't though, since we are not supposed to include any library, included <iostream>

//max_size_ accessor
int string::max_size(){
  return max_size_;
}

// length_accessor
int string::length(){
  return size_;
}

/**
// resize function 
void string::resize(int new_size, char c){
  if (new_size < this->size_) { // if the new string is shorter than the previous
    for (int i= new_size + 2 ; i <= this->size_ ; i++) {
      this->string_ptr_[i]=0; // remove all extra characters
    }
    this->size_ = new_size; // update size_
    this->capacity_ = new_size; // update capacity_
  }
  if (new_size > this->size_) { // if the new string is longer than the previous
    if (new_size > this->capacity_) {
      this->reserve(new_size) // increase capacity up to new_size
    }
    for (int i= size_ + 1 ; i <= new_size ; i++) {
      this->string_ptr_[i] = c; // add extra characters with value passed in parameters
    }
    this->size_ = new_size; // update size
  }
  this->string_ptr_[new_size + 1] = '\0'; // add null pointer 
}

// operator= from a string
void string::operator=(const string& new_str) {
  int len = new_str.size_; // get the length of new_str
  this->resize(len,'c'); // update size_ and capacity_ according to parameter's size_ and capacity_
  *this->string_ptr_ = *new_str.string_ptr_; // update string value to parameter's string value
}

// concatenation of a string and a character
string string::operator+(const string& str, char c) {
  string concat_str; // call to default constructor to build a string;
  concat_str.resize(str.size_ + 1); // resize the newly created string to match to wanted size and minimum capacity
  //size_ and capacity_ of concat_str are now updated
  *concat_str.string_ptr = *str.string_ptr_;
  *concat_str.string_ptr_[size_] = c;
  *concat_str.string_ptr_[size_+1] = '\0';
  return concat_str;
}
**/

