#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    //set a random value for answer
    srand((unsigned int)time(NULL));
    int answer = 1 + rand() % 100;

    int attempts = 10;//Can play for 5 times

    cout << "GUESS THE NUMBER (1 ~ 100)" << endl;
    cout << "You have only 10 attempts" << endl;

    //User input
    cout << "Enter a value: ";
    int num;
    cin >> num;
    attempts--;

    while (attempts > 0){
        if (num < answer) {
            cout << "Too small, try again." << endl;
            cout << "Left " << attempts << " attempts." << endl;
            cout << "Enter a value: ";
            cin >> num;

            attempts--;
            
        }
        else if(num > answer){
            cout << "Too large, try again." << endl;
            cout << "Left " << attempts << " attempts." << endl;
            cout << "Enter a value: ";
            cin >> num;

            attempts--; 
            
        }
        else{
            cout << "You win" << endl;
            return 0;
        }
    }

    //when all attempts used, the game end
    cout << "You lose." << endl;
    cout << "Correct Answer: " << answer << endl;
    return 0;
}