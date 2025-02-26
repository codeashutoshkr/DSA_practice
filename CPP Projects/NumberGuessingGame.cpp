/*
Rules of the game :>
> The computer generates a random number between 1 to 100 and you need to guess the number
> If your guess is greater than the number by 10 or lower than the number by 10 - the system will output 'Cold'
> If your guess is within a + / - 10 range from the number, the system will output 'Hot'
> You have unlimited attempts.
*/

#include <iostream>
#include <cstdlib>  // this provide rand() and srand() functions where rand()  generates a pseudo-random integer in the range 0 to RAND_MAX,
                   // where RAND_MAX is a constant defined in <cstdlib> (usually 2,147,483,647, but it depends on your system) and srand()  Sets the seed for the random number generator.
                  // Without setting a seed, the sequence of random numbers will be the same every time you run the program.
#include <ctime> // Provides the time() function to get the current system time, which is used to initialize the random number generator.

int getRandomNumber() {        //to get random number
    return rand() % 100 + 1;  //rand() % (max - min + 1): Reduces the random number to a value in the range [0, max-min] and +min: Shifts the range to start at min
}

std::string giveHint(int number, int guess) {
    if (guess > (number + 10) || guess < (number - 10)) {
        return "Cold";
    } else if (number == guess) {
        return "Right";
    } else {
        return "Hot";
    }
}

// update the function 
void runGuess() {
    int secretNumber = getRandomNumber();
    int user_guess;
    std::string hint;

    while(true){  // to continue the game untill he guessed the right number
    std::cout << "Enter a number between 1 and 100: ";
    std::cin >> user_guess;
    hint = giveHint(secretNumber, user_guess);

    
    if (hint == "Right") {
        std::cout << "You guessed it Right!" << std::endl;
        break;
    }
     else {
        std::cout << hint << std::endl;
        std::cout<<"Guess again "<<std::endl;
    }
    
    } 
}

int main() {
    srand(time(0));  // Initialize random seed and time(0): Returns the current system time in seconds. 
                    // This ensures that the seed changes with each run of the program.
    runGuess();
    return 0;
}