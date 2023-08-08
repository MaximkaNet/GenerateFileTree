#include "Walker.h"

Walker* Walker::instance = nullptr;

Walker* Walker::getWalker()
{
	if (instance == nullptr) instance = new Walker();
	return instance;
}

const Node* Walker::getCurrentNode()
{
	return currentNode;
}

void Walker::init(const Node* node)
{
	currentNode = node;
	cursorAt = 0;

	system("cls");

	std::cout << "Current path: " << currentNode->get_mypath() << std::endl;
	showWithCursor();
}

void Walker::next(const Node* node)
{
	currentNode = node;
	cursorAt = 0;
}

void Walker::back()
{	
	if (currentNode->get_parent() == nullptr) return;
	currentNode = currentNode->get_parent();
}

void Walker::showWithCursor(int col_width)
{
	auto dirs = currentNode->get_children();
	auto files = currentNode->get_files();

	// build directories
	string s_cursor = " -> ", s_space = "    ";
	int counter = 0;
	for (auto& dir : dirs) {
		counter == cursorAt ?
			std::cout << s_cursor :
			std::cout << s_space;

		int s_offset = col_width - dir->get_name().size();

		if (s_offset < 0)
			std::wcout << dir->get_name().substr(0, col_width - 3) << wstring(3, '.');
		else
			wcout << dir->get_name() << wstring(s_offset, ' ');

		wcout << '\t';
		std::cout << FileInfo::toHumanStyle(dir->get_size());

		std::cout << '\n';

		counter++;
	}
	std::cout << string(50, '-') << '\n';

	// build files
	for (auto& file : files) {
		std::cout << s_space;
		file.show();
		std::cout << '\n';
	}
}

void Walker::showInteractive()
{
	bool exit = false;
	while (!exit) {
		switch (KeyboardHandler::inventListener()) {
		case VK_UP: {
			if (cursorAt > 0)
				cursorAt += -1;

			system("cls");

			std::cout << "Current path: " << currentNode->get_mypath() << std::endl;
			showWithCursor();
			break;
		}
		case VK_DOWN: {
			if (cursorAt < this->currentNode->count_children() - 1)
				cursorAt += 1;
			system("cls");

			std::cout << "Current path: " << currentNode->get_mypath() << std::endl;
			showWithCursor();
			break;
		}
		case VK_RIGHT: {
			Node* founded = currentNode->get_nchild(cursorAt);
			if (founded != nullptr) {
				next(founded);
				system("cls");

				std::cout << "Current path: " << currentNode->get_mypath() << std::endl;
				showWithCursor();
			}
			else
				std::cout << "End\n";
			break;
		}
		case VK_LEFT: {
			back();

			system("cls");

			std::cout << "Current path: " << currentNode->get_mypath() << std::endl;
			showWithCursor();
			break;
		}
		case VK_ESCAPE:
			std::cout << "Exit" << '\n';
			exit = true;
			break;
		}
	}
}
