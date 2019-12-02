#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"tabla.h"
#define PI 3.14159265
using namespace std;
int m,n;
double glhf;
int main(){
	start:	cout<<"Unesite dimenzije zeljene table:";
	srand(time(NULL));
	cin>>m>>n;
	cout<<"Izaberite tezinu:"<<endl;
	cout<<"1)Lako(->20%)"<<endl;
	cout<<"2)Srednje(->30%)"<<endl;
	cout<<"3)Tesko(->42%)"<<endl;
	cout<<"4)XD(->?%)"<<endl;
	cout<<"5)Feeling lucky"<<endl;
	cin>>glhf;
	switch(int(glhf)){
		case 1:glhf=0.44;break;
		case 2:glhf=0.66;break;
		case 3:glhf=0.9;break;
		case 4:glhf=1;break;
		case 5:glhf=rand()/RAND_MAX;break;
	}
	board b(glhf,m,n);
	cout<<b.get_total_bombs()<<endl;
	int x,y,ind=0;
	char y1,f;
	bool p=false;
	system("cls");
	while(1){
		b.print();
		cin>>f;
		if(f=='a'){
			cin>>x>>y1;
			y=int(y1)-97;
			b.open(x-1,y);
			/*while(b.get_diff()==0&&ind==0&&glhf!=1){
				board b1(0.6,m,n);
				b1.open(x,y,p);
			}*/
			if(b.get_diff()==0){
				b.death();
				cout<<"Ako zelite da probate opet, stisnite 1, a ako zelite da izadjete , stisnite 0"<<endl;
				cin>>f;
				if(f==char(48)) break;
				else if(f==char(49)) goto start;
			}
			if(b.win()){
				cout<<"Cestitam, pobedili ste!"<<endl;
				cout<<"Ako zelite da probate opet, stisnite 1, a ako zelite da izadjete , stisnite 0"<<endl;
				cin>>f;
				if(f==char(48)) break;
				else if(f==char(49)) goto start;
			}
			system("cls");
			ind=1;
		}
		else if(f=='b'){
			cin>>x>>y1;
			y=int(y1)-97;
			b=b.mark(x,y);
			system("cls");
		}
		else if(f=='c'){
			cin>>x>>y;
			y=int(y1)-97;
			b=b.unmark(x,y);
			system("cls");
		}
		else{
			cout<<"Molimo unesite jednu od ponudjenih opcija."<<endl;
			Sleep(2000);
			system("cls");
		}
	}
	b.outro();
}
