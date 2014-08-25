/*Colin Smith
* CS 161
* Project 4
* Game Station
*********************************/


#include <iostream>
#include <windows.h>
#include "time.h"
#include <limits.h>

using namespace std;

//NumberGuessGame class
class NumberGuessGame
{
public:
    void gameStart( );

private:
    string yesorno;
    int guessed_number;
    int secret_number;
    int min_guess;
    int max_guess;
    int remaining_guesses;
    int guess_difference;
    int closest_guess;
};

//WordGuessGame class
class WordGuessGame
{
public:
    void wordGuessStart();
    void wordIsValid(string &testedWord);
    void letterIsValid (string &testedLetter);
    string makeSecret (string secretWord);
    void guessTheWord (string wordGuess, string secretWord, string guessedLetter);
    void winnerOrLoser (bool winCondition, string wordGuess, string secretWord);

private:
    //constants
    const int MAXGUESSES = 8;
    const int ALPHABETNUMBER = 26;
    const int LETTERLIMIT = 8;

    //wordGuessStart's variables
    string playerOneSecretWord;//secret word
    string wordGuess;//output that Player 2 sees
    string playerTwoGuess;//Player 2's guessed letter
    string playAgain; //the play again prompt's input

    //wordIsValid's variables
    int capitalCheck;
    string testedWordCopy;// = testedWord;
    bool validWordOne = false;
    bool validWordTwo = false;
    bool validWordThree = false;

    //letterIsValid Variables
    bool validLetterOne = false;
    bool validLetterTwo = false;
    bool validLetterThree = false;
    string testedLetterCopy;// = testedLetter;
    //int capitalCheck;

    //secretMaker's variables
    string secretWordGuess;// = secretWord;

    //guesstheWord's variables
    int j = 0;
    int attempts = 0;
    bool winCondition;
    char alphabet [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
};

//RandPhraseGuessGame class
class RandPhraseGuessGame
{
public:
//functions
void randPhraseGenerate (string randPhrase[]);
void secretMaker (string randPhrase[], string randPhraseGuess[]);
string guessIsValid (string testedLetter);
void wordGuess (string randPhraseGuess[], string randPhrase[], string guessInput);
void winnnerOrLoser (bool winCondition, string randPhraseGuess[], string randPhrase[], int j);
void randPhraseGuessStart ();

private:
    //constants
    const int CAPACITY = 1000;
    const int ALPHABETNUMBER = 26;
    const int MAXGUESSES = 20;

    //randPhraseGuessStart's variables
    string randPhrase[1000];
    string randPhraseGuess [1000];
    string guessInput;
    string playAgain;

    //randPhraseGenerate's variables
    string randWords[19] = {"how","now","brown","cow","cat","dog","sings","dances","cries","baby","never","always","but","happy","sad","tragic","professor","answer","jetpack"};
    int wordDetermine = 0;
    bool check = true;

    //guessIsValid's variables
    bool validString1 = false;
    bool validString2 = false;
    bool validString3 = false;
    int capitalCheck;
    string testedLetterCopy;

