#pragma once
#include "Entry.h"
class MultiLineFile : public Entry{
private:
	vector<string> lines;
public:
	MultiLineFile(string name);
	string displayName() override;
	void edit() override;
	void hide() override;
	void restore() override;
	void display() override;

};
