#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include<vector>
using namespace std;
class Snake
{
     private:
         COORD pos;
         int len;
         int vel;
         char direction;
         vector<COORD> body;
     public:
        Snake(COORD pos,int vel); // constructor
        void change_dir(char dir); // change the direction of the snake
        void move_snake(); // move the snake
        COORD get_pos();  // get the position of the snake
        void grow(); // to grow the snake
        bool eaten(COORD food); // if snake eat the food or not
        bool collided(); // if snake hit the wall or not
        vector<COORD> get_body(); // to get the body of the snake
};

#endif // SNAKE_H
