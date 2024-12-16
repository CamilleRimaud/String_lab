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
    
    // We added a "display" function to the class in order to check the results and be able to print strings produced by constructors and modified by function members
    void display() const;
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
