#include <iostream>
#include <stdlib.h>
#include<ctime>
using namespace std;

// This function should return the operation (or 'e' for exit)
// returned values: either '+', '*', or 'e'
// if user enters something else, you ignore that and asks for new valid input
char askUserToChooseOperation() {
	char y;
	while (1) {
		cout << " Enter the operation  '*' , '+' OR 'e' to to exit : ";
		cin >> y;
		if (y != '+' && y != '*' && y != 'e');
		else
		{
			return y;
		}
	}
}

// This function should return the numbering system (or 'e' for exit)
// returned values:
// 1: for binary
// 2: for decimal
// if user enters something else, you ignore that and ask for new valid input
int askUserToEnterNumberingSystem() {

	int y;
	while (1) {
		cout << " Enter the numbering system " << endl;
		cout << " 1: for binary " << endl << " 2: for decimal" << endl;
		cout << " Enter your choice : ";
		cin >> y;
		if (y != 1 && y != 2 && y != 3);
		else {
			return y;
		}
	}
}

// This function should receives the numbering system (either 1 or 2) and returns:
// a. a number composing of only 0s and 1s (binary number) if the received numbering system is 1
// b. a positive number if the received numbering system is 2
// if user enters something else, you ignore that and ask for new valid input
long convert(int arr[]) {
	long cnt = 0;
	int num = 1000;
	for (int i = 0; i < 4; i++) {
		cnt += arr[i] * num;
		num /= 10;
	}
	return cnt;
}
long chooseNumberRandomly(int numsys) {
	long x;
	while (1) {


		if (numsys == 1) {
			int y[4];
			for (int i = 0; i < 4; i++) {
				y[i] = (rand());
				y[i] = y[i] % 2;
			}
			x = convert(y);
			return x;
		}
		else if (numsys == 2) {

			x = rand() % 30;
			return x;

		}
		else {
			cout << " invalid numsys try another time " << endl;
			cin >> numsys;

		}
	}
}

// Here the function receives the operation, numbering system and the random numbers.
// Then it prints the equation for the user, asks user to enter the result, and finally returns
// the result
long askUserToEnterResult(char op, int numsys, long num1, long num2) {
	cout << " The Equation. is :" << num1 << " " << op << " " << num2 << endl;
	cout << " numbersys is : " << numsys << endl;
	long result;
	cout << " Enter your answer : ";
	cin >> result;
	return result;
}

// The function receives the operation, numbering system, the random numbers, and the result.
// Then it returns wehther the result is correct (true) or incorrect (false)
long converttodecimal(long num) {
	
	long x = num;
	int cnt = 0;
	long y = 0;
	
	while (x != 0) {
		y += x % 10 * pow(2, cnt++);
		x = x / 10;
	}
	;
	return y;
}
bool checkUserResult(char op, int  numsys, long num1, long num2, long result) {
	if (numsys == 2) {
		if (op == '*'){
			if (num1 * num2 == result)return true;
		}
		else 	{
			if (num1 + num2 == result)return true;
		}
	}
	else {
		if (op == '+') {
			int n1 = converttodecimal(num1);
			int n2 = converttodecimal(num2);
			int res = converttodecimal(result);
			if (n1 + n2 == res)return true;
		}
		else {
			int n1 = converttodecimal(num1);
			int n2 = converttodecimal(num2);
			int res = converttodecimal(result);
			if (n1 * n2 == res)return true;
		}
	}
	return false;
}

int main()
{

	cout << "\n\n\t *** Welcome To The Number Game ***  \n\n";
	// Here you might need to create arrays to store the components of the arithmetic
	// equations
	bool gameFinished = false;
	int i = 0;
	bool arrcheck[100];
	long arrnum1[100];
	long arrnum2[100];
	long arrresult[100];
	char arrop[100];
	int arrsys[100];

	short gradeT = 0, grade = 0;

	while (!gameFinished)
	{
		char operation = askUserToChooseOperation(); cout << endl;

		if (operation == 'e')
			break;


		int numSystem = askUserToEnterNumberingSystem();  cout << endl;
		long number1 = chooseNumberRandomly(numSystem);
		long number2 = chooseNumberRandomly(numSystem);

		long result = askUserToEnterResult(operation,
			numSystem,
			number1, number2);

		bool isResultTrue = checkUserResult(operation,
			numSystem,
			number1, number2,
			result);
		arrcheck[i] = isResultTrue;
		arrnum1[i] = number1;
		arrnum2[i] = number2;
		arrresult[i] = result;
		arrop[i] = operation;
		arrsys[i] = numSystem;
		i++;

		// Here you might need to call a new funtion to
		// store the arithematic equations in the arrays
		cout << "--------------------------------------" << endl << endl;

	}

	cout << " Game ended, The results are:" << endl;
	for (int j = 0; j < i; j++) {
		if (arrsys[j] == 1)cout << " (Binary)    ";
		else cout << " (Decimal)    ";
		cout << arrnum1[j] << " " << arrop[j] << " " << arrnum2[j] << " " << " = " << arrresult[j] << "     ";
		
		if (arrcheck[j]){
			cout << "(True)" << endl;
			gradeT++;
		}
		
		else cout << "(False)" << endl;
		
		cout << "--------------------------------------" << endl;

		grade++;
	}
	int finalGrade = gradeT / grade;
	cout << " Your grade is:" << gradeT << "/" << grade;
	// call a function here to print the results as follows:

	///////////////////////////////////////////////////////
	//	(Decimal)	12 + 13 = 20		(FALSE)
	//	(Decimal)	1 + 7 = 8			(True)
	//	(Binary)	110 + 111 = 1101	(True)
	//	Your grade is: 2/3
	///////////////////////////////////////////////////////
	cout << endl << endl;
	return 0;
}