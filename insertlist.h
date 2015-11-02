
 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
         ListNode*  pResult = head;
		 ListNode*  pTemp = NULL;

		 if(head == NULL)
		 return head;
		 pTemp = head->next;
		 head->next = NULL;
         while(pTemp!= NULL)
         {
            head = pTemp;
            pTemp = pTemp->next;
			head->next = NULL;
            pResult = Insert(pResult,head);

		 }
		 return pResult;
    }
	ListNode* Insert(ListNode* presult,ListNode* pNode)
	{
    	  ListNode*  ptemp;
		  ListNode*  pHead = presult;
		  ListNode*  pBefore = pNode;
		  pNode->next = NULL;
          if(pHead->val >= pNode->val)
		  	pHead = pNode;
		  
		  for(ptemp = presult; ptemp->val < pNode->val;)
		  {
              pBefore = ptemp;
			  ptemp = ptemp->next;
			  if(ptemp == NULL)
			  	break;
		  }
          pBefore->next = pNode;
		  pNode->next = ptemp;
		  return pHead;
	}
};