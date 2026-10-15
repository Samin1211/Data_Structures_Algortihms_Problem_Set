#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void sortedInsertion(node *&header, int value)
{
    node *newNode = new node;
    newNode->data = value;
    if (header == NULL || newNode->data < header->data)
    {
        newNode->next = header;
        header = newNode;
        return;
    }
    node *ptr = header;
    while (ptr->next != NULL && ptr->next->data < newNode->data)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void printList(node *header)
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *ptr = header;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void removeCommon(node *header1, node *&header2)
{
    node *ptr1 = header1;
    node *ptr2 = header2;
    node *prev2 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            node *temp = ptr2;
            if (prev2 == NULL)
            {
                header2 = ptr2->next;
            }
            else
            {
                prev2->next = ptr2->next;
            }
            ptr2 = ptr2->next;
            delete temp;
            ptr1 = ptr1->next;
        }
        else if (ptr1->data < ptr2->data)
        {
            ptr1 = ptr1->next;
        }
        else
        {
            prev2 = ptr2;
            ptr2 = ptr2->next;
        }
    }
}

void printLastTwo(node *header)
{
    if (header == NULL || header->next == NULL)
    {
        cout << "Not enough nodes" << endl;
        return;
    }

    node *ptr = header;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    cout << ptr->data << " " << ptr->next->data << endl;
}

void mergeList(node *&header1, node *&header2)
{
    if (header1 == NULL)
    {
        header1 = header2;
        header2 = NULL;
        return;
    }
    node *ptr = header1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = header2;
    header2 = NULL;
}

void selectionSort(node *header)
{
    node *ptr = header;
    while (ptr != NULL)
    {
        node *minNode = ptr;
        node *temp = ptr->next;
        while (temp != NULL)
        {
            if (temp->data < minNode->data)
            {
                minNode = temp;
            }
            temp = temp->next;
        }
        swap(ptr->data, minNode->data);
        ptr = ptr->next;
    }
}
int main()
{
    int n, m;

    cin >> n;

    node *header1 = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        sortedInsertion(header1, value);
    }

    cin >> m;

    node *header2 = NULL;

    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;

        sortedInsertion(header2, value);
    }

    cout << "List 1: ";
    printList(header1);

    cout << "List 2: ";
    printList(header2);

    removeCommon(header1, header2);

    cout << "After removing common elements:" << endl;

    cout << "List 1: ";
    printList(header1);

    cout << "List 2: ";
    printList(header2);

    cout << "Last two nodes of List 1: ";
    printLastTwo(header1);

    cout << "Last two nodes of List 2: ";
    printLastTwo(header2);

    mergeList(header1, header2);

    cout << "After merging: ";
    printList(header1);

    selectionSort(header1);

    cout << "After sorting: ";
    printList(header1);

    return 0;
}