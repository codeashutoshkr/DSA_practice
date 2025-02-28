#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

// Function declarations
void userChoice(int choice);
void digital_clock();
void countdown_timer(int seconds);

void userChoice(int choice) {
    if (choice == 1) {
        digital_clock();
    } else if (choice == 2) {
        int seconds;
        std::cout << "Enter the number of seconds to countdown: ";
        std::cin >> seconds;
        countdown_timer(seconds);
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

void digital_clock() {
    // Displays a digital clock
    while (true) {
        // Get the current time
        std::time_t now = std::time(nullptr);
        std::tm* local_time = std::localtime(&now);

        // Print the current time
        std::cout << "\rCurrent Time: " 
                  << std::put_time(local_time, "%H:%M:%S") 
                  << std::flush;

        // Pause for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// update the function 
void countdown_timer(int seconds) {
    std::cout << "Countdown Timer started!" << std::endl;
    
    //update this function from here 
        while (seconds > 0) {
        std::cout << "\rTime remaining: " << seconds << " seconds" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds--;
    }
    std::cout << "\nTime's up!" << std::endl;
}

int main() {
    while (true) {
        int choice;
        std::cout << "Choose an option (1: Digital Clock, 2: Countdown Timer): ";
        std::cin >> choice;
        userChoice(choice);
    }

    return 0;
}