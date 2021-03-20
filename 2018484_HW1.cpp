#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<iomanip>
#include<conio.h>

using namespace::std;
int score=0;
int p=0;
int obj[6]={0,20,40,60,80,100};
char letter[6];



struct agent
{
int points;
bool is_alive;
int energy;	
int movt=20;

void agentshape()
{
	cout<<setw(movt+2)<<"\\ /"<<endl;
	cout<<setw(movt+1)<<"O"<<endl;
	cout<<setw(movt+1)<<":"<<endl;
	cout<<setw(movt+2)<<"/ \\"<<endl;
	
}

void left()
{
movt-=10;
}

void right()
{
	movt+=10;
}	
}a1;



int random()
{
		return rand() % 26;
}

void randomobjective(){
	for (int i=0;i<6;i++)
	{
		int r = random();
		letter[i]= 'a' + r;
	}
}

void draw()
		{for (int i=0;i<6;i++)
	{
		cout<<letter[i]<<setw(20);
	}
	}
	
	
	
int main()
{
	int chance=0;
	char x;
	int r;
	char input;
	a1.energy =100;
	a1.points=0;
	a1.is_alive=1;
	srand(time(NULL));
	randomobjective();
	draw();
	cout<<endl<<"Pick any of the letters: ";
	cin>>x;
	cout<<endl;
	
for (int i=0;i<6;i++)
{
	if (x==letter[i])
	{
		p = i;
	}
}

	cout<<setw(a1.movt);
	a1.agentshape();
	input =getch();
	
	while (1)
	{
    system("CLS");
    
    if (a1.is_alive == 0 or chance >15){
    	cout<<"Sorry, game has ended";
		return 0;
	}
	draw();
	cout << x;
	cout << p;
	cout << endl << endl;
    a1.agentshape();
    
	if (a1.movt==obj[p]){
		system("CLS");
		
		if (chance <= 5){
			score+=2;
			chance=0;
		}
		
		if (chance > 5 and chance <= 10){
			score--;
			chance=0;
		}
		randomobjective();
		draw();
		cout << endl << endl;
		 a1.agentshape();
		 
			cout<<"Pick any of the letters: ";
	cin>>x;
	
	for (int i=0;i<6;i++)
{
	
	if (x==letter[i])
	{
		p = i;
	}
}

	}
	
	cout << "Your score is : " <<score<<endl;
	cout << "Your agent energy is : "<<a1.energy; 
	input =getch();	
	
	 if (input == 75)
	 {
	 	a1.left();
	 	chance++;
	 	a1.energy--;
	 	
	if (a1.energy==0)
	{
		a1.is_alive=0;
	}
	 }
	 
	 if (input == 77)
	{
		a1.right();
		chance++;
		a1.energy--;
		
	if (a1.energy==0)
	{
		a1.is_alive=0;
	}
	
	}
	}
	return 0; 
}
	
	
	
		   
