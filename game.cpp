#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"boardClass.h"

using namespace std;

int main()
{
    boardClass play;
    play.play_game();
    return 0;  
}

void boardClass::table_show()
{
    system("CLS");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(j==2)
            {
                cout<<board[i][j];
            }
            else
            {
                cout<<board[i][j]<<" | ";   
            }
        }
        cout<<endl;
        if(i!=2)
        {
            cout<<"---------";
            cout<<endl;
        }
    }
}

void boardClass::player_input()
{
    system("CLS");
    table_show();
    cout<<"Player "<<player_no<<".\n";
    cout<<"Your turn now.\n\n";
    cout<<"Enter the Row: ";
    cin>>r;
    cout<<"Enter the Column: ";
    cin>>c;
    check_player_input();
}

void boardClass::menu()
{   
    system("CLS");
    cout<<"Welcome to Kata Kuti Game\n";
    cout<<"1. START\n";
    cout<<"2. EXIT\n";
    cout<<"Choose your option : ";
    cin>>start_stop;
    switch(start_stop)
    {
        case 1: system("CLS");
                start_game();
                break;

        case 2: exit(0);
                break;

        default: system("CLS");
                 boardClass::menu();
    }
}

void boardClass::start_game()
{   
    player_choose :
    system("CLS");
    cout<<"Choose your Player Number \n";
    cout<<"Player 1 is X  \nPlayer 2 is O\n";
    cout<<"Enter Your Player Number (1 or 2) :";
    cin>>player_no;    
    if(player_no>2 || player_no<1)
    {   
        system("CLS");
        cout<<"Wrong Player Number Input!!";
        cin.ignore();
        cout<<"\nPress Enter to choose your Player Number again ";
        cin.get();
        goto player_choose;
    }
    system("CLS");
    table_show();
    cout<<"Place your X or O mark on the board";
    cout<<"\nProvide Row and Column number to place it in that position\n"; 
    cin.ignore();
    cout<<"\nPress Enter to continue";
    cin.get();
}

void boardClass::check_player_input()
{
    if (r <= 3 && c <= 3 && board[r-1][c-1] == gap)
    {
        player_input_valid = 1;
    }
    else
    {
        player_input_valid = 0;
    }  
}

void boardClass::check_win_lose()
{
    if( (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] == mark_1) || (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] == mark_2)
        || (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] == mark_1) || (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] == mark_2)
        || (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] == mark_1) || (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] == mark_2) 
        || (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == mark_1) || (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == mark_2) 
        || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == mark_1) || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == mark_2)
        || (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] == mark_1) || (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] == mark_2)
        || (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] == mark_1) || (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] == mark_2)
        || (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] == mark_1) || (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] == mark_2) )
    {
        check_win_lose_value = 1;
    }
    else
    {
        check_win_lose_value = 0;
    }
}

void boardClass::play_game()
{   
    main_menu :
    menu();
        for (int i = 0; i < 9; i++)
        {
            try_again :
            player_input();
            if(player_input_valid == 1)
            {
                if(player_no==1)
                {
                    board[r-1][c-1] = mark_1;
                    sign = 1;
                }   
                else
                {
                    board[r-1][c-1] = mark_2;
                    sign = -1;
                }
                player_number_change();    
            }
            else
            {   
                system("CLS");
                cout<<"Wrong Input !! Please Try Again.\n";
                cin.ignore();
                cout<<"Press Enter to Continue ";
                cin.get();
                goto try_again;
            }
        
            check_win_lose();
            if (check_win_lose_value == 1)
            {  
                system("CLS");
                table_show();
                cout<<"\nGame Over !!";
                if(player_no==2)
                {
                    cout<<"\nCongratulation !! \nPlayer "<<player_no - 1<<" won";
                    cin.ignore();
                    cout<<"\n\nPress Enter to move to the Main Menu ";
                    cin.get();
                    goto main_menu;
                }
                else
                {
                    cout<<"\nCongratulation !! \nPlayer "<<player_no + 1<<" won";
                    cin.ignore();
                    cout<<"\n\nPress Enter to move to the Main Menu ";
                    cin.get();
                    goto main_menu;
                }
            }
        }

        system("CLS");
        table_show();
        cout<<"\nMatch Draw !!";
        cin.ignore();
        cout<<"\n\nPress Enter to return to the Main Menu ";
        cin.get();
        goto main_menu;

}

void boardClass::player_number_change()
{
    player_no=player_no+sign;
}