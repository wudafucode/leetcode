#include<vector>
#include<string>
#include <unordered_set>

using namespace std;
//待会使用智能指针尝试一把 哈哈哈
class Solution {
public:

    int  totalnum;
    vector<string> data;
    bool wordBreak(string s, unordered_set<string> &dict) {



     return findword( s,  dict);
    }
   bool findword(string s, unordered_set<string> &dict)
   {
        if(s.size() == 0)
           return true;
         unordered_set<string>::const_iterator ite;
         string temp;
         int i=0;
         for(i=1; i<=s.size();i++)
          {

                temp=s.substr(0,i);

                if(dict.find(temp) != dict.end())
                {
                    temp = GetStr(s,temp);
                    if(findword(temp,dict))
                      return true;
                }
          }

        return false;

   }
   string GetStr(string& s, string& temp)
   {
      string patter;
      int len = 0;
       while(1)
       {
            patter = s.substr(len,temp.size());
            if(patter != temp)
              return  s.substr(len,-1);
            len+=temp.size();

       }

     return "";
   }
};