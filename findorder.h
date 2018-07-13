#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<vector<int>>  prebuf(numCourses,vector<int>());
		vector<int> indegree(numCourses,0);
		queue<int>  buf;
		vector<int> ret;
		for(int i=0; i<prerequisites.size();i++){
			
			prebuf[prerequisites[i].first].push_back(prerequisites[i].second);
			indegree[prerequisites[i].first] +=1;

		}
		for(int i=0; i<indegree.size();i++){
			if(indegree[i] == 0){
                ret.push_back(i);
				buf.push(i);
			}
		}
        while(!buf.empty()){
              int index = buf.front();
			  buf.pop();
			  for(int i=0; i<prebuf.size();i++){
					if(indegree[i] == 0)
						continue;
					for(int j=0; j<prebuf[i].size();j++){
                         if(prebuf[i][j] == index)
                         {
							indegree[i] -=1;
							if(indegree[i] == 0)
							 {
								buf.push(i);
								ret.push_back(i);
							 }
							 break;
						 }
						 
					}

			  }


		}
        if(ret.size() == numCourses)
			return ret;
		return vector<int>();

		
        
    }
};