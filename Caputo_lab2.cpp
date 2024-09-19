/* Code Created By: Charlie Caputo
    Task: Create a simple calculator that allows continuous operations until the user decides to exit
    Challenge: Add error handling to manage non-numeric inputs and division by zero
*/

#include <iostream>
#include <limits>  // For std::numeric_limits

// Function definitions
// Function to perform addition and print the result
void add(double a, double b) {
    std::cout << "Result: " << (a + b) << "\n";
}

// Function to perform subtraction and print the result
void sub(double a, double b) {
    std::cout << "Result: " << (a - b) << "\n";
}

// Function to perform multiplication and print the result
void mult(double a, double b) {
    std::cout << "Result: " << (a * b) << "\n";
}

// Function to perform division and print the result
void div(double a, double b) {
    std::cout << "Result: " << (a / b) << "\n";
}

int main() {
    char operation; // Variable to store the user's chosen operation
    double num1, num2; // Variables to store the numbers for the operation
    bool validInput = false; // Flag to indicate if the input was valid

    // Loop to allow continuous operations until the user decides to exit
    while (!validInput || operation != 'q') {
        validInput = false; // Reset validInput at the beginning of each loop iteration

        // Display menu of available operations
        std::cout << "Simple Calculator\n";
        std::cout << "Choose an operation:\n";
        std::cout << " + : Addition\n";
        std::cout << " - : Subtraction\n";
        std::cout << " * : Multiplication\n";
        std::cout << " / : Division\n";
        std::cout << " q : Quit\n";
        std::cout << "Enter operation: ";
        std::cin >> operation;

        // Check if user wants to quit
        if (operation == 'q') {
            std::cout << "Exiting the calculator. Goodbye!\n";
            break; // Exit the loop and end the program
        }

        // Get numbers from the user
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        // Validate numeric input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            std::cout << "Invalid input. Please enter numeric values.\n";
            continue; // Skip to the next iteration of the loop
        }

        // Perform the chosen operation using if-else statements
        if (operation == '+') { // Addition
            add(num1, num2);
            validInput = true; // Mark input as valid
        } else if (operation == '-') { // Subtraction
            sub(num1, num2);
            validInput = true; // Mark input as valid
        } else if (operation == '*') { // Multiplication
            mult(num1, num2);
            validInput = true; // Mark input as valid
        } else if (operation == '/') { // Division
            if (num2 != 0) { // Check for division by zero
                div(num1, num2);
            } else {
                std::cout << "Error: Cannot divide by zero.\n"; // Handle division by zero error
            }
            validInput = true; // Mark input as valid
        } else { // Handle invalid operation
            std::cout << "Invalid operation. Please try again.\n";
        }

        // Print a separator for readability
        std::cout << "---------------- \n";
    }
    return 0;
}