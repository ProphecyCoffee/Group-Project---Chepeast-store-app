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

    int id;
    string itemName;
    Store store;
    // Data not from the json file
    string bestStoreValue;
};

struct uniqueStore
{
    string name;
    int score;
    bool bestStoreValue;
};


// Silas Johnson
template <class T> class DataExtractor
{
public:
    vector<Items> items;
    vector<uniqueStore> stores;
protected:
    
    json j;
    fstream = file;
   
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

    void Data(T)
    {

		T >> data;
		j += data;
    }

    // Andrew Majewksi
    void extractUniqueStore()
    {
        while 
    };


};

class CalulateData : public DataExtractor
{
    string bestStoreValue;
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
    void FindBestPrice()
    {
        // contianers
        float bestPrice = 0;
        string bestStoreName = "";

        // For each store in Items item, compare cheapest price to price a, price b, etc. 
        for (auto element : vector_name) {

            for (auto innerElement : vector_name[element].store)
            {
               
                if (vector_name[element].store[innerElement] != bestPrice) 
                {
                
                    bestPrice = vector_name[element].store[innerElement].price;
                    
                
                }


            }

        }

    };
    // Destin Mingledoff
    void FindBestRank()
    {

    };
    // Andrew Majewski
    void FindBestOverallStore()
    {
        const int THRID_SCORE = 10;
        const int SECOND_SCORE = 20;
		const int FIRST_SCORE = 30;



        for (const auto& items.store.name)
        {
             


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