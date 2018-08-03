#include<vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
	struct node{
       int value;
	   int count;
	   node(int data,int temp):value(data),count(temp)
	   {}
	};
    vector<int> topKFrequent(vector<int>& nums, int k) {

		unordered_map<int, int> map;
		for(int i=0; i<nums.size();i++){
			  auto ite  = map.find(nums[i]); 
              if(ite != map.end()){
					ite->second++;
			  }else{
                  map.insert(pair<int,int>(nums[i],1));
			  }
		}
		vector<node> buf;
		for(auto i = map.begin(); i!= map.end();i++){
                buf.push_back(node(i->first,i->second));
		}
		sort(buf.begin(),buf.end(),[&](node& left,node& right){return left.count>right.count;}) ;
        vector<int> res;
		for(int i=0; i<k&&i<buf.size();i++){
			res.push_back(buf[i].value);
		}
		return res;
		
    }
};