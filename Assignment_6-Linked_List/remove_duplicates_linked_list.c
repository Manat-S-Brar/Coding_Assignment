/* Remove duplicate nodes from linked list
 *
 * Compilation: gcc remove_duplicates_linked_list.c
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


struct ListNode* deleteDuplicates(struct ListNode* head){
    
    //If there is no node or only one node then there is no duplicate
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    struct ListNode *temp = head;
    struct ListNode *prev = NULL;
    
    while(temp->next != NULL)
    {
        if(temp->next != NULL && temp->val == temp->next->val)
        {
            //Removing duplicate values
            while(temp->next != NULL && temp->val == temp->next->val)
            {
                temp = temp->next;
            }
            temp = temp->next;
            
            //If prev value is NULL that means 1st(starting) node contains duplicate values and we have to change the head of linked list
            if(prev == NULL)
            {
                head = temp;
            }
            else
            {
                prev->next = temp;
            }
            
            //If temp == NULL that means we have reached the end of list therefore we break from the loop
            if(temp == NULL)
            {
                break;    
            }
        }   
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    
    return head;
}