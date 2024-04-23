#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next)
        return false;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

// Example usage
int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    // Create a cycle
    head->next->next->next->next = head->next;

    bool hasCycleResult = hasCycle(head);
    std::cout << "Linked list has cycle: " << std::boolalpha << hasCycleResult << std::endl;

    // Clean up memory (not necessary for the algorithm but good practice)
    ListNode *current = head;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
