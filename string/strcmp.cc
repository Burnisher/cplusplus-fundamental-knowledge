#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

int my_strcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	int ret = 0;
	while(!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str1)
	{
		str1++;
		str2++;
	}
	if(ret<0)
		ret = -1;
	else if(ret > 0)
		ret = 1;
	return ret;
}

int main(int argc, const char *argv[])
{
	char a[] = "hello";
	char b[] = "hello";
	char c[] = "hell";
	char d[] = "world";
	cout << my_strcmp(a, b) << endl;
	cout << my_strcmp(a, c) << endl;
	cout << my_strcmp(a, d) << endl;
	return 0;
	
}