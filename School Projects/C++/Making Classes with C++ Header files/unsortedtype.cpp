#include "unsortedtype.h"

//Constructor
UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
}

//Destructor
UnsortedType::~UnsortedType()
{
    //post: list is empty; all items have been deleted
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}
//Observers
bool UnsortedType::IsFull() const
{
    //return (length == MAX_ITEMS);

    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

int UnsortedType::GetLength() const
{
    return length;
}
//Transformers
ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
    //Pre: Key members of item is initialized.
    //Post: if found, item's key matches an element's key in the
    //      list and a copy of that element has been returned;
    //      otherise, item is returned.

    //OLDCODE
    // bool moreToSearch;
    // int location = 0;
    // found = false;

    // moreToSearch = (location < length);

    // while (moreToSearch && !found)
    // {
    //     switch (item.ComparedTo(info[location]))
    //     {
    //         case LESS   :
    //         case GREATER:   location++;
    //                         moreToSearch = (location < length);
    //                         break;
    //         case EQUAL  :   found = true;
    //                         item = info[location];
    //                         break;
    //     }
    // }
    // return item;

    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(location->info))
        {
            case LESS   :
            case GREATER: location = location->next;
                          moreToSearch = (location != NULL);
                          break;
            case EQUAL  : found = true;
                          item = location->info;
                          break;
        }
    }
    return item;
}

void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
    //info [length] = item;
    //length++;

    NodeType* location;

    location = new NodeType;
    location->info = item;
    location->next = listData;

    listData = location;

    length++;
}

void UnsortedType::DeleteItem(ItemType item)
{
    //Pre:  item's key has been initialized.
    //      an element in the list has a key that matches item's
    //Post: an element in the list has a key that matches item's
    //OLDCODE
    // int location = 0;
    
    // while (item.ComparedTo(info[location]) != EQUAL)
    //     location++;

    // info[location] = info[length - 1];
    // length--;    
    NodeType* location = listData;
    NodeType* tempLocation;

    //locate node to be deleted.
    if (item.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next; // delete first node
    }
    else
    {
        while (item.ComparedTo((location->next)->info) != EQUAL)
            location = location->next;

        //delete node at location -> next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void UnsortedType::MakeEmpty()
//Post: list is empty; all items have been deallocated.
{
    NodeType* tempPtr;
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
//Iterators
// void UnsortedType::ResetList()
// {
//     //post: currentPos has been initialized.
//     currentPos = -1;
// }

ItemType UnsortedType::GetNextItem()
{
    // pre: ResetList was calld to inital
    //      no transformer has been executed
    //      currentPos is defined.
    // post:item is current item.
    //      currentPos has been updated.
    //OLDCODE;
    //currentPos++;
    //return info[currentPos];

    ItemType item;
    if (currentPos == NULL)
        currentPos = listData;
    else  
        currentPos = currentPos->next;
    item = currentPos->info;
    return item;
}
