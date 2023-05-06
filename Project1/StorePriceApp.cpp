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
#include <cmath>
#include <fstream>

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
    vector<Store> Stores;

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
    bool StorePlaceRank;
};


// Silas Johnson
// template <class T>
 class DataExtractor
{
public:
    vector<Items> items;
    vector<uniqueStore> uStores;

    DataExtractor()
    {
        items;
        uStores;
    }


protected:
    json j;
   
	void getJSONData(string filename)
	{
		ifstream inFile(DATA_FILE + filename);
		string data;
		if (inFile.is_open())
		{
			while (getline(inFile, data))
			{
				j += json::parse(data);
			}
		}
	};

    

	void parseJSONData()
	{
        //items[0].Stores
		for (auto& jei : j)
		{
            
			Items i;
			i.id = jei["id"];
			i.itemName = jei["item"];
			for (const auto& jes : j["stores"])
			{
				Items::Store s;
				s.name = jes["store"]["name"];
				s.price = jes["store"]["name"];
				i.Stores.push_back(s);
			}
			items.push_back(i);
		}

	};

    

    // Andrew Majewksi
    // This will extract the uninue names from items. 
    void extractUniqueStore()
    {
        unordered_set<string> uniqueStoreNames;

        for (const auto& j["stores"] : store)
        {
            const std::string& storeName = item.store.name;

            // Check if the store name is already in the set
            if (uniqueStoreNames.find(storeName) == uniqueStoreNames.end())
            {
                // Add the store name to the set
                uniqueStoreNames.insert(storeName);

                // Create a new uniqueStore object
                uniqueStore uniqueStoreObj;
                uniqueStoreObj.name = storeName;
                uniqueStoreObj.score = 0;
                uniqueStoreObj.StorePlaceRank = "";

                // Add the uniqueStore object to the stores vector
                stores.push_back(uniqueStoreObj);
            }
        }
    }

};

class CalulateData : DataExtractor

    // Notes for functions: 
     // are these getters or setters? 
{


    // Destin Mingledoff
    void FindDifference()
    { 

        // For each store in Items item, compare cheapest price to price a, price b, etc. 
        for (auto const element : vector_name) {
            
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
    

    // Andrew Majewski
    void FindMostexpensive()
    {

	};

    // Silas Johnson
    // The mean is just the avarge of all the prices so in this instance it would the ((Kprice Mprice Wprice) / 3 = Mean).
    double Mean(int item)
    {
        int mean = 0;
        int count = 0;
        for (auto item : items)
        {
            for (auto i : item.Stores)
            {
                int mean = mean + i.price;
                count++;
            }
        }
        mean = mean / count;
        return mean;
    }
    //Silas Johnson
    // double variance = (pow(price1 - mean, 2) + pow(price2 - mean, 2) + pow(price3 - mean, 2)) / 3.0;
    double variance(int mean)
    {
		int variance = 0;
		int count = 0;
		for (auto item : items)
		{
			for (auto i : item.Stores)
			{
                variance = pow(i.price - mean, 2);
                count++;
			}
		}
		variance = variance / count;
		return variance;
    }

    // Silas Johnson
    // 
    void StandardDeviaion(int variance)
    {
        variance = variance / 
        double std_dev = 0
		int count = 0;
		for (auto item : items)
		{
			for (auto i : item.Stores)
			{
				int variance = pow(i.price - mean, 2);
				count++;
			}
		}
		variance = variance / count;
		return std_dev;
    };

    // Destin Mingledoff

    
    void findBestPrice() // wrote as a setter. 
    {
        // contianers
        // For every item and the container 'items'
        for (auto& an_Item : items) {
            // initiaizesthe best price to the first store's price and pair that stores name in parrallel to that price as seen below:
            double bestPrice = an_Item.Stores[0].price;
            string bestStoreName = an_Item.Stores[0].name;

            // For the item that is currently parsing: For every store available, do the below:
            for (const auto& a_Store : an_Item.Stores)
            {
                // For the Store x that sells this item, see if it has a better price than the previous store. 
                // If the price is cheaper hence '<' make it the new best price.
                if (a_Store.price < bestPrice)
                {

                    // sets old best price value to the price of the current store's price for the currently loaded item if it is the cheaper than the prior value that was inputed before. 
                    bestPrice = a_Store.price;
                 



                }
            }
            // populates modifiable iValue (current struct element of items) value bestPriceFound with the found best/updated best price. 
            an_Item.bestPriceFound = bestPrice;
        }

        // We now have the best price, now, are we going to return it or have 
    };

    
    void findBestStore() // Wrote as a setter.
    {
        // Initialize the best store to the first store in the item's list
        string bestStoreName = Items.stores.price;
        double bestPrice = Items.stores.;

        // sort hightest to lowest

        // Iterate over all the stores for the item and find the one with the lowest price
        for (const auto& store : Items::stores) {
            if (store.price < bestPrice) {
                bestPrice = store.price;
                bestStoreName = store.name;
            }
        }

        items.BestStoreName = bestStoreName;
    
    
    }



    // Destin Mingledoff
    void FindBestRank() // what 3 items are the cheapest (1st, 2nd, 3rd), and which stores are selling them at cheapest value.
    {

        string first_cheapest_item;
        string second_cheapest_item;
        string third_cheapest_item;
        string loggedInfo;

        for (const auto& item : ::items) 
        {
            item.bestPriceFound 
            // if current new item.bestprice < last item.bestprice
                // make last item.best price first
                // make
            
        }

        loggedInfo = "[FindBestPrice] + ";
        OutPutFile();
        
    };

    /*
	struct Items
{
	struct Store
	{
		string name;
		double price;
		string rank;
	};
	int id;
	string itemName;
	vector<Store> Stores;
	string bestStoreValue;
	double bestPriceFound = 0; 
	string bestStoreFound = "";
}
struct uniqueStore
{
	string name;
	int score;
	bool StorePlaceRank;
};
    */


    // Andrew Majewski
    // can change price to best price. 
    void FindBestOverallStore()
    {
        const int THRID_SCORE = 10;
        const int SECOND_SCORE = 20;
		const int FIRST_SCORE = 30;

        for (auto& i : items)
        {
            for ()
        }
    };

    // Andrew Majewski
    virtual void OutPutFile(string logLine) // sends data to log.txt prettily  logging data as it goes.
    {
        // write the code to put a line into the log.txt file.
    }




};

// Andrew Majewski 
class DisplayData : CalulateData
{
    void ConsoleDisplay()
    {

    }

    void OutPutFile(string logLine)
    {

    }

};

// Destin Mingledoff
int main()
{
    cout << "Hello World!\n";
}