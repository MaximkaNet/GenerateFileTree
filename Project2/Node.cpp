#include "Node.h"
Node::Node(const Node& node) {
	parent = node.parent;
	name = node.name;
	children = node.children;
	files = node.files;
	mypath = node.mypath;
}

Node::Node(string _name, path _mypath) {
	name = _name;
	mypath = _mypath;
}

Node::Node(string _name, path _mypath, Node* _parent)
{
	name = _name;
	mypath = _mypath;
	parent = _parent;
}

Node::Node() {
	size = 0;
	parent = nullptr;
}

uintmax_t Node::total_size() {
	
	return -1;
}
void Node::set_parent(Node* _parent) {
	parent = _parent;
}

Node* Node::get_parent() const
{
	return parent;
}

void Node::append_child(Node* p_child)
{
	children.push_back(p_child);
}

void Node::append_file(const FileInfo& _FileInfo)
{
	files.push_back(_FileInfo);
}

const path Node::get_mypath()
{
	return mypath;
}

const list<Node*> Node::get_children()
{
	return children;
}

const string Node::get_name()
{
	return name;
}

const list<FileInfo> Node::get_files()
{
	return files;
}

bool Node::has_children()
{
	return children.size() != 0;
}

bool Node::has_files()
{
	return files.size() != 0;
}
