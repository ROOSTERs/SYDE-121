/*
Student Name: Surin Rao
Student Number: 20760312
Date: October 25th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab05
Exercise: 01
File name: lab05_01.cpp
Project: Lab05
Purpose: Tic Tac Toe

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline:
1. Create a string array (2d) to house the board
2. Have a input for the players to enter the square which they want to make their move
2a. Have an expression to determine which index in the array it will be 
3. Replace that value with an X or O
4. Swap players
5. Repeat above 
6. Have a function to check if someone wins vertically, horizontally or diagonally
7. Output stats and ask if they want to play again


Note: I have some extra functions because they were what I was using to test my code while I was building it (I just left them not commented 
because my code worked with them still on and I didn't want to remove them in fear of my code breaking). 

I tested it by trying to repeat an index to make sure it wouldn't override a previous move. Another scenario I tested was making sure there was
no winner, so to confirm it would output tie, which it did. I then tested to see winners for both X and O, both vertical, diagonal and horizontal to make
sure it would output the correct winner. 
*/
#include <iostream>
#include <string>
#include <iomanip> //manipulate output, so adds a space for 1 digit numbers to fix the spacing

using namespace std;

//Note: I didn't function prototype because I had main at the end anyways, so all my functions are defined before main, but an example would be:
//void print_board(string board[4][4]);

/*------------------------Printing the original board------------------------------*/
void print_board(string board[4][4]) {
    cout << endl;
    for (int row = 0; row< 4; row++) {
        for (int column = 0; column < 4; column++) {
           cout << setw(2) << board[row][column] << "    ";
        }//nested for loop
        cout << endl;
    }//original
}//print_board

/*---------------------------------Which index----------------------------------------------*/
void rows_and_columns (int& rows, int& columns, string board[4][4], const string& current_player) {
    int player_input;
    cout << "Enter an index " << current_player << ": ";
    bool valid_move;
    //do while loop to make sure they are entering a valid input
    //do {
        cin >> player_input;
        rows = ((player_input - 1) / 4);
        columns = ((player_input - 1) % 4);
       // valid_move = (player_input > 0 && player_input < 17 && board[rows][columns] != "X" && board[rows][columns] != "O");

       // if (valid_move == false) {
        //    cout << "Please enter a valid index" << endl;
      //  }//if
   // }//do
  //  while (valid_move == false);
}//rows and columns

/*------------------------Going through each player's turn ------------------------------*/
bool turns(string board[4][4], string current_player){
    int rows;
    int columns;
    rows_and_columns(rows, columns, board, current_player);
    board[rows][columns] = current_player;
    print_board(board);
    bool is_win = who_won(board, current_player);
    if (is_win) {
        cout << "WINNER! WINNER!";
        return true;
    }//if
    else {
        return false;
    }//else
}//turns

/*------------------------Adding the move------------------------------*/
bool make_move (string board[4][4], const int& row, const int& column, const string& current_player) {
    if (0 <= row && row < 4 && 0 <= column && column < 4 && board[row][column] != "X" && board [row][column] != "O") {
        board[row][column] = current_player;
        return true;
    }//if
    else {
    cout << "invalid" << endl;
    return false;
    }//else
}//make move

/*------------------------Was there a winner-----------------------------*/
bool who_won (string board[4][4], const string& current_player) {
    //check for horizontal W
    for (int row = 0; row <= 3; row++) {
        if (board[row][0] == current_player && board[row][1] == current_player && board[row][2] == current_player && board[row][3] == current_player) {
            return true;
        }//if
    }//for
    //check for vertical W
    for (int column = 0; column <=3; column++) {
        if (board[0][column] == current_player && board[1][column] == current_player && board[2][column] == current_player && board[3][column] == current_player) {
            return true;
        }//if
    }//for
    //check for diagonal W (top left to bottom right)
    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player && board[3][3] == current_player) {
        return true;
    }//if
    //check for diagonal W (top left to bottom right)
    else if (board[0][3] == current_player && board[1][2] == current_player && board[2][1] == current_player && board[3][0] == current_player) {
        return true;
    }//if
    return false;
}//who_won

/*------------------------Checks if player wants to play again----------------------------*/
bool play_again() {
    int play_again;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Do you want to play again? (1 = yes, 0 = no): ";

    // While they haven't entered a valid answer
    while(true) {
        cin >> play_again;
        if (play_again == 1) {
            return true;
        } //if
        else if (play_again == 0) {
            return false;
        }//else if
        //cout this if it's invalid 
        cout << "invalid" << endl;
    }//while 
}//play_again

/*------------------------Running the game-----------------------------*/
void game(const string& starting_player) {

    string board[4][4] = {{"1","2","3", "4" }, {"5","6","7","8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"}};
    string current_player = starting_player;

    for (int i = 1; i < 16; i++) {
    	bool is_win = turns(board, current_player);
    	if(i % 2 == 0) {
            current_player = "X";
    	}//if
    	else {
            current_player = "O";
    	}//else
    }//for
    who_won(board, current_player);
}//game 

/*------------------------Running the game-----------------------------*/
string run_game(const string& starting_player) {

    string board[4][4] = {{"1","2","3", "4" }, {"5","6","7","8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"}}; //board
    string current_player = starting_player;

    for (int i = 1; i <= 16; i++) {
        print_board(board);

        bool is_move_valid;
        do {
            int row;
            int column;
            rows_and_columns(row, column, board, current_player);

            is_move_valid = make_move(board, row, column, current_player);

        } while (!is_move_valid);

        // Check for victory
        if (who_won(board, current_player)) {
            // NOTE: The winning player is always the current player
            return current_player; // Return the who_won
        }

        // Swap X and O
        current_player = (current_player == "X") ? "O" : "X";
    }
    // All 16 iterations with no victory, therefore tie occurred
    return "TIE";

}

/*------------------------Main------------------------------*/
int main () {
    /*string test_board[4][4] = { //test board I used to make the game would output winner if there was one
                    {"X", "O", "X", "X"},
                    {"X", "O", "X", "X"},
                    {"O", "O", "O", "O"},
                    {"X", "X", "X", "X"},
                   };
    cout << who_won(test_board, "O") << endl; */
    bool repeat = true; // repeat variable if they want to play again
	string starting_player = "X"; //X will start the first game
    //print_board(board);
    //game(starting_player);
    int x_wins = 0; //counters for the wins and ties
    int o_wins = 0;
    int ties = 0;

    while (repeat) { //starts true 
        string who_won = run_game(starting_player);
        if (who_won == "X")  {
            x_wins++;
        }//x wins
        else if (who_won == "O") {
            o_wins++;
        }//o wins
        else if (who_won == "Tie") {
            ties++;
        }//ties

        cout << endl;

        if (who_won == "X" || who_won == "O") {
            cout << "WINNER WINNER" << endl;
            cout << "Player " << who_won << " has won!" << endl;
        }//winner
        else {
            cout << "Tie!" << endl;
        }//otherwise it's a tie

        //prints stats
        cout << endl;
        cout << "X: " << x_wins << endl;
        cout << "O: " << o_wins << endl;
        cout << "Ties: " << ties << endl;

        // Swap between X and O
        starting_player = (starting_player == "X" ? "O" : "X");
        repeat = play_again(); //will start the simulation again
    }
    return 0;
}//main