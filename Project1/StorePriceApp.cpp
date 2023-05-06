/*
    This is a final project for ITCS 2550 V1601 C++2

    The Authors are:
        Group Leader: Destin Mingledoff
        Programmer: Silas Johnson
        Programmer: Andrew Majewski

    This program will be a store compare application that will take in a JSON file to obtain prices and
    caclulate which is the cheapest or best value among the stores.

    Check List

    PC = Planed Check = It is planed but not implamented
    CC = Compleated Check = We meet the requirement
    ... = Uncertain of the implantation

	1. At least 3 user defined C++ class including - 15pts:                                         (CC)( DataExtractor, CalulateData, DisplayData)
        a. Class inheritance w/polymorphism - 10pts.                                                    (PC)(CalulateData to DisplayData Logging Data)
        b. Class composition - 5pts.                                                                    (CC)(Classs are structured as such)
        c. At least 2 overloaded operators - 10pts.                                                     (...)(Look below for potintal ways to make this work.)
    2. The defining and use of at least one user-defined template class - 15pts.                    (CC)(All the classes are templates Muahahah!!!)
    3. At least one user-defined function that performs searching - 10pts.                          (PC)(We will use a function to call up data on user user request to find data.)
    4. At least one user-defined function that performs sorting - 5pts.                             (PC)(Check: In DisplayData Class there is a sortbeststore.)
    5. Use of at least one Standard Template Library container                                      (CC)(We are using Vector)
        (e.g., vector, queue) which is used in an iteration of its contents - 5pst.                 
    6. Dynamic memory allocation (and deletion) in some form - 5pts.                                (...)(Need use pointers)
    7. At least one use of exception-handling (does not have to be a custom class) - 5pts.          (CC)(Try and catach statemnt in json parse.)
    8. Reading and writing of data to a file - 5pts.                                                (PC)(Using json file and writing a log)
    9. I/O to/from the console - 5pts.                                                              (PC)(Will write data and calucation finding on console)
    10. Comments that convince the instructor you understand the code you wrote - 5pts.             (CC)
    11. GitHub repo that contains all relevant source code and text files - 10pts.                  (CC)

	At least 2 overloaded operators Expanded: So This could be used for the calulate data so we can overload tha / operator to add up all the prices from an itmes and avratge it out.
    we can also use the + operator to add up all the prices to geather in an item.

    ++ get average
    << Diaplay data (Could be useful for pretty print.)

*/

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
// - the best store ranking is dependent on whichever has the best price value overall for all accountable items (omitting duplicate names).. 
// - Will be 
struct uniqueStore
{
    string name;
    int score;
    bool StorePlaceRank;
};


// Silas Johnson
template <typename T>
 class DataExtractor
{
public
	vector<T> items;
	vector<uniqueStore> uStores;

private:
    json j;
   
	void getJSONData(string filename)
	{
		ifstream inFile(DATA_FILE + filename);
		string data;
		if (inFile.is_open())
		{
            try
            {
		        while (getline(inFile, data))
		        {
			        j += json::parse(data);
		        }
			}
            catch (const exception& nf)
            {
                cerr << "Error while parsing Json data: " << nf.what() << endl;
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
		uniqueStore uniqueStoreObj;
		std::vector<std::string> uniqueStoreNames;

		for (const auto& item : items)
		{
			const std::vector<Items::Store>& stores = item.Stores;

			for (const auto& store : stores)
			{
				const std::string& storeName = store.name;

				// Check if the store name is already in the vector
				auto it = std::find(uniqueStoreNames.begin(), uniqueStoreNames.end(), storeName);
				if (it == uniqueStoreNames.end())
				{
					// Add the store name to the vector
					uniqueStoreNames.push_back(storeName);

					// Create a new uniqueStore object
					uniqueStoreObj.name = storeName;
					uniqueStoreObj.score = 0;
					uniqueStoreObj.StorePlaceRank = false;

					// Add the uniqueStore object to the uStores vector
					uStores.push_back(uniqueStoreObj);
				}
			}
		}
	}

public:
	

	void resolveJOSN(string fileName)
	{
		getJSONData(fileName);
		parseJSONData();
	}


};

 template <typename T>
class CalculateData :  public DataExtractor<T>
{


	// Notes for functions: 
	 // are these getters or setters? 

    // Destin Mingledoff

    public 


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

        loggedInfo = "[FindBestPrice] +  ";
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
		const int FIRST_SCORE = 30;
		const int SECOND_SCORE = 20;
        const int THRID_SCORE = 10;
        
		

        for (int i = 0; i < items.size(); i++;)
        {
            for (int s = 0; s < items[i].Stores.size(); s++;)
            {
                if (items[i].Stores[s].rank == "1st")
                {
                    items[i].Stores[s].score = FIRST_SCORE;
                }
                else if (items[i].Stores[s].rank == "2nd")
                {
					items[i].Stores[s].score = SECOND_SCORE;
                }
				else if (items[i].Stores[s].rank == "3rd")
				{
					items[i].Stores[s].score = THRID_SCORE;
				}
                else
                {
					cerr << "Error could not find stated rank: " << endl;
                }
            }
        }
    };

    // Andrew Majewski
    virtual void OutPutFile(string logLine) // sends data to log.txt prettily  logging data as it goes.
    {
        // write the code to put a line into the log.txt file.
    }




};

// Andrew Majewski 
template <typename T>
class DisplayData : public CalculateData<T>
{   
	// Will sort the best store on rank and score.
    

    void ConsoleDisplay()
    {

    }

    void OutPutFile(string logLine)
    {

    }
    // This will be our find function
    void findById()
    {

    }

};

// Destin Mingledoff
int main()
{
    DisplayData<Items> ddi;
    ddi.resolveJOSN(""); // JSON full name needs to be placed.
    
    // need to call function to parse extracrt data, but it is protectected. 
}