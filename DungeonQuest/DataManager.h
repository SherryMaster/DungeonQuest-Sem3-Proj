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

	string data_root = "Data";
	string configs = data_root + "\\Configs";
public:
	DataManager();
	~DataManager();

	void setDataRoot(string root);
	string getDataRoot() const;
	string getConfigsFolder() const;

	void saveData(string filename);
	void loadData(string filename);
	void deleteData(string filename);

	bool fileExists(string filename, bool root_mode = true) const;

	void addData(string key, string value);
	string getData(string key);
	void clearData();
	vector<string> getKeys();
	vector<string> getValues();
	vector<string> getKeysAndValues();
};