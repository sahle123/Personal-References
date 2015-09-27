#include<iostream>
#include<string>
using namespace std;

string get_string_name();

int main(int argc, char* args[])
{
  string file;
  file = get_string_name();
  cout << file << endl;
  return 0;
}

string get_string_name()
{
  string file_name;
  string file_extension = ".bmp"; 
  unsigned int i, j;

  cout << "Please provide a string :3" << endl;
  //getline(cin, file_name, '\n');
  cin >> file_name;
  cout << file_name << endl;

  j = 0;
  i = strlen(file_name.c_str());
  for(i = i - 4; i < strlen(file_name.c_str()); ++i)
    {
      if(file_name[i] != file_extension[j])
	{
	  file_name = file_name + file_extension;
	  i = strlen(file_name.c_str());
	}
      ++j;
    }
  return file_name;
}
