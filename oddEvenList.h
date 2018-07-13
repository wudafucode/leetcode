
//Definition for singly-linked list.
 struct ListNode {
    int val;
  ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
	
		
		if(head == NULL)
			return NULL;
		ListNode*  pevenhead = head->next;
		ListNode*  podd      = head;
		ListNode*  peven     = head->next;
        if(head->next == NULL)
			return head;
		
		while(1){
			podd->next = peven->next;
			
			if(podd->next == NULL){
				break;
			}
			podd = podd->next;

			peven->next = podd->next;
			if(peven->next == NULL){
				break;
			}
			peven       = peven->next;	
		}
		
		podd->next = pevenhead;
        return head;
    }
};