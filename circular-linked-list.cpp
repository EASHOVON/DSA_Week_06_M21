#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    // Constructor Creating
    Node(int val)
    {
        // Initializing value and next member
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
int countLength(Node *&head);
void insertAtSpecificPosition(Node *&head, int pos, int value);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void insertAfterSpecificValueUnique(Node *&head, int searchValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int pos);
void deletionByValueUnique(Node *&head, int Value);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        head->Next = head;
        return;
    }

    Node *temp = head;
    while (temp->Next != head)
    {
        temp = temp->Next;
    }
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;

    newNode->Next = head;
    do
    {
        temp = temp->Next;
    } while (temp->Next != head);
    temp->Next = newNode;
    head = newNode;
}

void display(Node *&head)
{
    if (head == NULL)
    {
        cout << "The Linked List is Empty!" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->value;
        if (temp->Next != head)
            cout << " -> ";
        temp = temp->Next;
    } while (temp != head);
    cout << endl
         << endl;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->Next;
    } while (temp != head);

    return count;
}

void insertAtSpecificPosition(Node *&head, int pos, int value)
{
    int i = 0;
    Node *newNode = new Node(value);
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }

    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (head == NULL)
    {
        return -1;
    }

    while (temp->value != key)
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

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    if (flag == 0)
    {
        cout << "The searched value is not yet in the list" << endl;
    }
    else
    {
        position[0] = k;
        cout << "The Value is at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ",";
        }
        cout << endl;
    }
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void insertAfterSpecificValueUnique(Node *&head, int searchValue, int value)
{
    // Step 1: Search the position of the search value
    int position;
    position = searchByValueUnique(head, searchValue);

    // Step 2: Insert the value of the position+1
    insertAtSpecificPosition(head, position + 1, value);
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        Node *delNode = head;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = delNode->Next;
        head = delNode->Next;
    }
    else
    {
        cout << "There is no value in the Linked List" << endl;
    }
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != head)
    {
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
            cout << "There is no value in the Linked List" << endl;
        else
            deletionAtHead(head);
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
        cout << "Position Out of Bound" << endl;
    }
}

void deletionByValueUnique(Node *&head, int value)
{
    // Find the position of the value
    int position = searchByValueUnique(head, value);

    if (position == -1)
    {
        cout << "Value Not Found In The Linked List" << endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}

int main()
{
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion at head" << endl
         << "Choice 2: Insertion at tail" << endl
         << "Choice 3: Insertion at specific position" << endl
         << "Choice 4: Deletion at Head" << endl
         << "Choice 5: Deletion at Tail" << endl
         << "Choice 6: Deletion at Specific Position" << endl
         << "Choice 0: Exit" << endl
         << endl;
    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;
        case 4:
            deletionAtHead(head);
            break;
        case 5:
            deletionAtTail(head);
            break;
        case 6:
            if (head == NULL)
            {
                cout << "There is no value in the Linked List" << endl;
                break;
            }
            cout << "Enter the Desired Position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            cout << endl;
            display(head);
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