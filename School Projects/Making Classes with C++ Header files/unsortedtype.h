#include <fstream>
#include "itemtype.h"
class UnsortedType
{
public:
    struct NodeType
    {
        ItemType info;
        NodeType* next;
    };

    //Constructor
    UnsortedType();
    //Destructor
    ~UnsortedType();
    //Observers
    bool IsFull() const;
    int GetLength() const;
    //Transformers
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void MakeEmpty();
    //Iterators
    void ResetList();
    ItemType GetNextItem();
private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};