/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Insert dummy node as head of list 3 to handle edge cases.
        ListNode* list3 = new ListNode();
        ListNode* currentNodeInList3 = list3;
        
        ListNode* currentNodeInList1 = list1;
        ListNode* currentNodeInList2 = list2;

        // while there are values to compare in each list, make the next node in list3 that node.
        // shift the iterator node in each list up by 1 after we make list3's next that node.
        while(currentNodeInList1 != nullptr && currentNodeInList2 != nullptr)
        {
            if(currentNodeInList1->val <= currentNodeInList2->val)
            {   
                currentNodeInList3->next = currentNodeInList1;
                currentNodeInList1 = currentNodeInList1->next;
            }
            else
            {
                currentNodeInList3->next = currentNodeInList2;
                currentNodeInList2 = currentNodeInList2->next;
            }

            // update the tail of List3, this will now be null
            currentNodeInList3 = currentNodeInList3->next;
        }

        // if either list currentNode iterator is not null, append the rest of that list to list3.
        if(currentNodeInList1 != nullptr)
        {
            currentNodeInList3->next = currentNodeInList1;
        }
        else if(currentNodeInList2 != nullptr)
        {
            currentNodeInList3->next = currentNodeInList2;
        }

        // returns the node after the dummy node as the head.
        return list3->next;
    }
};
