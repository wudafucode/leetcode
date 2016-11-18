



class Solution {
public:
	enum
	{
      visited = 2,
	};
	int totalcourses;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		
              vector<vector<bool>>  bufgrap(numCourses,vector<bool>(numCourses));
			  vector<int> resultgrap(numCourses,0xff);
		
			  
              bool flag  = false;
			  totalcourses = numCourses;
              InitGrap(bufgrap,prerequisites);
			  for(int i = 0; i<numCourses; i++)
			  {
			      if(resultgrap[i] == false)
				  	 continue;
              	  flag = DepthFirst(i,bufgrap,resultgrap);
				  if(flag == true)
				  	return false;
				  resultgrap[i] = false;
			  }
			  return true;
        
    }
   void InitGrap(vector<vector<bool>>& bufgrap,vector<pair<int, int>>& prerequisites)
   {

		for(int i= 0; i<prerequisites.size(); i++)
		{
        	int row = prerequisites[i].first;
			int col = prerequisites[i].second;
			bufgrap[row][col] = true;
		}

   }
   
   bool DepthFirst(int course, vector<vector<bool>>& bufgrap,vector<int>& resultgrap)
   {
      

        for(int i = 0; i<totalcourses; i++)
        {
            if(i == course)
				continue;
            if(bufgrap[course][i] == 1)
            {
                 if(resultgrap[i] == false)
				 	continue;
                 if(resultgrap[i] == visited)
				 	return true;
				 
				 resultgrap[i] = visited;
				
				 if(true == DepthFirst(i,bufgrap,resultgrap))
				 	return true;
				 resultgrap[i] = false;
			}
			
		}
		
   		return false;
   }
};





