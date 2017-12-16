#ifndef INVENTORY_H
#define INVENTORY_H

#include "Common.h"

class Inventory
{
    public:
        Inventory() = default;
        ~Inventory() = default;
        bool isItemAvailable(const std::string& itemToCheck);
        void loadNewItem(const Item& itemToAdd, const int& quantity);
        void incrementItemQuantity(const std::string& itemToIncrement, const int& quantity);
        void decrementItemQuantity(const std::string& itemToDecrement, const int& quantity);
        void showInventory();
        int getRemainingQuantity(const std::string& itemToCheck);
        double getItemPrice(const std::string& itemToCheck);

    private:
        InventoryList m_inventory;
        InventoryListItr findItem(const std::string& itemToFind);
};

#endif // INVENTORY_H
