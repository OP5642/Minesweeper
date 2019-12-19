#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include"tabla.h"
#define PI 3.14159265
using namespace std;
int m,n;
double glhf;
int main(){
	start:	SetConsoleTitle("Minesweeper");	
	system("Color 8F");
	cout<<"Unesite dimenzije zeljene table(prvo sirinu, pa onda visinu):";
	cin>>m>>n;
	cout<<"Izaberite tezinu:"<<endl;
	cout<<"1)Lako(->20%)"<<endl;
	cout<<"2)Srednje(->30%)"<<endl;
	cout<<"3)Tesko(->42%)"<<endl;
	cout<<"4)XD(->?%)"<<endl;
	cout<<"5)Feeling lucky"<<endl;
	srand(time(NULL));
	cin>>glhf;
	switch(int(glhf)){
		case 1:glhf=0.37;break;
		case 2:glhf=0.47;break;
		case 3:glhf=0.6;break;
		case 4:glhf=1;break;
		case 5:glhf=double(rand()%10+0.5)/10;break;
	}
	board b(glhf,m,n);
	int x,y,ind=0,da=0,score;
	clock_t start;
	char name[20];
   	double duration;
	char y1,f;
	bool p=false;
	fstream file("HighScores.txt");
	system("cls");
	while(1){
		b.print();
		cin>>f;
		if(f=='a'){
			cin>>x>>y1;
			if(da==0)                   
			{
			start=clock();
			da++;                       
			}
			y=int(y1)-97;
			b.open(x-1,y);
			while(b.get_diff()==0&&ind==0&&glhf!=1){
				board b1(glhf,m,n);
				b1.open(x-1,y);
				b=b1;
			}
			if(b.get_diff()==0){
				b.death();
				b.reset_board();
				greska: cout<<"Ako zelite da probate opet, stisnite 1, a ako zelite da izadjete, stisnite 0"<<endl;
				cin>>f;
				if(f==char(48)){
					system("cls");
					break;
				}
				else if(f==char(49)){
					system("cls");
					goto start;
				}
				else goto greska;
			}
			if(b.win()){
				system("cls");
				duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
				score=1000*pow(b.get_total_bombs(),3)/(duration+1);
				b.victory();
             	cout << "Proteklo vreme je "<< duration << " sekundi" << endl;
             	cout<<"Vas score je:"<<score<<"!"<<endl;
             	char s[30],p[20];
             	int h=0;
             	file.getline(s,30);
             	int j;
             	bool num=false;
             	j=0;
             	while(s[j]!=' '&&!num){
             		p[j]=s[j];
					j++;
					p[j]=' ';
					if(s[j]==' ')num=true;		
				}
				j++;
				while(s[j]!=' '&&num){
					h=10*h+int(s[j])-48;
					j++;
					if(s[j]==' ')num=false;
				}
				cout<<"Najbolji score je postavio/la "<<p<<"sa "<<h<<" poena."<<endl;
				if(score>h){
					file.close();
					file.open("HighScores.txt", ios::out| ios::trunc);
					j=0;
					cout<<"Cestitamo, zabelezili ste najbolji score u ovoj igri."<<endl;
					cout<<"Molimo Vas unesite ime radi evidencije rezultata(najvise 20 karaktera, bez razmaka):"<<endl;
					cin>>name;
					char hs[10],hs1[10],newhs[30];
					int dig=0;
					j=0;
					while(score>0){
						hs1[j]=score%10+48;
						score=score/10;
						j++;
					}
					j--;
					dig=j;
					for(int i=0;i<=dig;i++){
						hs[i]=hs1[j];
						hs[i+1]=' ';
						j--;
					}
					file<<name<<" "<<hs<<endl;
				}
				else{
				}
				greska1: cout<<"Ako zelite da probate opet, stisnite 1, a ako zelite da izadjete, stisnite 0"<<endl;
				cin>>f;
				if(f==char(48)){
					system("cls");
					break;
				}
				else if(f==char(49)){
					system("cls");
					b.reset_board();
					goto start;
				}
				else goto greska1;
			}
			system("cls");
			ind=1;
		}
		else if(f=='b'){
			cin>>x>>y1;
			y=int(y1)-97;
			b.mark(x,y);
			system("cls");
		}
		else if(f=='c'){
			cin>>x>>y1;
			y=int(y1)-97;
			b.unmark(x,y);
			system("cls");
		}
		else{
			cout<<"Molimo Vas unesite jednu od ponudjenih opcija."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
	b.outro();
}
