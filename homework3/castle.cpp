#include "castle.h"
#include "game.h"
#include <sstream>
castle::castle(){
    // lobby room_lobby("lobby","This grand  has witnessed laughter and tears, glory and decay; today, it echoes only whispers of the past.");
    // throne_room room_throne("throne room","Beneath this throne, the tides of history never cease, and the will of kings endures upon this land.");
    // armory room_armory("armory","Every blade here thirsted for blood, and every shield bore the weight of fate’s strike.");
    // chapel room_chapel("chapel","In this serene sanctuary, the whispers of divinity still linger, awaiting the ears of the faithful.");
    // library room_library("library","Endless wisdom lies within these scrolls, but only the brave soul may uncover their truths.");
    shared_ptr<lobby> room_lobby = make_shared<lobby>();
    shared_ptr<throne_room> room_throne = make_shared<throne_room>();
    shared_ptr<armory> room_armory = make_shared<armory>();
    shared_ptr<chapel> room_chapel = make_shared<chapel>();
    shared_ptr<library> room_library = make_shared<library>();
    shared_ptr<ballroom> room_ballroom = make_shared<ballroom>();
    start = room_lobby;
    // level_1.push_back(room_lobby);the only exit does not include when chose the room that princess or monster are.
    level_1.push_back(room_armory);
    level_1.push_back(room_throne);
    level_1.push_back(room_chapel);
    level_1.push_back(room_library);
    level_1.push_back(room_ballroom);
    room_lobby->link("west",room_armory);
    room_lobby->link("east",room_throne);
    room_lobby->link("north",room_library);
    room_lobby->link("south",room_chapel);
    room_library->link("east",room_ballroom);
    room_ballroom->link("south",room_throne);
    room_throne->link("west",room_lobby);
    room_armory->set_monster(true);
    room_throne->set_princess(true);
}
void castle::play(){
    game_init();//just print some information
    string user_input;
    // stringstream ss;
    do{
        shared_ptr<room> cur_room = p->get_current_room();
        cur_room->show_information();
        if(cur_room->princess_in_room()){
           p->chat_with_princess();
           p->set_princess(true);
        }
        if(cur_room->monster_in_room()){
            game_lose();
            cin>>user_input;
            bool try_again = check_lose_input(user_input);
            if(try_again){
                p->set_princess(false);
                p->set_room(start);
                continue;
            }else{
                cout<<"game over"<<endl;
                break;
            }
         }
        string go;
        string commond;
        // ss>>go;
        // ss>>commond;
        if(p->has_princess()&&p->get_current_room()==start){
            win_game();
            cin>>user_input;
            bool try_again = check_lose_input(user_input);
            if(try_again){
                p->set_princess(false);
                p->set_room(start);
                continue;
            }else{
                cout<<"game over"<<endl;
                break;
            }
        }//win the game
        cin>>go>>commond;
        if(cur_room->check_commond(commond)){
            p->set_room(cur_room->get_room(commond));//upfate the status
        }else{
            cout<<"this room is not in the exits,try again"<<endl;//invalid input
            continue;
        }
    }while(user_input != "quit");
}