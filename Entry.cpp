#include "Entry.h"

Directory* Entry::asDirectory() {
	return nullptr;
}
void Entry::hide() {
	if (!name.empty() && name[0] != '.') {
		name = '.' + name;
	}
}

void Entry::restore() {
	if (!name.empty() && name[0] == '.') {
		name.erase(0, 1);
	}
}
string Entry::displayName() {
	return name;
}

void Entry::edit() {
	cout << "Ошибка " << name << " неподдерживает редактирование" << endl;
}

Entry* Entry::find(string name) {
	if (this->name == name) {
		return this;
	}
	else {
		return nullptr;
	}
}

vector<Entry*> Entry::listAll() {
	return vector<Entry*>();
}

bool Entry::isHide() {
	return !name.empty() && name[0] == '.';
}

void Entry::display() {
	cout << "операция неподдерживается " << endl;
}

void Entry::setName(string newName) {
	name = newName;
}