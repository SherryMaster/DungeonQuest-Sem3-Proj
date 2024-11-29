#include"DataManager.h"
#include<fstream>
using namespace std;

DataManager::DataManager() {
}

DataManager::~DataManager() {
}

void DataManager::saveData(string filename) {
	ofstream file;
	file.open(filename);
	for (int i = 0; i < keys.size(); i++) {
		file << keys[i] << "=" << values[i] << endl;
	}
	file.close();
}

void DataManager::loadData(string filename) {

	if (!fileExists(filename)) {
		return;
	}

	ifstream file;
	file.open(filename);

	string line;
	while (getline(file, line)) {
		int index = line.find("=");
		string key = line.substr(0, index);
		string value = line.substr(index + 1);
		keys.push_back(key);
		values.push_back(value);
	}
	file.close();
}

bool DataManager::fileExists(string filename) const {
	ifstream file;
	file.open(filename);

	if (file.is_open()) {
		file.close();
		return true;
	}
	return false;
}

void DataManager::addData(string key, string value) {
	keys.push_back(key);
	values.push_back(value);
}

string DataManager::getData(string key) {
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i] == key) {
			return values[i];
		}
	}
	return "";
}

void DataManager::clearData() {
	keys.clear();
	values.clear();
}

vector<string> DataManager::getKeys() {
	return keys;
}

vector<string> DataManager::getValues() {
	return values;
}

vector<string> DataManager::getKeysAndValues() {
	vector<string> result;
	for (int i = 0; i < keys.size(); i++) {
		result.push_back(keys[i] + "=" + values[i]);
	}
	return result;
}