#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
//stating that namespace will remain in STD
using namespace std;
void userinput();
void mean();
void fileinput();
void standarddeviation();
void fileoutput();
//These are the IO functions as well as the 2 calculation functions
int i;
float sum = 0.0, average, SDT = 0.0, SD = 0.0, num[4];
//All variable used in this project were created as global in order to ensure transferability between fuctions
string inputfile = "inMeanStd.dat";
string outputfile = "outMeanStd.dat";
//Strings were set up for the files in order to help reduce 
int main() {
	userinput();
	mean();
	cout << "The mean is " << average << endl;
	standarddeviation();
	cout << "The standard deviation is " << SD << endl;
	fileinput();
	mean();
	standarddeviation();
	fileoutput();
	return 0;
}
//All calculations were done within functions and called in main, with visual outputs being declared here
void userinput() {
	for (i = 0; i < 4; ++i)
	{
		cout << "Enter number here: ";
		cin >> num[i];
		sum += num[i];
	}
}
//This uses a loop and an array to store any 4 user input number
void mean() {
	average = 0;
	average = sum / 4;
}
//The mean of the user data
void standarddeviation() {
	SDT = 0.0;
	SD = 0.0;
	for (i = 0; i < 4; ++i) {
		SDT += pow(num[i] - average, 2);
	}
	SD = pow(SDT / 4, 0.5);
}
//The standard deviation of the user inputted data
void fileinput() {
	ifstream infile;
	infile.open(inputfile);
	sum = 0;
	if (!infile)
		cout << "Can't find file!";
	for (i = 0; i < 4; ++i) {
		infile >> num[i];
		sum += num[i];
	}
}
//The file is opened in this function and its values are stored into a seperate array
void fileoutput() {
	ofstream outfile;
	outfile.open(outputfile);

	outfile << "The mean is: " << average << endl << "The standard deviation is: " << SD;
}
//The output file is opened and the desired data is displayed inside