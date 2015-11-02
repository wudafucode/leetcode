#include<vector>
#include<unordered_set>
#include<string>
using namespace std;
class Solution {
public:
      vector<string> totalresult;
      vector<string>  result;
      vector<int> totalflag;
    vector<string> wordBreak(string s, unordered_set<string> &dict) {

           totalflag.resize(s.size());
           findword(s,dict,0);
           return totalresult;

    }

    bool findword(string s, unordered_set<string> &dict,int index)
   {
        if(s.size() == 0)
       {
             GetResult();
             return true;
        }
       if(totalflag[index] == 1)
          return false;
         unordered_set<string>::const_iterator ite;
         string temp;
         string newstr;
         int flag=0;
         bool ret;
         int i=0,len=0;
         for(i=1; i<=s.size();i++)
          {

                temp=s.substr(0,i);

                if(dict.find(temp) != dict.end())
                {

                   // newstr = GetStr(s,temp,len);
                    len = temp.size();
                    newstr = s.substr(len,-1);
                    result.push_back(temp);

                     ret = findword(newstr,dict,index + len);
                     if(ret == true && flag ==0)
                     {

                         flag =1;
                     }
                     len = 0;
                     result.pop_back();
                   // ClearStr(temp);
                }
          }
        if(flag ==1)
        {
             return true;
        }
        else
        {
            if(index  < totalflag.size())
                totalflag[index ] = 1;
             return false;
        }


   }
   void  GetResult()
   {
     string temp;
     int i=0;
     for(i=0;  i < result.size()-1; i++)
     {
           temp +=result[i] +" ";
     }
     if(i<result.size())
     temp +=result[i];
     totalresult.push_back(temp);

   }
   void ClearStr(const string& temp)
   {
     int i = result.size()-1;
     for(; i>=0;i-- )
     {
           if(result[i] != temp)
            return ;
           if(result.size() !=0 )
            result.pop_back();
     }
   }
   string GetStr(string& s, const string& temp,int& len)
   {
      string patter;
       while(1)
       {
            patter = s.substr(len,temp.size());
            if(patter != temp)
              return  s.substr(len,-1);
            result.push_back(temp);
            len+=temp.size();

       }

     return "";
   }
};