    //wordGuess's variables
    int j = 0;
    int attempts = 0;
    bool winCondition;
};

int main ()
{
    string gameChoose;
    string playAgain;
    bool validEntry = false;
    NumberGuessGame a;
    WordGuessGame b;
    RandPhraseGuessGame c;

    do
    {
    cout <<"You have the option of playing 3 games."<<endl;
    cout << endl;
    cout <<"a. Number Guess Game(2 player)"<<endl;
    cout <<"b. Word Guess Game (2 player)"<<endl;
    cout <<"c. Random Phrase Guess Game (1 player)"<< endl;
    cout << endl;
    cout <<"Type \'a\' for the Number Guess Game."<<endl;
    cout <<"Type \'b\' for the Word Guess Game."<< endl;
    cout <<"Type \'c\' for the Random Phrase Guess Game."<<endl;
    cout << endl;


    validEntry = false;
    gameChoose.clear();

    getline(cin, gameChoose);

    while (validEntry == false)
    {
        if (gameChoose == "a" || gameChoose == "A")
        {
            a.gameStart();
            validEntry = true;
        }
        else if (gameChoose == "b" || gameChoose == "B")
        {
            b.wordGuessStart();
            validEntry = true;
        }
        else if (gameChoose == "c" || gameChoose == "C")
        {
            c.randPhraseGuessStart();
            validEntry = true;
        }
        else
        {
            cout <<"That doesn't seem to be one of the choices. Try again."<< endl;
            getline (cin, gameChoose);
        }
    }

    cout <<"Would you like to choose another game? Type any key to stop, type \"yes\" to continue."<<endl;

    if (gameChoose == "a" || gameChoose == "A")
    {
        cin.ignore(1000, '\n');
    }



    getline(cin, playAgain);
    cout <<"\n";
    }while (playAgain == "Yes"||playAgain == "yes" ||playAgain == "YES");
}

void NumberGuessGame::gameStart()
{

        remaining_guesses = 5;
        min_guess = 0;
        max_guess = 100;
        guess_difference = 0;

        /*User inputs the number. If it is not in the correct range
        the program will end*/
        cout <<"User 1, please enter your secret number. It must be between 1 and 100.\n"
             <<"If your number is not in this range, the game will end.\n";

        cin >>secret_number;

        //this code pattern was taken from the example code in cin error handling
        while(!cin)
        {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> secret_number;
        }

        while (secret_number < min_guess || secret_number > max_guess)
        {
            cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> secret_number;
        }



         //Creating empty space between user 1's secret number and user 2's guessing space.
        cout << "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"
             << "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"
             << "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"
             << "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n"<< "\n";

        /*This part stops the program if User 1 does not enter
        a value within the indicated range*/
        if (secret_number >= min_guess && secret_number <= max_guess)
            cout <<"That is indeed a valid number. Let's begin!\n";


            while (secret_number != guessed_number || remaining_guesses > 0)
            {
            cout << "User 2, please guess the number. It is in the range of "<<min_guess<<" to "<<max_guess<<".\n";
            cout <<"You have "<< remaining_guesses <<" guess(es) left.\n";
            cin >> guessed_number;

            remaining_guesses = remaining_guesses -1;

                while(!cin)
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Please enter a number between "<<min_guess<<" and "<<max_guess<< endl;
                    cin >> guessed_number;
                }

                while (guessed_number < min_guess || guessed_number > max_guess)
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Please enter a number between "<<min_guess<<" and "<<max_guess<< endl;
                    cin >> guessed_number;
                }

            if (guessed_number < secret_number)
            {
                cout << "You were too low. Try again.\n";
                min_guess = guessed_number;
            }

            else if (guessed_number > secret_number)
            {
                cout << "You were too high. Try again.\n";
                max_guess = guessed_number;
            }

            else if (guessed_number == secret_number)
            {
                cout << "You got the answer!\n";
            }

            else if (remaining_guesses == 0)
            {
                cout << "You have run out of guesses\n!";
            }




            //remaining_guesses = remaining_guesses -1;

            /*Used in order to keep the difference from
            the secret number a positive number*/
            if (secret_number > guessed_number)
            {
                guess_difference = secret_number - guessed_number;
            }

            else if (guessed_number > secret_number)
            {
                guess_difference = guessed_number - secret_number;
            }



            if (remaining_guesses == 0)
            {
                cout << "You lost.\n";
                cout << "The secret number was "<< secret_number << endl;
                cout << "Your closest guess was "<< guess_difference<<" from the secret number.\n";
                remaining_guesses = 5;
                break;
            }
            else if (secret_number == guessed_number)
            {
                cout << "Congratulations! You win!\n";
                remaining_guesses = 5;

                cout << endl;
                break;
            }



        }

}

