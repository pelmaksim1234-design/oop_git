#include "Inventory.h"

#include "GameExceptions.h"

namespace {
void validateInventoryState(const std::string& item, int itemCount) {
    if (item.empty()) {
        throw InventoryException("Inventory item name cannot be empty.");
    }
    if (itemCount < 0) {
        throw InventoryException("Inventory item count cannot be negative.");
    }
}
}

Inventory::Inventory(std::string item, int itemCount)
    : item(std::move(item)), itemCount(itemCount) {
    validateInventoryState(this->item, this->itemCount);
}

Inventory::Inventory(const Inventory& other)
    : item(other.item), itemCount(other.itemCount) {
}

Inventory::Inventory(Inventory&& other) noexcept
    : item(std::move(other.item)), itemCount(other.itemCount) {
    if (item.empty()) {
        item = "Potion";
        itemCount = 1;
    }
    other.item = "MovedFromItem";
    other.itemCount = 0;
}

Inventory& Inventory::operator=(const Inventory& other) {
    if (this != &other) {
        validateInventoryState(other.item, other.itemCount);
        item = other.item;
        itemCount = other.itemCount;
    }
    return *this;
}

Inventory& Inventory::operator=(Inventory&& other) noexcept {
    if (this != &other) {
        item = std::move(other.item);
        itemCount = other.itemCount;
        if (item.empty()) {
            item = "Potion";
            itemCount = 1;
        }
        other.item = "MovedFromItem";
        other.itemCount = 0;
    }
    return *this;
}

Inventory::~Inventory() = default;

const std::string& Inventory::getItem() const {
    return item;
}

int Inventory::getItemCount() const {
    return itemCount;
}

void Inventory::setItem(const std::string& newItem) {
    validateInventoryState(newItem, itemCount);
    item = newItem;
}

void Inventory::setItemCount(int newCount) {
    validateInventoryState(item, newCount);
    itemCount = newCount;
}

std::ostream& operator<<(std::ostream& os, const Inventory& inventory) {
    os << inventory.item << ' ' << inventory.itemCount;
    return os;
}

std::istream& operator>>(std::istream& is, Inventory& inventory) {
    std::string newItem;
    int newItemCount = 0;
    is >> newItem >> newItemCount;
    if (!is) {
        throw InventoryException("Failed to read inventory from stream.");
    }
    validateInventoryState(newItem, newItemCount);
    inventory.item = std::move(newItem);
    inventory.itemCount = newItemCount;
    return is;
}
