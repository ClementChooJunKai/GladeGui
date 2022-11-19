#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glib/gstdio.h>


/* Constant Variables */
#define PLAYER 'X'
#define COMPUTER 'O'

char board[3][3];
int turncounter;
int player_1_score;
int player_2_score;
int gamemode;
int bestMove[2];
float aiPercentage;
int row;
int column;
int check_winner;
int check_draw;

GtkWidget *window;
GtkWidget *mainMenu;
GtkWidget *player_vs_player;
GtkWidget *player_vs_computer_easy;
GtkWidget *player_vs_computer_medium;
GtkWidget *player_vs_computer_hard;
GtkWidget *quit;
GtkWidget *MainBox;
GtkWidget *tttpage;
GtkWidget *tttgrid;
GtkWidget *button1;
GtkWidget *child1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;
GtkWidget *image;
GtkWidget *player1;
GtkWidget *player2;
GtkWidget *score1;
GtkWidget *score2;
GtkWidget *header;
GtkWidget *announce;
GtkWidget *back;
GtkWidget *reset;
GtkWidget *restart;
GtkWidget *optionbox;

void hideMenu();
void hidegrid();
void changeGamemode(GtkWidget *widget, gpointer data);
void playerMove(GtkWidget *widget, gpointer data);
void computerMove();
int checkFreeSpaces();
int draw(int freeSpaces);
void printBoard();
int checkWinner();
void setAIdifficulty();
void initializeGUI();
void resetBoard();
void disableButtons();
void destroy(GtkWidget *widget, gpointer data);
void announceWinner(int winner, int draw);
int evaluate();
int minimax(int depth, int isMax);
void findBestMove();
int max(int num1, int num2);
int min(int num1, int num2);
void setAIDifficulty();
int getAIDecision();
int checkWinner();
int checkFreeSpaces();
void resetGame();
void resetBoard();


