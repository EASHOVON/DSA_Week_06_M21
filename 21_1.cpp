#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    // Creating Constractor
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int arr[1000];
};

// Function Initialization
void display(Node *n);
int countLength(Node *&head);
void insertAtHead(Node *&head, int value);
void insertAtTail(Node *&head, int value);
void insertAtSpecificPosition(Node *&head, int position, int value);
int searchByValueUnique(Node *&head, int value);
Test searchByValueDuplicateReturn(Node *&head, int value);
void insertAfterSpecificValueUnique(Node *&head, int target, int value);
void insertionAfterSpecificValueDuplicate(Node *&head, int key, int newValue);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int pos);
void deletionByValueUnique(Node *&head, int target);
void deletionByValueDuplicate(Node *&head, int target);
Node *reverseNonRecursive(Node *&head);
Node *reverseListRecursive(Node *&head);
// Function Making
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl
         << endl;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->Next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtSpecificPosition(Node *&head, int position, int value)
{
    int i = 0;
    Node *newNode = new Node(value);
    Node *temp = head;
    while (i < position - 2)
    {
        temp = temp->Next;
        i++;
    }

    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int value)
{
    Node *temp = head;
    int count = 1;
    if (head == NULL)
    {
        return -1;
    }
    while (temp->value != value)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

Test searchByValueDuplicateReturn(Node *&head, int value)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            T.arr[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.arr[0] = k;
    return T;
}

void insertAfterSpecificValueUnique(Node *&head, int target, int value)
{
    int position = searchByValueUnique(head, target);

    insertAtSpecificPosition(head, position + 1, value);
}

void insertionAfterSpecificValueDuplicate(Node *&head, int key, int newValue)
{
    Test positions;
    positions = searchByValueDuplicateReturn(head, key);
    if (positions.arr[0] == 0)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    int len = positions.arr[0];
    for (int i = 1; i < len; i++)
    {
        insertAtSpecificPosition(head, positions.arr[i] + 1, newValue);
        for (int j = i; j < len; j++)
        {
            positions.arr[j]++;
        }
    }
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the liked list!" << endl;
    }
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "There is no value in the linked list!" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecificPosition(Node *&head, int pos)
{
    if (pos <= countLength(head))
    {
        if (pos == 1)
        {
            deletionAtHead(head);
        }
        else if (pos == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            Node *temp = head;
            int i = 1;
            while (i < pos - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout << "Position Out of Bound!" << endl;
    }
}

void deletionByValueUnique(Node *&head, int target)
{
    int position = searchByValueUnique(head, target);
    if (position == -1)
    {
        cout << "Value Not Found in the linked list" << endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}

void deletionByValueDuplicate(Node *&head, int target)
{
    Test positions;
    positions = searchByValueDuplicateReturn(head, target);
    if (positions.arr[0] == 0)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }
    int len = positions.arr[0];
    for (int i = 1; i < len; i++)
    {
        deletionAtSpecificPosition(head, positions.arr[i]);
        for (int j = i; j < len; j++)
        {
            positions.arr[j]--;
        }
    }
}

Node *reverseListNonRecursive(Node *&head)
{
    if (head == NULL || head->Next == NULL)
    {
        if (head == NULL)
        {
            cout << "There is no value to reverse!" << endl;
            return head;
        }
        else
        {
            return head;
        }
    }
    Node *prevNode = head;
    Node *currNode = head->Next;
    while (currNode != NULL)
    {
        Node *nextNode = currNode->Next;
        currNode->Next = prevNode;

        // Update
        prevNode = currNode;
        currNode = nextNode;
    }
    head->Next = NULL;
    return prevNode;
}

Node *reverseListRecursive(Node *&head)
{
    if (head == NULL || head->Next == NULL)
    {
        if (head == NULL)
        {
            cout << "The Linked List is Empty!" << endl;
            return head;
        }
        else
        {
            return head;
        }
    }
    else
    {
        Node *newHead = reverseListRecursive(head->Next);
        head->Next->Next = head;
        head->Next = NULL;
        return newHead;
    }
}

int findMid(Node *&head)
{
    if (head == NULL)
    {
        return -1;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->Next != NULL)
    {
        fast = fast->Next->Next;
        slow = slow->Next;
    }

    return slow->value;
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;
    while (temp->Next != NULL)
    {
        if (pos == count)
            startNode = temp;
        temp = temp->Next;
        count++;
    }
    temp->Next = startNode;
}

bool detectCycle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->Next != NULL)
    {
        fast = fast->Next->Next;
        slow = slow->Next;

        if (slow->Next == fast->Next)
            return true;
    }
    return false;
}

int main()
{
    Node *head = NULL;
    int value, choice, position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insertion at Specific Position" << endl
         << "Choice 4: Search a value (Unique List)" << endl
         << "Choice 5: Search a value (Duplication Enabled List)" << endl
         << "Choice 6: Insertion After a Specific Value (Unique List)" << endl
         << "Choice 7: Insertion After a Specific Value (Duplication Enabled List)" << endl
         << "Choice 8: Deletion at Head" << endl
         << "Choice 9: Deletion at Tail" << endl
         << "Choice 10: Deletion at a Specific Position" << endl
         << "Choice 11: Deletion by value (Unique List)" << endl
         << "Choice 12: Deletion by value (Duplication Enabled List)" << endl
         << "Choice 13: Reversal of List Non-Recursive" << endl
         << "Choice 14: Reversal of List Recursive" << endl
         << "Choice 15: Find Mid Element" << endl
         << "Choice 16: Make Cycle of a LL" << endl
         << "Choice 17: Detect a Cycle" << endl
         << "Choice 0: Exit" << endl
         << endl;
    cout << "Next Choice: ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the Value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
            {
                cout << "The number is at position " << position << endl;
            }
            else
            {
                cout << "The number is not yet the list" << endl;
            }
            break;

        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.arr[0] == 1)
            {
                cout << "The Searched Value is not yet in the list" << endl;
            }
            else
            {
                int size = T.arr[0];
                cout << "The value is at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.arr[i];
                    if (i < size - 1)
                        cout << ",";
                }
                cout << endl;
            }
            break;

        case 6:
            cout << "Enter the value to Search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAfterSpecificValueUnique(head, searchValue, value);
            break;

        case 7:
            cout << "Enter the Search Value (Duplication Enabled): ";
            cin >> value;
            int newValue;
            cout << "Enter the new Value (Duplication Enabled): ";
            cin >> newValue;
            insertionAfterSpecificValueDuplicate(head, value, newValue);
            break;

        case 8:
            deletionAtHead(head);
            break;

        case 9:
            deletionAtTail(head);
            break;

        case 10:
            cout << "Enter the desired position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            break;

        case 11:
            cout << "Enter the value to delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;

        case 12:
            cout << "Enter the Value you want to delete: ";
            cin >> delValue;
            deletionByValueDuplicate(head, delValue);
            break;
        case 13:
            head = reverseListNonRecursive(head);
            break;
        case 14:
            head = reverseListRecursive(head);
            break;
        case 15:
            int mid;
            mid = findMid(head);
            if (mid == -1)
                cout << "LL is Empty!" << endl;
            else
            {
                cout << "Mid Element is " << mid << endl;
            }
            break;

        case 16:
            cout << "Enter a Desired Position: ";
            cin >> position;
            makeCycle(head, position);
            break;
        case 17:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if (cycleStatus)
                cout << "There is a cycle in the LL!" << endl;
            else
                cout << "There is no cycle in the LL!" << endl;
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl
         << "Linked List: ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    return 0;
}