
 // Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* pbegin,*pmiddle;
		ListNode* ptemp;

		if(head == NULL ||head->next == NULL)
		return head;
        

        pbegin  = head;
		pmiddle = GetMiddle(head);

        ptemp = pmiddle->next;
		pmiddle->next = NULL;
		pbegin  = sortList(pbegin);
		pmiddle = sortList(ptemp);
		return MergeList(pbegin,pmiddle);
    }
	
	ListNode* GetMiddle(ListNode* head)
	{
         ListNode* pSlow = head,*pFast = head;
         while(pFast!= NULL)
         {
             if(pFast->next == NULL || pFast->next->next == NULL)
			 	break;
			  pFast = pFast->next->next;
		      pSlow = pSlow->next;
			 
		}

		 return pSlow;
	}
	ListNode* MergeList(ListNode* pLeftList, ListNode* pRightList)
    {
    	ListNode* pHead;
		ListNode* pCurrent ;

        if(pLeftList == NULL || pRightList == NULL)
		return pLeftList != NULL?pLeftList:pRightList;
      
      if(pLeftList->val <= pRightList->val)
       {
            pHead= pLeftList;
       		pLeftList = pLeftList->next;
	   }
	   else
	   {
            pHead = pRightList;
       		pRightList = pRightList->next;

	   }
	  pCurrent = pHead;
		
        for(;pLeftList != NULL && pRightList != NULL; )
        {
           if(pLeftList->val <= pRightList->val)
           {
                pCurrent->next = pLeftList;
				pCurrent = pCurrent->next;
           		pLeftList = pLeftList->next;
		   }
		   else
		   {
                pCurrent->next = pRightList;
				pCurrent = pCurrent->next;
           		pRightList = pRightList->next;

		   }
		}
		if(pRightList != NULL)
		{
           pLeftList = pRightList;
		}
		pCurrent->next = pLeftList;
      

        return pHead;
	}
};