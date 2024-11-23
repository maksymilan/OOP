#ifndef P
#define P
#include "room.h"
class player{
    private:
        shared_ptr<room> current_room;
        bool get_princess;
    public:
        player(shared_ptr<room> r){
            get_princess = false;
            current_room = r;
        }
        void set_room(shared_ptr<room> r){
            current_room = r;
        }
        bool has_princess(){
            return get_princess;
        }
        void set_princess(bool check){
            get_princess = check;
        }//if meet princess,mark this to true
        shared_ptr<room> const get_current_room() const{
            return current_room;
        }
        void chat_with_princess();
        // void behavior(string name);//when pass in differen name of the room,the player can perform different action via current_room
};
void game_init();//print the init information of the game
void game_lose();//print the information about lose the game,and show the options user show chose
bool check_lose_input(string input);//check the input ,decide wheather continue a new game
void win_game();//print the winning information of the game
#endif