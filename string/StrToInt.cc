#include <iostream>
#include <limits>
using namespace std;

int StrToInt(const char *str)
{
	int long long num = 0;
	if(str != NULL)
	{
		const char *digit = str;
		bool minus = false;
		if(*digit == '+')
			digit ++;
		else if(*digit == '-')
		{
			digit ++;
			minus = true;
		}
		
		while(*digit != '\0')
		{
			if(*digit >= '0' && *digit <= '9')
			{
				num = num*10 + (*digit - '0');
				if(num > std::numeric_limits<int>::max())
				{
					num = 0;
					break;
				}
				digit ++;	
			}
			else
			{
				num = 0;
				break;
			}
		}		
		if(*digit == '\0')
		{
			if(minus)
				num = num*(-1);
		}
	}
	return (int)num;
	
}
int main(int argc, const char *argv[])
{
	char a[] = "123";
	char b[] = "-11";
	char c[] = "123f";
	char d[] = "1222222222222222222222222";
	cout << StrToInt(a) << endl;
	cout << StrToInt(b) << endl;
	cout << StrToInt(c) << endl;
	cout << StrToInt(d) << endl;
	cout << StrToInt(a) << endl;
	return 0;
}