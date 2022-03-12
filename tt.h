class tt
{
private:

    char board[3][3];
    int start_stop,player_no,r,c;
    int player_input_valid;
    int check_win_lose_value;
    char mark_1 = 'X';
    char mark_2 = 'O';
    int sign;
    char gap = 32;
    
    
public:   
    tt()
    {   check_win_lose_value=0;
        mark_1 = 'X';
        mark_2 = 'O';
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                board[i][j] = gap;
        }
    }
    void table_show();
    void player_input();
    void menu();
    void start_game();
    void check_player_input();
    void check_win_lose();
    void play_game();
    void player_number_change();
    void board_space_check();
    void input();
    void initialize_everything();
    
};

