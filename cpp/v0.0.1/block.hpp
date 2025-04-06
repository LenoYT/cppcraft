using namespace std;

class Block {
    public:
        enum class BlockType {
            NORMAL,
            AIR,
            TRANSPARENT,
            GRAVITY,
            INTERACTIVE,
            LIQUID,
            NULLB
        };

        class Interaction {
            public:
                void main(Block& b) {if (b.type == BlockType::INTERACTIVE) b.interacting=1;}
        };

        class StopInteraction {
            public:
                void main(Block& b) {if (b.type == BlockType::INTERACTIVE) b.interacting=0;}
        };

        Block(string rn, string c, BlockType t, bool i): type(t), ch(c), rawname(rn), interacting(i) {}

        BlockType type = BlockType::NORMAL;
        string ch;
        string rawname;
        bool interacting;
        
};

vector<Block> blocks = {
    Block("null", "", Block::BlockType::NULLB, 0),
    Block("stone", "S", Block::BlockType::NORMAL, 0),
    Block("dirt", "D", Block::BlockType::NORMAL, 0),
    Block("grass", "G", Block::BlockType::NORMAL, 0),
    Block("air", " ", Block::BlockType::AIR, 0),
    Block("water", "~", Block::BlockType::LIQUID, 0),
    Block("lava", "~", Block::BlockType::LIQUID, 0),
    Block("chest", "C", Block::BlockType::INTERACTIVE, 0)
};