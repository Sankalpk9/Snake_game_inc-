#include<iostream>
#include<conio.h>
#include<ctime>
#include "Snake.h"
#include "Food.h"
#define HEIGHT 25
#define WIDTH 50
int score;
using namespace std;
Snake snake({WIDTH/2,HEIGHT/2},1);
Food food;
void make_board(){ // making the playing board of the game
COORD snake_pos=snake.get_pos();
COORD food_pos=food.get_pos();
vector<COORD> snake_body =snake.get_body();
cout<<"SCORE : "<<score<<endl<<endl<<endl;
for(int i=0;i<HEIGHT;i++){
    cout<<"\t\t#";
    for(int j=0;j<WIDTH-2;j++){
        if(i==0 || i==HEIGHT-1) cout<<'#';
        else if(i==snake_pos.Y && j+1==snake_pos.X) cout<<'0';
        else if(i==food_pos.Y && j+1==food_pos.X) cout<<'@';
        else {
            bool isbodypart=false;
            for(int k=0;k<snake_body.size()-1;k++){
                if(i==snake_body[k].Y && j+1==snake_body[k].X){
                    cout<<'0';
                    isbodypart=true;
                   break;
                }
            }
           if(!isbodypart) cout<<' ';


        }
    }
    cout<<"#"<<endl;
}
}
int main(){
  score=0;
   srand(time(NULL));
   food.gen_food();
   bool game_over =false;
   while(!game_over){
     make_board();
     if(kbhit()){
        switch(getch()) {
        case 'w' : snake.change_dir('u'); break;
        case 'a' : snake.change_dir('l'); break;
        case 's' : snake.change_dir('d'); break;
        case 'd' : snake.change_dir('r'); break;

        }

     }
      if(snake.collided()) game_over=true;
      if(snake.eaten(food.get_pos())){
        food.gen_food();
        snake.grow();
        score+=10;
      }
       snake.move_snake();

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
     }
    if(score<=300) cout<<"YOU ARE A NOOB"<<endl;
    else if(score>300 && score<=600) cout<<"YOU ARE AN EXPERT"<<endl;
    else cout<<"YOU ARE A MASTER"<<endl;
return 0;
}
