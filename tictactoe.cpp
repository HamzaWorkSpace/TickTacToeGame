#include<iostream>
#include <windows.h>
#include<conio.h>
using namespace std;

// the following functions is used to switch players by using a global variable int switchingplayers=1; 
void playerz(int arr[],int size);
void player1(int arr[],int size);
void player2(int arr[],int size);
//following functions are used to check diagonally that if player 1 won or player 2 won
int chk_left_diagonal(int arr[],int size);
int chk_right_diagonal(int arr[],int size);

//following functions are used to check horizontally that if player 1 won or player 2 won
int chk_horizontal(int arr[],int size);
int chk_horzontal_line_1(int arr[],int size);//---------->this function checks 1st horizontal line
int chk_horzontal_line_2(int arr[],int size);//---------->this function checks 2nd horizontal line
int chk_horzontal_line_3(int arr[],int size);//---------->this function checks 3rd horizontal line

//following functions are used to check vertically that if player 1 won or player 2 won
int chk_vertical(int arr[],int size);
int chk_vertical_line_1(int arr[],int size);//---------->this function checks 1st vertical line
int chk_vertical_line_2(int arr[],int size);//---------->this function checks 1st vertical line
int chk_vertical_line_3(int arr[],int size);//---------->this function checks 1st vertical line

int chk_filled_location(int arr[],int size,int location);

void display(int arr[],int size); // this function displays the values inside the array o the console window

void game(void); //this function starts the game

void player_choice_after_win();

int chk_draw_game(int arr[],int size);
void win(int arr[],int size,int location);//this function checks which player won after every input given  by player 1 or player 2 by calling all the 
//checking functions like 1)int chk_horizontal(int arr[],int size); 2)int chk_vertical(int arr[],int size) 3)int chk_left_diagonal(int arr[],int size);
//int chk_right_diagonal(int arr[],int size);

void choise(void);//view credits or play game

void credits(void);// this function shows the credits


