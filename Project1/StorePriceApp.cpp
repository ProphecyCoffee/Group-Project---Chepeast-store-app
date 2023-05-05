/*
    This is a final project for ITCS 2550 V1601 C++2

    The Authors are:
        Group Leader: Destin Mingledoff
        Programmer: Silas Johnson
        Programmer: Andrew Majewski

    This program will be a store compare application that will take in a JSON file to obtain prices and
    caclulate which is the cheapest or best value among the stores.
*/

// Hello I am a teapot

#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;


const string DATA_FILE = "TestData\\";

struct Items 
{
    struct Store
    {
		string name;
        double price;
        string rank;
	};
// Original Values for Items:
    int id;
    string itemName;
    Store store;
    // Data not from the json file
    string bestStoreValue;

//Added 05/05/23, edit by destin for possible implementation:
    // This will be the best found price for this item.
    double bestPriceFound = 0; // this is okay, function FindBestPrice() will place the very first price value it finds for the item as bestPriceFound and will then compare that first value to the other store's prices.
    string bestStoreFound = "";
};



// Difference between struct store and unique store.
// - 3 items, walmart, kroger, and whatever the other one was.
// - the best store ranking is dependent on whichever has the best price value overall for all accountable items (omitting duplicates).. 
// - Will be 
struct uniqueStore
{
    string name;
    int score;
    bool bestStoreValue;
};


// Silas Johnson
template <class T>
 class DataExtractor
{
public:
    vector<Items> items;
    vector<uniqueStore> stores;
protected:
    
    json j;

   
    void getJSONData(T)
    {
        file.open(T);
        Data(T);
    };

    void parseJSONData()
    {
		for (auto& c : j["id"])
			Items.push_back(c);

        for (auto& c : j["item"])
			Items.push_back(c);

		for (auto& c : j["name"])
			Items.push_back(c);

		for (auto& c : j["price"])
			Items.push_back(c);

	};

    void Data(file)
    {

		T >> data;
		j += data;
    }

    // Andrew Majewksi
    // This will extract the uninue names form items. 
    void extractUniqueStore()
    {
        while (auto& [key, value] : j.items())
        {
            if (key == store)
        }
    };


};

class CalulateData : public DataExtractor<class Type>

    // Notes for functions: 
     // are these getters or setters? 
{


    // Destin Mingledoff
    void FindDifference()
    { 

        // For each store in Items item, compare cheapest price to price a, price b, etc. 
        for (auto element : vector_name) {
            
            for (auto innerElement : vector_name[element].store)
            {
                // Compare best price to 2nd best price
                
                // psudeo code:  (Need to figure out what to use to "GetBestPrice, atm it is void, will it store a value in a variable for this class or will it call the function FindBestPrice? Is FindBestPrice
                // element dependent or object dependent when it comes to returnining data. 
                /*
                

                if (Get best price != vector_name[element].store[innerElement].price)
                {
                
                
                
                }
                else { continue;  } // move to either next element in nested struct, or end the price comparison. 
                
                */

                // return difference.



            }

                
         };

        
    };
    // Destin Mingledoff
    void FindMostexpensive()
    {

	};
    // Silas Johnson
    void TBA()
    {

    };

    // Destin Mingledoff

    
    void findBestPrice() // wrote as a setter. 
    {
        // contianers
        // For every item and the container 'items'
        for (const auto& item : items) {
            // initiaizesthe best price to the first store's price and pair that stores name in parrallel to that price as seen below:
            double bestPrice = item.stores[0].price;
            string bestStoreName = item.stores[0].name;

            // For the item that is currently parsing: For every store available, do the below:
            for (const auto& store : item.stores) 
            {
                // For the Store x that sells this item, see if it has a better price than the previous store. 
                // If the price is cheaper hence '<' make it the new best price.
                if (store.price < bestPrice)
                {

                    bestPrice = store.price;
                   // Removd this, this could technically be here, but it would make the function do MORE than 1 thing, its suppose to get the best price, not the best store name.
                    // bestStoreName = store.name;



                }
            }

            //!!!Issue: We will need to store the best price for this current item somewhere before it is de-allocated from memory:
            /*
            
            Scenario a)  New Struct Variable to Hold Best Price = bestPrice; 
            -> moves onto next item or out of loop and de-allocates current items best price variable. This would be the best if we do not return a value and it will keep us from having to return an stl container
            or  send in a value throgh the parameters. 

            Scenario b) 
            returns bestPrice value.
            
            */

            // going with scenario a)
            item.bestPriceFound = bestPrice;
        }

        // We now have the best price, now, are we going to return it or have 
    };

    
    void findBestStore() // Wrote as a setter.
    {
        // Initialize the best store to the first store in the item's list
        string bestStoreName = item.stores[0].name;
        double bestPrice = item.stores[0].price;

        // Iterate over all the stores for the item and find the one with the lowest price
        for (const auto& store : item.stores) {
            if (store.price < bestPrice) {
                bestPrice = store.price;
                bestStoreName = store.name;
            }
        }

        item.BestStoreName = bestStoreName;
    
    
    }



    // Destin Mingledoff
    void FindBestRank() // what 3 items are the cheapest (1st, 2nd, 3rd), and which stores are selling them at cheapest value.
    {
        
    };




    // Andrew Majewski
    // can change price to best price. 
    void FindBestOverallStore()
    {
        const int THRID_SCORE = 10;
        const int SECOND_SCORE = 20;
		const int FIRST_SCORE = 30;



        for (const auto& items.store.name)
        {
            best_price = store.price;
            best_store_name = store.name;


        }

    };
};

// Andrew Majewski 
class DisplayData : CalulateData
{
    void ConsoleDisplay()
    {

    }

    void OutPutFile()
    {

    }

};

// Destin Mingledoff
int main()
{
    cout << "Hello World!\n";
}