#include "Linked_List.h"

Linked_List::Linked_List()
{
    head = NULL;
}

Linked_List::~Linked_List()
{
    ListItem* tempLocation;
    while(head != NULL)
    {
        tempLocation = head;
        head = head->next;
        delete tempLocation;
    }
}

void Linked_List::ClearList()
{
    ListItem* tempLocation;
    while(head != NULL)
    {
        tempLocation = head;
        head = head -> next;
        delete tempLocation;
    }
}

bool Linked_List::Insert(int key, float f)
{
    ListItem* location;
    location = new ListItem;
    location->key = key;
    location->theData = f;
    location->next = head;
    head = location;
}

bool Linked_List::Delete(int key)
{
    ListItem* location = head;
    ListItem* tempLocation;
    if(location->key == key)
    {
            tempLocation = location;
            head = head->next;
            return true;
    }
    else
    {
        while (key != (location->next)->key)
            location = location->next;

        tempLocation = location->next;
        location->next = (location->next)->next;
        
    }
    delete tempLocation;
    return false;
}

bool Linked_List::Search(int key, float *retVal)
{
    ListItem* location = head;
    while(location != NULL)
    {
        if (location->key == key)
        {
            return true;
            location = location->next;
        }
        return false;
    }
}

int Linked_List::ListLength()
{
    int length = 0;
    ListItem* location = head; 
    while(location != NULL)
        {
            length++;
            location = location -> next;
        }
    return length;
}

bool Linked_List::isEmpty()
{
    return (head == NULL);
}

bool Linked_List::isFull()
{
    ListItem* location;
    try
    {
        location = new ListItem;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

void Linked_List::PrintList()
{
     ListItem *temp;

     cout << "\n\nItems in the List\n";
     cout << "-----------------------------------------------------------\n";
     cout << "Key\t\tData\n";
     cout << "-----------------------------------------------------------\n";

     if(head == NULL)     // Report no items in the list
     {
          cout << "\t List is currently empty.\n";
     }
     else
     {
          temp = head;
          while(temp != NULL)
          {
               cout << temp->key << "\t\t" << temp->theData << "\n";
               temp=temp->next;
          }
     }
     cout << "-----------------------------------------------------------\n\n";
}