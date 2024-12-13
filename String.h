#ifndef STRING_H
#define STRING_H

class String{
  public:
    String();
    String(const char* cstring);


    char* string_ptr_;
    int size_;
    int capacity_;
    int max_size_ = 100;

  private:

};


#endif
