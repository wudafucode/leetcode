#include <string>
using namespace std;
class Solution {
public:
	vector<int> buf;
    int strStr(char *haystack, char *needle) {
        int index =0;
		if(needle == NULL || haystack == NULL)
		return 0;
		string strhay  = haystack;
		string strneed = needle;
		if(strneed.size()==0)
		return 0;
		if(strhay.size() == 0)
		return -1;
		
		buf.resize(strneed.size());
	    bool flag = false;
	
		
		Getdata(strneed);
		int j=0,i=0;
        for( i=0; i<strhay.size(); i++)
        {
           if(strhay[i] == strneed[j])
           { 

		     
              if(j == strneed.size()-1)
              {
                  flag = true;
				  break;
			  }
              j++;
		   }
		   else
		   {
              while(buf[j]!=0)
              {
                 j= buf[j];
				 if(strhay[i] == strneed[j])
				 	break;
			  }
			  j=buf[j];
		   }

		}
	   if(flag == true)
	   {
          return i-j;
	   }
	   else
	   	return -1;
       return strhay.find(strneed);
		
    }
    void Getdata(string& strneed)
    {
      buf[0]=0;
	  int repeatnum = 0;
	  int index ;
	  for(int i=1; i<strneed.size(); i++)
	  {
	     if(repeatnum != 0)
	     {
            index = repeatnum ;
		 }
		 else
		 {
            index =0;
		 }
	     if(strneed[i] == strneed[index])
	     {
	         buf[i]    = repeatnum;
             repeatnum++;
		 }
		 else
		 {
           buf[i] = repeatnum;
		   repeatnum = buf[repeatnum];

		 }
        
		 

	  }
	}
	
};
bool test1()
{
	Solution msol;
	int result;
	result = msol.strStr("abcabcfabc","abc");




	 
	return true;

}
bool test2()
{
    
	Solution msol;
	int result;
    result = msol.strStr("mississippi","issip");
	return true;
	

}