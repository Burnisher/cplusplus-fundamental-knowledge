#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

int my_strlen(const char *str)
{
	assert(str != NULL);
	int len = 0;
	while((*str++) != '\0')
		len++;
	return len;
}

int main()
{
	char a[] = {"hello world"};
	cout << my_strlen(a) << endl;
	
}