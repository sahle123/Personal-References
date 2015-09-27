// Test prorgam to test line class
// Written by Shivakant Mishra
// Last Update: February 17, 2012

#include <iostream>
#include <cstdlib>
#include "point.h"
#include "line.h"
using namespace std;


int main( )
{
    point p1(0, 0), p2(0, 1), p3(1, 0), p4(3.9, -2.8), p5(-1.8, 7.2), p6(1, 1);
    line l1, l2(p4), l3(p4, p5), l4(p1, p2), l5(p2, p1), l6(p2, p6), l7(p6, p3);

    cout << "l1 : " << l1 << endl;
    cout << "l2 : " << l2 << endl;
    cout << "l3 : " << l3 << endl;
    cout << "l4 : " << l4 << endl;
    cout << "l5 : " << l5 << endl;
    cout << "l6 : " << l6 << endl;
    cout << "l7 : " << l7 << endl;

    line l8(l3);
    cout << "l3 : " << l3 << endl;
    cout << "l8 : " << l8 << endl;

    cout << "l1 slope = " << l1.slope( ) << endl;
    cout << "l2 slope = " << l2.slope( ) << endl;
    cout << "l3 slope = " << l3.slope( ) << endl;
    cout << "l6 slope = " << l6.slope( ) << endl;
    cout << "l8 slope = " << l8.slope( ) << endl;

    point p7(10.0, 0), p8(12.0, 0);
    line l9(p7, p8);

    if (l1 == l9) cout << "l1 and l9 are equal" << endl;
    else cout << "l1 and l9 are not equal" << endl;
    if (l3 == l6) cout << "l3 and l6 are equal" << endl;
    else cout << "l3 and l6 are not equal" << endl;

    line l10 = l3;
    if (l10 == l3) cout << "l3 and l10 are equal" << endl;
    else cout << "l3 and l10 are not equal" << endl;
    if (l10 == l6) cout << "l10 and l6 are equal" << endl;
    else cout << "l10 and l6 are not equal" << endl;

    l1.reflect_x( );
    cout << "l1 : " << l1 << endl;
    l1.reflect_y( );
    cout << "l1 : " << l1 << endl;

    cout << "l3 : " << l3 << endl;
    l3.reflect_x( );
    cout << "l3 : " << l3 << endl;
    l3.reflect_y( );
    cout << "l3 : " << l3 << endl;


    l1.translate(5, 6.3);
    cout << "l1 : " << l1 << endl;

    cin >> l1;
    cout << "l1 = " << l1 << endl;
    cin >> l2;
    cout << "l2 = " << l2 << endl;
    cin >> l3;
    cout << "l3 = " << l3 << endl;

    return EXIT_SUCCESS;
}

