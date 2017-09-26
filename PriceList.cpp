
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
    ifstream myfile(filename);
    myfile.open("pricelist.txt");
    
    if (myfile.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string name;
        string code;
        double price;
        bool taxable;
        while (myfile >> name >> code >> price >> taxable) {
            // cout << code << " " << taxable << endl;
            addEntry(name, code, price, taxable);
        }
        myfile.close();
    }
    else
        throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
    // TO BE COMPLETED
    PriceListItem *temp = itemList;
    if(temp != NULL)
    {
        if(temp->getCode().compare(code)==0)
        {
            return true;
        }
        while(temp->nextItem != NULL)
        {
            if(temp->getCode().compare(code)==0)
            {
                return true;
            }
            temp = temp->nextItem;
        }
    }
    return false;
}

// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
    // TO BE COMPLETED
    if(isValid(code))
    {
        PriceListItem *temp = itemList;
        if(temp != NULL)
        {
            if(temp->getCode().compare(code)==0)
            {
                return *temp;
            }
            while(temp->nextItem != NULL)
            {
                if(temp->getCode().compare(code)==0)
                {
                    return *temp;
                }
                temp = temp->nextItem;
            }
        }
    }
    throw invalid_argument("invalid code" + code);
    
}

// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
    // TO BE COMPLETED
    //create an item
    PriceListItem newItem(itemName,code,price,taxable);
    //make item next to NULL
    newItem.nextItem =NULL;
    
    PriceListItem *temp = itemList;
    if(temp != NULL)
    {
        while(temp->nextItem != NULL)
        {
            temp = temp->nextItem;
        }
        
        temp->nextItem = &newItem;
    }
    else
    {
        itemList = &newItem;
    }
    
}
PriceListItem* PriceList::getPriceList()
{
    return itemList;
}
