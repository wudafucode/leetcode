#include<unordered_map>
class Solution {
public:

	typedef pair<int,string> Sdata;
    string intToRoman(int num) {
         Sdata pattern[] = {
		 	                pair<int,string>(1000,"M"),
                            pair<int,string>(900,"CM"),
                            pair<int,string>(500,"D"),
                            pair<int,string>(400,"CD"),
                            pair<int,string>(100,"C"),
                            pair<int,string>(90,"XC"),
                            pair<int,string>(50,"L"),
                            pair<int,string>(40,"XL"),
                            pair<int,string>(10,"X"),
                            pair<int,string>(9,"IX"),
                            pair<int,string>(5,"V"),
                            pair<int,string>(4,"IV"),
                            pair<int,string>(1,"I"),
		 };
		 
		 string str[]={
		 	         "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"
		 };
         //unordered_map<int,string> buf;
		 //cout<<sizeof(Sdata)<<endl;
		 //cout<<sizeof(pattern[0])<<endl;
		 //for(int i=0; i<sizeof(pattern)/sizeof(pattern[0]);i++)
		 //	buf.insert(pattern[i]);
		 string result;
		 int index = 0;
		 for(int i=0; i<sizeof(pattern)/sizeof(pattern[0]);i++)
		 {
         	 
                index = num/pattern[i].first;
				num   = num%pattern[i].first;
				int j = hashfunction(pattern[i].first);
				while(index >0)
				{
                   result +=str[j];
				   index--;
				}
		 }
        return result;
    }
	int hashfunction(int num)
	{
        int index = 0;
		int result = 0;
		if(num >=100)
		{
           index =2;
		   num = num/100;
		}
		else if(num >=10)
		{
           index =1;
		   num = num/10;
		}
		switch(num)
		{
		 case 10:
		 	result = 12;
		    break;
         case 9:
		 	result = index*4 + 3;
			break;
		 case 5:
		 	result = index*4 + 2;
			break;
		case 4:
	 	    result = index*4 + 1;
		    break;
		case 1:
	 	    result = index*4 + 0;
		    break;
		default:
		 	result = 0;
			break;
		}
		return result;
	}
};