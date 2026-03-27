#include "Directory.h"

Directory::Directory(string name) : Entry(name) {};

Directory::~Directory() {
	for (Entry* entry : direct) {
		delete entry;
	}
}

string Directory::displayName()  {
	return name + '/';
}
vector<Entry*> Directory::listAll() {
	return direct;

}
void Directory::hide() {
	Entry::hide();
	for (Entry* entry : direct) {
		entry->hide();
	}

}
void Directory::restore()  {
	Entry::restore();
	for (Entry* entry : direct) {
		entry->restore();
	}
	
}
void Directory::edit()  {
	cout << "Ошибка дирикторию " << name << "нельзя редактировать" << endl;
}

Directory* Directory::asDirectory()  {
	return this;
}

Entry* Directory::find(string name) {
	if (this->name == name) {
		return this;
	}
	for (Entry* entry : direct) {
		if (entry->displayName() == name) {
			return entry;
		}
	}
	return nullptr;
}

void Directory::replaceObject(Entry* oldObject, Entry* newObject) {
	for (size_t i = 0; i < direct.size(); ++i) {
		if (direct[i] == oldObject) {
			direct[i] = newObject;
			delete oldObject;
			return;
		}
	}
}

void Directory::add(Entry* entry) {
	direct.push_back(entry);
}
