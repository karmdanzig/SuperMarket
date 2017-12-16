#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
    public:
        Item(const std::string& name, const double& price);
        ~Item() = default;
        std::string getName() const;
        double getPrice() const;
        bool operator<(const Item& toCompare) const;
        friend std::ostream& operator<<(std::ostream& out, const Item& toPrint);
    private:
        const std::string m_name;
        const double m_price;
};

#endif // ITEM_H
