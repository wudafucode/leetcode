#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for(int i=0; i<grid.size();i++)
			for(int j=0; j< grid[i].size();j++){
				if(grid[i][j] != '1')
					continue;
				overwrite(grid,i,j);
				count++;
		     }
		return count;
    }
    void overwrite(vector<vector<char>>& grid,int x,int y){

		
		
		grid[x][y] = '2';
        if(x-1>=0){
			if(grid[x-1][y] == '1'){
				overwrite(grid,x-1,y);
			}
		}
		
		if(x+1<grid.size()){
			if(grid[x+1][y] == '1'){
				overwrite(grid,x+1,y);
			}
		}
		if(y+1<grid[x].size()){
			if(grid[x][y+1] == '1'){
				overwrite(grid,x,y+1);
			}
		}
		if(y-1>=0){
           if(grid[x][y-1]=='1'){
				overwrite(grid,x,y-1);
		   }

		}
		
	}
	
};






