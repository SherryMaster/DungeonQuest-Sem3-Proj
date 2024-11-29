//#pragma once
//#include<iostream>
//#include <string>
//#include<vector>
//#include"MenuSelection.h"
//#include"SceneManager.h"
//using namespace std;
//
//int Scene::count = 0;
//
//Scene::Scene() {
//	name = "Default";
//	content = "Default";
//	nextScenes = {};
//	id = 0;
//}
//
//Scene::Scene(string name, string content, int id, initializer_list<Scene> nextScenes = {}) : name(name), content(content), nextScenes(nextScenes) {
//	this->id = id;
//}
//
//Scene::~Scene() {
//}
//
//void Scene::setName(string name) {
//	this->name = name;
//}
//
//void Scene::setContent(string content) {
//	this->content = content;
//}
//
//string Scene::getName() const {
//	return name;
//}
//
//string Scene::getContent() const {
//	return content;
//}
//
//int Scene::getId() const {
//	return id;
//}
//
//SceneManager::SceneManager() {
//	startScene = Scene();
//	scenes = {};
//}
//
//SceneManager::SceneManager(initializer_list<Scene> scenes) : startScene(*scenes.begin()), scenes(scenes) {
//}
//
//SceneManager::~SceneManager() {
//}
//
//void SceneManager::addScene(Scene scene) {
//	scenes.push_back(scene);
//}
//
//void SceneManager::removeScene(Scene scene) {
//	scenes.erase(find(scenes.begin(), scenes.end(), scene));
//}
//
//Scene SceneManager::getScene(int id) const {
//	for (auto& scene : scenes) {
//		if (scene.getId() == id) {
//			return scene;
//		}
//	}
//	return Scene();
//}
//
//int SceneManager::getTotalScenes() const {
//	return scenes.size();
//}
//
//void SceneManager::displayScene(Scene scene) {
//	cout << scene.getContent() << endl;
//}
//
//void SceneManager::displayScene(int id) {
//	for (auto& scene : scenes) {
//		if (scene.getId() == id) {
//			cout << scene.getContent() << endl;
//			break;
//		}
//	}
//}
//
//void SceneManager::setMainScene(Scene scene) {
//	startScene = scene;
//}