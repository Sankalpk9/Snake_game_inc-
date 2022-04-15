#ifndef FOOD_H
#define FOOD_H
#include<windows.h>
#include<cstdio>
#define HEIGHT 25
#define WIDTH 50
class Food
{
    private:
        COORD pos;
    public:
        void gen_food();
        COORD get_pos();

};

#endif // FOOD_H
