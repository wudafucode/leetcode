#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
       string::reverse_iterator itea,iteb;
	   string result;
	   char temp;
	   int flag =0;
	   for(itea = a.rbegin(), iteb = b.rbegin(); itea != a.rend()&& iteb !=b.rend(); itea++, iteb++ )
	   {
         temp = GetResult(*itea,*iteb,flag);
		 if(temp >= 2)
		 {
           flag =1;
		   temp = temp%2;
		 }
		 else
		 {
          	flag =0;
		 }
		 result.insert(result.begin(),temp + '0');
	    }
	   for(; itea != a.rend(); itea++)
      	{
      	   temp = GetResult(*itea,'0',flag);
      	   if(temp >= 2)
      	   {
      		 flag =1;
      		 temp = temp%2;
      	   }
      	   else
      	   {
      		  flag =0;
      	   }
      	   result.insert(result.begin(),temp + '0');
      	}
	   for(; iteb != b.rend(); iteb++)
	   {
			 temp = GetResult(*iteb,'0',flag);
			 if(temp >= 2)
			 {
			   flag =1;
			   temp = temp%2;
			 }
			 else
			 {
				flag =0;
			 }
			result.insert(result.begin(),temp + '0');
	   }
	   if(flag != 0)
	   result.insert(result.begin(),'1');

	   return result;
        
    }
	char GetResult(char a, char b,int flag)
	{
	   char result;
	   a = a -'0';
	   b = b - '0';
	   result = a + b + flag;
	   return result;

	}
};
