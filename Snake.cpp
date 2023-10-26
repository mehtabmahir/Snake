#include "Snake.h"

Snake::Snake(COORD pos, int vel){
    this->pos = pos;
    this->vel = vel;
    len = 1;
    dir = 'n';

    body.push_back(pos);
}

void Snake::change_dir(char dir){
    this->dir = dir;
}

vector<COORD> Snake::get_body() {
    return body;
}

void Snake::move_snake(){
    switch(dir){
        case 'u': pos.Y -= vel; break;
        case 'd': pos.Y += vel; break;
        case 'l': pos.X -= vel; break;
        case 'r': pos.X += vel; break;
    }
    if (pos.X > WIDTH - 2)
        pos.X = 1;
    if (pos.X < 1)
        pos.X = WIDTH - 2;
    
    
    
    
    if (pos.Y > HEIGHT - 2)
        pos.Y = 1;
    if (pos.Y < 1)
        pos.Y = HEIGHT - 2;


    body.push_back(pos);
    if (body.size() > len)
        body.erase(body.begin());
}

COORD Snake::get_pos(){
    return pos;
}

bool Snake::eaten(COORD food) {
    if (pos.X == food.X && pos.Y == food.Y)
        return true;
    return false;
}

void Snake::grow() {
    len++;
}
bool Snake::collided() {
    if (pos.X < 1 || pos.X > WIDTH-2 || pos.Y < 1 || pos.Y > HEIGHT-2)
        return true;
    for (int i = 0; i < len - 1; i++) 
        if (pos.X == body[i].X && pos.Y == body[i].Y)
            return true;
    return false;
}