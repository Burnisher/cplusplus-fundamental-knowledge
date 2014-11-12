#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    char str[] = "glad to test something";
    char *p = str;
    p++;
    //int *p1 = static_cast<int *>(p)//错误，不可隐式转换
    int *p1 = (int *)(p);
    p1++;
    p = (char *)(p1);
    cout << p << endl;

    return 0;
}
