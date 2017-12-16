#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Common.h"
#include "Inventory.h"

class ShoppingCart
{
    public:
        ShoppingCart(Inventory *inv);
        ~ShoppingCart() = default;
        void addItemToCartWithQuantity(const std::string& itemToAdd, const int& quantity);
        void removeItemFromCartWithQuantity(const std::string& itemToLeave, const int& quantityOfItemsToLeave);
        void showShoppingCart();
        void applyDiscounts();
        void printReceipt();
    private:
        InventoryList m_shoppingCart;
        Inventory *m_inventory;
        double m_totalPrice;
        double m_totalDiscount;
};

#endif // SHOPPINGCART_H
