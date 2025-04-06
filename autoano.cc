#include <iostream>
#include <string>
#include <conio.h> // For kbhit() and getch()
#include <chrono>
#include <thread>

#define FPS 60

int main() {
    std::string input;

    while (true) {
        input.clear();
        auto start = std::chrono::steady_clock::now();
        // Waiting for input

        while (true) {
            if (_kbhit()) { // Check if a key is pressed
                char ch = _getch(); // Get the pressed key
                if (ch == '\r') { // Enter key pressed
                    break;
                }
                input += ch;
                std::cout << ch << "\n";
                // input = inputkb
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Small delay before restarting
    }

    return 0;
}