#include <fstream>
#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
    // TO BE COMPLETED
    // added line
  
    this->itemName = itemName;
    this->itemCode = code;
    this->itemPrice = price;
    this->isItemTaxable = taxable;
}

PriceListItem::PriceListItem() {
    // TO BE COMPLETED
    itemName = "";
    itemCode = "";
    itemPrice = 0.0;
    isItemTaxable = false;
    
    
}

string PriceListItem::getItemName() {
    // TO BE COMPLETED
    return itemName;
}

string PriceListItem::getCode() {
    // TO BE COMPLETED
    return itemCode;
    
}

double PriceListItem::getPrice() {
    // TO BE COMPLETED
    return itemPrice;
}

bool PriceListItem::isTaxable() {
    // TO BE COMPLETED
    return isItemTaxable;
}

