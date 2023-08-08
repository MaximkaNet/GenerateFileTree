#pragma once
#include <filesystem>
#include <list>
#include <string>

#include "FileInfo.h"

using std::list;
using std::wstring;
using std::string;

namespace fs = std::filesystem;

using fs::path;

class Node
{
	Node* parent;
	path mypath;

	wstring name;
	uintmax_t size;

	list<Node*> children;
	list<FileInfo> files;
public:
	Node();
	Node(wstring _Name, path _Path);
	Node(wstring _Name, path _Path, Node* _Parent);
	Node(const Node&);

	uintmax_t get_size();

	void set_parent(Node* _Parent);
	Node* get_parent() const;

	void append_child(Node* _Children);
	void append_file(const FileInfo& _FileInfo);

	path get_mypath() const;
	wstring get_name() const;

	list<Node*> get_children() const;
	list<FileInfo> get_files() const;

	Node* get_nchild(int inx) const;

	int count_files() const;
	int count_children() const;

	bool has_children();
	bool has_files();

	bool is_root();
};
