#pragma once
#include "Entry.h"


class Directory : public Entry{
private:
	vector<Entry*> direct;
public:
	Directory(string name);
	~Directory();
	string displayName() override;
	vector<Entry*> listAll() override;
	void hide() override;
	void restore() override;
	
	void edit() override;

	Directory* asDirectory() override;
	Entry* find(string name) override;
	void replaceObject(Entry* oldObject, Entry* newObject);
	void add(Entry* entry);

};