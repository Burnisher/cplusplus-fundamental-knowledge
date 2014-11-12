#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

//typeid 的适用场景
//返回动态类型信息
class A
{
    private:
        int x_;
    public:
        A(int i = 0):x_(i) {}
        void virtual print() const
        { cout << x_ << " A" << endl; }
};

class B : public A
{
    private:
        int y_;
    public:
        B(int i = 0):A(1), y_(i) {}
        void print() const 
        { 
            A::print(); 
            cout << y_ << " B" << endl;
        }
};


int main(int argc, const char *argv[])
{
    cout << typeid(A).name() << endl;
    cout << typeid(A *).name() << endl;
    
    A *pa = new B(1);
    pa -> print();

    A *p1 = new A(1);
    A *p2 = new A(2);

    cout << (typeid(*pa) == typeid(B)) << endl;
    cout << (typeid(p1) == typeid(p2)) << endl;
    cout << (typeid(*p1) == typeid(*p2)) << endl;
   
    return 0;
}
