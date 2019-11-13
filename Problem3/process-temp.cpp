
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define file_path "/home/debian/Exam/Problem2/"


int main()
{
	cout << endl;
	cout << "Taking tempuratures from file and finding average" << endl;
		
	std::fstream fs;
	string line;
	string filename = "temperatures.txt";
	cout<<"File Path: "<<file_path+filename<<endl;
	fs.open((file_path + filename).c_str(), std::fstream::in);
        double i = 0;
	double a;
	double b = 0;
	double avg;
	while(std::getline(fs, line))
	{
 	  a = std::stod(line);
          i = i + 1;
	  b = a + b;
	}
	avg = b/i;
        cout<<"The average temperature is: "<<avg<<" Celsius"<<endl;
	fs.close();
		
}
