#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> data(m,vector<int>(n,1));
		for(int i= m-2;i>=0; i--){
			for(int j=n-2;j>=0;j--){
                data[i][j] = data[i+1][j]+data[i][j+1];
			}
		}
		return data[0][0];
        
    }
};



