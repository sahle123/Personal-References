/*
 *   Example for a Ternary statement. A short-hand way for an if-else statement.
 *   
 *   Sahle "Nomad" Alturaigi
 *   Nov. 27th, 2012
 */

#include <iostream>
#include <cstdlib>

using namespace std;

template<class Data>
Data ternary_statement(Data &added_value, bool &is_true);

int main(int args, char *argv[])
{
  int value;
  bool bBool;

  cin >> value >> bBool;
  value = ternary_statement(value, bBool);
  cout << "Result was " << bBool << " and the value is: " << value << endl;

  return EXIT_SUCCESS; // For Prof. Main
}

template<class Data>
Data ternary_statement(Data &added_value, bool &is_true)
{
  Data final_ans;

  final_ans = (is_true) ? added_value : -added_value;

  /*
   * The above statement is exactly the same as:
   * if(is_true)
   *      final_ans = added_value;
   * else
   *      final_ans = -added_value;
   *
   */

  return final_ans;
}