void WordGuessGame::wordGuessStart()
{
    WordGuessGame a;

    cout <<"Player 1, please enter your secret word. It can only be one word and cannot contain any special "
         <<"characters, spaces, numbers or capital letters. It can be, at max, 8 letters long. Player 2 will then try to guess "
         <<"your secret word with the allotted guesses given."<< endl;
    cout << endl;

    getline (cin, playerOneSecretWord);

    cout << endl;

    a.wordIsValid (playerOneSecretWord);
    wordGuess = a.makeSecret(playerOneSecretWord);

    //empty space between Player 1's secret word and Player 2's guessing space
    cout <<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"
         <<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"
         <<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"
         <<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n";

    cout << wordGuess << endl;

    cout << endl;

    cout <<"Player 2, the secret word has been entered. The hyphens above represent the word Player 1 entered. "
         <<"Each hyphen in the word above represents one letter. Please use your first guess. "
         <<"It can only be one letter and cannot be a number, special character, space or capital letter."
         <<"The first guess is free!"<< endl;
    cout << endl;

    getline (cin, playerTwoGuess);

    a.letterIsValid(playerTwoGuess);

    a.guessTheWord(wordGuess,playerOneSecretWord, playerTwoGuess);

}

void WordGuessGame::wordIsValid(string &testedWord)
{

    testedWordCopy = testedWord;



    //loops while the input entered is not valid
    while (validWordOne == false && validWordTwo == false && validWordThree == false)
    {


        //makes sure that if nothing is entered at
        //all, it will be considered invalid input
        if (testedWord.empty())
        {
            validWordOne = false;
        }
        else
        {
            validWordOne = true;
        }

        //this makes sure no capital letters are entered
        for (int i = 0; i < testedWord.length(); i++)
        {
            capitalCheck = testedWordCopy.at(i);
            if (capitalCheck < 97 || capitalCheck > 122)
            {
                validWordTwo = false;
                break;
            }
            else
            {
                validWordTwo = true;
            }
        }
        //makes sure that no numbers, special characters, or spaces are
        //entered and that the word is only up to 8 letters long
        for (int i = 0; i < testedWord.length();i++)
        {
            if (!(isalpha(testedWord.at(i)))|| testedWord.at(i) == ' '|| testedWord.length() > LETTERLIMIT)
            {
                validWordThree = false;
                break;
            }

            else
            {
                validWordThree = true;
            }
        }



        //prompts the user for new input if the word is not valid
        if (!validWordOne || !validWordTwo || !validWordThree)
        {
            cout <<"The word you entered was not valid, please try again. Same rules apply as stated before."<< endl;
            getline (cin, testedWord);
            cout << endl;
            testedWordCopy = testedWord;

            validWordOne = false;
            validWordTwo = false;
            validWordThree = false;
        }
    }

}

void WordGuessGame::letterIsValid (string &testedLetter)
{
    testedLetterCopy = testedLetter;


    //loops while the letter entered is not valid
    while (validLetterOne == false && validLetterTwo == false && validLetterThree == false)
    {
        //makes sure that if nothing is entered at
        //all, it will be considered invalid input
        if (testedLetter.empty())
        {
            validLetterOne = false;
        }
        else
        {
            validLetterOne = true;
        }

        //makes sure that no numbers, special characters, or spaces are
        //entered and that the word is only up to 8 letters long
        for (int i = 0; i < testedLetter.length(); i++)
        {
            if (!isalpha(testedLetter.at(i))|| testedLetter.at(i) == ' ' || testedLetter.length()> 1)
            {
                validLetterTwo = false;
                break;
            }
            else
            {
                validLetterTwo = true;
            }
        }

        //makes sure that the guess is not a capital letter
        for (int i = 0; i < testedLetter.length(); i++)
        {
            capitalCheck = testedLetterCopy.at(0);
            if (capitalCheck < 97 || capitalCheck > 122)
            {
                validLetterThree = false;
                break;
            }
            else
            {
                validLetterThree = true;
            }
        }

        //if the guess entered is not valid then the user will
        //be prompted to type in another guess
        if (!validLetterOne || !validLetterTwo || !validLetterThree)
        {
            cout << "You have entered an invalid guess. Please try again. Remember no special "
                 << "characters, spaces, multiple letters or numbers."<< endl;
            cout << endl;
            getline(cin, testedLetter);
            cout << endl;
            testedLetterCopy = testedLetter;

            validLetterOne = false;
            validLetterTwo = false;
            validLetterThree = false;

        }
    }

}

