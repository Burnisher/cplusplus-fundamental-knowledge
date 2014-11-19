#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

char *my_strcat(char *strDest, const char *strSrc)
{
	char *address = strDest;
	assert((strDest != NULL) && (strSrc != NULL));
	while(*strDest)
	{
		strDest++;
	}
	while(*strDest++ = *strSrc++);
	return address;												
}

int main(int argc, const char *argv[])
{
	char a[20] = {"hello "};
	char b[] = "world";
	cout << my_strcat(a, b) << endl;
	return 0;
}