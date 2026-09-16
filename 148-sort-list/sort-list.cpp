class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        for (int size = 1; size < n; size *= 2) {

            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr != NULL) {
                ListNode* left = curr;
                ListNode* right = left;

                for (int i = 0; i < size && right != NULL; i++)
                    right = right->next;
                ListNode* next = right;

                for (int i = 0; i < size && next != NULL; i++)
                    next = next->next;
                int l = 0, r = 0;

                while (l < size && r < size && left != NULL && right != NULL) {

                    if (left->val <= right->val) {
                        prev->next = left;
                        left = left->next;
                        l++;
                    }
                    else {
                        prev->next = right;
                        right = right->next;
                        r++;
                    }

                    prev = prev->next;
                }
                while (l < size && left != NULL) {
                    prev->next = left;
                    left = left->next;
                    prev = prev->next;
                    l++;
                }
                while (r < size && right != NULL) {
                    prev->next = right;
                    right = right->next;
                    prev = prev->next;
                    r++;
                }

                prev->next = next;
                curr = next;
            }
        }

        return dummy.next;
    }
};