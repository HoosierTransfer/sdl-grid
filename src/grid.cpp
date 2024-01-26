#include "grid.hpp"
#include <vector>
#include <unordered_map>

void Grid::setCell(int x, int y, int value) {
    grid[std::make_pair(x, y)] = value;
}

int Grid::getCell(int x, int y) {
    auto it = grid.find(std::make_pair(x, y));
    return it == grid.end() ? 0 : it->second;
}

void Grid::clear() {
    grid.clear();
}

std::vector<std::vector<int>> Grid::gridSlice(int x, int y, int width, int height) {
    std::vector<std::vector<int>> slice;
    for (int i = x; i < x + width; i++) {
        std::vector<int> column;
        for (int j = y; j < y + height; j++) {
            column.push_back(getCell(i, j));
        }
        slice.push_back(column);
    }
    return slice;
}