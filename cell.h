struct cell
{
    enum State { dead, alive };

    State state;

    int x, y;

    cell(int xPos = 0, int yPos = 0) : state(dead), x(xPos), y(yPos) {};
    cell(const cell &c) : state(c.state), x(c.x), y(c.y) {};

    bool is_alive();
    void flip_state();

    bool operator==(const cell &c);
    bool operator!=(const cell &c);
};
