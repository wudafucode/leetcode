#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<limits>
#include<map>
using namespace std;
bool test1()
{
     Solution msol;
	 string dict[] = {"hot","dot","dog","lot","log"};
	 unordered_set<string> buf;
	 string start = "hit";
	 string end = "cog";
	 for(int i=0; i<5;i++)
	 {
        buf.insert(dict[i]);
	 }
	 vector<vector<string>> result;
	 result = msol.findLadders(start,end,buf);
	 

	 return true;

}
bool test2()
{
     Solution msol;
	 string dict[] = {"a","b","c"};
	 unordered_set<string> buf;
	 string start = "a";
	 string end = "c";
	 for(int i=0; i<3;i++)
	 {
        buf.insert(dict[i]);
	 }
	 vector<vector<string>> result;
	 result = msol.findLadders(start,end,buf);
	 


     	
	

     return true;

}
bool test3()
{
     Solution msol;
	 string dict[] = {"ted","tex","red","tax","tad","den","rex","pee"};
	 unordered_set<string> buf;
	 string start = "red";
	 string end = "tax";
	 for(int i=0; i<8;i++)
	 {
        buf.insert(dict[i]);
	 }
	 vector<vector<string>> result;
	 result = msol.findLadders(start,end,buf);
	

     return true;

}
bool test4()
{

	 Solution msol;
	 string dict[] = {"hot","dog"};
	 unordered_set<string> buf;
	 string start = "hot";
	 string end = "dog";
	 for(int i=0; i<2;i++)
	 {
        buf.insert(dict[i]);
	 }
	 vector<vector<string>> result;
	 result = msol.findLadders(start,end,buf);

     return true;

}
class Solution {
public:

      vector<vector<string>> wordsladders;

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

	  
		
		  unordered_map<string,vector<string>> forword;
		  dict.insert(end);
		  InitData(forword,dict);
		  bool ret;
		  ret = GetTraces(forword,start,end,dict);
	      if(ret == false)
		  	return wordsladders;
		  vector<string> path;
		  GetPath(end,forword,path);

	      return wordsladders;
		
    }
	void GetPath(string& tempstr,unordered_map<string,vector<string>> &forword,vector<string>& path)
    {
    
	  vector<string> result;
	  path.push_back(tempstr);

	  if(forword[tempstr].empty())
	  {
	     result.resize(path.size());
         copy(path.rbegin(), path.rend(),result.begin());
		 wordsladders.push_back(result);
		 path.pop_back();
         return ;
	  }
	  	
      for(auto ite = forword[tempstr].begin(); ite!= forword[tempstr].end(); ite++)
      {
      	 GetPath(*ite,forword,path);
	  }
	  path.pop_back();

	}
	void InitData(unordered_map<string,vector<string>> &forword,unordered_set<string> &dict)
	{
	   unordered_set<string>::iterator ite;
	   pair<string,vector<string>> temp;
       for(ite = dict.begin(); ite!= dict.end(); ite++)
       { 
          temp.first = *ite;
          forword.insert(temp);
	   }

	}
	bool GetTraces(unordered_map<string,vector<string>> &forword,string& start,string& end,unordered_set<string> &dict)
	{
	      vector<unordered_set<string> > buf(2); 
		  int cur,pre;
          cur =0;
		  pre =1;
		  string tempstr;
		  buf[0].insert(start);
		  while(1)
		  {
			   cur = !cur;
			   pre = !pre;
	           for(auto ite = buf[pre].begin(); ite != buf[pre].end(); ite++)
	           {
	               dict.erase(*ite);
			   }
			   for(auto ite = buf[pre].begin(); ite!= buf[pre].end(); ite++)
			   {
	               for(int i = 0; i < (*ite).size(); i++)
			       {
			           tempstr = *ite;
			           for(int j=0; j< 26;j++)
			           {
			      
			             if('a'+j == tempstr[i])
						  continue ;
						 tempstr[i] = 'a'+j;
						 if(dict.find(tempstr) == dict.end())
						   continue;
						 forword[tempstr].push_back(*ite);
						 buf[cur].insert(tempstr);
					   }

				  }

			 }
			 buf[pre].clear();
			 if(buf[cur].size() == 0)
			 	return false;
			 if(buf[cur].count(end))
			 	 return true;
		
		

		}
	   
   }
		
};
class Solution2 {
public:

