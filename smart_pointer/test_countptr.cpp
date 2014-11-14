#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "CountPtr.hpp"
using namespace std;

class Test
{
    public:
    Test() { cout << "Test" << endl; }
    ~Test() { cout << "~Test" << endl; }

    private:
    Test(const Test &);
    void operator=(const Test &);
};

int main(int argc, char const *argv[])
{
    CounterPtr<Test> ptr(new Test);

    vector<CounterPtr<Test> > coll;//由于使用了计数智能指针，放入vector不会发生控制权转移
    coll.push_back(ptr);//vector采用的拷贝模式，容易造成控制转移

    cout << "count = " << ptr.count() << endl;
    assert(!ptr.unique());

    return 0;
}
