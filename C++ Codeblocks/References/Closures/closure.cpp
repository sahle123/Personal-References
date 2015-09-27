/*	closure.cpp
*	
*	Example code for how to use closures in C++11
*	
*	Sahle "Nomad" Alturaigi
*	02/11/15
*
*	Just in case you forgot, be sure to add the -std=c++11 
*	flag in the compile command.
*	i.e. g++ -Wall -std=c++1 closure.cpp -o closure
*
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	string theString = "Hello World";

	// The auto keyword automatically determines the return type
	// Also, the format for a closure is:
	// auto func_name = [captures](parameters) -> return_type{ //code; };
	auto func = [](string leString) { cout << leString << endl; };
	func(theString);

	return 0;
}