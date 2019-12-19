#include<bits/stdc++.h>
using namespace std;
class board{
	int bomb[100][100],m,n,total_bombs,marked_bombs,opened_fields=0;
	char symbol[100][100];
	double diff;
	public:
		board(double difficulty, int height, int width);//Nevena,Filip
		void open(int x,int y);//Ognjen,Filip
		bool win();//Ognjen,Filip
		void mark(int x,int y);//Filip
		void unmark(int x, int y);//Ognjen
		double get_diff();//Nevena
		int get_opened_fieds();//Nevena
		int get_total_bombs();//Nevena
		void print();//Jovan
		void victory();//Jovan
		void outro();//Jovan
		void death();//Jovan
		void reset_board();//Filip,Ognjen
};
