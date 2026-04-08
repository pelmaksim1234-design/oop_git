#include "Inventory.h"

Inventory::Inventory(std::string item, int itemCount)
    : item(std::move(item)), itemCount(itemCount < 0 ? 0 : itemCount) {
    std::cout << "Inventory created: " << this->item << " x" << this->itemCount << std::endl;
}

Inventory::~Inventory() {
    std::cout << "Inventory destroyed for item: " << item << std::endl;
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
