#include<map>
using namespace std;

class Solution {
public:

    int romanToInt(string s) {
	    int data[26] = {0};
		data['I'-'A'] = 1;
		data['V'-'A'] = 5;
		data['X'-'A'] = 10;
		data['L'-'A'] = 50;
		data['C'-'A'] = 100;
		data['D'-'A'] = 500;
		data['M'-'A'] = 1000;

		int result = 0;
		int value = 0;
		int i= 0;
		for( i=0; i<s.size()-1;i++)
		{
            if(s[i]<'A' || s[i] >'Z')
			 return 0;
		    if(data[s[i]-'A'] >= data[s[i+1]-'A'])
		    {
               result +=data[s[i]-'A'];
			}
			else
			{
               result += data[s[i+1]-'A'] - data[s[i]-'A'];
			   i++;
			}
		}
		if(i == s.size()-1)
		{
           result += data[s[i]-'A'] ;
		}
		return result;
	}
	   
};