#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void trim_space(char *s)
{
	int i = 0, j = 0;
	while(s[j] == ' ')
		j++;
	int len = strlen(s) - 1;
	while(s[len] == ' ')
		len--;
	s[len+1] = '\0';
	while(s[j] != '\0')
	{
		while(s[j] == ' ')
			j++;
		if(s[j-1] == ' ' && i != 0)
			s[i++] = ' ';
		s[i++] = s[j++];
	}
	s[i] = '\0';
}

int main(int argc, const char* argv[])
{
	char a[] = " hello world how are you !";
	trim_space(a);
	cout << a << endl;
	return 0;
}