#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"tabla.h"
#define PI 3.14159265

using namespace std;

board::board(double difficulty, int width, int height){
	diff=difficulty;
	if(diff==1)	total_bombs=m*n-1;
	else total_bombs=sqrt(2)*difficulty*width*height/PI; // nzm ovo pi kako da bude konstanta? Stavis define
	marked_bombs=total_bombs;
	m=height;
	n=width;
	int x,y;
	srand(time(NULL));
	for(int i=0;i<total_bombs;)
	{
		x=rand()%m; //i jel treba negde da stavim da je m=height? 
		y=rand()%n; // n=width?dada na pocetku
		if(bomb[x][y]!=9)
		{
			i++;
			bomb[x][y]=9;
			if(bomb[x-1][y]!=9) bomb[x-1][y]++;
			if(bomb[x-1][y+1]!=9) bomb[x-1][y+1]++;
			if(bomb[x][y+1]!=9) bomb[x][y+1]++;
			if(bomb[x+1][y+1]!=9) bomb[x+1][y+1]++;
			if(bomb[x+1][y]!=9) bomb[x+1][y]++;
			if(bomb[x+1][y-1]!=9) bomb[x+1][y-1]++;
			if(bomb[x][y-1]!=9) bomb[x][y-1]++;
			if(bomb[x-1][y-1]!=9) bomb[x-1][y-1]++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			symbol[i][j]=char(254);
		}
	}
}
void board::print(){
	cout<<"Preostalih bombi:"<<marked_bombs<<endl;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0&&j==0) cout<<"  ";
			else if(i==0&&j>0) cout<<char((int)j+96)<<" ";
			else if(j==0&&i>0) cout<<i<<" ";
			else cout<<symbol[i-1][j-1]<<" ";
		}
		cout<<endl;
	}
	cout<<"Unesite jedno od sledecih slova da biste uradili odredjenu funkciju:"<<endl;
	cout<<"a) Otvori polje (int x,char y)"<<endl;
	cout<<"b) Markiraj polje (int x,char y)"<<endl;
	cout<<"c) Obrisi markaciju polja (int x,char y)"<<endl;
	/*cout<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<bomb[i][j]<<" "; 
		}
		cout<<endl;
	}*/
}
void board::outro(){
	char a=178;
	for(int i=0;i<20;i++){
		system("cls");
		cout<<endl<<endl<<"      "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<endl<<"       "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"      "<<a<<"     "<<a<<"            Projekat napravili:"<<endl<<"      "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<endl<<"      "<<a<<"     "<<a<<""<<endl<<"      "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<endl<<"      "<<a<<"  "<<a<<"  "<<a<<"                 Ognjen Petrov"<<endl<<"       "<<a<<"   "<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<"         "<<a<<""<<a<<""<<endl<<"         "<<a<<"          "<<a<<""<<a<<""<<endl<<"     "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<"     "<<a<<" "<<a<<"        Jovan Bjegovic"<<endl<<"    "<<a<<"         "<<a<<"   "<<a<<"  "<<a<<""<<endl<<"    "<<a<<"          "<<a<<" "<<a<<"  "<<a<<""<<endl<<"    "<<a<<" "<<a<<"     "<<a<<""<<a<<"  "<<a<<"  "<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<"  "<<a<<"   "<<a<<"           Filip Negojevic"<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<"   "<<a<<""<<a<<""<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<"                  Nevena Stojanovic"<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<""<<endl<<"  "<<a<<""<<a<<"  "<<a<<""<<a<<"   "<<a<<""<<endl<<"   "<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl;
		Sleep(100);
		system("cls");
		cout<<endl<<endl<<"      "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<endl<<"       "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"      "<<a<<"     "<<a<<"            Projekat napravili:"<<endl<<"      "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<endl<<"      "<<a<<"     "<<a<<""<<endl<<"      "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<endl<<"      "<<a<<"  "<<a<<"  "<<a<<"                 Ognjen Petrov"<<endl<<"       "<<a<<"   "<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<endl<<"     "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<"                Jovan Bjegovic"<<endl<<"    "<<a<<"         "<<a<<""<<endl<<"    "<<a<<"          "<<a<<""<<endl<<"    "<<a<<" "<<a<<"     "<<a<<""<<a<<"  "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<"  "<<a<<"        "<<a<<""<<a<<"     Filip Negojevic"<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<"   "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<""<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<"                  Nevena Stojanovic"<<endl<<"    "<<a<<" "<<a<<""<<a<<"   "<<a<<""<<endl<<"  "<<a<<""<<a<<"  "<<a<<""<<a<<"   "<<a<<""<<endl<<"   "<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl;
		Sleep(100);
	}
}
void board::open(int x, int y, bool p){
	if(bomb[x-1][int(y)-97]==9){
		diff=0;
	}
	symbol[x-1][int(y)-97]=bomb[x-1][int(y)-97]+48;
	if(bomb[x-1][int(y)-97]==0){
		int y1=int(y)-97;
		if(x<=n&&x>=0&&y1>=0&&y1<=m){
			if(bomb[x-1][y1-1]==0){
				open(x-1,char(y1-1+97),p);
			}
			if(bomb[x-1][y1+1]==0){
				open(x-1,char(y1+1+97),p);
			}
			if(bomb[x][y1]==0){
				open(x,char(y1+97),p);
			}
			if(bomb[x-2][y1]==0){
				open(x-2,char(y1+97),p);
			}
		}
		else{
			return;
		}
	}
}
double board::get_diff(){
	return diff;
}
board board::mark(int x, int y) {
	if(symbol[x-1][y]!=char(177)) symbol[x-1][y]=char(177);
	board b1(0,0,0);
	b1.diff=diff;
	b1.m=m;
	b1.n=n;
	b1.total_bombs=total_bombs;
	b1.marked_bombs=marked_bombs-1;
	b1.opened_fields=opened_fields;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			b1.bomb[i][j]=bomb[i][j];
			b1.symbol[i][j]=symbol[i][j];
		}
	}
	return b1;
}
board board::unmark(int x,int y){
	if(symbol[x-1][y]==char(177))symbol[x-1][y]=char(254);
	board b1(0,0,0);
	b1.diff=diff;
	b1.m=m;
	b1.n=n;
	b1.total_bombs=total_bombs;
	if(marked_bombs<total_bombs)b1.marked_bombs=marked_bombs+1;
	b1.opened_fields=opened_fields;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			b1.bomb[i][j]=bomb[i][j];
			b1.symbol[i][j]=symbol[i][j];
		}
	}
	return b1;
}
void board::death(){
	
	int n=5;
	char a=177;
	system("cls");
	cout<<endl<<endl<<"                  "<<a<<""<<a<<""<<endl<<"                  "<<a<<""<<a<<""<<endl<<"                 "<<a<<""<<endl<<"                 "<<a<<""<<endl<<"                "<<a<<""<<endl<<"             "<<a<<""<<a<<""<<a<<""<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<"                 "<<a<<""<<a<<""<<endl<<"                 "<<a<<""<<a<<""<<endl<<"                 "<<a<<""<<endl<<"                "<<a<<""<<endl<<"             "<<a<<""<<a<<""<<a<<""<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<endl<<"                 "<<a<<""<<a<<""<<endl<<"                 "<<a<<""<<a<<""<<endl<<"                "<<a<<""<<endl<<"             "<<a<<""<<a<<""<<a<<""<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<"                "<<a<<""<<a<<""<<endl<<"                "<<a<<""<<a<<""<<endl<<"             "<<a<<""<<a<<""<<a<<""<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<"               "<<a<<""<<a<<""<<endl<<"             "<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<"              "<<a<<""<<a<<""<<endl<<"             "<<a<<""<<a<<""<<a<<""<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<"             "<<a<<""<<a<<""<<endl<<"             "<<a<<""<<a<<""<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<"            "<<a<<""<<a<<""<<endl<<"            "<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(300);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<"            "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"           "<<a<<""<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(100);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                "<<a<<""<<endl<<"          "<<a<<""<<a<<""<<a<<"  "<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<""<<a<<"   "<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<""<<a<<"    "<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<"      "<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<"      "<<a<<""<<a<<""<<a<<""<<endl<<"      "<<a<<""<<a<<""<<endl<<"       "<<a<<""<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<"      "<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<a<<"  "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<"   "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"              "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"         "<<a<<""<<a<<""<<a<<"   "<<a<<""<<a<<""<<a<<""<<endl<<"          "<<a<<""<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl;
	Sleep(100);
	system("cls");
	cout<<endl<<"                    "<<a<<""<<endl<<"                     "<<a<<""<<endl<<"         "<<a<<"     "<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<""<<endl<<"        "<<a<<""<<a<<"        "<<a<<""<<a<<""<<endl<<"     "<<a<<"             "<<a<<""<<a<<"   "<<a<<""<<endl<<"     "<<a<<""<<a<<"                  "<<a<<""<<endl<<"     "<<a<<""<<a<<"  "<<a<<""<<a<<"      "<<a<<" "<<a<<""<<endl<<"      "<<a<<"  "<<a<<"        "<<a<<""<<a<<""<<endl<<endl<<"                     "<<a<<""<<a<<""<<endl<<endl<<endl<<"   "<<a<<""<<a<<""<<endl<<""<<a<<""<<a<<""<<a<<""<<"    "<<a<<"   "<<a<<""<<endl<<"        "<<a<<"          "<<a<<""<<a<<""<<a<<""<<endl<<"               "<<a<<""<<a<<"  "<<a<<""<<a<<""<<a<<""<<endl<<"               "<<a<<""<<a<<"    "<<a<<""<<a<<""<<endl<<"       "<<a<<""<<endl<<"      "<<a<<"           "<<a<<""<<endl<<"        "<<a<<""<<a<<"       "<<a<<""<<a<<""<<endl<<"        "<<a<<"         "<<a<<""<<endl<<endl;
	Sleep(100);
	system("cls");
	cout<<endl<<"               "<<a<<""<<endl<<"          "<<a<<""<<endl<<"   "<<a<<"                "<<a<<""<<endl<<"  "<<a<<"                  "<<a<<""<<endl<<endl<<endl<<"  "<<a<<""<<endl<<endl<<endl<<"    "<<a<<"                   "<<a<<""<<endl<<endl<<endl<<"                     "<<a<<""<<endl<<endl<<endl<<endl<<"                     "<<a<<""<<endl<<"      "<<a<<""<<a<<""<<endl<<" "<<a<<""<<a<<""<<endl<<"  "<<a<<"                   "<<a<<""<<a<<""<<endl<<"               "<<a<<"       "<<a<<""<<endl<<"                  "<<a<<""<<endl<<"        "<<a<<""<<a<<"       "<<a<<"   "<<a<<""<<endl<<"           "<<a<<""<<a<<""<<endl;
	Sleep(100);
	system("cls");
	cout<<endl<<" "<<a<<""<<endl<<"                       "<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<" "<<a<<""<<endl<<endl<<"                        "<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<" "<<a<<""<<endl<<"                       "<<a<<""<<endl<<"                     "<<a<<""<<endl<<"  "<<a<<"             "<<a<<""<<endl<<"      "<<a<<"            "<<a<<""<<endl<<"        "<<a<<""<<endl;
	Sleep(500);
	system("cls");
	for(int i=0;i<n;i++){
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"      "<<a<<""<<a<<"  "<<a<<"  "<<a<<" "<<a<<" "<<a<<""<<a<<""<<a<<""<<endl<<"     "<<a<<"   "<<a<<" "<<a<<" "<<a<<""<<a<<""<<a<<" "<<a<<""<<endl<<"     "<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<" "<<a<<" "<<a<<" "<<a<<""<<a<<""<<a<<""<<endl<<"     "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<endl<<"      "<<a<<""<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<a<<""<<a<<""<<endl<<endl<<"      "<<a<<"  "<<a<<" "<<a<<" "<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<""<<endl<<"     "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<"   "<<a<<" "<<a<<""<<endl<<"     "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<""<<endl<<"     "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<"   "<<a<<""<<a<<""<<endl<<"      "<<a<<"   "<<a<<"  "<<a<<""<<a<<""<<a<<" "<<a<<" "<<a<<""<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		Sleep(200);
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<"   "<<a<<""<<a<<""<<a<<""<<a<<"   "<<a<<"   "<<a<<"   "<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"  "<<a<<"      "<<a<<" "<<a<<"  "<<a<<"   "<<a<<" "<<a<<"   "<<endl<<"  "<<a<<"     "<<a<<"   "<<a<<" "<<a<<""<<a<<" "<<a<<""<<a<<" "<<a<<""<<endl<<"  "<<a<<"     "<<a<<"   "<<a<<" "<<a<<" "<<a<<" "<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"  "<<a<<" "<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<" "<<a<<"   "<<a<<" "<<a<<""<<endl<<"  "<<a<<"   "<<a<<" "<<a<<"   "<<a<<" "<<a<<"   "<<a<<" "<<a<<""<<endl<<"   "<<a<<""<<a<<""<<a<<"  "<<a<<"   "<<a<<" "<<a<<"   "<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<endl<<"   "<<a<<""<<a<<""<<a<<"  "<<a<<"   "<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"  "<<a<<"   "<<a<<" "<<a<<"   "<<a<<" "<<a<<"     "<<a<<"   "<<a<<""<<endl<<"  "<<a<<"   "<<a<<" "<<a<<"   "<<a<<" "<<a<<"     "<<a<<"   "<<a<<""<<endl<<"  "<<a<<"   "<<a<<" "<<a<<"   "<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<" "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<""<<endl<<"  "<<a<<"   "<<a<<" "<<a<<"   "<<a<<" "<<a<<"     "<<a<<" "<<a<<""<<endl<<"  "<<a<<"   "<<a<<"  "<<a<<" "<<a<<"  "<<a<<"     "<<a<<"  "<<a<<""<<endl<<"   "<<a<<""<<a<<""<<a<<"    "<<a<<"   "<<a<<""<<a<<""<<a<<""<<a<<""<<a<<" "<<a<<"   "<<a<<""<<endl;
		Sleep(200);
		system("cls");
	}
}
int board::get_opened_fieds(){
	return opened_fields;
}
int board::get_total_bombs(){
	return total_bombs;
}
