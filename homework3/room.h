#ifndef ROOM
#define ROOM
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
using namespace std;

class room{
    protected:
        string name_;//the name of this room
        string script_;// the backgroud script of this room
        map<string,shared_ptr<room>> exits_;//this map store the exits of this room ,every exit is stored as <string ,room> pair
        bool has_player;
        bool has_princess;
        bool has_monster;
    public:
        // player* current_player;//when player enter different room ,he will perform different action;
        inline void show_script(){
            cout<<script_<<endl;
        }
        void set_princess(bool in){
              has_princess = in;  
        }
        void set_monster(bool in){
            has_monster = in;
        }
        void set_name(string name){
            name_ = name;
        }
        void set_script(string script){
            script_ = script;
        }
        string get_name(){
            return name_;
        }
        bool princess_in_room(){
            return has_princess;
        }
        bool monster_in_room(){
            return has_monster;
        }
        room(){
            exits_ = {{"east",nullptr},{"west",nullptr},{"north",nullptr},{"south",nullptr}};
            has_princess = false;
            has_monster = false;
        }
        void show_information();//show the informationof the room
        void show_exits();//show the exits of this room
        map<string,shared_ptr<room>> get_exits(){
            return exits_;
        }
        void add_room(shared_ptr<room> r){
            exits_.insert(make_pair(r->get_name(),r));
        }//add the room to exits,this function is used when generate the castle rooms
        bool check_commond(string room_name);//check wheather the input name of the room is in the exits_ of current room;
        void link(const string& direction,shared_ptr<room> next_room);//link the next room to current room
        shared_ptr<room> get_room(string name);//get the room of the corresponding name
};
class lobby:public room{
    private:

    public:
        lobby():room(){
            set_name("lobby");
            set_script("This lobby has witnessed laughter and tears, glory and decay; today, it echoes only whispers of the past.");
        }
};

class throne_room:public room{
    private:
    public:
        throne_room():room(){
            set_name("throne room");
            set_script("Beneath this throne, the tides of history never cease, and the will of kings endures upon this land.");
        }
};

class armory:public room{
    private:
    public:
        armory():room(){
            set_name("armory");
            set_script("Every blade here thirsted for blood, and every shield bore the weight of fate’s strike.");
        } 
};

class chapel:public room{
    private:
    public:
        chapel(){
            set_name("chapel");
            set_script("In this serene sanctuary, the whispers of divinity still linger, awaiting the ears of the faithful.");
        }
};

class library:public room{
    private:
    public:
        library(){
            set_name("library");
            set_script("Endless wisdom lies within these scrolls, but only the brave soul may uncover their truths.");          
        }        
};

class ballroom:public room{
    private:
    public:
        ballroom(){
            set_name("ballroom");
            set_script("Once, the steps here danced to the music of glory and intrigue; now, only silence remains.");            
        }
};


#endif