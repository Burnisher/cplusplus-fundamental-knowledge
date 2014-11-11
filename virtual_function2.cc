#include <iostream>
#include <string>
#include <vector>
using namespace std;
//虚基类表指针（bptr）
//虚基类只存在一个实体


class X { int a; char b; char c; };
class Y:public virtual X{};
class Z:public virtual X{};
class A:public Y, public Z{ char m;};

int main(int argc, const char *argv[])
{
    cout << "sizeof(X) : " << sizeof(X) << endl;
    cout << "sizeof(Y) : " << sizeof(Y) << endl;
    cout << "sizeof(Z) : " << sizeof(Z) << endl;
    cout << "sizeof(A) : " << sizeof(A) << endl;
    return 0;
}

