#pragma once
#include <windows.h>
#include <iostream>

class KeyboardHandler
{
public:
	static short inventListener(int delayms = 120) {
		do{
			HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
			HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			INPUT_RECORD inp;
			DWORD num_of_events;

			ReadConsoleInput(hIn, &inp, 1, &num_of_events);

			switch (inp.EventType)
			{
			case KEY_EVENT:
				WORD VK_code = inp.Event.KeyEvent.wVirtualKeyCode;
				if (GetKeyState(VK_code) & 0x8000) {
					Sleep(delayms);
					return VK_code;
				}
			}
			;

			/* OLD */

			/*if (GetKeyState(VK_UP) & 0x8000) {
				Sleep(delayms);
				return VK_UP;
			}
			else if (GetKeyState(VK_DOWN) & 0x8000) {
				Sleep(delayms);
				return VK_DOWN;
			}
			else if (GetKeyState(VK_RIGHT) & 0x8000) {
				Sleep(delayms);
				return VK_RIGHT;
			}
			else if (GetKeyState(VK_LEFT) & 0x8000) {
				Sleep(delayms);
				return VK_LEFT;
			}*/
		} while (true);
	}
};

