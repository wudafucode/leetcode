#include <limits>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL)
		return 0;
		int i=0;
		int flag =1;
	
		string tempstr;

		while(str[i] != '\0')
		{
           if(str[i] == ' ')
		   	 i++;
		   else
		   	 break;
		}
	
		if(str[i] == '-')
		{
           flag =-1;
		   i++;
		}
		else if(str[i] == '+')
		{
		   i++;
		}
		while(str[i] != '\0')
		{
           if(str[i] == '0')
		   	 i++;
		   else
		   	 break;
		}  
		long long data = 0;
		while(str[i] != '\0')
		{
		  if(str[i]>='0' && str[i]<='9')
		  {
          
			data = data * 10 + flag * (str[i]- '0');	
			if(flag > 0 && data > numeric_limits<int>::max())
			 return numeric_limits<int>::max();
			if(flag < 0 && data < numeric_limits<int>::min())
			 return numeric_limits<int>::min();
		  }
		  else
		  {
             break;
		  }

          i++;
		}
		
		
        return data;
		
        
    }
};