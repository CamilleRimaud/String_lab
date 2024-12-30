#include <cstddef>

#ifndef STRING_H
#define STRING_H

class string{
  public:
    string();
    ~string();
    string(const string &str); //copy constructor
    string(const char* cstring);

    size_t length();
    size_t max_size();
    size_t size();
    size_t capacity();

    // We added a "display" function to the class in order to check the results and be able to print strings produced by constructors and modified by function members
    void display() const;

    void resize(size_t new_size, char c);
    void operator=(const string& new_str);
    void operator+(char c);
    void reserve(size_t n);

    bool empty();
    void operator=(const char* s);

    const char* c_str();
    void clear();
    void operator=(char c);
    void operator_concat(const char* ptr);

    char* string_ptr_;

  protected:
    size_t size_;
    size_t max_size_ = 100;
    size_t capacity_;


};


#endif