int main (int argc,char *argv[]){
    gtk_init(&argc,&argv);
  

    //Creating a window and styling of window
    window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Tic Tac Toe");
    gtk_window_set_default_size(GTK_WINDOW(window),800,600);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
    //gtk_window_set_decorated(GTK_WINDOW(window),FALSE);
    
    image = gtk_image_new_from_file ("download.jfif");


    //gtk_widget_show (MainBox);
    //creating a MainBox container
    MainBox = gtk_fixed_new();
    
    gtk_widget_set_name(MainBox,"MainBox");
    
    gtk_container_add (GTK_CONTAINER (window), MainBox);
    
    //creating box container
    mainMenu = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    //tttpage = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    tttpage = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(MainBox),mainMenu);
    
    gtk_container_add(GTK_CONTAINER (MainBox), tttpage);
    gtk_widget_set_name(mainMenu,"mainMenu");
    gtk_widget_set_name(tttpage,"tttpage");
    
   
    
    //Main Menu
    //creating elements in main menu 
    player_vs_player = gtk_button_new_with_label("Player Vs Player");
    player_vs_computer_easy = gtk_button_new_with_label("Player Versus Computer(Easy)");
    player_vs_computer_medium = gtk_button_new_with_label("Player Versus Computer(Medium)");
    player_vs_computer_hard = gtk_button_new_with_label("Player Versus Computer(Hard)");


    quit= gtk_button_new_with_label("Quit");
    g_signal_connect(quit,"clicked", G_CALLBACK(gtk_main_quit),NULL);
    

    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_player);
    gtk_widget_set_name(player_vs_player,"player_vs_player");
    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_computer_easy);
    gtk_widget_set_name(player_vs_computer_easy,"player_vs_computer_easy");
    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_computer_medium);
    gtk_widget_set_name(player_vs_computer_medium,"player_vs_computer_medium");
    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_computer_hard);
    gtk_widget_set_name(player_vs_computer_hard,"player_vs_computer_hard");
    gtk_container_add(GTK_CONTAINER(mainMenu),quit);
    gtk_widget_set_name(quit,"quit");
    
    //Creating welcome page
    header = gtk_label_new("TIC TAC TOE");
    gtk_widget_set_name(header,"header");
    gtk_container_add(GTK_CONTAINER(MainBox),header);

    //Creating player 1,2 label
    player1 = gtk_label_new("Player 1");
    player2 = gtk_label_new("Player 2");
    gtk_container_add(GTK_CONTAINER(MainBox),player1);
    gtk_container_add(GTK_CONTAINER(MainBox),player2);
    gtk_widget_set_name(player1,"player1");
    gtk_widget_set_name(player2,"player2");


    //Create scores label
    score1 = gtk_label_new("0");
    score2 = gtk_label_new("0");
    gtk_container_add(GTK_CONTAINER(MainBox),score1);
    gtk_container_add(GTK_CONTAINER(MainBox),score2);
    gtk_widget_set_name(score1,"score1");
    gtk_widget_set_name(score2,"score2");


    //Announce winner label
    announce = gtk_label_new("Winner");
    gtk_container_add(GTK_CONTAINER(MainBox),announce);
    gtk_widget_set_name(announce,"winner");


    optionbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_container_add(GTK_CONTAINER(MainBox),optionbox);
    gtk_widget_set_name(optionbox,"optionbox");


    back = gtk_button_new_with_label("Back");
    reset = gtk_button_new_with_label("Restart");
    restart = gtk_button_new_with_label("Reset Score");
    gtk_container_add(GTK_CONTAINER(optionbox),back);
    gtk_container_add(GTK_CONTAINER(optionbox),reset);
    gtk_container_add(GTK_CONTAINER(optionbox),restart);
    gtk_widget_set_name(back,"back");
    gtk_widget_set_name(reset,"reset");
    gtk_widget_set_name(restart,"restart");

    

    //Tic tac toe page 
    //creating elements in page ttt
    tttgrid = gtk_grid_new();
    gtk_widget_set_name(tttgrid,"tttgrid");
    gtk_container_add(GTK_CONTAINER(tttpage),tttgrid);
    

    button1 = gtk_button_new();
    button2 = gtk_button_new();
    button3 = gtk_button_new();
    button4 = gtk_button_new();
    button5 = gtk_button_new();
    button6 = gtk_button_new();
    button7 = gtk_button_new();
    button8 = gtk_button_new();
    button9 = gtk_button_new();

    gtk_widget_set_name(button1,"button1");
    gtk_widget_set_name(button2,"button2");
    gtk_widget_set_name(button3,"button3");
    gtk_widget_set_name(button4,"button4");
    gtk_widget_set_name(button5,"button5");
    gtk_widget_set_name(button6,"button6");
    gtk_widget_set_name(button7,"button7");
    gtk_widget_set_name(button8,"button8");
    gtk_widget_set_name(button9,"button9");

    //adding image to button
    //gtk_button_set_always_show_image (GTK_BUTTON (button1), TRUE);
    //gtk_button_set_image(GTK_BUTTON(button1),image);



    gtk_grid_set_row_homogeneous(GTK_GRID(tttgrid),TRUE);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button1),1,0,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button2),2,0,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button3),3,0,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button4),1,1,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button5),2,1,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button6),3,1,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button7),1,2,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button8),2,2,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(button9),3,2,1,1);


    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "theme.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),GTK_STYLE_PROVIDER(cssProvider),GTK_STYLE_PROVIDER_PRIORITY_USER);
    
  
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(window);

    gtk_widget_hide(tttpage);
    gtk_widget_hide(player1);
    gtk_widget_hide(player2);
    gtk_widget_hide(score1);
    gtk_widget_hide(score2);
    gtk_widget_hide(announce);
    gtk_widget_hide(back);
    gtk_widget_hide(reset);
    gtk_widget_hide(restart);

    
    g_signal_connect(player_vs_player, "clicked", G_CALLBACK(changeGamemode), "0");
    g_signal_connect(player_vs_computer_easy, "clicked", G_CALLBACK(changeGamemode), "1");
    g_signal_connect(player_vs_computer_medium, "clicked", G_CALLBACK(changeGamemode), "2");
    g_signal_connect(player_vs_computer_hard, "clicked", G_CALLBACK(changeGamemode), "3");

    g_signal_connect(button1, "clicked", G_CALLBACK(playerMove), &board[0][0]);
    g_signal_connect(button2, "clicked", G_CALLBACK(playerMove), &board[0][1]);
    g_signal_connect(button3, "clicked", G_CALLBACK(playerMove), &board[0][2]);
    g_signal_connect(button4, "clicked", G_CALLBACK(playerMove), &board[1][0]);
    g_signal_connect(button5, "clicked", G_CALLBACK(playerMove), &board[1][1]);
    g_signal_connect(button6, "clicked", G_CALLBACK(playerMove), &board[1][2]);
    g_signal_connect(button7, "clicked", G_CALLBACK(playerMove), &board[2][0]);
    g_signal_connect(button8, "clicked", G_CALLBACK(playerMove), &board[2][1]);
    g_signal_connect(button9, "clicked", G_CALLBACK(playerMove), &board[2][2]);

    g_signal_connect(back,"clicked", G_CALLBACK(hidegrid),NULL);
    g_signal_connect(reset,"clicked", G_CALLBACK(resetBoard),NULL);
    g_signal_connect(restart,"clicked", G_CALLBACK(resetGame),NULL);
    

    //gtk code comes here
    gtk_main();

    return 0;
    
}

