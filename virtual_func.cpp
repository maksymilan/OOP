#include <iostream>
using namespace std;
class Base{
public:
	int show(){
		return 1;
	}
};
class derived:public Base{
public:
	int show(){
        return Base::show()+10;
	}
};
int main(){
    Base* obj_1;
    derived* obj_2;
    cout<<obj_1->show()<<endl;
    cout<<obj_2->show()<<endl;
}