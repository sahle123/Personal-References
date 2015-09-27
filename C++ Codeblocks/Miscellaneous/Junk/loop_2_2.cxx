// Description
// This will repeat a set of numbers over and over, like a 10 sided dice. Only
// that this one never repeats the same number twice.

// Directives:
#include<graphics.h>
#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;

// Global Constants:
const int N = 10;
const int S = 500;

bool QUIT = false;

//------------------------------------------------------------------------------
// Prototypes:
// This will take an array of intergers and will randomly print another
// interger onto the screen. However, there is a quirk to this loop. When
// an interger is printed, that interger is temporarily timed out from the
// repeater. This happens to up to 2 intergers, then the last timed out
// interger becomes valid again. This is much like the character voice repeaters
// in SC II.
void loop_2(int array[], size_t n);

void case_number(int k);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main( )
{
    int array_of_numbers[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    initwindow(S, S, "Loop run.", 50, 50, false);

    cout << "Press BACKSPACE to quit." << endl;

    while(true)
    {
	delay(10);
	
	if(QUIT)
	{
	    goto end_it;
	}

	loop_2(array_of_numbers, N);
    }

end_it:
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void case_number(int k)
{
    static int midx = getmaxx()/2;
    static int midy = getmaxy()/2;

    clearviewport();
    
    switch(k)
    {
    case 0: outtextxy(midx - 50, midy - 10, "Zero"); break;
    case 1: outtextxy(midx - 50, midy - 10, "One"); break;
    case 2: outtextxy(midx - 50, midy - 10, "Two"); break;
    case 3: outtextxy(midx - 50, midy - 10, "Three"); break;
    case 4: outtextxy(midx - 50, midy - 10, "Four"); break;
    case 5: outtextxy(midx - 50, midy - 10, "Five"); break;
    case 6: outtextxy(midx - 50, midy - 10, "Six"); break;
    case 7: outtextxy(midx - 50, midy - 10, "Seven"); break;
    case 8: outtextxy(midx - 50, midy - 10, "Eight"); break;
    case 9: outtextxy(midx - 50, midy - 10, "Nine"); break;

    case 10: QUIT = true; break; 
    }

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void loop_2(int array[], size_t n)
{
    int k = 0;          // temporary variable for random number.        
    static int i = 0; 
    
    if(getch() == 32)
    {
	k = (rand() % 9);
	
	while(k == i)
	{
	    k = (rand() % 9);
	}

	cout << k << endl;
	case_number(k);

	i = k;
    }
    else if(getch() == 8)
    {
	k = 10;

	case_number(k);
    }
    
}
//------------------------------------------------------------------------------
