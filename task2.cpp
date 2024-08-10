#include <iostream>


using namespace std;

void displayMenu() {
    cout << "\nSimple Calculator\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
}

float addition(float n1,float n2){
   float n3;
   n3 = n1 + n2;
   return n3;
}
float substraction(float n1,float n2){
    float n3;
    n3 = n1 - n2;
    return n3;
}
float multiplication(float n1,float n2){
    float n3;
    n3 = n1*n2;
    return n3;
}
float division(float n1, float n2){
    float n3;
    n3 =n1/n2;
    return n3;
}

int main() {
    float n1,n2;
   cout <<"Enter a 1st number:";
   cin>>n1;
   cout <<"Enter a 2nd number:";
   cin>>n2;
   int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
               cout << "addition is : "<< addition(n1,n2);
                break;
            case 2:
                cout << "substraction is : "<< substraction(n1,n2);
                break;
            case 3:
                cout << "multiplication is : "<< multiplication(n1,n2);
                break;
            case 4:
                cout << "division is : "<< division(n1,n2);
                break;
           
            }
    }

    return 0;
}
