#include <vector>
#include "cell.h"

using namespace std;

struct grid
{
    vector<vector<cell>> cells;
    vector<cell> changes;

    grid(int width, int height);

    int count_living_neighbors(cell& c);

    void change(cell& c);
    void update();
};
