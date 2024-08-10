#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    // Set a large upper limit (practically infinite for this purpose)
    const long long int MAX_NUMBER = numeric_limits<long long int>::max();

    srand(time(0)); // Seed the random number generator

    // Generate a random number within the large range
    long long int randomNumber = rand() % MAX_NUMBER;

    long long int guess;

    cout << "Guess a number between 0 and " << MAX_NUMBER << endl;

    while (true) {
        cin >> guess;

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the number." << endl;
            break;
        } else if (guess < randomNumber) {
            cout << "Too low. Try again." << endl;
        } else {
            cout << "Too high. Try again." << endl;
        }
    }

    return 0;
}