//global variables
int switchingplayers=1;
char print_X_0_array[9]={'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
void main()
{
	// main function calls choise
	choise();
}

void choise(void)
{
	//choise function further calls credits and game based on player's choice if player press a then game function is called and if player  press b then 
	// players may view credits.....

	char ch;
again :
	system("cls");
	cout<<"\t  ***_______________________________________________________***\n";
	cout<<"\t  ******_________________________________________________******\n";
	cout<<"\t  **********                                         **********\n";
	cout<<"\t  **********      WELCOME TO TIC TAC TOE GAME        **********\n";
	cout<<"\t  **********                                         **********\n";
	cout<<"\t  ******_________________________________________________******\n";
	cout<<"\t  ***_______________________________________________________***\n\n\n";

	cout<<"\t\t\t\t   O | X | X\n";
	cout<<"\t\t\t\t  ___________\n";
	cout<<"\t\t\t\t   O | X | X\n";
	cout<<"\t\t\t\t  ___________\n";
	cout<<"\t\t\t\t   O | X | X\n";


	cout<<"\n\n\t       ENTER YOUR CHOISE : \n\n";

	cout<<"\t\t\t\t1)PRESS 'a' TO START A NEW GAME\n\n\t\t\t\t2)PRESS 'b' TO VIEW CREDITS\n\n\t\t\t\t3)PRESS 'e' TO EXIT GAME";
	
	ch=getch();// player inputs a character and the character is got by using 'getch()' function and it is then saved in a variable 'ch' of data type char

	if(ch=='a')
	{
		game();//if player press 'a' then game function is called
	}
	if(ch=='b')
	{
		credits(); //if player press b then credits function is called
	}
	if(ch=='e')
	{
	exit(0);
	}
	if(ch!='a'&&ch!='b'&&ch!='e') // if player presses any other key other than 'a' or 'b' then inform him that it is an invalid input
	{
		cout<<"\n\n\t\t\t            invalid input";
		getch();
		goto again; // using goto because if player inputs invalid character then go to label 'again:'that is on top on top and start executing from there
	}
}
void credits()
{
	system("cls");
	int x=30,y=5;

	COORD coord;
	//for(int i=0;i<=3;i++)
	//{
		//system("cls");
		
		coord.X = x;
		coord.Y = y;
		coord.Y--;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	cout<<"   CREDITS \n\t\t\t        ~~~~~~~~~\n\n\t\t  ASSIGNMENT BY-----------Sir AbuBakar Siddique\n\n\t      LOGIC & CODING BY-----------Ameer Hamza Munir\n\n\t\t CODING PARTNER-----------Adeel Sajjad\n\n\t\t    ROLL NUMBER-----------111820020 & 111820012\n\n\t\t	SECTION-----------W3\n\n\t\t    INSTITUTION-----------UMT\n\n\t\t        ADDRESS-----------Lahore\n\n\t\tALL RIGHTS RESERVED(LOLX)........";
		//Sleep(6);
			\
			getch();

	//}
}

void game(void)
{ 
	//if player press 'a' then this function is called this function starts the game
	//here only array is declered and initialized
	int size=9,location=0;
	int arr[9]={0,0,0,0,0,0,0,0,0};
//we know pass the array and its size to the display function so that we can print the array
	display(arr,size);
}

void display(int arr[],int size)
{
	// 3*3 array is displayed on console

	//coping O or X to character array if integer array contains 1 or 2 
	for(int i=0;i<9;i++)
	{
		if(arr[i]==1)
		{
			print_X_0_array[i]='O';
		}
		if(arr[i]==2)
		{
			print_X_0_array[i]='X';
		}
		if(arr[i]!=1 && arr[i]!=2)
		{
			print_X_0_array[i]=' ';
		}
		
	}


	
	
	system("cls");
	char c=179,d=197,e=196,f=194;
	cout<<"\n\n\n";
	cout<<"     PLAYER 1 : 'O'.....PLAYER 2 : 'X'\n";
	cout<<"     _________________________________\n\n\n";
	cout<<"     Location Information Box Below         Input Box Of Game Below\n";
	cout<<"     ______________________________\t    _______________________\n\n\n\n";
	cout<<"\t\t   "<<"0"<<" | "<<"1"<<" | "<<"2"<<"\t\t\t "<<print_X_0_array[0]<<"  "<<c<<"  "<<print_X_0_array[1]<<"  "<<c<<"  "<<print_X_0_array[2]<<"\n";
	cout<<"\t\t  ___________\t\t\t"<<e<<e<<e<<e<<d<<e<<e<<e<<e<<e<<d<<e<<e<<e<<e<<"\n";
	cout<<"\t\t   "<<"3"<<" | "<<"4"<<" | "<<"5"<<"\t\t\t "<<print_X_0_array[3]<<"  "<<c<<"  "<<print_X_0_array[4]<<"  "<<c<<"  "<<print_X_0_array[5]<<"\n";
	cout<<"\t\t  ___________\t\t\t"<<e<<e<<e<<e<<d<<e<<e<<e<<e<<e<<d<<e<<e<<e<<e<<"\n";
	cout<<"\t\t   "<<"6"<<" | "<<"7"<<" | "<<"8"<<"\t\t\t "<<print_X_0_array[6]<<"  "<<c<<"  "<<print_X_0_array[7]<<"  "<<c<<"  "<<print_X_0_array[8]<<"\n";
	
	
	// after displaying array on console array and its size is passed to players function 
	playerz(arr,size);
}

void playerz(int arr[],int size)
{
//on top of  the program where functions prototypes are decleared there a global variable named 'switchingplayers==1' is also decleared so that its
//value may retain(do not change)...switchingplayers is made equal to 1 because i am giving 1st chance to player 1....that is if switchingplayers value
//is 1 so  its player 1 chance if switchingplayers value is 2 then it is player 2 chance....for example if i am calling player 1.....in player 1 function
//before the  player 1  function defination ends i make 'switchingplayers=2' in ....similarly i make 'switchingplayers=1' in player 2 function.....
//so that when player 1 and player 2 function ends switchingplayers value is 2 or 1 and when it returns to this(PLAYERZ) function it calls player 2 
//function or player 1 function one by one.....


	if(switchingplayers==1)
	{
		//if switchingplayers value is 1 call player 1 function by passing array and its size

		cout<<"\n\n\n\t\t\t\tPLAYER 1";
		player1(arr,size);
	}
	if(switchingplayers==2)
	{
		//if switchingplayers value is 2 call player 2 function by passing array and its size
		cout<<"\n\n\n\t\t\t\tPLAYER 2 ";
		player2(arr,size);
	}
	
}

void player1(int arr[],int size)
{
	

	int location,chki;
//in this function we ask the desired location by player that where he wants to mark a TIC SIGN(where there is a tic sign there is 1)...
	cout<<"\n\n\n\t\tENTER LOCATION   0,1,2,3,4,5,6,7,8	:";
	cin>>location;

	// the desired location is used as an index to change the value of desired location to 1 because 1 means player 1

		chki=chk_filled_location(arr, size, location);
		if(chki==1)
		{
		arr[location]=1;
		}
	switchingplayers=2;// changing switchingplayers value to 2 because when player 1 function ends it will return to playerz funtion with 
					   // switchingplayers value equal to 2 so to give player 2 next chance

	win(arr,size,location); // win function is called to check if after this input player 1 won or not
	
	display(arr,size);// it displays the changed values of array on consoles
}

void player2(int arr[],int size)
{

	int location,chki;
	
	cout<<"\n\n\n\t\tENTER LOCATION  0,1,2,3,4,5,6,7,8	:";
	cin>>location;


	chki=chk_filled_location(arr,size, location);

	if(chki==1)
	{
		arr[location]=2;

	}
	switchingplayers=1;
	// changing switchingplayers value to 1 because when player 2 function ends it will return to playerz funtion with 
	// switchingplayers value equal to 1 so to give player 1 next chance

	win(arr,size,location);
	// win function is called to check if after this input player 2 won or not
	
	display(arr,size);
	// it displays the changed values of array on consoles
	
}

void win(int arr[],int size,int location)
{
	int winp=0;
	char chs;
	if(location==0 || location==4 || location==8)//checking diagonally right
	{
		winp=chk_right_diagonal(arr,size);

		if(winp==1)
		{
				system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 1 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";

			player_choice_after_win();
		
		}

		if(winp==2)
		{
			system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 2 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";
			player_choice_after_win();
		}

	}
	if(location==2 || location==4 || location==6)//checking diagonally left
	{
		winp=chk_left_diagonal(arr,size);
		

		if(winp==1)
		{
			system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 1 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";

			player_choice_after_win();
		}

		if(winp==2)
		{
			system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 2 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";
			player_choice_after_win();

		}


	}

if(location==0 || location==1 || location==2 || location==3 || location==4 || location==5 || location==6 || location==7 || location==8 )//checking horizontally
	{
		winp=chk_horizontal(arr,size);
		

		if(winp==1)
		{
			system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 1 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";

			player_choice_after_win();
		}

		if(winp==2)
		{
			system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 2 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";

				player_choice_after_win();
		}
	}

//checking 
	if(location==0 || location==1 || location==2 || location==3 || location==4 || location==5 || location==6 || location==7 || location==8 )
	{
		winp=chk_vertical(arr,size);
	

		if(winp==1)
		{
			system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 1 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";
			player_choice_after_win();


		}

		if(winp==2)
		{
						system("cls");
			cout<<"\n\n\n\t\t ************************************************";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t *	       PLAYER 2 WON THE GAME		*";
			cout<<"\n\t\t *                                              *";
			cout<<"\n\t\t ************************************************";

			player_choice_after_win();
		}
	}

	winp=chk_draw_game(arr,size);
	if(winp==1)
	{
		system("cls");
		cout<<"\n\n\n\t\t ************************************************";
		cout<<"\n\t\t *                                              *";
		cout<<"\n\t\t *	       GAME IS A DRAW		*";
		cout<<"\n\t\t *                                              *";
		cout<<"\n\t\t ************************************************";
		player_choice_after_win();
	}
}


int chk_draw_game(int arr[],int size)
{
	if(((arr[0]==1)||(arr[0]==2)) && ((arr[1]==1)||(arr[1]==2)) && ((arr[2]==1)||(arr[2]==2)) && ((arr[3]==1)||(arr[3]==2)) && ((arr[4]==1)||(arr[4]==2)) && ((arr[5]==1)||(arr[5]==2)) && ((arr[6]==1)||(arr[6]==2)) && ((arr[7]==1)||(arr[7]==2)) && ((arr[8]==1)||(arr[8]==2)))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


int chk_right_diagonal(int arr[],int size)
{
	if(arr[0]==1 && arr[4]==1 && arr[8]==1)
	{
	return 1;
	}
	if(arr[0]==2 && arr[4]==2 && arr[8]==2)
	{
	return 2;
	}
	return 0;
}

int chk_left_diagonal(int arr[],int size)
{
	if(arr[2]==1 && arr[4]==1 && arr[6]==1)
	{
	return 1;
	}

	if(arr[2]==2 && arr[4]==2 && arr[6]==2)
	{
	return 2;
	}
	return 0;
}

int chk_horizontal(int arr[],int size)
{
	int horizontal=0;

	if((arr[0]==1 && arr[1]==1 && arr[2]==1) || (arr[0]==2 && arr[1]==2 && arr[2]==2) )
	{
			horizontal= chk_horzontal_line_1( arr,size);

			return horizontal;
	}

	if((arr[3]==1 && arr[4]==1 && arr[5]==1) || (arr[3]==2 && arr[4]==2 && arr[5]==2) )
	{
			horizontal= chk_horzontal_line_2( arr,size);

			return horizontal;
	}

	if((arr[6]==1 && arr[7]==1 && arr[8]==1) || (arr[6]==2 && arr[7]==2 && arr[8]==2) )
	{
			horizontal= chk_horzontal_line_3( arr,size);

			return horizontal;
	}

	return horizontal;
}

int chk_horzontal_line_1( int arr[],int size)
{
	if( arr[0]==1 && arr[1]==1 && arr[2]==1 )
	{
		return 1;
	}
	if( arr[0]==2 && arr[1]==2 && arr[2]==2 )
	{
		return 2;
	}
	return 0;
}
int chk_horzontal_line_2( int arr[],int size)
{
	if( arr[3]==1 && arr[4]==1 && arr[5]==1 )
	{
		return 1;
	}
	if( arr[3]==2 && arr[4]==2 && arr[5]==2 )
	{
		return 2;
	}
	return 0;
}
int chk_horzontal_line_3( int arr[],int size)
{
	if( arr[6]==1 && arr[7]==1 && arr[8]==1 )
	{
		return 1;
	}
	if( arr[6]==2 && arr[7]==2 && arr[8]==2 )
	{
		return 2;
	}
	return 0;
}


int chk_vertical(int arr[],int size)
{
	int vertical=0;

	if((arr[0]==1 && arr[3]==1 && arr[6]==1) || (arr[0]==2 && arr[3]==2 && arr[6]==2) )
	{
			vertical= chk_vertical_line_1( arr,size);

			return vertical;
	}

	if((arr[1]==1 && arr[4]==1 && arr[7]==1) || (arr[1]==2 && arr[4]==2 && arr[7]==2) )
	{
			vertical= chk_vertical_line_2( arr,size);

			return vertical;
	}

	if((arr[2]==1 && arr[5]==1 && arr[8]==1) || (arr[2]==2 && arr[5]==2 && arr[8]==2) )
	{
			vertical= chk_vertical_line_3( arr,size);

			return vertical;
	}

	return vertical;
}

int chk_vertical_line_1( int arr[],int size)
{
	if( arr[0]==1 && arr[3]==1 && arr[6]==1 )
	{
		return 1;
	}
	if( arr[0]==2 && arr[3]==2 && arr[6]==2 )
	{
		return 2;
	}
	return 0;
}
int chk_vertical_line_2( int arr[],int size)
{
	if( arr[1]==1 && arr[4]==1 && arr[7]==1 )
	{
		return 1;
	}
	if( arr[1]==2 && arr[4]==2 && arr[7]==2 )
	{
		return 2;
	}
	return 0;
}
int chk_vertical_line_3( int arr[],int size)
{
	if( arr[2]==1 && arr[5]==1 && arr[8]==1 )
	{
		return 1;
	}
	if( arr[2]==2 && arr[5]==2 && arr[8]==2 )
	{
		return 2;
	}
	return 0;
}

int chk_filled_location(int arr[],int size,
	int location)
{

		if((arr[location]!=1) && arr[location]!=2)
		{
			return 1;
		}
		else 
		{
			cout<<"\ninvalid input please enter again : ";
			getch();
			
			if(switchingplayers==1 || switchingplayers==2)
			{
				display(arr,size);
			}
			return 0;
		}
}

void player_choice_after_win()
{
	char chs;
			cout<<"\n\n\n\n\t\tPRESS 'a' TO GO BACK TO MAIN MENU\n\n\t\tPRESS 'b' TO PLAY GAME AGAIN\n\n\t\tPRESS 'e' TO EXIT GAME";

			chs=getch();
			if(chs=='a')
			{
					choise();
			}
			if(chs=='b')
			{
					game();
			}
			if(chs=='e')
			{
				getch();
				exit(0);
			}
			else
			{
				exit(0);
			}
}
