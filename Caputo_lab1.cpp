#include <iostream>
/* Creator: Charlie Caputo
    purpose: Write a C program that takes a user’s name and
        age as input and prints a personalized greeting.
    Challenge: Modify the program to ensure that the name string contains 
        only alphabetic characters, prompting re-entry if the validation 
        fails.
*/

int main (){
    std::string name; //initalize name variable
    int age;//initalize age variable
    bool valid = false;//initialize variable to check validity of entered name
    //ask for name and save input
    std::cout << "please enter a name: ";
    std::getline(std::cin, name);
    //check if name is valid (letter or space)
    while (!valid){
        for (int i = 0; i < name.length() ; ){
            if (isalpha(name[i]) or isspace(name[i])){
                //if letter is valid keep valid true to exit loop and intcrease iterator
                valid = true; 
                i++;
            }else{
                //else set valid to false to rerun while loop and set iterator to 0
                std::cout << "please enter a VALID name: ";
                std::getline(std::cin, name);
                valid = false;
                i = 0 ;
            }
        }   
    }

    //ask for age and save answer
    std::cout<< "\n enter your age: ";
    std::cin>> age;

    //check if they are old enough for beer(personalized message part)
    if (age >= 21 ){
        std::cout<< "Hello "<< name << " would you like a beer?";
    }else{
        std::cout<< "Hello "<< name << " would you like a water?";
    }

    return 0;
}