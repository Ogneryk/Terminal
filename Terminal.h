#pragma once
#include "Directory.h"
#include "SingleLineFile.h"
#include "MultiLineFile.h"
#include "PostponedFile.h"

#include <sstream>

class Terminal {
private:
	Directory* root;
	vector<Directory*> workingDirectory;

	void help();
	void ls();
	void cd(string target);
	void cat(string file);
	void touch(string name);
	void mkdir(string name);
	void rm(string name);
	void restore(string name);
	void mv(string oldName, string newName);
	void edit(string name);
	void command(string cmd, string atg);
	string Promt();
public:
	Terminal();
	~Terminal();
	void run();
};