#include"DataManager.h"

DataManager::DataManager() {
}

DataManager::~DataManager() {
}

void DataManager::setDataRoot(string root) {
	data_root = root;
}

string DataManager::getDataRoot() const {
	return data_root;
}

string DataManager::getConfigsFolder() const {
	return configs;
}

void DataManager::saveData(string filename) {
	ofstream file;
	//cout << data_root + "\\" + filename << endl;
	file.open(data_root + "\\" + filename);
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
	file.open(data_root + "\\" + filename);

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

void DataManager::saveItemList(string filename) {
	ofstream file;
	file.open(data_root + "\\" + filename);
	file << items.size() << endl;
	for (int i = 0; i < items.size(); i++) {
		file << items[i] << endl;
	}
}

void DataManager::loadItemList(string filename) {
	if (!fileExists(filename)) {
		return;
	}

	ifstream file;
	file.open(data_root + "\\" + filename);

	string line;
	getline(file, line);

	int total_items = stoi(line);

	items.clear();
	for (int i = 0; i < total_items; i++) {
		getline(file, line);
		items.push_back(line);
	}
}

void DataManager::deleteData(string filename) {
	if (fileExists(filename)) {
		remove((data_root + "\\" + filename).c_str());
	}
}

bool DataManager::fileExists(string filename, bool root_mode) const {
	ifstream file;
	if (!root_mode) {
		file.open(filename);
	}
	else {
		file.open(data_root + "\\" + filename);
	}

	if (file.is_open()) {
		file.close();
		return true;
	}
	file.close();
	return false;
}

void DataManager::addData(string key, string value) {
	bool key_exist = false;
	int index = -1;
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i] == key) {
			values[i] = value;
			key_exist = true;
			index = i;
			break;
		}
	}
	if (!key_exist) {
		keys.push_back(key);
		values.push_back(value);
	}
	else {
		values[index] = value;
	}
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

void DataManager::addItem(string item) {
	this->items.push_back(item);
}

bool DataManager::itemExist(string item) {
	for (int i = 0; i < this->items.size(); i++) {
		if (this->items[i] == item) {
			return true;
		}
	}

	return false;
}

vector<string> DataManager::getItems() {
	return this->items;
}