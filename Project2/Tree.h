#pragma once
#include "Node.h"
#include "FileInfo.h"
#include "Ignore.h"

constexpr auto DEV = "In development.";

void reduce(Node* root);

class TreeHelper {
private:
	list<IgnoreFilename> ignoreFilenames;
public:
	TreeHelper();
	TreeHelper(list<IgnoreFilename>);

	void setIgnoreFiles(list<IgnoreFilename>);
	const list<IgnoreFilename> getIgnoreFiles();

	Node* make_tree(path root, Node* parent);
	/*void clear_tree(Node& root);*/

	bool checkIgnoreFilename(string filename);
};
