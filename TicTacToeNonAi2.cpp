#include <stdio.h>

void BOARD(void);
void play_game(void);
void computer_move(void);
void player_move(void);
int user_first(void);
int play_again(void);
int Poss_Win(char);
int middle_open(void);
int find_corner(void);
int find_side(void);
int symbol_won(char);
int square_valid(int);

char board[3][3];
char computer, user;

int main(void)
{
	int row,col;
	while(1)
    	{

		for (row = 0; row < 3; row++)

		    for (col = 0; col < 3; col++)

			board[row][col] = ' ';

	     	if (user_first())
			{
			  	computer = 'O';
				user = 'X';
			}
	      	else
			{
		  		computer = 'X';
		  		user = 'O';
			}
	      		play_game();
	      		if (!play_again())
				break;
   	}
  	return 0;
}

void play_game(void)
{
  	int turn = 1 ;
  	if( turn==1 && computer=='X' )
    {
        board[1][1]='X';
        printf("\nComputer Choosing 5th square!\n");
        BOARD();
        turn=2;

        player_move();
        BOARD();
        turn=3;

        if(turn==3 && computer=='X')
        {
            if(board[0][0]!='O')
            {
                board[0][0]='X';
            }
            else
            {
                board[0][2]='X';
            }
            BOARD();
            turn=4;
        }
    }

    if( turn==1 && user=='X' )
    {
        player_move();
        BOARD();
        if(board[1][1]!='X')
        {
            printf("\nComputer Choosing 5th square!\n");
            board[1][1]='O';
        }
        else
        {
            printf("\nComputer Choosing 1st square!\n");
            board[0][0]='O';
        }
        BOARD();
        turn=3;
    }

  	for (turn; turn <= 9; turn++)
    {
		if (turn % 2 == 1)
		{
	  		if (computer == 'X')
	    			computer_move();
	  		else
	    			player_move();
		}
      	else
		{
	  		if (computer == 'O')
				computer_move();
	  		else
				player_move();

		}
      	BOARD();
      	if (symbol_won(computer))
		{
			printf("\nComputer Wins...\n\n");
				return;
      	}
      	else if (symbol_won(user))
		{
			printf("\nCongratulations,You win!\n\n");
				return;
      		}
    	}
  	printf("\nDRAW!.\n\n");
  	return;
}

void BOARD(void)
{
   	int row;
	printf("\n\t\t\t\tTIC-TAC-TOE\n");
	printf("\n\t\t\t\t-----------\n");
	printf("\n\n");
	for(row=0;row<3;row++)
	{
		printf("\t\t\t_________________________\n");
		printf("\n\t\t\t|   %c \t|   %c \t|   %c \t|\n",board[row][0],board[row][1],board[row][2]);
		printf("\t\t\t_________________________\n");
	}
	if(row !=2)
	{
		printf("\n\n\t\t========================================\n");
	}
	printf("\n");
	return ;
}
int first ;

int user_first(void)
{
	int response;
  	printf("\n========== NON AI TIC TAC TOE ==========");
  	printf("\n1.) Play First (Symbol = X)");
  	printf("\n2.) Play Second (Symbol = O)");
  	printf("\nEnter your choice = ");
  	scanf("%d",&response);

  	switch(response)
  	{
  	    case 1:first=1;
  	    	return 1;
  	    break;

  	    case 2: return 0;
  	    	break;

  	    default:
			printf("Invalid Choice");
			break ;
  	}

}

int middle_open(void)
{
  	if (board[1][1] == ' ')
    	return 5;
  	else
    	return 0;
}

int find_corner(void)
{
  	if (board[0][0] == ' ')
    	return 1;
  	if (board[0][2] == ' ')
    	return 3;
  	if (board[2][0] == ' ')
    	return 7;
  	if (board[2][2] == ' ')
    	return 9;
  	return 0;
}

int find_side(void)
{
  	if (board[0][1] == ' ')
    	return 2;
  	if (board[1][0] == ' ')
    	return 4;
  	if (board[1][2] == ' ')
    	return 6;
  	if (board[2][1] == ' ')
    	return 8;
  	return 0;
}

int Poss_Win(char symbol)
{
  	int square, row, col;
  	int result=0 ;
	for (square = 1; square <= 9; square++)
    {
      		row = (square - 1) / 3;
      		col = (square - 1) % 3;
      	if (board[row][col] == ' ')
		{
	  		board[row][col] = symbol;
			if (symbol_won(symbol))
	    			result = square;
	  		board[row][col] = ' ';
		}
    }
	return result;
}

int symbol_won(char symbol)
{
  	int row, col;
	for (row = 0; row < 3; row++)
    {
      	if ((board[row][0] == symbol) && (board[row][1] == symbol) && (board[row][2] == symbol))
			return 1;
    }
  	for (col = 0; col < 3; col++)
    {
      	if ((board[0][col] == symbol) && (board[1][col] == symbol) && (board[2][col] == symbol))
			return 1;
    }
  	if ((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol))
		return 1;

  	if ((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] == symbol))
    	return 1;

  	return 0;
}

void computer_move(void)
{
  	int square,i,j;
  	int flag=0;
  	int row, col;
  	square = Poss_Win(computer);

    if (!square)
    	square = Poss_Win(user);

    if(!square)
		for(i=0;i<3;i++)
		{
			if (flag==1)
				break;
			for(j=0;i<3;j++)
			{
				if(board[i][j]==' ')
					{
						square=((i*3)+j)+1;
						flag=1;
						break;

					}
			}
		}
    flag=0;


  	printf("\nComputer Choosing %dth square!\n", square);
	row = (square - 1) / 3 ;
  	col = (square - 1) % 3 ;
  	board[row][col] = computer ;
	return ;
	
}

void player_move(void)
{
  	int square;
  	int row, col;
  	do
    {
      		printf("\nEnter a square: ");
      		scanf("%d", &square);

    } while (!square_valid(square));
  	row = (square - 1) / 3;
  	col = (square - 1) % 3;
  	board[row][col] = user;
  	return;
}

int square_valid(int square)
{
  	int row, col;
	row = (square - 1) / 3;
  	col = (square - 1) % 3;
	if ((square >= 1) && (square <= 9))
	{
      		if (board[row][col] == ' ')
				return 1;
    	}
	return 0;
}
int play_again(void)
{
  	char response;
  	printf("Do you want to play again? (y/n) ");
  	do
    {
      		response = getchar();

	} while ((response != 'y') && (response != 'Y') && (response != 'n') && (response != 'N'));

  	if ((response == 'y') || (response == 'Y'))
    	return 1;
  	else
    	return 0;
}