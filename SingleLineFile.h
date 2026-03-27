#pragma once
#include "Entry.h"
class SingleLineFile : public Entry {
private:
	string line;
public:
	SingleLineFile(string name);
	string displayName() override;
	void display() override;
	void hide() override;
	void restore() override;
	void edit() override;
	string getContent() const;
	void setContent(const string& newLine);
};