    struct SWord
    {
       char alpha;
	   int  index;
	};
    struct SNode
	{
	   string        first;
       int           count;
       vector<SWord> words;
	};
	unordered_set<string> data;
	queue<SNode> result;
	vector<vector<string>> wordsresult;
	string mstart;
	string mend;
    int maxindex ;

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

	      SNode temp;
		  vector<string> tempresult;
		  
	      temp.count = 1;
		  temp.first  = start;

		  mstart = start;
		  mend   = end;
		  maxindex = numeric_limits<int>::max();
  
	      InitData(end);
		  
	      if(CheckResult(temp,end) == true)
	      {
              tempresult.push_back(start);
			  tempresult.push_back(end);
			  wordsresult.push_back(tempresult);
			  return wordsresult;
		  }
		 
	      GetData(temp,dict);
		  if(result.size() == 0)
		  	return wordsresult;
		
	      while(result.size() !=0)
	      {
			
	         temp = result.front();
			 if(temp.count >= maxindex)
			 	return wordsresult;
			 if(CheckResult(temp, end)== true)
			 {
	            maxindex = temp.count+1;	
				wordsresult.push_back(WriteResult(temp));	
				result.pop();
				
			 }
			 else
			 {
                result.pop();
			    GetData(temp,dict);

			 }
			
			 	 
		  }


	     return wordsresult;
		
    }
    void InitData(string end)
	{
         int i=0,j=0;
		 string temp;
        for(i = 0; i < end.size(); i++)
        {
           temp = end;
           for(j=0; j< 26;j++)
           {
             
			 if(end[i] != 'a'+j)
			 {
                temp[i] = 'a'+j;
			    data.insert(temp);
			 }
		   }

		}
	}
	bool GetData(SNode &start,unordered_set<string> &dict)
	{
	    int i=0,j=0;
		string tempstr;
		SWord  tempword;
		SNode pattern;
		pattern.words.assign(start.words.begin(), start.words.end());
	
		unordered_set<string>::iterator ite;
        for(i = 0; i < start.first.size(); i++)
        {
           tempstr = start.first;
           for(j=0; j< 26;j++)
           {
             tempstr[i] = 'a'+j;
             if('a'+j == start.first[i])
			  continue ;
			 ite = dict.find(tempstr);
			 if(ite == dict.end())
			   continue;
			 if(CheckWord(tempstr,start) == true)
			 	continue;
			  pattern.first  = tempstr;
			  pattern.count  = start.count + 1;

			  tempword.alpha = 'a'+j;
			  tempword.index = i;
			  pattern.words.push_back(tempword);
	
              result.push(pattern);
			  pattern.words.pop_back();
		   }

		}
	
	   
		return true;
        
	}
	bool CheckWord(string temp, SNode &start)
	{
	    int i=0;
		string data;
		int index;
		char alpha;
		data = mstart;
		for (i=0; i<start.words.size(); i++)
		{
		   index = start.words[i].index;
		   alpha = start.words[i].alpha;
		   data[index] = alpha;
           if(data == temp)
		   	return true;
		}
		return false;
      
	}
   vector<string> WriteResult(SNode &temp)
   {
     vector<string> result;
	 string str;
	 result.push_back(mstart);
	 str = mstart;
	 int index;
	 char alpha;
	 for(int i=0; i< temp.words.size(); i++)
	 {
         index = temp.words[i].index;
		 alpha = temp.words[i].alpha;
		 str[index] = alpha;
         result.push_back(str);
	 }
     result.push_back(mend);
	 return result;
   }
   bool CheckResult(SNode &temp, string &end)
   {
      unordered_set<string>::iterator ite;
	  ite = data.find(temp.first);
      if(ite != data.end())
      {
    
         return true;
	  }
	  else
	  {
 	    return false;
	  }
	 
   }

	
};