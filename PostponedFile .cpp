
#include "PostponedFile.h"

PostponedFile::PostponedFile(string name, Directory* parentDir) : Entry(name), parent(parentDir){}

void PostponedFile::edit() {
	cout << "Файл " << name << "еще не инициализирован" << endl;
	cout << "Выберите тип s - однострочный  m - многострочный" << endl;
	char chois;
	cin >> chois;
	Entry* newFile = nullptr;
	if (chois == 's' || chois == 'S') {
		newFile = new SingleLineFile(name);
		cout << "создан однострочный файл " << endl;
	}
	else if (chois == 'M' || chois == 'm') {
		newFile = new MultiLineFile(name);
		cout << "создан многострочный файл" << endl;
	}
	else {
		cout << "Отмена инициализации" << endl;
		return;
	}

	if (parent != nullptr) {
		parent->replaceObject(this, newFile);
	}
	newFile->edit();
}