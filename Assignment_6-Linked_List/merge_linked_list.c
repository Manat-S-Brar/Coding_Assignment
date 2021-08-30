/* Merge two sorted linked list
 *
 * Compilation: gcc merge_linked_list.c
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode merged;
    struct ListNode *head = &merged;
    
    if(l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    
    while (l1 != NULL && l2 != NULL) 
    {
        if(l1->val < l2->val) 
        {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        } 
        else 
        {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
    }

    if(l1 != NULL) 
    {
        head->next = l1;
    }
    
    if(l2 != NULL)
    {
        head->next = l2;
    }
  
    return merged.next;

}