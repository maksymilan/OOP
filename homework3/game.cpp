#include "game.h"
#include "castle.h"
#include "room.h"
int main(){
    castle Castle;
    player p(Castle.get_start_place());
    Castle.p = &p;//set the player of the game
    Castle.play();
    return 0;
}

void game_init(){
    cout<<"game start,you are in lobby now, chose a direction to go:";
}
void game_lose(){
    cout<<"a oh ,monster in here, you die..."<<endl;
}
void win_game(){
    cout<<"congratulation! you saved the princess! now you can input \"try again\" to have a new game ,or input\"quit\" to quit the game:" ;
}
bool check_lose_input(string input){
    if(input == "quit"){
        return false;
    }else{
        return true;
    }
}
void player::chat_with_princess(){
    cout<<"princess: you finaly come ,my knghit"<<endl;
    cout<<"player: I'll always protect you ,my lord"<<endl;
}