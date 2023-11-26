#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
int i,j,crefresh=0,pos,block=0,icount=0,bcount,arr,colx=0,hit=0,score=0,max=0;
char m;
char car[100];
COORD c;
int laneno[12]= {0};
void newpos(int,int*);
void printroad();
void printcar(int*,int*);
void obstacles();
void collision(int*,int*);
void main() {
	int in=0,c,x,y,pos;
	int* px;
	int* py;
	x=7;
	y=37;
	px=&x;
	py=&y;
	printcar(&x,&y);
	block=0;
	COORD z;
	z.X=15;
	z.Y=16;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),z);

	printf("\t\t\t\t\t\t\t\t****WELCOME TO CAR ARH!****\n\n\n\t\t\t\t\t\t\tINSTRUCTIONS:\n\n\t\t\t\t\t\t\t\t-->USE ARROW KEYS TO TURN LEFT OR RIGHT\n\n\t\t\t\t\t\t\t\t-->DODGE THE OBSTACLES BY STEERING THE CAR\n\n\t\t\t\t\t\t\t\t-->PRESS S TO EXPERIENCE CAR ARH THRILL!\n");
	scanf(" %c",&m);

	if(m=='s'||m=='S') {
game:
		hit=0;
		while(hit==0) {

			if(kbhit()==0) {
				newpos(in,&x); //changes position of vehicle
				system("cls"); //clears screen
				crefresh++; //used to detect colission of obstacle
				printroad();
				printcar(&x,&y);//prints car according to new location
				obstacles(); //prints and moves obstacles


			}
			if(kbhit() ) {

				in=getch();
				newpos(in,&x);
				system("cls");
				crefresh++;
				printroad();
				printcar(&x,&y);
				obstacles();
				in=0;
			}
		}
	}


}

void newpos(int in, int* px) {

	switch (in) {
		case 75: {
			if(*px!=1) { //max position at left
				*px=*px-3;
			}
			break;
		}
		case 77: { //max position at right
			if(*px!=19) {
				*px=*px+3;
			}
			break;
		}

	}


}

void printcar(int* px, int* py) {
	c.X=1;
	c.Y=1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c); //car is always printed relative to beginning position of cursor
	char car[1000] = {'\0'};
	for(j=0; j<*py; j++) {  //fixed vertical position of the car
		strcat(car,"\n");
	}
	for(pos=0; pos<5; pos++) {
		for(i=0; i<*px; i++) {
			strcat(car,"\t");
		}
		if(pos==0) {
			strcat(car,"  *  *\n");
		}
		if(pos==1) {
			strcat(car," **  **\n");
		}
		if(pos==2) {
			strcat(car,"********\n");
		}
		if(pos==3) {
			strcat(car," **  **\n");
		}
		if(pos==4) {
			strcat(car,"  *  *\n");
		}
	}
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(cons,2); //changes colour of car
	printf("%s",car);
	SetConsoleTextAttribute(cons,7); //reverts back to white
}

void printroad() {

	for(j=0; j<60; j++) {
		for(i=0; i<6; i++) {
			printf("\t\t\t|"); //widht of road lanes
		}
		printf("\n");
	}

}

void obstacles() {

	int lane,i;
	srand(time(0));
	int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0;
	if ( block==0||block>38 ) {
here:
		//	if(icount>10)
		//	icount=0;
		block++;
		if(block>38)//if true, car has avoided obstacle
			block=1;
		crefresh=1;
		icount=0;
		//for(i=0; i<5; i++) {
		while(icount<5) {

			c.X=1;
			c.Y=1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
			lane=(rand()%(7-1+1))+1;
			if(lane==1) {
				if (c1==0) {
					laneno[icount]=lane;
					icount++;
					printf("\n\t\b******");
					c1=1;
				}
			} else if(lane==2) {
				if (c2==0) {
					laneno[icount]=lane;
					icount++;
					c2=1;
					printf("\n\t\t\t\t\b******");
				}
			} else if(lane==3) {
				if(c3==0) {
					laneno[icount]=lane;
					icount++;
					c3=1;
					printf("\n\t\t\t\t\t\t\t\b******");
				}
			} else if(lane==4) {
				if(c4==0) {
					laneno[icount]=lane;
					icount++;
					c4=1;
					printf("\n\t\t\t\t\t\t\t\t\t\t\b******");
				}
			} else if(lane==5) {
				if (c5==0) {
					laneno[icount]=lane;
					icount++;
					c5=1;
					printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\b******");
				}
			} else if(lane==6) {
				if(c6==0) {
					laneno[icount]=lane;
					icount++;
					c6=1;
					printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\b******");
				}
			} else if(lane==7) {
				if(c7==0) {
					laneno[icount]=lane;
					icount++;
					c7=1;
					printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\b******");
				}

			} else {
				i--;
			}
		}
	} else {
		block+=3;
		for(arr=0; arr<12; arr++) {
			//	if(arr==11)
			//	goto(keep);
			if(laneno[arr]!=0) {
				c.X=1;
				c.Y=block+1;
				if(c.Y<44) {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
					if(laneno[arr]==1)
						printf("\t******");
					if(laneno[arr]==2)
						printf("\t\t\t\t******");
					if(laneno[arr]==3)
						printf("\t\t\t\t\t\t\t******");
					if(laneno[arr]==4)
						printf("\t\t\t\t\t\t\t\t\t\t******");
					if(laneno[arr]==5)
						printf("\t\t\t\t\t\t\t\t\t\t\t\t\t******");
					if(laneno[arr]==6)
						printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t******");
					if(laneno[arr]==7)
						printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t******");
				} else {
					for(arr=0; arr<5; arr++) {
						laneno[arr]=0;
					}
					goto here;
				}
			}
		}
	}
}



