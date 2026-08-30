#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    int val;
    Node(int value)
    {
        next = NULL;
        val = value;
    }
};

class Linkedlist
{
private:
    Node *head;

public:
    Linkedlist()
    {
        head = NULL;
    }
    void addAtStart(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void printAllNode()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    void addAtEnd(int val)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        temp->next = newNode;
        temp = temp->next;
        temp->next = NULL;
    }
    void deleteAtEnd()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
};

int main()
{
    Linkedlist obj;
    obj.addAtStart(5);
    obj.addAtStart(4);
    obj.addAtStart(3);
    obj.addAtStart(2);
    obj.addAtStart(1);
    obj.addAtEnd(6);
    obj.deleteAtEnd();
    obj.deleteAtEnd();
    obj.printAllNode();
    return 0;
}