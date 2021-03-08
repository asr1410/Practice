
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    int flag;
};
Node *Empty(Node *head, int data)
{
    head = new Node();
    head->data = data;
    head->next = head;
    head->flag = 0;
    return head;
}
void insertNode(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->flag = 0;
    Node *current = head;
    do
    {
        current = current->next;
    } while (current->next != head);
    newNode->next = current->next;
    current->next = newNode;
}

void display(Node *head)
{
    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}

//detect loop using hashing for each value
bool detectLoopUsingHashing(struct Node *head)
{
    unordered_set<Node *> s;
    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}

//using flag value for each nodes
bool detectLoopUsingFlag(struct Node *head)
{
    while (head != NULL)
    {
        if (head->flag == 1)
            return true;
        head->flag = 1;
        head = head->next;
    }
    return false;
}
//detect loop using floyd cycle
int detectLoopUsingFloydCycle(Node *list)
{
    Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    Node *head = NULL;
    head = Empty(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);
    insertNode(head, 20);
    display(head);
    cout << endl;
    if (detectLoopUsingFloydCycle(head))
    {
        cout << "Loop founded";
    }
    else
    {
        cout << "No loop";
    }

    return 0;
}