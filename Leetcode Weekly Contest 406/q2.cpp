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
        unordered_set<int> st;
        for(auto &num : nums){
            st.insert(num);
        }
        // checking that how many element will delete from starting to adjuct pointer
        ListNode* curr = head;
        while(curr){
            int data = curr->val;
            if(st.find(data) != st.end()){
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }else{
                break;
            }
        }
        head = curr; // updating head to its actual updated linkedlist head
        if(head == NULL) return head;
        ListNode* prev = head;
        curr = curr->next;
        while(curr){
            int data = curr->val;
            if(st.find(data) != st.end()){
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};