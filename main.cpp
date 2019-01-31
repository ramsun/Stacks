/*
Ramamurthy Sundar
Fall 2018

main.cpp

Driver for Machine Problem 4.  This programs will showcase 
the usefullness of stacks as a data structure.

There are 3 operations this driver will perform.  First, it will reverse a
string using a stack and check to see whether the reverse is the same as
the original string.  Second, it will use stacks to convert a base 10
number into a number between base 2 and base 16 inclusive.  Third, it will
check to see whether the paranthesis in a text file are balanced.

All of the terminal communication is streamed to a text file.
*/

#include "class.h"

using namespace std;

//helper functions
//1. reverse a string with a stack
template <typename T>
string reverse_string(StudentStack<T> &stack, string inputstring) {
	
	//initial loop to create stack of inputstring
	int sz = inputstring.size();
	for (int i = 0; i < sz; i++) {
		stack.push(inputstring[i]);
	}
	//creating the string and popping from the stack
	for (int i = 0; i < sz; i++) {
		inputstring[i] = stack.front();
		stack.pop();
	}
	return inputstring;
}

//2. convert an input base ten number into a number of another base between 2 and 16
//outputs a string as the in order to account for hexidemical
template <typename T>
string multibaseOutput(StudentStack<T> &stack, int decimal, const int base) {
	
	int remainder;
	while (decimal != 0) {
		remainder = decimal % base;
		decimal /= base;
		stack.push(remainder);
	}
	
	//pop from the stack and push to the string, which will be converted to an int
	//creating the string and popping from the stack
	string solutionstring; char ASCII; int solution;
	int sz = stack.size();
	for (int i = 0; i < sz; i++) {
		//Case 1 - Base is 16
		if (base == 16) {
			//stack.front() > 9 and < 16
			if (stack.front() == 10) {
				ASCII = 'A';
				solutionstring.push_back(ASCII);
				stack.pop();
			}
			else if (stack.front() == 11) {
				ASCII = 'B';
				solutionstring.push_back(ASCII);
				stack.pop();
			}
			else if (stack.front() == 12) {
				ASCII = 'C';
				solutionstring.push_back(ASCII);
				stack.pop();
			}
			else if (stack.front() == 13) {
				ASCII = 'D';
				solutionstring.push_back(ASCII);
				stack.pop();
			}
			else if (stack.front() == 14) {
				ASCII = 'E';
				solutionstring.push_back(ASCII);
				stack.pop();
			}
			else if (stack.front() == 15) {
				ASCII = 'F';
				solutionstring.push_back(ASCII);
				stack.pop();
			}
			//stack.front() < 9
			else {
				ASCII = '0' + stack.front(); //convert int to ASCII charachter
				solutionstring.push_back(ASCII);
				stack.pop();
			}
		}
		//Case 2 - Base is not 16
		else {
			ASCII = '0' + stack.front(); //convert int to ASCII charachter
			solutionstring.push_back(ASCII);
			stack.pop();
		}
	}
	return solutionstring;
}

//3. tell whether the paranthesis of a text file are balanced
template <typename T>
bool are_paranthesis_balanced(StudentStack<T> &stack, string inputstring) {
	for (unsigned int i = 0; i < inputstring.size(); i++) {
		if (inputstring[i] == '(' || inputstring[i] == '{' || inputstring[i] == '[') {
			stack.push(inputstring[i]);
		}
		if (inputstring[i] == ')' || inputstring[i] == '}' || inputstring[i] == ']')
		{
			//right paranthesis without a left pair
			if (stack.isEmpty()) {
				return 0; 
			}
			/* Pop the top element from stack, if it is not a pair
			bracket of character then there is a mismatch.
			This will happen for expressions like {(}) */
			else if (!matching_pair(stack.front(), inputstring[i])) {
				return 0;
			}
			// pop from the stack if the pair is complete 
			stack.pop();
				
		}
	}
	//case 1: The stack was balanced
	if (stack.isEmpty()) return 1;
	//case 2: The stack is not ballanced;
	else return 0; 
}

//4. check whether a pair of paranthesis are matching
bool matching_pair(const char char1, const char char2) {
	if (char1 == '(' && char2 == ')')
		return 1;
	else if (char1 == '{' && char2 == '}')
		return 1;
	else if (char1 == '[' && char2 == ']')
	   return 1;
	else
	   return 0;
}

//main
int main() {

	//create file stream
	ofstream outfile;
	outfile.open("OutputFile.txt");

	//1. charachter reversal
	StudentStack<char> ForwardStack; 
	string inputString; string reverseString;
	cout << "Input a string in the form STRING1#STRING2 or quit to terminate: ";
	cin >> inputString;
	outfile << "Input a string in the form STRING1#STRING2 or quit to terminate: " << inputString;
	while (inputString != "quit") {
		reverseString = reverse_string(ForwardStack, inputString);
		//check to see whether the two stacks are the same and outputs to terminal
		if (inputString == reverseString) {
			cout << inputString << " matches the pattern" << endl << endl;
			outfile << "\n";
			outfile << inputString << " matches the pattern" << "\n" << "\n";
		}
		else {
			cout << inputString << " does not match the pattern" << endl << endl;
			outfile << "\n";
			outfile << inputString << " does not match the pattern" << "\n" << "\n";

		}
		//next round
		cout << "Input a string in the form STRING1#STRING2 or quit to terminate: ";
		cin >> inputString;       
		outfile << "Input a string in the form STRING1#STRING2 or quit to terminate: " << inputString;

	}
	
	//2. base converter
	cout << endl;
	outfile << "\n" << "\n";
	StudentStack<int> NewBaseStack;
	int decimal; int base;
	cout << "Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: ";
	cin >> decimal >> base;
	outfile << "Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: " << decimal << " " << base;
	while (decimal != 0 && base != 0) {
		string solution = multibaseOutput(NewBaseStack, decimal, base);
		cout << "\t" << decimal << " base " << base << " is " << solution << endl;
		outfile << "\n";
		outfile << "\t" << decimal << " base " << base << " is " << solution << "\n";
		cout << "Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: ";
		cin >> decimal >> base;
		outfile << "Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: " << decimal << " " << base;
	}

	//3. Check whether paranthesis are balanced in a text file
	cout << endl;
	outfile << "\n" << "\n";
	ifstream infile; string filename;
	StudentStack<char> ParanthesisStack;
	cout << "Enter the file name : ";
	cin >> filename;
	outfile << "Enter the file name : " << filename;
	infile.open(filename);
	string equation;
	while (!infile.eof()) {
		getline(infile, equation);
		if (!are_paranthesis_balanced(ParanthesisStack, equation)) {
			cout << "The symbols in " << filename << " are not balanced." << endl;
			outfile << "\n";
			outfile << "The symbols in " << filename << " are not balanced." << "\n";
		}
	}
	if (are_paranthesis_balanced(ParanthesisStack, equation)) {
		cout << "The symbols in " << filename << " are balanced." << endl;
		outfile << "\n";
		outfile << "The symbols in " << filename << " are balanced." << "\n";

	}

	outfile.close();
	return 0;
}
