/*
Student Name: Surin Rao
Student Number: 20760312
Date: October 8th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab04
Exercise: 01
File name: lab04_01.cpp
Project: Lab04
Purpose: Soccer Simulation

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline
1. Use top-down problem solving and identify the subproblems and which functions need to be created
1b. This includes a boolean simulator, a shot function, penalty and free kick functions, and a foul card function
2. Use a random number generator to say how many events occur during a game
3. Using a for loop and if/switch statements, show the different scenarios that can arise from each different number
4. Print a statement commentating on each event that occurs
5. Print the stats at the end of each half  

*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;

/*-----------------------------------------------Function Prototyping-------------------------------------*/
bool run_simulation();
void shots(string team, int& goals, int& blocks, int& misses, int& total_shots);
void freekick(string team, int& goals, int& blocks, int& misses, int& total_shots);
void penaltyshot(string team, int& goals, int& blocks, int& misses, int& total_shots);
void fouls(string team, int& yellow_cards, int& red_cards);
/*--------------------------------------------------Main----------------------------------------------*/
int main() {
    cout << endl;
    if (run_simulation()) {
        cout << "Soccer simulation completed successfully!" << endl;
    }//if
    return 0;
}//main
/*--------------------------------------------Run Simulation-----------------------------------*/
bool run_simulation() {
//Purpose: Runs the game
//Input: none
//Output: returns true if the simulation was successful otherwise false

/*----Variable declaration----*/
    string team_a = "Team A";
    string team_b = "Team B";
    int event;
    int first_half;
    int second_half;
    int score_a = 0;
    int score_b = 0;
    int a_block = 0;
    int b_block = 0;
    int a_miss = 0;
    int b_miss = 0;
    int a_yellow_card = 0;
    int b_yellow_card = 0;
    int a_red_card = 0;
    int b_red_card = 0;
    int a_total_shots = 0;
    int b_total_shots = 0;

    srand(time(0));

    first_half = (rand() % 30 + 1)/2;
    second_half = first_half;

    for (int i = 0; i < first_half; i++) { //runs through the possibilities for each event in the first half
        int event = rand() % 6 + 1;

        switch (event) { //using a switch function instead of an if statement
            case 1: //if the random number is 1, then it will use the shots function for team_a (they will score based on requirements)
                shots(team_a, score_a, a_block, a_miss, a_total_shots);
                break;
            case 2:
                shots(team_b, score_b, b_block, b_miss, b_total_shots); //shot for team_b
                break;
            case 3:
                fouls(team_b, b_yellow_card, b_red_card); //Free kick for team_a + now there can be fouls
                shots(team_a, score_a, a_block, a_miss, a_total_shots);
                break;
            case 4:
                fouls(team_a, a_yellow_card, a_red_card); //Free kick team_b
                shots(team_b, score_b, b_block, b_miss, b_total_shots);
                break;
            case 5:
                fouls(team_b, b_yellow_card, b_red_card); //Penalty shot team_a
                penaltyshot(team_a, score_a, a_block, a_miss, a_total_shots);
                break; //important to have the break so it doesn't just run through all the code at once for a case
            case 6:
                fouls(team_a, a_yellow_card, a_red_card); //Penalty team_b
                penaltyshot(team_b, score_b, b_block, b_miss, b_total_shots);
                break;
        }//switch
    }//for loop for 1st half

/*--------Half Time (printing stats)---------*/
    cout << endl;
    cout << "\t\t\t\t HALF TIME" << endl;
    cout << "\t\t\t\t SCORE (A:B): " << score_a << ":" << score_b << endl;
    cout << "\t\t\t\t A SHOTS: " << a_total_shots << endl;
    cout << "\t\t\t\t B SHOTS: " << b_total_shots << endl;
    cout << "\t\t\t\t A CARDS (yellow, red): " << a_yellow_card << ", " << a_red_card << endl;
    cout << "\t\t\t\t B CARDS (yellow, red): " << b_yellow_card << ", " << b_red_card << endl;
    cout << "\t\t\t\t A MISSES: " << a_miss << endl;
    cout << "\t\t\t\t B MISSES: " << b_miss << endl;
    cout << "\t\t\t\t A BLOCKED: " << a_block << endl;
    cout << "\t\t\t\t B BLOCKED: " << b_block << endl;
    cout << endl;
    cout << "\t\t\t\t RESUME GAME" << endl;
    cout << endl;

    for (int i = 0; i < second_half; i++) { //runs through the possibilities for each event in the second half
        int event = rand() % 6 + 1;
        switch (event) {
            case 1:
                shots(team_a, score_a, a_block, a_miss, a_total_shots);
                break;
            case 2:
                shots(team_b, score_b, b_block, b_miss, b_total_shots);
                break;
            case 3:
                fouls(team_b, b_yellow_card, b_red_card);
                shots(team_a, score_a, a_block, a_miss, a_total_shots);
                break;
            case 4:
                fouls(team_a, a_yellow_card, a_red_card);
                shots(team_b, score_b, b_block, b_miss, b_total_shots);
                break;
            case 5:
                fouls(team_b, b_yellow_card, b_red_card);
                penaltyshot(team_a, score_a, a_block, a_miss, a_total_shots);
                break;
            case 6:
                fouls(team_a, a_yellow_card, a_red_card);
                penaltyshot(team_b, score_b, b_block, b_miss, b_total_shots);
                break;
        }//switch
    }//for loop second half

/*-----Full Time------*/
    cout << endl;
    cout << "\t\t\t\t FULL TIME" << endl;
    cout << "\t\t\t\t SCORE (A:B): " << score_a << ":" << score_b << endl;
    cout << "\t\t\t\t A SHOTS: " << a_total_shots << endl;
    cout << "\t\t\t\t B SHOTS: " << b_total_shots << endl;
    cout << "\t\t\t\t A CARDS (yellow, red): " << a_yellow_card << ", " << a_red_card << endl;
    cout << "\t\t\t\t B CARDS (yellow, red): " << b_yellow_card << ", " << b_red_card << endl;
    cout << "\t\t\t\t A MISSES: " << a_miss << endl;
    cout << "\t\t\t\t B MISSES: " << b_miss << endl;
    cout << "\t\t\t\t A BLOCKED: " << a_block << endl;
    cout << "\t\t\t\t B BLOCKED: " << b_block << endl;
    cout << endl;
    cout << "\t\t\t\t END GAME" << endl;
    cout << endl;

    if (score_a > score_b) {
        cout << "\t\t\t\t A WINS" << endl;
    }//a
    else if (score_b > score_a) {
        cout << "\t\t\t\t B WINS" << endl;
    }//b
    else if (score_a == score_b) {
        cout << "\t\t\t\t TIE GAME" << endl;
    }//tie
    return 0;
}//run simulation
/*----------------------------------------Shot Function---------------------------*/
void shots(string team, int& goals, int& blocks, int& misses, int& total_shots) {
//Purpose: Keep track of normal shots on goal
//Input: Team (A or B), goals (# of goals scored), blocks (# of shots blocked), misses (# of shots that missed the net), total_shots (total # of shots)
//Output: A statement explaning the event that occurs
    int event = rand() % 4;
    switch(event){
        case 0:
            cout << team << " scored! " << endl;
            total_shots++;
            goals++;
            break;
        case 1:
            cout << team << " took a shot but it was blocked by the goalie with help from the first defender!" << endl;
            total_shots++;
            blocks++;
            break;
        case 2:
            cout << team << " shot but it went wide!" << endl;
            total_shots++;
            misses++;
            break;
        case 3:
            cout << team << " 's shot got blocked by the second defender! Too bad!" << endl;
            total_shots++;
            blocks++;
            break;
    }//switch
}//shots function
/*----------------------------------------Free Kick Function---------------------------*/
//Purpose: Keep track of free kick shots on goal
//Input: Team (A or B), goals (# of goals scored), blocks (# of shots blocked), misses (# of shots that missed the net), total_shots (total # of shots)
//Output: A statement explaning the event that occurs
void freekick(string team, int& goals, int& blocks, int& misses, int& total_shots) {
    int event = rand() % 3;
    switch(event){
        case 0:
            cout << team << " scored off of a free kick!" << endl;
            total_shots++;
            goals++;
            break;
        case 1:
            cout << team << " 's free kick was blocked by the goalie with help from the first defender!" << endl;
            total_shots++;
            blocks++;
            break;
        case 2:
            cout << team << " 's free kick went too far and missed the net!" << endl;
            total_shots++;
            misses++;
            break;
        case 3:
            cout << team << " shot was blocked by the second defender, not even close!" << endl;
            total_shots++;
            blocks++;
            break;
    }//switch
}//free kick
/*----------------------------------------Penalty Shot Function---------------------------*/
//Purpose: Keep track of penalty shots on goal
//Input: Team (A or B), goals (# of goals scored), blocks (# of shots blocked), misses (# of shots that missed the net), total_shots (total # of shots)
//Output: A phrase explaning the event that occurs
void penaltyshot(string team, int& goals, int& blocks, int& misses, int& total_shots) {
    int event = rand() % 3;
    switch(event){
        case 0:
            cout << team << " 's penalty kick went in! Congrats!!" << endl;
            total_shots++;
            goals++;
            break;
        case 1:
            cout << team << " took a penalty shot but it was saved by the goalie!" << endl;
            total_shots++;
            blocks++;
            break;
        case 2:
            cout << team << " goofed and didn't even kick the ball at the net! What a waste of a penalty shot!" << endl;
            total_shots++;
            misses++;
            break;
    }//switch
}//penalty function
/*---------------------------------------------Foul Function-----------------------------*/
//Purpose: Keep track of the fouls committed
//Input: Team (A or B), yellow card (# of yellow cards), red card (# of red cards)
//Output: A phrase explaning the event that occurs
void fouls(string team, int& yellow_card, int& red_card) {
    int event = rand() % 3;
    cout << team << " fouled! What do the refs say? ";
    switch(event){
        case 0:
            cout << team << " receives no card." << endl;
            break;
        case 1:
            cout << team << " receives a yellow card." << endl;
            yellow_card++;
            break;
        case 2:
            cout << team << " receives a red card!" << endl;
            red_card++;
            break;
    }//switch
}//fouls
/*-----------------------------------------------------------END--------------------------------------------------*/