void hideMenu(){

    gtk_widget_hide(mainMenu);
    gtk_widget_hide(header);
    gtk_widget_show(tttpage);
    gtk_widget_show(player1);
    gtk_widget_show(player2);
    gtk_widget_show(score1);
    gtk_widget_show(score2);
    gtk_widget_show(announce);
    gtk_widget_show(back);
    gtk_widget_show(reset);
    gtk_widget_show(restart);

}

void changeGamemode(GtkWidget *widget, gpointer data)
{
    char* ptr_gamemode = data;

    if (*ptr_gamemode == '0')
    {
        gamemode = 0;
        hideMenu();
        gtk_label_set_label(GTK_LABEL(player2), "Player 2");
        resetBoard();
    }
    else if (*ptr_gamemode == '1')
    {
        gamemode = 1;
        setAIDifficulty();
        hideMenu();
        gtk_label_set_label(GTK_LABEL(player2), "Computer (Easy)");
        resetBoard();
    }
    else if (*ptr_gamemode == '2')
    {
        gamemode = 2;
        setAIDifficulty();
        hideMenu();
        gtk_label_set_label(GTK_LABEL(player2), "Computer (Medium)");
        resetBoard();
    }
    else if (*ptr_gamemode == '3')
    {
        gamemode = 3;
        setAIDifficulty();
        hideMenu();
        gtk_label_set_label(GTK_LABEL(player2), "Computer (Hard)");
        resetBoard();
    }
}

void hidegrid(){
    gtk_widget_show(mainMenu);
    gtk_widget_show(header);
    gtk_widget_hide(tttpage);
    gtk_widget_hide(player1);
    gtk_widget_hide(player2);
    gtk_widget_hide(score1);
    gtk_widget_hide(score2);
    gtk_widget_hide(announce);
    gtk_widget_hide(back);
    gtk_widget_hide(reset);
    gtk_widget_hide(restart);
    resetGame();
}

void playerMove(GtkWidget *widget, gpointer data)
{
    /* Pointer to the Board Array */
    char* ptr_board = data;

    /* Check if the space is occupied */
    if (*ptr_board == 'X' || *ptr_board == 'O')
    {
        printf("\nInvalid Move!\n");
        return;
    }

    if (gamemode == 0)
    {
        if (turncounter % 2 == 0 || turncounter == 0)
        {
            *ptr_board = PLAYER;
            gtk_button_set_label(GTK_BUTTON(widget), "X");
            turncounter = turncounter + 1;

        }
        else if (turncounter % 2 == 1 && gamemode == 0)
        {
            *ptr_board = COMPUTER;
            gtk_button_set_label(GTK_BUTTON(widget), "O");
            turncounter = turncounter + 1;
        }
        check_winner = checkWinner();
        check_draw = draw(checkFreeSpaces());
        announceWinner(check_winner, check_draw);
    }

    if (gamemode == 1 || gamemode == 2 || gamemode == 3)
    {
        *ptr_board = PLAYER;
        gtk_button_set_label(GTK_BUTTON(widget), "X");
        turncounter = turncounter + 1;
        check_winner = checkWinner();
        check_draw = draw(checkFreeSpaces());
        announceWinner(check_winner, check_draw);

        if (check_winner == 0 && check_draw == 0)
        {
            computerMove();
            turncounter = turncounter + 1;
            check_winner = checkWinner();
            check_draw = draw(checkFreeSpaces());
            announceWinner(check_winner, check_draw);
        }
    }

    printBoard();
}

