#include "room.h"
void room::show_exits(){
    for(auto& pair:exits_){
        int count = 0;
        cout<<"exits of this room are:";
        if(pair.second != nullptr){
            cout<<pair.first<<" ";
        }
    }
}
void room::show_information(){
    cout<<"now you are in the "<<name_<<endl;
    cout<<script_<<endl;
    show_exits();
}
bool room::check_commond(string room_name){
    if(exits_.count(room_name)){
        return true;
    }
    return false;
}
void room::link(const string& direction,shared_ptr<room> next_room){
    if(exits_.count(direction)){
        exits_[direction] = next_room;
        return;
    }
}
shared_ptr<room> room::get_room(string name){
    return exits_[name];
}