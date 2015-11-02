#include<vector>
#include<string>
using namespace std;

class Solution{
public:
	vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
     int len = s.length();
	 vector<string> soloresult;

	 if(s.length() == 0)
	 return result;
     vector<vector<int>> buf(len, vector<int>(len));
     dp(s,buf);
     ds(s,buf,0,soloresult);;

	 return result;
	 
    }
	void ds(const string &s,vector<vector<int>>& buf,int index,vector<string>& soloresult)
    {
     
      for(int i=index ; i<s.length();i++)
      {
        if(buf[index][i] == 1)
        {
            soloresult.push_back(s.substr(index,i-index +1));
			if(i == s.length()-1)
			{
                result.push_back(soloresult);
			}
			else
			{
                ds(s,buf,i+1,soloresult);
			}
			soloresult.pop_back();
		}


	  }
	}
	void dp(const string& s,vector<vector<int>>& buf)
    {
      for(int i=s.length()-1; i>=0;i--)
        for(int j=i; j<s.length();j++)
        {
            if(i == j)
            {
               buf[i][j] =1;
			}
			else
			{
                if(s[i] == s[j])
                {
                   if(i+1 >= j-1 || buf[i+1][j-1] == 1)
                   {
                       buf[i][j] = 1;
				   }
				}

			}

		}
	}
	
};
bool test1()
{
	Solution msol;
	vector<vector<string>> buf;
	string result;
	string word = "a";

	buf = msol.partition(word);

	return true;

}
bool test2()
{
    
	Solution msol;
	vector<vector<string>> buf;
	string result;
	string word = "aab";

	buf = msol.partition(word);

	return true;
	

}

class Solution1 {
public:
	vector<int> buf;
    vector<vector<string>> partition(string s) {
   
       GetNum(s);

        
    }
	void GetNum(string& s)
    {
       string temp;
       for(int i=0; i<s.size();i++)
       {
       		temp.push_back('#');
			temp.push_back(s[i]);
	   }
	   temp.push_back('#');
	   buf.resize(temp.size());
	   int len = 0;
	   int maxindex = 0;
	   buf[0] = 0;
	   for(int i= 1; i<temp.size(); i++)
	   {
	     if(buf[maxindex] > i - maxindex)
	     {

		 
	     }
         len = GetLen(i,temp);
		 buf[i] = len;

	   }

	}
	int GetLen(int index, string& s)
	{
        int num = 0;
		while((index - num > 0) && (index + num < s.size()))
	    {
           if(s[index-num] != s[index + num])
		   	break;
		   num++;
		   	
		}
		return num;

	}
};

