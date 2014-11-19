#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

int main(int argc, const char *argv[])
{
	cout << "test1" << endl;
    int a[][2] = {1,2,3,4};
    int (&b)[2][2] = a;//a的引用
    cout << b[0][0] << endl;

	cout << "test2" << endl;
    int a2[3][2] = {1,2,3,};
    int *p = a2[0];
    cout << p[3] << endl;

	cout << "test3" << endl;
    int a3[2][2] = {1,2,3,4};
    int (*p1)[2];
	int (*p2)[2][2];
    p1 = a3;
	p2 = &a3;
	cout << typeid(&a3).name() << endl;
	cout << typeid(a3).name() << endl;
	cout << p1[0][0] << endl;
	cout << p2[0][0][3] << endl;
	
	cout << "test4" << endl;
	char a4[] = {"abc"};
	a4[0] = 'b';
	cout << a4[2] << endl;
	//(char *)a4 += 1;//error
	cout << a4 << endl;
	
	cout << "test5" << endl;
	int a5[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
	int *p5 = (int *)(&a5 + 1);
	printf("%d_%d\n", *(int*)(a5+1), *(p5-1));
	
	
    return 0;
}
