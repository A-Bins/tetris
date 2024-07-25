#ifndef CHUNK_H
#define CHUNK_H
#include <algorithm>

class Chunk {

    public:

    static int o[5][5];
    static std::pair<int, int> pivot_o;
    static int i[5][5];
    static std::pair<int, int> pivot_i;
    static int t[5][5];
    static std::pair<int, int> pivot_t;
    static int s[5][5];
    static std::pair<int, int> pivot_s;
    static int z[5][5];
    static std::pair<int, int> pivot_z;
    static int j[5][5];
    static std::pair<int, int> pivot_j;
    static int l[5][5];
    static std::pair<int, int> pivot_l;

    enum ChunkType {
        O, I, T, S, Z, J, L
    };

    Chunk(const std::pair<int, int> xy, const ChunkType type, const int cell[5][5]): x(xy.first), y(xy.second), type(type) {
        std::copy(&cell[0][0], &cell[0][0] + 25, &this->cell[0][0]);
    }

    int x, y;

    const ChunkType type;
    int cell[5][5] {};
};



#endif //CHUNK_H
