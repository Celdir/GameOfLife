#include <iostream>
#include <string>
#include "grid.h"

grid::grid(int width, int height)
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
    for (int i = c.x-1; i <= c.x+1; ++i) {
        for (int j = c.y-1; j <= c.y+1; ++j) {
            if (cells[i][j] != c && cells[i][j].is_alive()) ++count;
        }
    }
    return count;
}

int main() 
{
    grid g(100, 100);
    std::cout << "Created 100x100 grid of cells." << std::endl;
    string s = g.cells[1][1] == g.cells[2][2] ? "True" : "False";
    std::cout << "Comparing cells[1][1] with cells[2][2]: " << s << std::endl;
    std::cout << "Cell 1 (x,y): (" << g.cells[1][1].x << ", " << g.cells[1][1].y << ")" << std::endl;
    std::cout << "Cell 2 (x,y): (" << g.cells[2][2].x << ", " << g.cells[2][2].y << ")" << std::endl;
}
