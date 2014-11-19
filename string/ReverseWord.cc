#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void Reverse(char *pb, char *pe)
{
	if(pb == NULL || pe == NULL)
		return;
	while(pb < pe)
	{
		char tmp = *pb;
		*pb = *pe;
		*pe = tmp;
		pb ++, pe --;
	}
}

char * ReverseSentence(char *pData)
{
	if(pData == NULL)
		return NULL;
		
	char *pBegin = pData;
	char *pEnd = pData;
	while(*pEnd != '\0')
	{
		pEnd++;
	}
	pEnd --;
	Reverse(pBegin, pEnd);
	
	pBegin = pEnd = pData;
	while(*pBegin != '\0')
	{
		if(*pBegin == ' ')
		{
			pBegin ++;
			pEnd ++;
			continue;
		}
		else if(*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
			continue;
		}
		else 
			pEnd ++;
	}
	return pData;
}
int main(int argc, const char *argv[])
{
	char a[] = " hello world how are you ?";
	cout << ReverseSentence(a) << endl;
	return 0;
}