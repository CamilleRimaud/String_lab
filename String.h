#ifndef STRING_H
#define STRING_H

class string{
  public:
    string();
    ~string();
    string();
    string(const string &str);
    string(const char* cstring);

    int length();
    int max_size();


    char* string_ptr_;
    int size_;
    int capacity_;
    int max_size_ = 100;

  private:

};


#endif
