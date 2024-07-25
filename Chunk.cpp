#include "Chunk.h"

using namespace std;
int Chunk::o[5][5] =
    {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    };
pair<int, int> Chunk::pivot_o = make_pair(1, 2);

int Chunk::i[5][5] =
    {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
    };
pair<int, int> Chunk::pivot_i = make_pair(2, 2);

int Chunk::t[5][5] =
    {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    };
pair<int, int> Chunk::pivot_t = make_pair(1, 2);

int Chunk::s[5][5] =
    {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    };
pair<int, int> Chunk::pivot_s = make_pair(2, 2);

int Chunk::z[5][5] =
    {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    };
pair<int, int> Chunk::pivot_z = make_pair(2, 3);

int Chunk::j[5][5] =
    {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    };
pair<int, int> Chunk::pivot_j = make_pair(2, 2);

int Chunk::l[5][5] =
    {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    };
pair<int, int> Chunk::pivot_l = make_pair(1, 2);
