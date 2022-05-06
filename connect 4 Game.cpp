/*
By : SMSM -------connect 4 Game------- 2 players
*/ 
#include<iostream>
using namespace std ;

//the board
char arr[6][7]={{',',',',',',',',',',',',','}, {',',',',',',',',',',',',','},{',',',',',',',',',',',',','},{',',',',',',',',',',',',','},{',',',',',',',',',',',',','},{',',',',',',',',',',',',','}};
	//cheak the places of board
	int c1=6;
	int c2=6;
	int c3=6;
	int c4=6;
	int c5=6;
	int c6=6;
	int c7=6;
//function of place of x or o
int insert(int x)
{

	//cheak values
	if(x==1){
		if (c1>0) {
			c1--;
			return c1;
		}
		else
		return -1;
	}
	else if(x==2){
		if (c2>0){
			c2--;
			return c2;
		}
		else
		return -1;
	}
	else if(x==3){
		if (c3>0){
			c3--;
			return c3;
		}
		else
		return -1;
	} 
	else if(x==4){
		if (c4>0)
		{
			c4--;
			return c4;
		}
		else
		return -1;
	}
	else if(x==5){
		if (c5>0){
			c5--;
			return c5;
		}
		else
		return -1;	
	}
	else if(x==6){	
		if (c6>0){
			c6--;
			return c6;
		}
		else
		return -1;
	}
	else if(x==7){
		if (c7>0){
			c7--;
			return c7;
		}
		else
		return -1;	
	}
	else 
	return -1;
	
}

bool win_p1_row (int a)//1st case to win p1
{
	int count=0;
		for(int j=0; j<7;j++){
			if (arr[a][j]=='X')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
		}
		return false;
		
}

bool win_p1_dai1 (int a , int b)//2nd case to win p1
{
	int count=0;
	b--;
	if (a>=b)
	{
		a-=b;
		b=0;
		while(a<6)
		{
			if (arr[a][b]=='X')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b++;
		}
	}
	else
	{
		b-=a;
		a=0;
		while(b<7)
		{
			if (arr[a][b]=='X')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b++;
		}
	}
		return false;
		
}

bool win_p1_dai2 (int a , int b)//3rd case to win p1
{
	int count=0;
	b--;
	int c =a+b;
	if (c<7 && c>2)
	{
		b=c;
		a=0;
		while(a<6)
		{
			if (arr[a][b]=='X')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b--;
		}
	}
	else if (c>6 && c<9)
	{
		b=6;
		a=c-6;
		while(a<6)
		{
			if (arr[a][b]=='X')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b--;
		}
	}
		return false;
		
}

bool win_p1_col (int a)//4th case to win p1
{
	int count=0;
	a--;
		for(int j=0; j<6;j++)
		{
			if (arr[j][a]=='X')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
		}
		return false;
		
}

bool win_p2_row (int a)//1st case to win p2
{
	int count=0;
	
		for(int j=0; j<7;j++)
		{
			if (arr[a][j]=='O')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
		}
		return false;
		
}

bool win_p2_col (int a)//2nd case to win p2
{
	int count=0;
	a--;
		for(int j=0; j<6;j++)
		{
			if (arr[j][a]=='O')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
		}
		return false;
		
}

bool win_p2_dai1 (int a , int b)//3rd case to win p2
{
	int count=0;
	b--;
	if (a>=b)
	{
		a-=b;
		b=0;
		while(a<6)
		{
			if (arr[a][b]=='O')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b++;
		}
	}
	else
	{
		b-=a;
		a=0;
		while(b<7)
		{
			if (arr[a][b]=='O')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b++;
		}
	}
		return false;
		
}

bool win_p2_dai2 (int a , int b)//4th case to win p2
{
	int count=0;
	b--;
	int c =a+b;
	if (c<7 && c>2)
	{
		b=c;
		a=0;
		while(a<6)
		{
			if (arr[a][b]=='O')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b--;
		}
	}
	else if (c>6 && c<9)
	{
		b=6;
		a=c-6;
		while(a<6)
		{
			if (arr[a][b]=='O')
			{
				count++;
				if (count==4)
				return true ;
			}
			else
			count =0;
			a++;
			b--;
		}
	}
		return false;
		
}

void board(int a, int b, char x)//show the board
{
	
	//the move
	arr[a][b-1]=x;
	//head of board
	for(int f=1; f<8;f++)
	{
		cout<<f<<'|';
	}
	cout<<endl;
	//the board
	for(int i=0;i<6;i++)
	{
		for(int j =0;j<7;j++)
		{
			cout<<arr[i][j]<<'|';
		}
		cout<<endl;
	}
}

//the main
int main()
{
	cout<<"Welcome To Connect4 !!"<<endl;//welcome message
	//head of board
	for(int f=1; f<8;f++)
	{
		cout<<f<<'|';
	}
	cout<<endl;
	//the board
	for(int i=0;i<6;i++)
	{
		for(int j =0;j<7;j++)
		{
			cout<<arr[i][j]<<'|';
		}
		cout<<endl;
	}
	int c=0;//counter
	while(c<21)//loop to take the moves
	{
		int p1=0, p2=0;
		int col=0;
		int k=0;//row
		while(p1<1)
		{
			cout<<"Player1"<<endl<<"Enter colmn: ";//take move of p1
			col=0;
			cin>>col;
			 k=insert(col);//calclute the row
			while (k==-1)//if p1 write invalid place
			{
				cout<< "invalid place, Play Again: ";
				cin>>col;
				k=insert(col);
			}
			board(k,col,'X');//show the board
			
			p1++;
		}
		//cheak the p1 is winner or no
		if (win_p1_row (k)==true)
			{
				cout<<"Player 1 is Winner"<<endl<<"Congratulations!!";
				break;
			}
		
		if (win_p1_col (col)==true)
			{
				cout<<"Player 1 is Winner"<<endl<<"Congratulations!!";
				break;
			}
			
		if (win_p1_dai1 (k,col)==true)
		{
			cout<<"Player 1 is Winner"<<endl<<"Congratulations!!";
			break;
		}
		if (win_p1_dai2 (k,col)==true)
		{
			cout<<"Player 1 is Winner"<<endl<<"Congratulations!!";
			break;
		}
			
		while(p2<1)
		{
			cout<<"Player2"<<endl<<"Enter colmn: ";//take move of p2
			col=0;
			cin>>col;
			k=insert(col);//calclute the row
			while (k==-1)//if p1 write invalid place
			{
				cout<< "invalid place, Play Again: ";
				cin>>col;
				k=insert(col);
			}
			board(k,col,'O');//show the board
			p2++;
		}
		//cheak the p2 is winner or no
		if (win_p2_row (k)==true)
			{
				cout<<"Player 2 is Winner"<<endl<<"Congratulations!!";
				break;
			}
		if (win_p2_col (col)==true)
			{
				cout<<"Player 2 is Winner"<<endl<<"Congratulations!!";
				break;
			}
		if (win_p2_dai1 (k,col)==true)
		{
			cout<<"Player 2 is Winner"<<endl<<"Congratulations!!";
			break;
		}
		if (win_p2_dai2 (k,col)==true)
		{
			cout<<"Player 2 is Winner"<<endl<<"Congratulations!!";
			break;
		}
		c++;
		//if No Winner
		if (c==21)
		{
			cout<<"Sorry! No Winner";
		}
	}
}
