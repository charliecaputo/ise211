/*created by charlie caputo
Objectives:
Function 1:
    Declare an integer variable a and a pointer ptr that points to a.
    Modify the value of a using the pointer ptr.
    Print the address of a and the value of a through both direct access and pointer dereferencing.
Function 2:
    Declare an array of 5 integers.
    Use a pointer to access each element of the array, and print each element using pointer arithmetic.
    Modify each element of the array by adding 10 to each value using the pointer.
Function 3:
    Dynamically allocate an array of n integers, where n is provided by the user.
    Use a pointer to input values into the array from the user.
    Find and print the sum of the elements in the array using the pointer.
    Deallocate the memory using delete[] to avoid memory leaks.
*/

#include <iostream>

void func1(){
    int a = 10;                 // Initialize an integer 'a' with value 10
    int* ptr = &a;              // Declare a pointer 'ptr' and assign the address of 'a'
    *ptr = 12;                  // Dereference 'ptr' to change the value of 'a' to 12
    
    // Prints the address of 'a' via pointer and direct access, 
    // and prints the value of 'a' after dereferencing the pointer
    std::cout<< "address of a(pointer): " << ptr 
             << "\naddress of a(direct access): " << &a 
             << "\nvalue of a(dereferenced): " << *ptr 
             << "\nvalue of a(direct access): " << a << "\n";
}

void func2(){
    int arr[] = {6, 7, 8, 9, 10}; // Initialize an array of integers
    int* ptr = arr;               // Pointer 'ptr' points to the first element of the array
    for (int i = 0; i < 5; i++){  // Loop through the array
        std::cout << *ptr;        // Print the value at the current pointer location
        *ptr = *ptr + 10;         // Add 10 to the value at the current pointer location
        std::cout << " + 10 = " << *ptr << "\n"; // Print the updated value
        ptr++;                    // Increment the pointer to point to the next element in the array
    }
}

void func3(){
    int arr_size = 0;
    std::cout << "enter the size of the array: ";
    std::cin >> arr_size;                  // Get the size of the array from the user
    int* arr = new int[arr_size];          // Dynamically allocate memory for the array

    std::cout << "enter the numbers for the array and follow each number by pressing \"Enter\": ";
    for (int i = 0; i < arr_size; i++){    // Input elements into the array
        std::cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < arr_size; i++){    // Sum the array elements
        sum += *(arr + i);                 // Dereference the pointer to access array values
    }

    std::cout << "Sum of array elements: " << sum << "\n"; // Output the sum of the array
    delete[] arr;                          // Deallocate the memory used by the array
}

int main (){
    func1(); // Demonstrates pointer usage with a variable
    std::cout << "---------------------\n";
    func2(); // Demonstrates pointer arithmetic with arrays
    std::cout << "---------------------\n";
    func3(); // Demonstrates dynamic memory allocation and array summing
    return 0;
}
