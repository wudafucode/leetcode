


/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode *pslow = NULL,*pquick = NULL;
		if(head == NULL)
		return false;
	    pquick = head;
		if(pquick->next == NULL)
		return false;
		pquick = pquick->next;
		pslow  = head;
		while(pslow != pquick)
	    {
        	pslow = pslow->next;
			if(pquick->next == NULL)
			return false;
			if(pquick->next->next == NULL)
			return false;
			pquick = pquick->next->next;
			
		}
        return true;
    }
};





