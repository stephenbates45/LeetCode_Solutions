#include <iostream>

// This struct is copied from the problem code on the website
// to define a ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This is a helper function to build a ListNode for the purposes
// of this code but is not required in the website submission
ListNode* buildList(std::initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode** tail = &head;

    for (int value : values) {
        *tail = new ListNode(value);
        tail = &(*tail)->next;
    }

    return head;
}

// This is a helper function to print a ListNode for the purposes
// of this code but is not required in the website submission
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << '\n';
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        // Use a dummy node to make it easy to build the result list.
        ListNode dummy(0);
        ListNode* answer = &dummy;
        int carry = 0;

        // Add matching digits until both lists and any final carry are handled.
        while (list1 || list2 || carry) {
            int sum = carry;

            // Add the current digit from each list, if available.
            if (list1) {
                sum += list1->val;
                list1 = list1->next;
            }

            if (list2) {
                sum += list2->val;
                list2 = list2->next;
            }

            // Store this digit and carry any tens into the next addition.
            answer->next = new ListNode(sum % 10);
            answer = answer->next;
            carry = sum / 10;
        }

        // Skip the dummy node and return the first actual result digit.
        return dummy.next;
    }
};

int main(int, char**){
    
   Solution solution;

    // Build the input lists, add them, and print the resulting list.
    auto test = [&](std::initializer_list<int> a,
                    std::initializer_list<int> b) {
        ListNode* l1 = buildList(a);
        ListNode* l2 = buildList(b);

        ListNode* result = solution.addTwoNumbers(l1, l2);
        printList(result);
    };

    // Try regular addition, zero, and a case that produces several carries.
    test({2, 4, 3}, {5, 6, 4}); // 342 + 465 = 807
    test({0}, {0});             // 0 + 0 = 0
    test({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9});
}
