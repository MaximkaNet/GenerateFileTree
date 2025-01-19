#include "Header.h"
#include "Node.h"
#include "Ignore.h"
#include "IgnoreFile.h"
#include "Tree.h"
#include "Walker.h"

int main() {
	setlocale(LC_ALL, ".utf8");

	/*
	Available paths
	1. Full path like "c:\example\file.ignore"
	2. Directory path "c:\example"
	3. Relative path "example" or "example\nested", "example\nested\second"
	*/

	IgnoreFileProvider ignoreFileProvider(L"file.ignore", L"data");
	wcout << ignoreFileProvider.info() << '\n';

	// root/di1/dir2

	//auto path = fs::path("D:\\Test");
	auto path = fs::path("C:\\");
	auto pathDocuments = fs::path("D:\\Documenty");
	auto minecraftFloder = fs::path("C:\\Users\\mzava\\AppData\\Roaming\\.minecraft");

	cout << "Loading...\n";

	TreeHelper treeHelper(ignoreFileProvider.getIgnoreNames());

	Node* tree;
	//tree = treeHelper.make_tree(path, nullptr);
	//tree = treeHelper.make_tree(pathDocuments, nullptr);
	tree = treeHelper.make_tree(minecraftFloder, nullptr);

	cout << "Loaded!\n";

	//show_tree(*tree);

	Walker* walker = Walker::getWalker();

	walker->init(tree);

	walker->showInteractive();
	
	return 0;
}