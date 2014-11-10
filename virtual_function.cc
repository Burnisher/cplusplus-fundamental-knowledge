#include <iostream>
#include <string>
#include <vector>
using namespace std;
//虚函数表的实现,了解虚函数表的构造过程
class Base
{
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
};

int main(int argc, const char *argv[])
{
    typedef void(*Fun) (void);
    Base b;
    Fun pFun = NULL;
    cout << "vptr address:" << (int *)(&b) << endl;
    cout << "虚函数表-第一个函数地址: " << (int*)*(int*)(&b) << endl;
    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();
    pFun = (Fun)*((int*)*(int*)(&b)+1);
    pFun();
    pFun = (Fun)*((int*)*(int*)(&b)+2);
    pFun();
    return 0;
}
