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

        Block(string rawname, string ch, BlockType type): rawname(rawname), ch(ch), type(type), interacting(false) {}
        Block(BlockType t, string c, string rn, bool i): type(t), ch(c), rawname(rn), interacting(i) {}

        string getChar() {return ch;}
        string getRName() {return rawname;}
        BlockType getType() {return type;}
        bool isInteracting() {return interacting;}
        

    private:
        BlockType type = BlockType::NORMAL;
        string ch;
        string rawname;
        bool interacting;
};

vector<Block> blocks = {
    Block("null", "", Block::BlockType::NULLB),
    Block("stone", "S", Block::BlockType::NORMAL),
    Block("dirt", "D", Block::BlockType::NORMAL),
    Block("grass", "G", Block::BlockType::NORMAL),
    Block("air", " ", Block::BlockType::AIR),
    Block("water", "~", Block::BlockType::LIQUID),
    Block("lava", "~", Block::BlockType::LIQUID),
    Block("chest", "C", Block::BlockType::INTERACTIVE)
};