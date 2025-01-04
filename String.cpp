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
  size_ = 13;
  char phrase[size_+1] = "Hello world !";
  string_ptr_ = new char [capacity_];
  for (size_t i=0; i<size_;i++){
    string_ptr_[i]=phrase[i];
  }
  string_ptr_[size_] = '\0';
}

//destructor
string::~string(){
  delete[] string_ptr_;
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

//copy constructor
string::string(const string &str){
  size_ = str.size_;
  capacity_ = str.capacity_;
  string_ptr_ = new char [size_+1];
  for (size_t i=0; i<size_+1 ; i++) {
    string_ptr_[i] = str.string_ptr_[i];
  }
}

//constructor from a c-string
string::string(const char* cstring){
  size_t len_cstring = 0;
  while (cstring[len_cstring]!='\0'){len_cstring++;}; // determine the length of cstring

  if (len_cstring < this->max_size_) { // only process the following instructions if size < max_size_
    this->size_ = len_cstring;
    this->capacity_ = this-> size_+1; // add one for the null character
    this->string_ptr_ = new char [this->capacity_]; // initialise a pointer to string in the heap with the size "capacity"
    for (size_t i=0 ; i<size_ ; i++){
      this->string_ptr_[i] = cstring[i]; // associate char values to the string pointed to (values = char values from cstring, in the same order)
    }
    this->string_ptr_[size_] = '\0'; // add the null char at the end of the string produced by the constructor
  }
  else {std::cerr<<"Error : you are trying to construct a string of length superior to the maximum size : " << this->max_size_ << ". Please use a shorter string.\n";}
}

// ACCESSSORS
// length_accessor
size_t string::length(){
  return size_;
}

// size_ accessor
size_t string::size(){
   return size_;
}

//max_size_ accessor
size_t string::max_size(){
  return max_size_;
}

// capacity_ accessor
size_t string::capacity(){
   return capacity_;
}

/*
// string_ptr accessor
char* string::string_ptr(){
  return string_ptr_;
}
*/

// MEMBER FUNCTIONS
// We added a "display" function to the class in order to check the results and be able to print strings produced by constructors and modified by function members
void string::display() const {
    if (string_ptr_ != nullptr) {
        for (size_t i = 0; i < size_; i++) {
            std::cout << string_ptr_[i];
        }
        std::cout << std::endl; // add a line break after displaying the string
    }
    else {
        std::cerr << "Erreur : string_ptr_ est un pointeur nul : impossible d'afficher une chaine de caractères." << std::endl;
    }
}

// reserve function : change the capacity for a change of size up to n characters
void string::reserve(size_t n) {
  if (n > capacity_){this->capacity_ = n;}
  else {std::cerr<<"Error : the requested capacity must be superior to the current capacity : "<<this->capacity_<<". Please use a lower capacity.\n";}
}

// resize function
/** Specifications : la taille donnée en paramètre doit être un entier positif pour correspondre à size_t, c doit être un caractère compris entre des guillemets simples**/
void string::resize(size_t new_size, char filling_char){
  if (new_size > this->max_size_) {std::cerr<<"Error : you are trying to resize a string with length superior to the maximum size : " << this->max_size_ << ". Please use a lower size.\n";}
  else if (new_size < this->size_) { // if the new string is shorter than the previous
    for (size_t i= new_size; i < this->size_ ; i++) {
      this->string_ptr_[i]='\0'; // remove all extra characters
    }
    this->size_ = new_size; // update size_
    this->capacity_ = new_size+1; // update capacity_
  }
  else if (new_size > this->size_) { // if the new string is longer than the previous but still shorter than the maximum size authorized (otherwise we can't build it)
    char* new_string_ptr = new char[new_size + 1]; // add one for null character
    if (new_size > this->capacity_) {
      this->reserve(new_size); // increase capacity up to new_size
    }
    for (size_t i= size_; i < new_size; i++) {
      new_string_ptr[i] = filling_char; // add extra characters with value passed in parameters
    }
    new_string_ptr[new_size] = '\0'; // add null pointer
    this->size_ = new_size; // update size
    delete[] this->string_ptr_; //liberate memory of former string pointer
    // reallocate pointer and size
    this->string_ptr_ = new_string_ptr;
    this->size_ = new_size;
  }

  // In case new_size == this->size : we don't need to do anything
}


// clear function : erase the content of a string (no characters left)
void string::clear(){
  this->size_=0;
  char * ptr = new char[size_+1];
  ptr[0]='\0';
  for (size_t i=0; i<size_+1; i++){
    string_ptr_[i]=ptr[i];
  }
  delete[] ptr;
}

// empty function : check if the string is empty (return 0 if false, 1 if true)
bool string::empty(){
  if (this->size_==0){
    return true;
  }
  return false;
}


// c_str function : create a c-string from a string
const char* string::c_str() {
  char * string_ptr_ = new char[this->size_+1];
  for (size_t i=0; i<size_ ; i++) {
    string_ptr_[i] = this->string_ptr_[i];
  }
  string_ptr_[this->size_]='\0';
  return string_ptr_;
}


// OPERATORS
// operator=(char) function
void string::operator=(char c){
  this->size_=1;
  char * str_c = new char [size_+1];
  str_c[0]=c;
  for (size_t i=0; i<size_+1; i++){
    string_ptr_[i]=str_c[i];
  }
  delete[] str_c;
}

// operator= from a string : assign the string to another string passed in parameter
/** Specifications : the parameter must be of type string (an instance of the class string) **/
void string::operator=(const string& new_str) {
  size_t len = new_str.size_; // get the length of new_str
  this->resize(len,'c'); // update size_ and capacity_ according to parameter's size_ and capacity_
  *this->string_ptr_ = *new_str.string_ptr_; // update string value to parameter's string value
}

// operator= from a c-string : assign the c-string to the current string
void string::operator=(const char* s){
  size_t len_s = 0;
  while (s[len_s]!='\0'){len_s++;}; // determine the length of cstring
  char c ='i';
  this->resize(len_s, c);
  for (size_t i=0; i < size_; i++){
    string_ptr_[i]=s[i];
  }
}

// operator+ from a c-string : concatenation of a c-string to the string
// operator+(const string&, const char*)
void string::operator_concat(const char* ptr) {
  this->size_ = this->size_+1;
  if (size_<this->max_size_){
    this->capacity_ = this->size_;
    string_ptr_[size_-1]=*ptr;
  }
  else
  {
  std::cout<<"La taille de la chaine de caractére dépasse la taille limite imposée"<<std::endl;
  }
}

// operator+ from a character : concatenation of a character to the string
/** Specifications : the parameter must be a single character **/
void string::operator+(char c) {
  this->resize(size_ + 1, c); // resize the string to size_ and capacity_ incremented by one, complete the string with character c passed as a parameter (use of the default behavior of resiez function, which automatically adds character indicated to the string when the new size is large
  //size_ and capacity_ of the string of concern are now updated as well as the pointer value (insertion of character c at the end of the string)
}

// operator+ from a string : concatenation of a second string to the string
void string::operator+(const string& str) {
  size_t old_size_ = size_;
  size_t new_size_ = size_ + str.size_;
  char c ='i';
  this->resize(new_size_, c);
  for (size_t i=0; i<size_; i++){
    string_ptr_[i+old_size_]=str.string_ptr_[i];
  }
}
