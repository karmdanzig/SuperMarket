#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <map>
#include "Item.h"

typedef std::map<Item, int> InventoryList;
typedef std::map<Item, int>::iterator InventoryListItr;
typedef std::pair<Item, int> ItemQuantityPair;

class CheckIfEqualItem
{
public:
    std::string name;

    CheckIfEqualItem(const std::string& name) : name(name)
    {
    }

    bool operator()(const ItemQuantityPair& p)
    {
        return (name == p.first.getName());
    }
};


#endif // COMMON_H_INCLUDED
