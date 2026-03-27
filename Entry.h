#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Directory;

class Entry
{
protected:
	string name;
public:
	Entry(string name) : name(name) {};
	virtual ~Entry() {};
	virtual vector<Entry*> listAll();
	virtual Directory* asDirectory();
	virtual void hide();

	virtual void restore();
	virtual string displayName();
	virtual Entry* find(string name);
	virtual void edit();
	virtual void display();
	bool isHide();
	void setName(string newName);
};