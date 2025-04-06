#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "block.hpp"
#include "player.hpp"
#include "render.hpp"

using namespace std;

#define FPS 60

Block getBlock(string rawname) {
    for (auto b : ::blocks) { // Explicitly reference the global blocks vector
        if (b.rawname == rawname) {
            return Block(b.rawname, b.ch, b.type, b.interacting);
        }
    }
    return Block( "null", "null", Block::BlockType::NULLB, false); // default block if not found
}


void tick(std::chrono::steady_clock::time_point frameStart) {
    //for each block chcecking if interacting==1 if true then open gui of this block
    // cout<<"Clock is ticking! ";

    defPlayer.tick();
    if (defPlayer.kbpress == true) {
        Player::Movement().main(defPlayer);
    }
}

// vector<Block> bs = {
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
//     blocks[1],blocks[1],blocks[2],
//     blocks[3],blocks[4],blocks[5],
// };

int main() {
    // TRenderer.world(RendererObject::WORLDTRendererObject(bs));



    // Block block(Block::BlockType::INTERACTIVE); // LET'S JUST SAY IT'S A CHEST, OK?

    // Block::Interaction().main(block);
    // Block::StopInteraction().main(block);

    cout << "Hello, Minecraft!" << endl;
    cout << "This is a \"simple\" C++ program." << endl;

    using namespace std::chrono;

    auto frameDuration = milliseconds(1000 / FPS);

    while (true) {
        auto frameStart = steady_clock::now();

        tick(frameStart);

        auto frameEnd = steady_clock::now();
        auto frameTime = duration_cast<milliseconds>(frameEnd - frameStart);
        if (frameTime < frameDuration) {
            std::this_thread::sleep_for(frameDuration - frameTime);
        }
    }

    return 0;
}