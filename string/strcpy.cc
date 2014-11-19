#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

char *my_strcpy(char *strDest, const char *strSrc)
{
	assert(strDest != NULL && strSrc != NULL);
	char *strD = strDest;
	while((*strDest++ = *strSrc++) != '\0');
	return strD;
}

int main(int argc, const char *argv[])
{
	char a[20] = "hello";
	char b[] = "world";
	cout << my_strcpy(a, b) << endl;
	return 0;
}