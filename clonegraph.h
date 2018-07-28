#include<vector>
#include<map>
using namespace std;
 struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };
 
class Solution {
public:
	map<UndirectedGraphNode *,UndirectedGraphNode *> path;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL)
			return NULL;
		UndirectedGraphNode *phead;
		auto ite  = path.find(node);
		if(ite != path.end()){
			
        	return ite->second;
		}
		phead = new UndirectedGraphNode(node->label);
		path.insert(pair<UndirectedGraphNode *,UndirectedGraphNode *>(node,phead));
		for(int i=0; i<node->neighbors.size();i++){
			UndirectedGraphNode *pneighbor;
			if(path.find(node->neighbors[i]) != path.end()){
				auto ite  = path.find(node->neighbors[i]);
			    pneighbor = ite->second;
			}
			else{
				
				pneighbor = cloneGraph(node->neighbors[i]);
			}
			phead->neighbors.push_back(pneighbor);

		}
        return phead;
    }
};





