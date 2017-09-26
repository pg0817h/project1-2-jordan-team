#include "GroceryBill.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
    // To be completed
    price_list = *priceList;
    tax_rate = taxRate;
    
}


void GroceryBill::scanItem(string scanCode, double quantity) {
    // To be completed
    if(price_list.isValid(scanCode))
    {
        PriceListItem newItem = price_list.getItem(scanCode);
        
        if(newItem.isTaxable())
        {
            total +=(quantity * newItem.getPrice()) +((quantity * newItem.getPrice())* tax_rate/100);
        }
        
        else
        {
            total += (quantity * newItem.getPrice());
        }
        
        price_list.isValid(scanCode);
        PriceListItem *temp = itemList;
        if(temp != NULL)
        {
            while(temp->nextItem != NULL)
            {
                temp = temp ->nextItem;
            }
            
            temp->nextItem = &newItem;
        }
        
        else{
            itemList = &newItem;
        }
    }
    else
    {
        throw invalid_argument("Item is not found" + scanCode);
    }
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
    // To be completed
    // HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
    
    ifstream myfile(filename);
    myfile.open("billitems1.txt");
        
    if(myfile.is_open()){
        cout << "Opened file successfully" << filename <<endl;
        
        string code;
        double quantity;
        
        while(myfile >> code >> quantity){
            
            scanItem(code, quantity);
        }
        myfile.close();
    }
    
    else
        throw invalid_argument("It could not open file" + filename);
    
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
    // To be completed
    return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded.
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
    // To be completed
    
    PriceListItem *temp = itemList;
    
    while(itemList->nextItem != NULL)
    {
        if(temp->isTaxable())
        {
            cout << temp->getItemName() << "\n"<<temp->getPrice() << "\n"<<temp->isTaxable() << endl;
        }
        else
        {
            cout << temp->getItemName() << "\n" << temp->getPrice() << "\n" << temp->isTaxable()<<endl;
        
        }
        
        temp = temp->nextItem;
    }
    
}


