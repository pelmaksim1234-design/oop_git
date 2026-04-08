#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <utility>

class Inventory {
private:
    std::string item;
    int itemCount;

public:
    Inventory(std::string item = "Potion", int itemCount = 1);
    Inventory(const Inventory& other);
    Inventory(Inventory&& other) noexcept;
    Inventory& operator=(const Inventory& other);
    Inventory& operator=(Inventory&& other) noexcept;
    ~Inventory();

    const std::string& getItem() const;
    int getItemCount() const;
    void setItem(const std::string& newItem);
    void setItemCount(int newCount);

    friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory);
    friend std::istream& operator>>(std::istream& is, Inventory& inventory);
};

#endif
