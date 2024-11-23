all:pd_list pd_list pd_show pd_remove

pd_list: pd_list.o pd_diary.o
	g++ pd_list.o pd_diary.o -o pd_list

pd_add: pd_add.o pd_diary.o
	g++ pd_add.o pd_diary.o -o pd_add

pd_show: pd_show.o pd_diary.o
	g++ pd_show.o pd_diary.o -o pd_show

pd_remove: pd_remove.o pd_diary.o
	g++ pd_remove.o pd_diary.o -o pd_remove
# generate .o file

pd_list.o: pd_list.cpp
	g++ -c pd_list.cpp -o pd_list.o

pd_add.o: pd_add.cpp
	g++ -c pd_add.cpp -o pd_add.o

pd_show.o: pd_show.cpp
	g++ -c pd_show.cpp -o pd_show.o

pd_remove.o: pd_remove.cpp
	g++ -c pd_remove.cpp -o pd_remove.o
	
pd_diary.o: pd_diary.cpp
	g++ -c pd_diary.cpp -o pd_diary.o
