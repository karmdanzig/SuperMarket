#include "stdafx.h"
#include "Item.h"

Item::Item(const std::string& name, const double& price)
: m_name(name), m_price(price)
{
}

std::string Item::getName() const
{
    return m_name;
}

double Item::getPrice() const
{
    return m_price;
}

bool Item::operator<(const Item& toCompare) const
{
    if (m_price == toCompare.m_price)
    {
        return m_name < toCompare.m_name;
    }
    return m_price < toCompare.m_price;
}

std::ostream& operator<<(std::ostream& out, const Item& toPrint)
{
    out << "Item: " << toPrint.m_name << " Price: " <<  toPrint.m_price;
    return out;
}

