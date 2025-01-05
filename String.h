#include <cstddef>

#ifndef STRING_H
#define STRING_H

class string{
  public:
    string();
    ~string();
    string(const string &str); //copy constructor
    string(const char* cstring);

    char* string_ptr_; // pointer to the array of characters

    size_t length(); // same as size() accessor
    size_t size(); // same as length() accessor
    size_t max_size();
    size_t capacity();

    // We added a "display" function to the class in order to check the results and be able to print strings produced by constructors and modified by function members
    void display() const;

    void reserve(size_t n);
    void resize(size_t new_size, char c);
    void clear();
    bool empty();

    const char* c_str();

    void operator=(char c);
    void operator=(const string& new_str);
    void operator=(const char* s);


    void operator+(const char* ptr);
    void operator+(char c);
    void operator+(const string& str);


  protected:
    size_t size_;
    size_t max_size_ = 100;
    size_t capacity_;


};


#endif
