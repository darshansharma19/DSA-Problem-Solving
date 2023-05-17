class Solution {
public:
    
    int getLen(ListNode* head)
    {
        int count =0;
        while(head != NULL) 
        {
            count++;
            head = head->next;
        }
        return count;
    }
 
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr!= NULL)  
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        int len = getLen(head);
        ListNode* temp = head, *prev = NULL;
        len = len/2;
        
    
        while(len--)
        {
            prev = temp;
            temp = temp->next;
        }
       
        
        prev->next = reverse(temp);
        temp = head;
        prev= prev->next;
        int maxSum = INT_MIN;
        
      
        while(prev != NULL)
        {
            int currSum = temp->val + prev->val;
            maxSum = max(currSum,maxSum);
            temp = temp->next;
            prev = prev->next;
        }
        return maxSum;

    }
};