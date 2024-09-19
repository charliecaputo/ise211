/*created by: Charlie Caputo
    Objective: Learn to manipulate arrays and strings.
    Task: Write a program that sorts a user-provided list of names alphabetically.
    Challenge: Extend the program to remove duplicates from the list before sorting.
*/
#include <iostream>

//function to sort names alphabetically
void sortNames(std::string names[], int total_names){
    std::string temp;
    std::string sorted_names[total_names] = {};
    int l = 0;
    //bubble sorter shown in class with my own variables
    for (int i = 0; i < total_names; i++){
        for (int n = 0; n < total_names-i-1; n++){
            if (names[n]>names[n+1]){
                temp = names[n];
                names[n] = names[n+1];
                names[n+1] = temp;
            }
        }
    }
    //tell the user what is about to be printed
    std::cout << "the names in alphabetical order with no repeats is: \n";
    //for loop to sort through and check for repeated names after 
    //alphabetic sort and stores them in a new array
    for(int z = 0; z < total_names; z++){
        if (names[z] == names[z-1]){
            continue;
        }else{
            sorted_names[l] = names[z];
            l++; 
        }
    }
    //prints the sorted names
    for (int a = 0; a < l; a++){
        std::cout<<sorted_names[a] << "\n";
    }
}

int main (){
    //create necessary variables  
    std::string name;
    int itr = 0;
    int total_names = 0;
    //ask for the amount of names that will be entered
    std::cout << "enter the number of names you would like to enter: ";
    std::cin >> total_names;
    //initalize array to size specified
    std::string names[total_names] = {};
    //ask for list of names and let user know how to end the list
    std::cout << "please enter a list of names. press enter after each name and q to quit: ";
    //allow user to enter names and stop entering names with wile loop
    while (true){
        std::cin>> name;
        if (name == "q"){
            break;
        }else{
            names[itr] = name;
            itr++;
        }
    }
    //send names array to sort names function
    sortNames(names, total_names);

    return 0;
}