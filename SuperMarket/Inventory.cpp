#include "stdafx.h"
#include "Inventory.h"
#include <algorithm>
#include <iostream>

bool Inventory::isItemAvailable(const std::string& itemToCheck)
{
    bool toReturn = false;
    InventoryListItr it = findItem(itemToCheck);
    if(it != m_inventory.end() && it->second > 0)
    {
        toReturn = true;
    }
    return toReturn;
}

int Inventory::getRemainingQuantity(const std::string& itemToCheck)
{
    int toReturn;
    InventoryListItr it = findItem(itemToCheck);
    if(it != m_inventory.end())
    {
        toReturn = it->second;
    }
    return toReturn;
}

double Inventory::getItemPrice(const std::string& itemToCheck)
{
    double toReturn;
    InventoryListItr it = findItem(itemToCheck);
    if(it != m_inventory.end())
    {
        toReturn = it->first.getPrice();
    }
    return toReturn;
}

void Inventory::loadNewItem(const Item& itemToAdd, const int& quantity)
{
    InventoryListItr it = findItem(itemToAdd.getName());
    if(it != m_inventory.end())
    {
        std::cout << "Item already in inventory" << std::endl;
    }
    else
    {
        m_inventory.insert(ItemQuantityPair(itemToAdd, quantity));
    }
}

void Inventory::incrementItemQuantity(const std::string& itemToIncrement, const int& quantity)
{
    InventoryListItr it = findItem(itemToIncrement);
    if(it != m_inventory.end())
    {
        it->second += quantity;
    }
    else
    {
        std::cout << "Item not present already in inventory" << std::endl;
    }
}

void Inventory::decrementItemQuantity(const std::string& itemToDecrement, const int& quantity)
{
    InventoryListItr it = findItem(itemToDecrement);
    if(it != m_inventory.end())
    {
        it->second -= quantity;
    }
    else
    {
        std::cout << "Item not present already in inventory" << std::endl;
    }
}

void Inventory::showInventory()
{
    std::cout << "\n----- FULL INVENTORY -----" << std::endl;
    for(InventoryListItr it = m_inventory.begin(); it != m_inventory.end(); ++it)
    {
        std::cout << it->first << " Quantity left: " << it->second << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

InventoryListItr Inventory::findItem(const std::string& itemToFind)
{
    return std::find_if(m_inventory.begin(), m_inventory.end(), CheckIfEqualItem(itemToFind));
}
