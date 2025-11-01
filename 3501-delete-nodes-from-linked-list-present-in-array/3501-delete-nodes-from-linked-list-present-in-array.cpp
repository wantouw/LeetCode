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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int tracker[100005] = {};
        for(auto num: nums){
            tracker[num]=1;
        }
        ListNode* curr = head;
        while(curr != nullptr && curr->next){
            // cout << curr->val << endl;
            ListNode* after;
            while(curr->next != nullptr && tracker[curr->next->val]){
                after = curr->next->next;
                // delete curr->next;
                // curr->next = nullptr;
                curr->next = after;
            }
            curr = curr->next;
        }
        curr = head;
        // while(curr){
        //     cout << curr->val << endl;
        //     curr = curr->next;
        // }
        if(tracker[head->val]){
            curr = head;
            head = head->next;
            // delete curr;
            // curr = nullptr;
        }
        curr = head;
        // while(curr){
        //     cout << curr->val << endl;
        //     curr = curr->next;
        // }
        return head;
    }
};