string WordGuessGame::makeSecret (string secretWord)
{
    secretWordGuess = secretWord;

    //changes secretWordGuess into only hyphens
    for (int i = 0; i < secretWordGuess.length(); i++)
    {
        secretWordGuess.at(i)= '-';
    }

    return secretWordGuess;
}

void WordGuessGame::guessTheWord (string wordGuess, string secretWord, string guessedLetter)
{
    WordGuessGame a;

    do
    {
            bool gotLetter = false;

            //cout << MAXGUESSES - attempts<<" guesses left." << endl;

            cout << endl;

            //changes alphabet that was guessed to asterisks
            for (int m = 0; m < ALPHABETNUMBER; m++)
            {
                if (alphabet[m] == guessedLetter.at(0))
                {
                    alphabet[m] = '*';
                }
            }

            cout << "Unused Letter: ";

            //outputs alphabet
            for(int n = 0; n < ALPHABETNUMBER; n++)
            {
                cout << alphabet[n]<<" ";
            }
            cout <<"\n"<<"\n";

            //changes guessed letters that were in the word from hyphens to the guessed letter
            for (int x = 0; x < wordGuess.length();x++)
            {
                if (secretWord.at(x) == guessedLetter.at(0))
                {
                    wordGuess.at(x) = guessedLetter.at(0);
                }
            }

            //tests to see if a correct letter was guessed and tells the user they got it if they guessed correctly
            for (int x = 0; x < wordGuess.length(); x++)
            {
                if (secretWord.at(x) == guessedLetter.at(0))
                {
                    cout << "You got the letter!"<< endl;
                    cout << endl;

                    gotLetter = true;
                }
            }

            //tests to see if the user did not get the correct letter and tells them
            if (gotLetter != true)
            {
                cout << "You did not get the letter."<< endl;
                cout << endl;
                attempts = attempts+1;
            }

            //shows the guesses that the user has left.
            if (!(MAXGUESSES-attempts == 0))
            {
                cout << MAXGUESSES - attempts<<" guesses left." << endl;
                cout << endl;
            }
            else if (MAXGUESSES-attempts == 0)
            {
                cout <<"Last chance!"<< endl;
                cout << endl;
            }

            //outputs the hyphened secret phrase
            cout << wordGuess;
            cout << endl;
            gotLetter = false;

            //while the word has not been guessed, this will allow the user to guess again
            if (wordGuess != secretWord)
            {
                cout <<"Guess another letter. Same rules apply."<< endl;
                cout << endl;
                getline (cin, guessedLetter);

                a.letterIsValid(guessedLetter);

                cout <<"\n"<<"\n";
            }


    }while (wordGuess != secretWord && attempts < MAXGUESSES);

    //these are the win or lose conditions
    if (attempts < MAXGUESSES && wordGuess == secretWord)
    {
        winCondition = true;
    }
    else if (attempts == MAXGUESSES && wordGuess != secretWord)
    {
        winCondition = false;
    }

    a.winnerOrLoser (winCondition, wordGuess, secretWord);
}

void WordGuessGame::winnerOrLoser (bool winCondition, string wordGuess, string secretWord)
{
    if (winCondition == true)
    {
        cout <<"Player 2 wins. Player 1 is a simpleton."<<endl;
    }

    if (winCondition == false)
    {
        cout <<"Player 1 wins. I am so disappointed Player 2. You're grounded."<<endl;

        cout <<"The secret word was "<<secretWord<<"."<<endl;

        cout <<"The letters missing from the word were ";

        //outputs the letters missing that Player 2 didn't guess
        for (int x = 0; x < wordGuess.length(); x++)
        {
            if (wordGuess.at(x) != secretWord.at(x))
            {
                cout <<"\""<< secretWord.at(x)<<"\"";
            }
        }
    }


    cout << "\n"<<"\n";
}


