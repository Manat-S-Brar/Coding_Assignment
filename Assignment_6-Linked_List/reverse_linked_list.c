/* Reverse Linked list between left (L) to right (R)
 *
 * Compilation: gcc reverse_linked_list.c
 * Execution: ./a.out
 *
 * Assignment: 6
 * Date: 30/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    
    if(head->next == NULL)
    {
        return head;
    }
    
    if(left == right)
    {
        return head;
    }
    
    //curr,prev,next are used for reversing the list 
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    struct ListNode *temp = NULL;
    struct ListNode *temp1 = head;
    
    int count = 1;
    
    while(curr != NULL)
    {
        if(left == count)
        {
            while(count != right + 1)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            temp1->next = next;
            if(temp != NULL)
            {
                temp->next = prev;
            }
            if(temp == NULL)
            {
                head = prev;
            }
            break;
        }
        count++;
        temp = curr;
        temp1 = temp1->next;
        curr = curr->next;
    }
    return head;
}