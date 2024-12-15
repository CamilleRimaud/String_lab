#ifndef STRING_H
#define STRING_H

class string{
  public:
    string();
    ~string();
    string(const string &str);
    string(const char* cstring);

    int length();
    int max_size();
/**
    void resize(int new_size, char c);
    void operator=(const string& new_str);
    string operator+(const string& str, char c);
**/

    char* string_ptr_;
    int size_;
    int capacity_;
    int max_size_ = 100;

  private:

};


#endif
