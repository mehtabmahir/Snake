#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <vector>

#define WIDTH 100
#define HEIGHT 50

using namespace std;

class Snake{
    private:
        COORD pos;
        int len;
        int vel;
        char dir;
        vector<COORD> body;
    public:
        Snake(COORD pos, int vel);
        void change_dir(char dir);
        void move_snake();
        COORD get_pos();
        bool eaten(COORD food_pos);
        void grow();
        bool collided();
        vector<COORD> get_body();
};

#endif