/*
 *	Sahle "Nomad" Alturaigi
 *
 *		Prove Him wrong by showing him some of your personal projects
 *
 *	4/21/14
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>

// using namespace std;

// Prototypes
bool check_answer(std::string param_answer);

int main(int argc, char* argv[])
{
	std::string answer = "";
	bool proved_wrong = false;
	
	std::cout << "Prove Him wrong. Have you started or completed any projects yet? Yes or no? "
    << std::endl;
	getline(std::cin, answer);
	
	proved_wrong = check_answer(answer);
	
	if(proved_wrong)
		std::cout << "\nGood job! As you should! ";
	else
		std::cout << "\nYou should be working harder! ";
	
	std::cin.get();
	
	return EXIT_SUCCESS;
}

bool check_answer(std::string param_answer)
{
	// Setting up enum (for practice)
	enum validAnswer {yes, no, notsure};
	validAnswer response;
	
	if((param_answer == "Yes") || (param_answer == "yes"))
		response = yes;
	else if ((param_answer == "No") || (param_answer == "no"))
		response = no;
	else
		response = notsure;
    
	// check with switch
	switch(response)
	{
        case yes:
            return true;
            break;
        case no:
            return false;
            break;
        default:
            return false;
            break;
	}
	
	// Should never reach here.
	return false;
}