#include <conio.h>
// for now
#include <cstdlib>
#include <iostream>

class Player {
    public:
        bool kbpress = 0;

        void tick() {
            kbkey = ' ';
            kbpress = 0;
            if (_kbhit()) {
                kbkey = _getch();
                kbpress = 1;
            }
        }

        class Movement {
            public:
                void main(Player& pl) {
                    if (pl.kbkey == 'w' || pl.kbkey == 'W') {
                        std::cout << "BRUMM!" << std::endl; // Replaced system call with standard output
                    }
                }
        };
    private:
        char kbkey = ' ';
};

Player defPlayer = Player();
