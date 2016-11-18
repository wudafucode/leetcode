class Solution {
public:
	set<string> data;
	set<string> result;
    vector<string> removeInvalidParentheses(string s) {
         int num = 0;
         vector<int> leftinvalid;
		 vector<int> rightinvalid;
		 vector<string> finalresult;
         GetMinNum(s,leftinvalid,rightinvalid);
		 RDsearchfirst(s,rightinvalid,0);
		 for(int i=0; i<leftinvalid.size(); i++)
		 {
             leftinvalid[i]-=rightinvalid.size();
		 }
		 for(set<string>::iterator ite = data.begin() ; ite != data.end(); ite++)
		 {
			LDsearchfirst(*ite,leftinvalid,0);
		 }
		 for(set<string>::iterator ite = result.begin(); ite != result.end(); ite++)
		 {
            finalresult.push_back(*ite);
		 }
		
		 return finalresult;
    }
	void RDsearchfirst(string s,vector<int>&rightinvalid,int index)
	{
	   if(rightinvalid.size() == index)
	   {
	      data.insert(s);    
          return ;
	   }
       string temps;
       for(int j=0; j<s.size()&&j<=rightinvalid[index]-index;j++)
       {
           if(s[j] == ')')
           {  
               temps = s;
               RDsearchfirst(temps.erase(j,1),rightinvalid,index+1);
		   }
	   }
	   

	}
	void LDsearchfirst(string s,vector<int>&leftinvalid,int index)
	{
       if(leftinvalid.size() == index)
	   {
	      result.insert(s);    
          return ;
	   }  
	   string temps;

       for(int j=leftinvalid[index]-index; j<s.size();j++)
       {
           if(j + leftinvalid.size()-index >s.size())
		   	break;
           if(s[j] == '(')
           {  
               temps = s;
               LDsearchfirst(temps.erase(j,1),leftinvalid,index+1);
		   }
	   }

	}
    void  GetMinNum(string s,vector<int>& leftinvalid,vector<int>& rightinvalid)
	{
	     int leftbracet = 0;
		 int resultnum = 0;
		 for(int i=0; i<s.size();i++)
		 {
             if(s[i] == '(')
             {
                leftinvalid.push_back(i);
			 }
			 else if(s[i] == ')')
			 {
             	if(leftinvalid.size()>0)
				    leftinvalid.pop_back();
				else
					rightinvalid.push_back(i);
			 }
		 }
	}
};

