#include <iostream>
#include <vector>

#include "block.hpp"

#define RENDERING_FRAME_CHAR "#"

using namespace std;

class RendererObject {
    public:
        // class hover effect from #include "guihover.cpp"

        class GUITRendererObject {
            public:
                GUITRendererObject(string n): name(n) {}
                string name;
                // vector Items
                // 
        };

        class WORLDTRendererObject {
            public:
                WORLDTRendererObject(vector<Block> o): objs(o) {}
                vector<Block> objs;
        };
};

class TerminalRenderer {
public:
    TerminalRenderer() {}

        void world(RendererObject::WORLDTRendererObject tro) {
            int colc = 0;

            for (int i = 0; i < 12; i++) {
                cout << RENDERING_FRAME_CHAR;
            }
            cout << "\n"; // Added newline after the top border

            for (Block b : tro.objs) {
                cout << b.getChar();
                colc = (colc + 1) % 12;
                if (colc == 0) {
                    cout << "\n";
                }
            }

            if (colc != 0) { // Ensure the bottom border aligns properly
                cout << "\n";
            }

            for (int i = 0; i < 12; i++) {
                cout << RENDERING_FRAME_CHAR;
            }
            cout << "\n"; // Added newline after the bottom border
        }

        void gui(RendererObject::GUITRendererObject tro) {
            cout << "Rendering: " << tro.name << endl;
        }
};

TerminalRenderer TRenderer = TerminalRenderer();
