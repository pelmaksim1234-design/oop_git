#include "Inventory.h"

Inventory::Inventory(std::string item, int itemCount)
    : item(std::move(item)), itemCount(itemCount < 0 ? 0 : itemCount) {
    std::cout << "Inventory constructor: " << this->item << " x" << this->itemCount << std::endl;
}

Inventory::Inventory(const Inventory& other)
    : item(other.item), itemCount(other.itemCount) {
    std::cout << "Inventory copy constructor: " << item << " x" << itemCount << std::endl;
}

Inventory::Inventory(Inventory&& other) noexcept
    : item(std::move(other.item)), itemCount(other.itemCount) {
    other.itemCount = 0;
    std::cout << "Inventory move constructor: " << item << " x" << itemCount << std::endl;
}

Inventory& Inventory::operator=(const Inventory& other) {
    if (this != &other) {
        item = other.item;
        itemCount = other.itemCount;
    }
    std::cout << "Inventory copy operator=: " << item << " x" << itemCount << std::endl;
    return *this;
}

Inventory& Inventory::operator=(Inventory&& other) noexcept {
    if (this != &other) {
        item = std::move(other.item);
        itemCount = other.itemCount;
        other.itemCount = 0;
    }
    std::cout << "Inventory move operator=: " << item << " x" << itemCount << std::endl;
    return *this;
}

Inventory::~Inventory() {
    std::cout << "Inventory destructor for item: " << item << std::endl;
}

const std::string& Inventory::getItem() const {
    return item;
}

int Inventory::getItemCount() const {
    return itemCount;
}

void Inventory::setItem(const std::string& newItem) {
    item = newItem;
}

void Inventory::setItemCount(int newCount) {
    itemCount = newCount < 0 ? 0 : newCount;
}

std::ostream& operator<<(std::ostream& os, const Inventory& inventory) {
    os << inventory.item << ' ' << inventory.itemCount;
    return os;
}

std::istream& operator>>(std::istream& is, Inventory& inventory) {
    is >> inventory.item >> inventory.itemCount;
    if (inventory.itemCount < 0) {
        inventory.itemCount = 0;
    }
    return is;
}
