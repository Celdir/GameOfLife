#include "grid.h"
#include <cstdlib>

grid::grid(int w, int h) : width(w), height(h)
{
    for (int i = 0; i < width; ++i) {
        vector<cell> c;
        for (int j = 0; j < height; ++j) {
            c.push_back(cell(i, j));
        }
        cells.push_back(c);
    }
}

int grid::count_living_neighbors(cell& c)
{
    int count = 0;
    for (int i = c.x-1 + width; i <= c.x+1 + width; ++i) {
        for (int j = c.y-1 + height; j <= c.y+1 + height; ++j) {
            if (cells[i % width][j % height] != c && cells[i % width][j % height].is_alive()) ++count;
        }
    }
    return count;
}

void grid::update()
{
    for (int i = 0; i < cells.size(); ++i) {
        for (int j = 0; j < cells[i].size(); ++j) {
            int live_neighbors = count_living_neighbors(cells[i][j]);
            if (cells[i][j].is_alive()) {
                if (live_neighbors < 2 || live_neighbors > 3) changes.push_back(&cells[i][j]);
            } else {
                if (live_neighbors == 3) changes.push_back(&cells[i][j]);
            }
        }
    }
    
    for (cell* c : changes) {
        c->flip_state();
    }
    changes.clear();
}

void grid::clear()
{
    for (int i = 0; i < cells.size(); ++i) {
        for (int j = 0; j < cells[i].size(); ++j) {
            cells[i][j].state = cell::State::dead;
        }
    }
}

void grid::randomize()
{
    for (int i = 0; i < cells.size(); ++i) {
        for (int j = 0; j < cells[i].size(); ++j) {
            if (std::rand() & 1) cells[i][j].flip_state();
        }
    }
}