void RandPhraseGuessGame::randPhraseGuessStart ()
{
    RandPhraseGuessGame a;


    a.randPhraseGenerate(randPhrase);
    a.secretMaker(randPhrase, randPhraseGuess);

    //for testing purposes only
    /*for (int i = 0; i < 4; i++)
    {
        cout << randPhrase[i]<<" ";
    }*/

    for (int i = 0; i < 4; i++)
    {
        cout << randPhraseGuess[i]<<" ";
    }

    cout << endl;
    cout << "These hyphens represent the secret phrase. Please guess a letter from the first word. "
         << "This can only be one letter, with no spaces, no special characters, no numbers and no capital letters. When you finish "
         << "guessing the first word, the program will automatically move on to the next word. You will have "
         <<MAXGUESSES<<" guesses TOTAL, not for each word. If you guess the letter correctly, that guess does not "
         <<"count towards your total guesses. First guess is free!"<< endl;
    getline(cin, guessInput);

    guessInput = a.guessIsValid(guessInput);
    a.wordGuess(randPhraseGuess, randPhrase, guessInput);

}

void RandPhraseGuessGame::randPhraseGenerate (string randPhrase[])
{
    srand (time(NULL));

    for (int i = 0; i < 4; i++)
    {
        do
        {
        wordDetermine = rand() % 19;
        randWords[i] = randWords[wordDetermine];
        randPhrase [i] = randWords [i];

        check = true;
        for (int j = 0 ; (check) && (j < i) ; j++)
        {
            check = (randPhrase[i] != randPhrase[j]);
        }
        } while (check == false);
    }
}

void RandPhraseGuessGame::secretMaker (string randPhrase[], string randPhraseGuess[])
{
    //copies randPhrase to randPhraseGuess
    for (int i = 0; i < 4; i++)
    {
        randPhraseGuess[i] = randPhrase [i];
    }

    //puts hyphens in places of the letters for the words in randPhraseGuess
    for (int k = 0; k < 4; k++)
    {
        for (int j = 0; j < randPhraseGuess[k].length(); j++)
        {
            randPhraseGuess[k].at(j) = '-';
        }
    }

}

string RandPhraseGuessGame::guessIsValid (string testedLetter)
{
    testedLetterCopy = testedLetter;

    while (validString1 == false && validString2 == false && validString3 == false)
    {
        if (testedLetter.empty())
        {
            validString1 = false;
        }
        else
        {
            validString1 = true;
        }

        //makes sure that the guess is not a capital letter
        for (int i = 0; i < testedLetter.length(); i++)
        {
            capitalCheck = testedLetterCopy.at(0);
            if (capitalCheck < 97 || capitalCheck > 122)
            {
                validString2 = false;
            }
            else
            {
                validString2 = true;
            }
        }

        for (int i = 0; i < testedLetter.length(); i++)
        {
            if (!isalpha(testedLetter.at(i)) || (testedLetter.at(i) == ' ' || testedLetter.length()> 1))
            {
                validString3 = false;
                break;
            }
            else
            {
                validString3 = true;
            }
        }

        if (!validString1 || !validString2 || !validString3)
        {
            cout <<"Invalid entry. Please enter a valid letter. Refer to the rules above."<<endl;
            cout << endl;
            getline(cin, testedLetter);
            cout << endl;
            testedLetterCopy = testedLetter;

            validString1 = false;
            validString2 = false;
            validString3 = false;
        }
    }

    return testedLetter;

}


