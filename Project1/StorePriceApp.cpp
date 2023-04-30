/*
    This is a final project for ITCS 2550 V1601 C++2

    The Authors are:
        Group Leader: Destin Mingledoff
        Programmer: Silas Johnson
        Programmer: Andrew Majewski

    This program will be a store compare application that will take in a JSON file to obtain prices and
    caclulate which is the cheapest or best value among the stores.
*/

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
    string item;
    Store store;
    // Data not from the json file

    string bestStoreValue;
};

// Silas Johnson
class DataExtractor
{
    vector<Items> vector_name;
    json j;

    void getJSONData()
    {
    };

    void parseJSONData()
    {
	};


};

class CalulateData : public DataExtractor
{
    string bestStoreValue;
    // Destin Mingledoff
    void FindDifference()
    {
        
    };
    // Destin Mingledoff
    void FindMostexpensive()
    {
	};
    // Silas Johnson
    void FindBestValue()
    {
    };

    // Destin Mingledoff
    void FindBestPrice()
    {
    };
    // Destin Mingledoff
    void FindBestRank()
    {
    };
    // Andrew Majewski
    void FindBestOverallStore()
    {
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