#include "stdafx.h"
#include "ShoppingCart.h"
#include <algorithm>
#include <iostream>
#include <vector>

ShoppingCart::ShoppingCart(Inventory *inv)
        : m_inventory(inv), m_totalPrice(0), m_totalDiscount(0)
{
}

void ShoppingCart::addItemToCartWithQuantity(const std::string& itemToAdd, const int& quantityOfItemsToTake)
{
    if(!m_inventory->isItemAvailable(itemToAdd))
    {
        return;
    }
    else
    {
        int quantityOfItemRemaining = m_inventory->getRemainingQuantity(itemToAdd);
        if(quantityOfItemsToTake > quantityOfItemRemaining)
        {
            std::cout << "Cannot fulfill request of " << quantityOfItemsToTake << " as only " << quantityOfItemRemaining << " are left" << std::endl;
            return;
        }
    }

    InventoryListItr it = std::find_if(m_shoppingCart.begin(), m_shoppingCart.end(), CheckIfEqualItem(itemToAdd));
    if(it != m_shoppingCart.end())
    {
        it->second += quantityOfItemsToTake;
    }
    else
    {
        double price = m_inventory->getItemPrice(itemToAdd);
        m_shoppingCart.insert(ItemQuantityPair(Item(itemToAdd, price), quantityOfItemsToTake));
    }

    m_inventory->decrementItemQuantity(itemToAdd, quantityOfItemsToTake);
}

void ShoppingCart::removeItemFromCartWithQuantity(const std::string& itemToLeave, const int& quantityOfItemsToLeave)
{
    InventoryListItr it = std::find_if(m_shoppingCart.begin(), m_shoppingCart.end(), CheckIfEqualItem(itemToLeave));
    if(it != m_shoppingCart.end())
    {
        if(quantityOfItemsToLeave > it->second)
        {
            std::cout << "You dont have all these items in your cart" << std::endl;
            return;
        }
        else
        {
            it->second -= quantityOfItemsToLeave;

            if(it->second == 0)
            {
                m_shoppingCart.erase(it);
            }

            m_inventory->incrementItemQuantity(itemToLeave, quantityOfItemsToLeave);
        }
    }
    else
    {
        std::cout << "Item not present in shopping cart" << std::endl;
        return;
    }
}

void ShoppingCart::showShoppingCart()
{
    std::cout << "\n--- YOUR CART CONTAINS ---" << std::endl;
    for(InventoryListItr it = m_shoppingCart.begin(); it != m_shoppingCart.end(); ++it)
    {
        std::cout << it->first << " Quantity: " << it->second << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

void ShoppingCart::applyDiscounts()
{
    InventoryList temp(m_shoppingCart);

    //Discount type 1
    for(InventoryListItr it = temp.begin(); it != temp.end(); ++it)
    {
        if(it->second >= 3)
        {
            int sameTypeItemsOff = it->second / 3;
            m_totalDiscount += it->first.getPrice() * sameTypeItemsOff;
            it->second %= 3;

            std::cout << "You have qualified for a discount of type 1" << std::endl;
            std::cout << "\tYou will receive " << sameTypeItemsOff << " " << it->first.getName() << " for free" << std::endl;
        }
    }

    //Discount type 2
    int totalQuantityOfItems = 0;
    for(InventoryListItr it = temp.begin(); it != temp.end(); ++it)
    {
        totalQuantityOfItems += it->second;
    }
    int numberOfItemsForFreeDueToDiscountType2 = totalQuantityOfItems / 3;

    InventoryListItr it = temp.begin();
    while(numberOfItemsForFreeDueToDiscountType2 > 0)
    {
        if(it->second > 0)
        {
            std::cout << "You have qualified for a discount of type 2" << std::endl;
            std::cout << "\tYou will receive 1 " << it->first.getName() << " for free" << std::endl;
            m_totalDiscount += it->first.getPrice();
            --(it->second);
            --numberOfItemsForFreeDueToDiscountType2;
        }
        else
        {
            ++it;
        }
    }
}

void ShoppingCart::printReceipt()
{
    std::cout << "\n----- YOUR RECEIPT ------" << std::endl;

    for(InventoryListItr it = m_shoppingCart.begin(); it != m_shoppingCart.end(); ++it)
    {
        std::cout << it->first << " Quantity: " << it->second << std::endl;
        m_totalPrice += it->first.getPrice() * it->second;
    }

    applyDiscounts();

    std::cout << "SUBTOTAL: " << m_totalPrice << std::endl;
    std::cout << "TOTAL WITH DISCOUNTS APPLIED: " << m_totalPrice - m_totalDiscount << std::endl;
    std::cout << "--------------------------" << std::endl;
}
