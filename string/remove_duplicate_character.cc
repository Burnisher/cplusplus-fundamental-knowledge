#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void removeDuplicates1(char *str)
{
	if(str == NULL)
		return;
	int len = strlen(str);
	if(len < 2)
		return;
	int tail = 1;
	for(int i = 1; i < len; ++i)
	{
		int j;
		for(j = 0; j < tail; ++j)
		{
			if(str[i] == str[j])
				break;
		}
		if(j == tail)
		{
			str[tail++] = str[i];
		}
	}
	str[tail] = '\0';
}

void removeDuplicates2(char *str)
{
	if(str == NULL)
		return;
	int len = strlen(str);
	if(len < 2)
		return;
	bool hit[256];
	for(int i = 0; i < 256; ++i)
		hit[i] = false;
	hit[str[0]] = true;
	int tail = 1;
	for(int i = 1; i < len; ++i)
	{
		if(!hit[str[i]])
		{
			str[tail++] = str[i];
			hit[str[i]] = true;
		}
	}
	str[tail] = '\0';
}


int main(int argc, const char* argv[])
{
	char a[] = "aaabbb";
	char b[] = "abababa";
	removeDuplicates1(a);
	removeDuplicates2(b);
	cout << a << endl;
	cout << b << endl;
	return 0;
}