void computerMove()
{
    int ai_decision = getAIDecision();
    printf("\n%d", ai_decision);
    int ai_row, ai_column;
    int x, y;

    if (ai_decision == 1)
    {
        findBestMove();
        ai_row = bestMove[0];
        ai_column = bestMove[1];
    }
    else if (ai_decision == 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (strlen(&board[x][y]) != 0);
        
        ai_row = x;
        ai_column = y;
    }

    board[ai_row][ai_column] = COMPUTER;
    if (ai_row == 0 && ai_column == 0)
    {
        gtk_button_set_label(GTK_BUTTON(button1), "O");
    }
    else if (ai_row == 0 && ai_column == 1)
    {
        gtk_button_set_label(GTK_BUTTON(button2), "O");
    }
    else if (ai_row == 0 && ai_column == 2)
    {
        gtk_button_set_label(GTK_BUTTON(button3), "O");
    }
    else if (ai_row == 1 && ai_column == 0)
    {
        gtk_button_set_label(GTK_BUTTON(button4), "O");
    }
    else if (ai_row == 1 && ai_column == 1)
    {
        gtk_button_set_label(GTK_BUTTON(button5), "O");
    }
    else if (ai_row == 1 && ai_column == 2)
    {
        gtk_button_set_label(GTK_BUTTON(button6), "O");
    }
    else if (ai_row == 2 && ai_column == 0)
    {
        gtk_button_set_label(GTK_BUTTON(button7), "O");
    }
    else if (ai_row == 2 && ai_column == 1)
    {
        gtk_button_set_label(GTK_BUTTON(button8), "O");
    }
    else if (ai_row == 2 && ai_column == 2)
    {
        gtk_button_set_label(GTK_BUTTON(button9), "O");
    }
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (strlen(&board[i][j]) != 0)
            {
                freeSpaces = freeSpaces - 1;
            }
        }
    }

    return freeSpaces;
}

int draw(int freeSpaces)
{
    if (freeSpaces == 0)
    {
        return 1;
    }
    return 0;
}

void printBoard()
{
    printf("\n");
    printf(" %c  | %c   | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n--- | --- | --- \n ");
    printf(" %c | %c   | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n--- | --- | --- \n ");
    printf(" %c | %c   | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n--- | --- | --- \n ");
    printf("\n");
}

int checkWinner()
{
    /* 
    Check every row to see if there is a Winning Combination
    */
    for (int row = 0; row < 3; ++row){
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && strlen(&board[row][0]) != 0){
            if (board[row][0] == PLAYER){
                return -1;
            }
            else if (board[row][0] == COMPUTER){
                return 1;
            }
        }
    }

    /*
    Check every column to see if there is a Winning Combination
    */
    for (int col = 0; col < 3; ++col){
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && strlen(&board[0][col]) != 0){
            if (board[0][col] == PLAYER){
                return -1;
            }
            else if (board[0][col] == COMPUTER){
                return 1;
            }
        }
    }


    /*
    Check Left-to-Right downward diagonally to see if there is a Winning Combination
    */
    int count = 0;
    for (int col = 0; col < 3; ++col)
    {
        if (board[col][col] == COMPUTER)
        {
            count = count + 1;
        }
        else if (board[col][col] == PLAYER)
        {
            count = count - 1;
        }
        else
        {
            count = count + 0;
        }
    }
    if (count == 3 || count == -3)
    {
        /*
        Returns either 1 or -1 to declare the appropriate winner
        */
        return count / abs(count); 
    }

    /*
    Check Left-to-Right upward diagonally to see if there is a Winning Combination
    */
    count = 0;
    for (int col = 0; col < 3; ++col)
    {
        if (board[col][2 - col] == COMPUTER)
        {
            count = count + 1;
        }
        else if (board[col][2 - col] == PLAYER)
        {
            count = count - 1;
        }
        else
        {
            count = count + 0;
        }
    }
    if (count == 3 || count == -3)
    {
        /*
        Returns either 1 or -1 to declare the appropriate winner
        */
        return count / abs(count);
    }
    
    return 0;
}

void announceWinner(int winner, int draw)
{
    if (winner == -1)
    {
        gtk_label_set_label(GTK_LABEL(announce), "Player 1 has won!");
        player_1_score = player_1_score + 1;
        gchar *display;
        display = g_strdup_printf("%d", player_1_score);
        gtk_label_set_label(GTK_LABEL(score1), display);
        g_free(display);
        disableButtons();
    }
    else if (winner == 1)
    {
        if (gamemode == 1 || gamemode == 2 || gamemode == 3)
        {
            gtk_label_set_label(GTK_LABEL(announce), "Computer has won!");
        }
        else
        {
            gtk_label_set_label(GTK_LABEL(announce), "Player 2 has won!");
        }
        player_2_score = player_2_score + 1;
        gchar *display;
        display = g_strdup_printf("%d", player_2_score);
        gtk_label_set_label(GTK_LABEL(score2), display);
        g_free(display);
        disableButtons();
    }
    else if (draw == 1 && winner == 0)
    {
        gtk_label_set_label(GTK_LABEL(announce), "It's a Draw!");
        disableButtons();
    }
}

