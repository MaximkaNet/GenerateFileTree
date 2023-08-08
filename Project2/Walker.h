#pragma once
#include <list>
#include <iostream>
#include <string>

#include "Node.h"
#include "KeyboardHandler.h"

constexpr auto WALKER_NOT_BE_NULLPTR = "Walker not be nullptr!";


class Walker
{
protected:
	static Walker* instance;
	Walker() : currentNode(nullptr), cursorAt(0) {}

	const Node* currentNode;

	int cursorAt;
public:
	Walker(Walker& other) = delete;

	static Walker* getWalker();

	const Node* getCurrentNode();

	void init(const Node*);
	void next(const Node*);
	void back();

	void showWithCursor(int col_width = 50);
	void showInteractive();

	void operator=(const Walker&) = delete;
};