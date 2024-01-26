#pragma once

#include <vector>
#include <unordered_map>
#include <boost/functional/hash.hpp>

class Grid {
public:
    void setCell(int x, int y, int value);
    int getCell(int x, int y);
    void clear();
    std::vector<std::vector<int>> gridSlice(int x, int y, int width, int height);
private:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2> &pair) const {
            std::size_t seed = 0;
            boost::hash_combine(seed, pair.first);
            boost::hash_combine(seed, pair.second);
            return seed;
        }
    };
    std::unordered_map<std::pair<int, int>, int, pair_hash> grid;
};