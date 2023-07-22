#include "Tree.h"

TreeHelper::TreeHelper(){}

TreeHelper::TreeHelper(list<IgnoreFilename> filenames)
{
	this->ignoreFilenames = filenames;
}

void TreeHelper::setIgnoreFiles(list<IgnoreFilename> filenames)
{
	this->ignoreFilenames = filenames;
}

const list<IgnoreFilename> TreeHelper::getIgnoreFiles()
{
	return this->ignoreFilenames;
}

Node* TreeHelper::make_tree(path path, Node* parent)
{
	string dir_name = path.filename().string();
	string filename, stem, extension;
	uintmax_t size = 0;

	Node* root = new Node(dir_name, path, parent);

	for (auto& obj : fs::directory_iterator(path)) {
		try {
			filename = fs::path(obj).filename().string();

			if (checkIgnoreFilename(filename)) continue;

			if (!fs::is_directory(obj)) {
				// Common values
				stem = fs::path(obj).stem().string();
				extension = fs::path(obj).extension().string();
				size = fs::file_size(obj);

				FileInfo file(filename, stem, extension, size);
				root->append_file(file);
			}
			else {
				root->append_child(make_tree(obj, root));
			}
		}
		catch (fs::filesystem_error& err) {
			cout << "\033[1;31mFile not available \\> " << filename << "\n";
		}
	}

	return root;
}

bool TreeHelper::checkIgnoreFilename(string filename)
{
	for (auto& ignoreFilename : ignoreFilenames) {
		string temp_ignoreFilename = ignoreFilename.filename();
		string temp_filename = filename;

		// all strings to lowwer case
		transform(temp_ignoreFilename.begin(), temp_ignoreFilename.end(), temp_ignoreFilename.begin(), ::tolower);
		transform(temp_filename.begin(), temp_filename.end(), temp_filename.begin(), ::tolower);
		
		if (temp_ignoreFilename == temp_filename) {
			return true;
		}
	}
	return false;
}

//void TreeHelper::clear_tree(Node& root)
//{
//	throw DEV;
//	/*for (auto& child : root.childrens) {
//		if (child.has_children()) clear_tree(child);
//		child.files.clear();
//	}
//	root.childrens.clear();*/
//}
