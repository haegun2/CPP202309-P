#ifndef LUNCH_H
#define LUNCH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

struct MenuItem {
	string name;
	int rating;
};

extern vector<MenuItem> menuItems;
extern string user_who;

void ManageUsers();
bool UserExists(const string& userName);
void AddUser();
void LoadMenu(const string& user);

void AddMenuItem();
void SaveMenu(const string& user);
void RecommendMenu();

#endif