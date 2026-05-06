#ifndef PLAYER.H
#define PLAYER.H

//Parent of a HumanPlayer and a ComputerPlayer
//Guessing game, guess a number between 0-manNumber.

class player{
  public:
    //constructors
    player();
    player(max_number);

    //accessor functions
    int getMaxNumber() const;
    int getLastGuess() const;
    char getLastHigherLower() const;




}



#endif
