#include "MultiLineFile.h"

MultiLineFile::MultiLineFile(string name) : Entry(name) {
	lines.push_back("Путсая строка");
}

string MultiLineFile::displayName() {
	return Entry::displayName();
}

void MultiLineFile::hide() {
	Entry::hide();
}

void MultiLineFile::restore() {
	Entry::restore();
}

void  MultiLineFile::display() {
	if (lines.empty()) {
		cout << "пустой файл" << endl;
	}
	else {
		for (rsize_t i = 0; i < lines.size(); ++i) {
			cout << i << ": " << lines[i] << endl;
		}
	}
}

void MultiLineFile::edit() {
	cout << "Выберите режим редактирования:" << endl
		<< "1 - изменить конкретную строку по индексу\n2 - добавление текста (вводите строки, -1 для выхлда)" << endl;
	int chois;
	cin >> chois;
	if (chois == 1) {
		int index;
		cout << "Файл содержит " << lines.size() << " строк" << endl
			<< "Ввндите номер строки от 0 до " << lines.size() << endl;
		cin >> index;
		if (index == lines.size()) {
			lines.push_back("");
			cout << "создана новая строка " << endl;
		}

		if (index >= 0 && index < lines.size()) {
			cout << "Введите текст: " << endl;
			getline(cin >> ws, lines[index]);
			cout << "текст сохранен в строку " << index << endl;
		}
		else {
			cout << "Ошибка: неверный индекс";
		}
	}
	else if (chois == 2) {
		cout << "Введите строки, для выхода введите -1" << endl;
		string input;
		while (true)
		{
			getline(cin >> ws, input);
			if (input == "-1") {
				break;
			}
			lines.push_back(input);
		}
		cout << "Файл сохранен" << endl;
	}
	else {
		cout << "неверный выбор редактирования введите 1 или 2" << endl;
	}
}