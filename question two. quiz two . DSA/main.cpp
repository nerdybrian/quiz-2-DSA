#include <iostream>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    // Detect cycle using Floyd's Tortoise and Hare algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // If there's no cycle
    if (fast == NULL || fast->next == NULL)
        return NULL;

    // Reset one pointer to head and move both at the same pace until they meet
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Returns the node where the cycle begins
}

// Example usage
int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    // Create a cycle
    head->next->next->next->next = head->next;

    ListNode *cycleStart = detectCycle(head);
    if (cycleStart)
        std::cout << "Cycle begins at node with value: " << cycleStart->val << std::endl;
    else
        std::cout << "No cycle found." << std::endl;

    // Clean up memory (not necessary for the algorithm but good practice)
    ListNode *current = head;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
