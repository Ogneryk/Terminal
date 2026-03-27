#pragma once
#include "Directory.h"
#include "Entry.h"
#include "MultiLineFile.h"
#include "SingleLineFile.h"

class Directory;

class PostponedFile : public Entry {
private:
	Directory* parent;
public:
	PostponedFile(string name, Directory* parentDir);
	void edit() override;

};