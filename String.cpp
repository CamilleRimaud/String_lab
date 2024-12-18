/**
Groupe 4BIM - B
Student A : Paulène RIOU
Student B : Albane WEBER
Student C : Camille RIMAUD
**/

#include "String.h"
#include <iostream> //used only for displaying messages and results
#include <cstddef>//used only to be able to use the type size_t

// CONSTRUCTORS AND DESTRUCTOR
//initial default constructor : initialise a "Hello world" string
string::string(){
  capacity_ = 20;
  size_ = 15;
  char phrase[size_+1] = "Hello world !";
  string_ptr_ = new char [capacity_];
  for (size_t i=0; i<size_;i++){
    string_ptr_[i]=phrase[i];
  }
  string_ptr_[size_] = '\0';
}

/**
//final default constructor : initialise an empty string
string::string(){
  capacity_ = 10;
  size_ = 0;
  string_ptr_ = new char [capacity_];
  string_ptr_[size_] = '\0';
}
**/ 

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
  size_t len_cstring = 0;
  while (cstring[len_cstring]!='\0'){len_cstring++;}; // determine the length of cstring
  
  if (len_cstring < this->max_size_) { // only process the following instructions if size < max_size_
    this->size_ = len_cstring;
    this->capacity_ = this-> size_;
    this->string_ptr_ = new char [this->capacity_]; // initialise a pointer to string in the heap with the size "capacity"
    for (size_t i=0 ; i<size_ ; i++){
      this->string_ptr_[i] = cstring[i]; // associate char values to the string pointed to (values = char values from cstring, in the same order)
    }
    this->string_ptr_[size_] = '\0'; // add the null char at the end of the string produced by the constructor
  }
  else {std::cout<<"Error : you are trying to construct a string of length superior to the maximum size : " << this->max_size_ << ". Please use a shorter string.\n";}
}

//max_size_ accessor
size_t string::max_size(){
  return max_size_;
}

// length_accessor
size_t string::length(){
  return size_;
}

// resize function 
void string::resize(size_t new_size, char c){
  if (new_size > this->max_size_) {std::cout<<"Error : you are trying to resize a string with length superior to the maximum size : " << this->max_size_ << ". Please use a lower size.\n";}
  else if (new_size < this->size_) { // if the new string is shorter than the previous
    for (size_t i= new_size; i <= this->size_ ; i++) {
      this->string_ptr_[i]='\0'; // remove all extra characters
    }
    this->size_ = new_size; // update size_
    this->capacity_ = new_size; // update capacity_
  }
  else if (new_size > this->size_) { // if the new string is longer than the previous but still shorter than the maximum size authorized (otherwise we can't build it)
    if (new_size > this->capacity_) {
      this->reserve(new_size); // increase capacity up to new_size
    }
    for (size_t i= size_; i <= new_size+2; i++) {
      this->string_ptr_[i] = c; // add extra characters with value passed in parameters
    }
    this->size_ = new_size; // update size
  }
  this->string_ptr_[new_size] = '\0'; // add null pointer 
}


// operator= from a string : assign the string to another string passed in parameter
void string::operator=(const string& new_str) {
  size_t len = new_str.size_; // get the length of new_str
  this->resize(len,'c'); // update size_ and capacity_ according to parameter's size_ and capacity_
  *this->string_ptr_ = *new_str.string_ptr_; // update string value to parameter's string value
}

// operator+ from a character : concatenation of a character to the string
void string::operator+(char c) {
  this->resize(size_ + 1, c); // resize the string to size_ and capacity_ incremented by one, complete the string with character c passed as a parameter (use of the default behavior of resiez function, which automatically adds character indicated to the string when the new size is large
  //size_ and capacity_ of the string of concern are now updated as well as the pointer value (insertion of character c at the end of the string)
}


void string::display() const {
    for (size_t i = 0; i < size_; i++) {
        std::cout << string_ptr_[i];
    }
    std::cout << std::endl; // add a line break after displaying the string
}



// RESERVE YOUSSEF
void string::reserve(size_t n) {
  if (n > capacity_) {
    char* new_data = new char[n];
    for (size_t i = 0; i < size_; ++i) {
    new_data[i] = this->string_ptr_[i];		
    }	
    new_data[this->size_] = '\0';
    delete [] this->string_ptr_;
    this->string_ptr_ = new_data;
    this->capacity_ = n;
  }  
}
    









