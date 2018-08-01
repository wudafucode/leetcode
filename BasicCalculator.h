#include<string>
#include<stack>

using namespace std;
class Solution {
public:
    int calculate(string s) {
		stack<char> opbuf;
		stack<int>  databuf;
	
		if(s.size() == 0)
			return 0;
		string formula;
		for(int i=0; i<s.size();i++){		
			if(s[i] == ' ')		
				continue;			
			formula.push_back(s[i]);		
		}
		s=formula;
		if(s.size() == 0)
			return 0;
        int i=0;
		opbuf.push('+');
		while(!opbuf.empty() && i < s.size()){
			
			int data = 0;
			char op = 0;
			while(isdigit(s[i])){
				data  = data*10 + s[i]-'0';
				i++;
				if(i>= s.size())
					break;
			}
			databuf.push(data);
			
			if(i >= s.size())
				break;
			
			op = s[i++];
			if(op == '+' || op == '-')
			{
				 while(databuf.size() >=2){
			        calc(databuf,opbuf);
				 }
			}else if(opbuf.top() == '*' || opbuf.top() == '/'){
				calc(databuf,opbuf);
			}
			opbuf.push(op);
			
		}
	    while(databuf.size() >=2){
			calc(databuf,opbuf);
		}
		return databuf.top();
		 
    }
	void calc(stack<int>&  buf,stack<char>& cal){
		if(buf.size() < 2)
			return ;
		int right = buf.top();
		buf.pop();
		int left = buf.top();
		buf.pop();
		char op  = cal.top();
		cal.pop();
		int ret = 0;
		if(op == '*'){
            ret = left*right;
		}
		if(op == '/'){
             ret = left/right;
		}
		if(op == '+'){
            ret = left+right;
		}
		if(op == '-'){
            ret = left-right;
		}
		buf.push(ret);
		return ;
	}
};