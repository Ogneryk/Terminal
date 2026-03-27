#include "SingleLineFile.h"

SingleLineFile::SingleLineFile(string name) : Entry(name), line("") {};

string SingleLineFile::displayName()  {
	return name;
}

void SingleLineFile::display() {
	cout << "Содержимое файла " << name << endl;
	cout << line << endl;
}

void SingleLineFile::hide() {
	Entry::hide();
}

void SingleLineFile::restore() {
	Entry::restore();
}

void SingleLineFile::edit() {
	cout << "введите строку для создания/замены" << endl;
	getline(cin >> ws, line);
	cout << "изменения схранены" << endl;
}

string SingleLineFile::getContent() const {
	return line;
}

void SingleLineFile::setContent(const string& newLine) {
	line = newLine;
}
