/* closure2.cpp
*
*	Another closure example in C++11
*
*	Sahle "Nomad" Alturaigi
*	02/11/15
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	// This does nothing.
	auto leFwee = []() {};
	
	// Another example with more detail.
	auto fooBar = [] () -> void {cout << "Hello Computer." << endl; };

	return EXIT_SUCCESS;
}