void resetBoard()
{
    memset(board, 0, sizeof(board));
    turncounter = 0;

    gtk_label_set_label(GTK_LABEL(announce), " ");

    gtk_button_set_label(GTK_BUTTON(button1), " ");
    gtk_button_set_label(GTK_BUTTON(button2), " ");
    gtk_button_set_label(GTK_BUTTON(button3), " ");
    gtk_button_set_label(GTK_BUTTON(button4), " ");
    gtk_button_set_label(GTK_BUTTON(button5), " ");
    gtk_button_set_label(GTK_BUTTON(button6), " ");
    gtk_button_set_label(GTK_BUTTON(button7), " ");
    gtk_button_set_label(GTK_BUTTON(button8), " ");
    gtk_button_set_label(GTK_BUTTON(button9), " ");

    gtk_widget_set_sensitive (button1, TRUE);
    gtk_widget_set_sensitive (button2, TRUE);
    gtk_widget_set_sensitive (button3, TRUE);
    gtk_widget_set_sensitive (button4, TRUE);
    gtk_widget_set_sensitive (button5, TRUE);
    gtk_widget_set_sensitive (button6, TRUE);
    gtk_widget_set_sensitive (button7, TRUE);
    gtk_widget_set_sensitive (button8, TRUE);
    gtk_widget_set_sensitive (button9, TRUE);
}

void resetScore()
{
    gtk_label_set_label(GTK_LABEL(score1), "0");
    gtk_label_set_label(GTK_LABEL(score2), "0");
    player_1_score = 0;
    player_2_score = 0;
}

void resetGame()
{
    resetBoard();
    resetScore();
}

void disableButtons()
{
    gtk_widget_set_sensitive (button1, FALSE);
    gtk_widget_set_sensitive (button2, FALSE);
    gtk_widget_set_sensitive (button3, FALSE);
    gtk_widget_set_sensitive (button4, FALSE);
    gtk_widget_set_sensitive (button5, FALSE);
    gtk_widget_set_sensitive (button6, FALSE);
    gtk_widget_set_sensitive (button7, FALSE);
    gtk_widget_set_sensitive (button8, FALSE);
    gtk_widget_set_sensitive (button9, FALSE);
}

int evaluate()
{
    int check_winner;
    check_winner = checkWinner();
    if (check_winner == -1)
    {
        return -10;
    }
    else if (check_winner == 1)
    {
        return +10;
    }
    else
    {
        return 0;
    }

}

int minimax(int depth, int isMax)
{
    int score, spaces_left;

    score = evaluate();
    
    if (score == 10)
    {
        return score;
    }

    if (score == -10)
    {
        return score;
    }

    spaces_left = checkFreeSpaces();
    if (spaces_left == 0)
    {
        return 0;
    }

    if (isMax == 1)
    {
        int best = -1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (strlen(&board[i][j]) == 0)
                {
                    board[i][j] = COMPUTER;

                    best = max(best, minimax(depth + 1, !isMax));

                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (strlen(&board[i][j]) == 0)
                {
                    board[i][j] = PLAYER;

                    best = min(best, minimax(depth + 1, !isMax));

                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}

void findBestMove()
{
    int bestVal = -1000;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (strlen(&board[i][j]) == 0)
            {
                board[i][j] = COMPUTER;

                int moveVal = minimax(0, 0);

                board[i][j] = 0;

                if (moveVal > bestVal)
                {
                    bestMove[0] = i;
                    bestMove[1] = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The value of the best Move: %d\n\n", bestVal);
}

int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    return num2;
}

int min(int num1, int num2)
{
    if (num1 < num2)
    {
        return num1;
    }
    return num2;
}

void setAIDifficulty()
{
    if (gamemode == 1)
    {
        aiPercentage = 0.0;
    }
    else if (gamemode == 2)
    {
        aiPercentage = 0.75;
    }
    else if (gamemode == 3)
    {
        aiPercentage = 1.0;
    }
    return;
}

/* Write a function to calculate the possibility of picking the MiniMax Best Move and a random move on the board */

int getAIDecision()
{
    float value;
    value = (float) rand() / RAND_MAX;
    printf("\nRandomised Value is:");
    printf("%f", value);

    if (value <= aiPercentage)
    {
        printf("\n Best Move");
        return 1; /* Return 1 indicates that AI uses MiniMax Algorithm */ 
    }
    printf("\n Not Best Move");
    return 0; /* Return 0 indicates that AI uses a randomiser */
}