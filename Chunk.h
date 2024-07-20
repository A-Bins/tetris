#ifndef CHUNK_H
#define CHUNK_H
#include <algorithm>

class Chunk {

    public:

    static int o[4][4];
    static int i[4][4];
    static int t[4][4];
    static int s[4][4];
    static int z[4][4];
    static int j[4][4];
    static int l[4][4];

    enum ChunkType {
        O, I, T, S, Z, J, L
    };

    Chunk(const int x, const int y, const ChunkType type, const int cell[4][4]): x(x), y(y), type(type) {
        std::copy(&cell[0][0], &cell[0][0] + 16, &this->cell[0][0]);
    }

    int x, y;

    const ChunkType type;
    int cell[4][4] {};
};



#endif //CHUNK_H
