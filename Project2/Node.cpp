#include "Node.h"
Node::Node(const Node& node) {
	parent = node.parent;
	name = node.name;
	children = node.children;
	files = node.files;
	mypath = node.mypath;
}

Node::Node(wstring _name, path _mypath) {
	name = _name;
	mypath = _mypath;
}

Node::Node(wstring _name, path _mypath, Node* _parent)
{
	name = _name;
	mypath = _mypath;
	parent = _parent;
}

Node::Node() {
	size = 0;
	parent = nullptr;
}

uintmax_t Node::get_size() {
	
	return this->size;
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
	this->size += p_child->get_size();
	children.push_back(p_child);
}

void Node::append_file(const FileInfo& _FileInfo)
{
	this->size += _FileInfo.size();
	files.push_back(_FileInfo);
}

path Node::get_mypath() const
{
	return mypath;
}

list<Node*> Node::get_children() const
{
	return children;
}

Node* Node::get_nchild(int inx) const
{
	int cursor = 0;
	list<Node*> children = this->children;
	
	//find from back
	if (inx < 0) {
		children.reverse();
		inx *= -1;
	}

	for (auto& child : children) {
		if (cursor == inx) {
			return child;
		}
		cursor++;
	}
	return nullptr; // if inx not found
}

wstring Node::get_name() const
{
	return name;
}

list<FileInfo> Node::get_files() const
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

int Node::count_files() const
{
	return files.size();
}

int Node::count_children() const
{
	return children.size();
}

bool Node::is_root()
{
	return parent == nullptr ? true : false;
}
