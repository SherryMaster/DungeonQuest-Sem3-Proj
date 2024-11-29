//#pragma once
//#include <string>
//#include<vector>
//#include"MenuSelection.h"
//using namespace std;
//
//class Scene {
//	static int count;
//
//	string name;
//	int id;
//	MenuManager menuManager;
//	string content;
//
//	vector<Scene> nextScenes;
//public:
//	Scene();
//	Scene(string name, string content, int id,initializer_list<Scene> nextScenes);
//	~Scene();
//
//	void setName(string name);
//	void setContent(string content);
//	string getName() const;
//	string getContent() const;
//
//	int getId() const;
//
//};
//
//
//class SceneManager {
//	Scene startScene;
//	vector<Scene> scenes;
//public:
//	SceneManager();
//	SceneManager(initializer_list<Scene> scenes);
//	~SceneManager();
//
//	void addScene(Scene scene);
//	void removeScene(Scene scene);
//
//	Scene getScene(int id) const;
//	int getTotalScenes() const;
//
//	void displayScene(Scene scene);
//	void displayScene(int id);
//
//	void setMainScene(Scene scene);
//
//};