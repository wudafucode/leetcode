#include<vector>
using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
			vector<ListNode*>  databuf;
			ListNode* head  = NULL;
			for(int i=0; i<lists.size();i++){
				head = lists[i];
				while(head != NULL){
					databuf.push_back(head);
					head = head->next;
				}
			} 
			sort(databuf.begin(),databuf.end(),[](ListNode* left,ListNode* right){ return left->val < right->val;});
            if(databuf.size() == 0)
				return NULL;
			head = databuf[0];
			for(int i=1; i<databuf.size();i++){
               head->next = databuf[i];
			   head= head->next;
			}
			head->next = NULL;

			return databuf[0];
    }
};