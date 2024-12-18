#include <cstddef>

#ifndef STRING_H
#define STRING_H

class string{
  public:
    string();
    ~string();
    string(const string &str);
    string(const char* cstring);

    size_t length();
    size_t max_size();
    
    // We added a "display" function to the class in order to check the results and be able to print strings produced by constructors and modified by function members
    void display() const;
    
    void resize(size_t new_size, char c);
    void operator=(const string& new_str);
    void operator+(char c);
    void reserve(size_t n);

    char* string_ptr_;
    size_t size_;
    size_t capacity_;
    size_t max_size_ = 100;

  protected:

};


#endif
