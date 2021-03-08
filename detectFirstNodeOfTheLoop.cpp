#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to detect and remove loop
// in a linked list that may contain loop
Node *detectAndRemoveLoop(Node *head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop does not exist
    if (slow != fast)
        return NULL;

    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Function to detect first node of loop
// in a linked list that may contain loop
Node *detectLoop(Node *head)
{

    // Create a temporary node
    Node *temp = new Node;
    while (head != NULL)
    {

        // This condition is for the case
        // when there is no loop
        if (head->next == NULL)
        {
            return NULL;
        }

        // Check if next is already
        // pointing to temp
        if (head->next == temp)
        {
            break;
        }

        // Store the pointer to the next node
        // in order to get to it in the next step
        Node *nex = head->next;

        // Make next point to temp
        head->next = temp;

        // Get to the next node in the list
        head = nex;
    }

    return head;
}
int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    //create loop for testing
    head->next->next->next->next->next = head->next->next;
    Node *res = detectAndRemoveLoop(head);
    if (res == NULL)
    {
        cout << "loop does not exist";
    }
    else
    {
        cout << "loop starting node is " << res->key;
    }
    return 0;
}