void RandPhraseGuessGame::wordGuess (string randPhraseGuess[], string randPhrase[], string guessInput)
{
  RandPhraseGuessGame a;



  do
  {
    char alphabet[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    do
    {
        bool gotLetter = false;


        cout <<"\n";

        //changes alphabet that was guessed to asterisks
        for (int m = 0; m < ALPHABETNUMBER; m++)
        {
            if (alphabet[m] == guessInput.at(0))
            {
                alphabet[m] = '*';
            }
        }

        cout <<"Unused letters: ";

        //outputs alphabet
        for (int n = 0; n < ALPHABETNUMBER; n++)
        {
            cout << alphabet[n]<< " ";
        }
        cout << "\n"<< "\n";

        //changes guessed letters that were in the word from hyphens to the guessed letter
        for (int x = 0; x < randPhraseGuess[j].length(); x++)
        {
            if (randPhrase[j].at(x) == guessInput.at(0))
            {
                randPhraseGuess[j].at(x) = guessInput.at(0);
            }

        }

        //tests to see if a correct letter was guessed and tells the user they got it if they guessed correctly
        for (int x = 0; x < randPhraseGuess[j].length(); x++)
        {
            if (randPhrase[j].at(x) == guessInput.at(0))
            {
                cout << "You got the letter!"<< endl;
                cout << "\n";

                gotLetter = true;

            }

        }

        //tests to see if the user did not get the correct letter and tells them
        if (gotLetter != true)
        {
            cout << "You did not get the letter."<<endl;
            cout << "\n";
            attempts = attempts +1;
        }

        //shows the guesses that the user has left.
            if (!(MAXGUESSES-attempts == 0))
            {
                cout << MAXGUESSES - attempts<<" guesses left." << endl;
                cout << endl;
            }
            else if (MAXGUESSES-attempts == 0)
            {
                cout <<"Last chance!"<< endl;
                cout << endl;
            }

        //outputs the hyphened secret phrase
        for (int l = 0; l < 4; l++)
        {
            cout << randPhraseGuess[l]<<" ";
        }


        gotLetter = false;
        cout << endl;

        //while the word has not been guessed, this will allow the user to guess again
        if (randPhraseGuess[j] != randPhrase [j]&& randPhraseGuess[3] != randPhrase[3] )
        {
            cout <<"Guess another letter. Same rules apply."<< endl;
            cout << "\n";
            getline(cin, guessInput);

            a.guessIsValid(guessInput);

            cout << "\n"<< "\n";

        }
        //if the word is completely guessed before the if statement above finishes, this catches the input for it,
        //clears it and continues the program.
        if (randPhraseGuess[j] == randPhrase [j]&& randPhraseGuess[3] != randPhrase[3])
        {
            guessInput.clear();

            cout <<"Guess another letter. Same rules apply."<< endl;
            cout << "\n";
            getline(cin, guessInput);

            a.guessIsValid(guessInput);

            cout << "\n"<< "\n";

        }

    }while (randPhraseGuess[j] != randPhrase [j] && attempts < MAXGUESSES);

    if(attempts != MAXGUESSES)
    {
       j++;
    }


  }while (randPhraseGuess[3] != randPhrase[3] && attempts < MAXGUESSES);

if (attempts < MAXGUESSES&& randPhraseGuess[3] == randPhrase[3] )
{
    winCondition = true;
}
else if (randPhraseGuess[3] != randPhrase[3]&& attempts == MAXGUESSES)
{
    winCondition = false;
}

a.winnnerOrLoser(winCondition, randPhraseGuess, randPhrase, j);

}


void RandPhraseGuessGame::winnnerOrLoser (bool winCondition, string randPhraseGuess[],string randPhrase[], int j)
{

    //If the user guessed the phrase, this if statement is run.
    if (winCondition == true)
    {
        cout <<"WINNAH WINNAH CHICKEN DINNAH!"<< endl;
    }

    //If the user did not guess the phrase, then this if statement is run.
    if (winCondition == false )
    {
      cout <<"You lose, loser. The secret phrase was ";

      for (int i = 0; i < 4; i++)
        {
            cout <<"\""<< randPhrase[i]<<"\" ";
        }
      cout <<"\n";

      cout << "The letters missing from the word you were on were ";

      for (int x = 0; x < randPhraseGuess[j].length();x++)
      {
          if (randPhraseGuess[j].at(x) != randPhrase[j].at(x))
          {
              cout <<"\""<< randPhrase[j].at(x)<<"\" ";
          }
      }

      cout <<"\n"<<"\n";

  }
}

