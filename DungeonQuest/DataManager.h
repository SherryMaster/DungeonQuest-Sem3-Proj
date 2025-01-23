#pragma once
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class DataManager {
	vector<string> keys;
	vector<string> values;

	vector<string> items; // for array of items in a file whose first line is the number of items.

	string data_root = "Data";
public:
	DataManager();
	~DataManager();

	void setDataRoot(string root);
	string getDataRoot() const;

	void saveData(string filename);
	void loadData(string filename);
	void saveItemList(string filename);
	void loadItemList(string filename);
	void deleteData(string filename);

	bool fileExists(string filename, bool root_mode = true) const;

	void addData(string key, string value);
	string getData(string key);
	void clearData();
	vector<string> getKeys();
	vector<string> getValues();
	vector<string> getKeysAndValues();

	void addItem(string item);
	void removeItem(string item);
	bool itemExist(string item);
	vector<string> getItems();

};