#include "stdafx.h"
#include <iostream>
#include "Inventory.h"
#include "ShoppingCart.h"

void menu();

int main(int argc, char* argv[])
{
	menu();
	return 0;
}

void menu()
{
	Inventory lis;
	lis.loadNewItem(Item("Bread", 1.3), 100);
	lis.loadNewItem(Item("Wine", 5.3), 100);
	lis.loadNewItem(Item("Apple", 1.2), 100);
	lis.loadNewItem(Item("Butter", 1), 100);
	lis.loadNewItem(Item("Rice", 1.4), 100);
	lis.loadNewItem(Item("Water", 3), 100);
	lis.loadNewItem(Item("Milk", 1.4), 100);

	ShoppingCart shoppingcart(&lis);

	int choose = 0;
	do {
		std::cout << " _______________________________________________________" << std::endl;
		std::cout << "|\t\t\t\t\t\t\t|" << std::endl;
		std::cout << "|\t\tWELCOME TO SHOPPING ONLINE\t\t|" << std::endl;
		std::cout << "|_______________________________________________________|" << std::endl;
		std::cout << "|\t\t\t\t\t\t\t|" << std::endl;
		std::cout << "|\tPlease choose one of the following options:\t|" << std::endl;
		std::cout << "|\t1) View whole inventory\t\t\t\t|" << std::endl;
		std::cout << "|\t2) Add items to your cart\t\t\t|" << std::endl;
		std::cout << "|\t3) Remove items from cart\t\t\t|" << std::endl;
		std::cout << "|\t4) Show current cart\t\t\t\t|" << std::endl;
		std::cout << "|\t5) Pay\t\t\t\t\t\t|" << std::endl;
		std::cout << "|\t0) End Program\t\t\t\t\t|" << std::endl;
		std::cout << "|\t\t\t\t\t\t\t|" << std::endl;
		std::cout << "|_______________________________________________________|" << std::endl;

		std::cout << "Select: ";
		std::cin >> choose;

		switch (choose)
		{
		case 1:
		{
			lis.showInventory();
			break;
		}
		case 2:
		{
			std::cout << "Which item do you want to purchase?" << std::endl;
			std::string itemToPurchase;
			std::cin >> itemToPurchase;
			std::cout << "How many " << itemToPurchase << " do you want?" << std::endl;
			int quantityToPurchase;
			std::cin >> quantityToPurchase;
			shoppingcart.addItemToCartWithQuantity(itemToPurchase, quantityToPurchase);
			break;
		}
		case 3:
		{
			std::cout << "Which item do you want to remove from cart?" << std::endl;
			std::string itemToRemove;
			std::cin >> itemToRemove;
			std::cout << "How many " << itemToRemove << " do you want to remove?" << std::endl;
			int quantityToRemove;
			std::cin >> quantityToRemove;
			shoppingcart.removeItemFromCartWithQuantity(itemToRemove, quantityToRemove);
			break;
		}
		case 4:
		{
			shoppingcart.showShoppingCart();
			break;
		}
		case 5:
		{
			shoppingcart.printReceipt();
			break;
		}
		default:
		{
			if (choose != 0)
			{
				std::cout << "Invalid input" << std::endl;
			}
		}
		}
	} while (choose != 0);
	std::cout << "Goodbye!" << std::endl;
}
