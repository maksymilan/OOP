#ifndef CASTLE
#define CASTLE

#include "room.h"
#include "game.h"
class castle{
    private:
        vector<shared_ptr<room>> level_1;//all rooms in the castle of level 1
        vector<shared_ptr<room>> level_2;//all rooms in the castle of level 2
        shared_ptr<room> start;//the start place of the game,construction will set this to the lobby
    public:
        shared_ptr<room> get_start_place(){
            return start;
        }
        player* p;
        castle();//this function is used to generate the rooms and its link
        void play();//the process of the game

};

#endif