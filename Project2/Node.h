#pragma once
#include <filesystem>
#include <list>
#include <string>

#include "FileInfo.h"

using std::list;
using std::string;

namespace fs = std::filesystem;

using fs::path;

class Node
{
	Node* parent;
	path mypath;

	string name;
	uintmax_t size;

	list<Node*> children;
	list<FileInfo> files;
public:
	Node();
	Node(string _Name, path _Path);
	Node(string _Name, path _Path, Node* _Parent);
	Node(const Node&);
	uintmax_t total_size();
	void set_parent(Node* _Parent);
	Node* get_parent() const;
	void append_child(Node* _Children);
	void append_file(const FileInfo& _FileInfo);
	const path get_mypath();
	const list<Node*> get_children();
	const string get_name();
	const list<FileInfo> get_files();
	bool has_children();
	bool has_files();
};
