#include <vector>
#include "cell.h"

using namespace std;

struct grid
{
    int width, height;
    vector<vector<cell>> cells;
    vector<cell*> changes;

    grid(int w, int h); 

    int count_living_neighbors(cell& c);

    void update();
};
