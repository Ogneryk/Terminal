#include "Terminal.h"
#include "Directory.cpp"

string Terminal::Promt() {
	string message = "";

	for (size_t i = 0; i < workingDirectory.size(); ++i) {
		if (!workingDirectory[i]->isHide()) {
			message += workingDirectory[i]->displayName();
			if (i < workingDirectory.size() - 1) {
				//message += '/';
			}
		}
	}
	message += " >> ";
	return message;
}

void Terminal::help() {
	cout << "Список поддерживаемых команд" << endl;
	cout << "exit  - завершение работы" << endl;
	cout << "ls    - показ содержимого текущей директории" << endl;
	cout << "cd    -  переход в директорию" << endl;
	cout << "cat   - вывод содержимого файла" << endl;
	cout << "touch - создание файла" << endl;
	cout << "mkdir - создание директориии" << endl;
	cout << "rm    - удаление файла/директории" << endl;
	cout << "restor - восстановление файла" << endl;
	cout << "mv    -  переименование файла/директории" << endl;
	cout << "edit  - редактирование файла" << endl;
}

void Terminal::ls() {
	Directory* curr = workingDirectory.back();
	vector<Entry*> items = curr->listAll();
	if (items.empty()) {
		cout << "Директория путса" << endl;
		return;
	}
	cout << "Видимые файлы" << endl;
	for (Entry* entry : items) {
		if (!entry->isHide()) {
			cout << entry->displayName() << " ";
		}
	}
	cout << endl << "скрытые файлы" << endl;
	bool hasHidden = false;
	for (Entry* entry : items) {
		if (entry->isHide()) {
			cout << entry->displayName() << " ";
			hasHidden = true;
		}
	}
	if (!hasHidden) {
		cout << "нет скрытых файлов" << endl;
	}
}

void Terminal::cd(string target) {
	if (target == "up") {
		if (workingDirectory.size() > 1) {
			workingDirectory.pop_back();
		}
		else {
			cout << "Ошибка: вы находитесть в корневой директории" << endl;
		}
		return;
	}

	Entry* found = workingDirectory.back()->find(target);
	if (found == nullptr) {
		cout << "Ошибка: " << target << " не найдена" << endl;
		return;
	}

	Directory* nextDir = found->asDirectory();
	if (nextDir != nullptr) {
		workingDirectory.push_back(nextDir);
	}
	else {
		cout << "Ошибка: " << target << "не является директрорией" << endl;
	}
}

void Terminal::cat(string file) {
	Entry* foud = workingDirectory.back()->find(file);
	if (foud != nullptr) {
		foud->display();
	}
	else {
		cout << "Файл " << file << " не найден" << endl;
	}
}

void Terminal::touch(string name) {
	Directory* curr = workingDirectory.back();
	if (curr->find(name) != nullptr) {
		cout << "Файл с таким именем уже существует " << endl;
		return;
	}

	PostponedFile* zygote = new PostponedFile(name, curr);
	curr->add(zygote);
	cout << "создана заготовка файла " << name << endl;
}

void Terminal::mkdir(string name) {
	Directory* curr = workingDirectory.back();

	if (curr->find(name) != nullptr) {
		cout << "Директория с таким именем уже есть" << endl;
		return;
	}
	Directory* newDir = new Directory(name );
	curr->add(newDir);
	cout << "Директория " << name << "успешно создана" << endl;
}

void Terminal::rm(string name) {
	Directory* curr = workingDirectory.back();
	Entry* found = curr->find(name);
	if (curr->find('.' + name) != nullptr) {
		cout << "Файл уже скрыт" << endl;
		return;
	} 
	if (found != nullptr) {
		found->hide();
		cout << "Файл успешно скрыт" << endl;
	}
	else {
		cout << "Файл не найден" << endl;
	}

}

void Terminal::restore(string name) {
	Directory* curr = workingDirectory.back();
	Entry* found = curr->find('.' + name);
	if (curr->find(name) != nullptr) {
		cout << "Файл не был скрыт" << endl;
	}
	if (found != nullptr) {
		found->restore();
		cout << "Файл успешно восстановлен" << endl;
	}
	else {
		cout << "Файл не найден" << endl;
	}
}

void Terminal::mv(string oldName,string newName) {
	Directory* curr = workingDirectory.back();

	Entry* found = curr->find(oldName);
	if (found == nullptr) {
		cout << "Файл или папка с именем " << oldName << " не найдены" << endl;
		return;
	}
	if (curr->find(newName) != nullptr) {
		cout << "Это имя уже занято " << endl;
		return;
	}
	found->setName(newName);
	cout << "Имя успешно изменено" << endl;
	
}

void Terminal::edit(string name) {
	Directory* curr = workingDirectory.back();

	Entry* found = curr->find(name);
	if (found != nullptr) {
		found->edit();
		cout << "Фвйл  успешно отредактирован" << endl;
	}
	else {
		cout << "Файл не найден" << endl;
	}

}

Terminal::Terminal() {
	root = new Directory("root");
	workingDirectory.push_back(root);
	cout << "Система акивна." << endl;
}

Terminal::~Terminal() {
	delete root;
	cout << "Сессия завершена. Память очищена" << endl;
}




void Terminal::run() {
	string input;

	while (true) {

		cout << Promt();


		if (!getline(cin, input) || input == "exit") {
			cout << "Завершение работы..." << endl;
			break;
		}

		if (input.empty()) continue;

	
		stringstream ss(input);
		string cmd, arg;
		ss >> cmd;               
		getline(ss >> ws, arg);  
		if (arg == "") {
			cout << "Вы не написали имя файла/дериктории" << endl;
			continue;

		}
		command(cmd, arg);
	}
}

void Terminal::command(string cmd, string arg) {

	Directory* current = workingDirectory.back();

	if (cmd == "ls") {
		
		ls();
	}
	else if (cmd == "cd") {
		cd(arg); 
	}
	else if (cmd == "mkdir") {
		mkdir(arg); 
	}
	else if (cmd == "touch") {
		
		touch(arg);
	}
	else if (cmd == "edit") {
		
		edit(arg);
	}
	else if (cmd == "rm") {
		rm(arg); 
	}
	else if (cmd == "restore") {
		restore(arg); 
	}
	else if (cmd == "mv") {
		cout << "Введите новое имя для '" << arg << "': ";
		string newName;
		cin >> newName;
		mv(arg, newName);
	}
	else if (cmd == "cat") {
		cat(arg);
	}
	else if (cmd == "help") {
		help();
	}
	else {
		cout << "Ошибка: команда '" << cmd << "' не распознана. Введитн 'help'." << endl;
	}
}