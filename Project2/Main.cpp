#include "Header.h"
#include "Node.h"
#include "Ignore.h"
#include "Tree.h"

void show_tree(Node& tree) {
	cout << "Tree path: " << tree.get_mypath() << "\n";

	// Show directories
	list<Node*> dirs = tree.get_children();
	for (auto& obj : dirs) {
		cout << obj->get_name() << "\n";
	}

	// Show files
	list<FileInfo> files = tree.get_files();
	for (auto& obj : files) {
		obj.show();
		cout << "\n";
	}
}

int main() {
	setlocale(LC_ALL, ".utf8");

	/*
	Available paths
	1. Full path like "c:\example\file.ignore"
	2. Directory path "c:\example"
	3. Relative path "example" or "example\nested", "example\nested\second"
	*/

	IgnoreFileProvider ignoreFileProvider("file.ignore", "data");
	cout << ignoreFileProvider.info() << '\n';

	// root/di1/dir2

	//auto path = fs::path("D:\\Test");
	auto path = fs::path("C:\\");

	TreeHelper treeHelper(ignoreFileProvider.getIgnoreNames());

	Node* tree;
	tree = treeHelper.make_tree(path, nullptr);

	show_tree(*tree);

	return 0;
}