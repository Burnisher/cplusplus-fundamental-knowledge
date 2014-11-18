#include <iostream>
#include <string.h>
using namespace std;

class String 
{
public:
    String();
    String(const char *s); //转化语义
    String(const String &s);
    String(String &&s);
    ~String();

    String &operator=(const String &s);
    String &operator=(String &&s);

    friend ostream &operator<<(ostream &os, const String &s)
    {
        return os << s.data_;
    }


private:
    char *data_;
};

String::String()
    :data_(new char[1])
{
    *data_ = 0;
    cout << "default" << endl;
}


String::String(const char *s) 
    :data_(new char[::strlen(s) + 1])
{
    ::strcpy(data_, s);
    cout << "char *" << endl;
}

String::String(const String &s)
    :data_(new char[::strlen(s.data_) + 1])
{
    ::strcpy(data_, s.data_);
    cout << "copy" << endl;
}
   

String::String(String &&s)
    :data_(s.data_)
{
    cout << "move construct" << endl;
    s.data_ = NULL;
}


String:: ~String()
{
    delete[] data_;
    data_ = NULL;
}

String &String::operator=(const String &s)
{
    if(this != &s)
    {
        delete[] data_;
        data_ = new char[::strlen(s.data_) + 1];
        ::strcpy(data_, s.data_);
    }
    return *this;
}


String &String::operator=(String &&s)
{
    if(this != &s)
    {
        cout << "move assignment" << endl;
        delete[] data_;
        data_ = s.data_;
        s.data_ = NULL; //防止释放data
    }

    return *this;
}

int main(int argc, const char *argv[])
{
    String s("foo");
    String s2(s);
    String s3(std::move(String("bar")));//先char*，后move
    String s4(String("bar")); //编译器优化 直接使用char*
    cout << s3 << endl;
    cout << endl;

    s3 = s;
    s3 = String("hello");
    cout << s3 << endl;
    s3 = std::move(s2);//移动语义
    cout << s3 << endl;
    return 0;
}
