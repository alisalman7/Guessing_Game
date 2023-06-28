#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GuessingNumber
{
private:
    string name;
    int guessNumber;
    int randomNumber;
    int rangeNumber1;
    int rangeNumber2;
    int tryNumber;

public:
    GuessingNumber(string n = "", int th = 0, int r_num1 = 0, int r_num2 = 100, int t = 5)
    {
        name = n;
        guessNumber = th;
        rangeNumber1 = r_num1;
        rangeNumber2 = r_num2;
        tryNumber = t;
    }

    void SetName(string n)
    {
        name = n;
    }

    string GetName()
    {
        return name;
    }

    void SetGuessNumber(int number)
    {
        guessNumber = number;
    }

    int GetGuessNumber()
    {
        return guessNumber;
    }

    void ChoiceRangeNumbers(int r_num1, int r_num2)
    {
        rangeNumber1 = r_num1;
        rangeNumber2 = r_num2;
    }

    void RandomNumber()
    {
        srand(time(NULL));
        randomNumber = rangeNumber1 + (rand() % (rangeNumber2 - rangeNumber1 + 1));
    }

    void StartGame()
    {
        cout << "Welcome to the Guessing Number Game!" << endl;
        cout << "You have choseing a number between " << rangeNumber1 << " and " << rangeNumber2 << ". Can you guess it?" << endl;
        cout << "You have " << tryNumber << " attempts to find the number." << endl;

        for (int i = 1; i <= tryNumber; i++)
        {
            cout << "Attempt " << i << ": Enter your guess: ";
            cin >> guessNumber;

            if (guessNumber == randomNumber)
            {
                cout << "Congratulations! You guessed the correct number." << endl;
                return;
            }
            else if (guessNumber < randomNumber)
            {
                cout << "Too low." << endl;
            }
            else
            {
                cout << "Too high." << endl;
            }
        }

        cout << "Sorry, you have used all your attempts. The correct number was " << randomNumber << "." << endl;
    }
};

int main()
{
    string playerName;
    int rangeNum1, rangeNum2;
    int tryNum;

    cout << "Hello, lucky person!" << endl;
    cout << "Enter your name: ";
    cin>>playerName;

    cout << "Hello, " << playerName << "! Let's play the Guessing Number Game." << endl;

    cout << "Enter the range of numbers (start and end): ";
    cin >> rangeNum1 >> rangeNum2;

    cout << "Enter the number of attempts you want: ";
    cin >> tryNum;

    GuessingNumber game(playerName, 0, rangeNum1, rangeNum2, tryNum);
    game.RandomNumber();
    game.StartGame();

    cout << "Thank you for playing the Guessing Number Game. Goodbye!" << endl;

    return 0;
}
