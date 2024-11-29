#pragma once
#include <vector>
#include <string>
using namespace std;

class DataManager {
	vector<string> keys;
	vector<string> values;
public:
	DataManager();
	~DataManager();

	void saveData(string filename);
	void loadData(string filename);

	bool fileExists(string filename) const;

	void addData(string key, string value);
	string getData(string key);
	void clearData();
	vector<string> getKeys();
	vector<string> getValues();
	vector<string> getKeysAndValues();
};