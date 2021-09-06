/* Check if a linked list is a palindrome or not
 *
 * Compilation: gcc palindrome_linked_list.c
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


bool isPalindrome(struct ListNode* head){
    
    if(head == NULL || head->next == NULL)
    {
        return true;
    }
    
    //If there are two nodes,if value of node1 = value of node2 them it is a palindrome
    if(head->next->next == NULL)
    {
        return (head->val == head->next->val);
    }
    
    struct ListNode *sptr = head;
    struct ListNode *fptr = head;
    
    //For finding the middle of linked list
    while(fptr->next != NULL && fptr->next->next != NULL)
    {
        sptr = sptr->next;
        fptr = fptr->next->next;
    }
    
    
    //Reversing the second half
    struct ListNode *curr = sptr->next;
    struct ListNode *next = NULL;
    struct ListNode *prev = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    sptr->next = prev;
    
    //We will compare first with second, if both are equal then the list is a palindrome
    sptr = sptr->next;
    
    while(sptr != NULL)
    {
        if(head->val != sptr->val)
        {
            return false;
        }
        head = head->next;
        sptr = sptr->next;
    }
    
    return true;
}