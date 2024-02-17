#include<iostream>
#include<windows.h>
using namespace std;

int add(int num1, int num2) {
    cout << "\t\t\tThe sum of " << num1 << " + " << num2 << " is: ";
    return num1 + num2;
}
int sub(int num1, int num2) {
    cout << "\t\t\tThe subtraction of " << num1 << " - " << num2 << " is: ";
    return num1 - num2;
}
int mult(int num1, int num2) {
    cout << "\t\t\tThe multiplication of " << num1 << " * " << num2 << " is: ";
    return num1 * num2;
}
float divi(float num1, float num2) {
    if (num2 != 0) {
        cout << "\t\t\tThe division of " << num1 << " / " << num2 << " is: ";
        return num1 / num2;
    } else {
        cout << "\t\t\tError: Division by zero!" << endl;
        return 0;
    }
}
int modlu(int num1, int num2) {
    cout << "\t\t\tThe remainder of " << num1 << " % " << num2 << " is: ";
    return num1 % num2;
}
int main() {
		 system("color 71");
	cout<<"\t\t\t\t\tSimple Calculator"<<endl;
    char choice;
    do {
        int num1, num2;
		 float result;
        char op;
        cout << "\t\t\tEnter 1st number: ";
        cin >> num1;
        cout << "\t\t\tEnter any operator: ";
        cin >> op;
        cout << "\t\t\tEnter 2nd Number: ";
        cin >> num2;
        if (op == '+') {
            result = add(num1, num2);
        } else if (op == '-') {
            result = sub(num1, num2);
        } else if (op == '*') {
            result = mult(num1, num2);
        } else if (op == '/') {
            result = divi(num1, num2);
        } else if (op == '%') {
            result = modlu(num1, num2);
        } else {
            cout << "Invalid operator" << endl;
            result = 0;
        }
        cout << result << endl;
        cout << "\t\t\tDo you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\t\t\tCalculator closed." << endl;

    return 0;
}

