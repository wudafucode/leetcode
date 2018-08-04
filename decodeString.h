#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
		  string ret;
		  int num = 0;
		  for(int i=0; i<s.size();i++){
			if(isdigit(s[i])){
				 string temp;
				 while(i<s.size() && isdigit(s[i])){
					 temp.push_back(s[i]);
					 i++;
				 }
				 i--;
				 num = stoi(temp);
			}else if(s[i] == '['){
			
			 	 int index = findindex(s,i);
				 string temp  = decodeString(s.substr(i+1,index-i-1));
				 for(int j=0; j<num;j++)
				 	ret.append(temp);
				 i=index;

			}else if(isalpha(s[i])){
			
				ret.push_back(s[i]);

			}

		  }		
		  return ret;
		
    }
	int findindex(string& s,int beginindex){
		int count =0;
		int i=0;
		for(i=beginindex; i<s.size();i++){
			if(s[i] == '['){
				count++;
			}else if (s[i] == ']'){
				count--;
				if(count == 0)
				   return i;
			}
		}
		return i;
	}
	
	
};