#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
//stating that namespace will remain in STD
using namespace std;
float userinput();
float means();
float standarddeviationuser();
//First three functions are used for user calculated population
float fileinput();
float mean2();
float standarddeviation();
float fileoutput();
//These 4 functions are for the file IO population
int i, j;
float sum = 0.0, average, SDT = 0.0, SD, num[4], sum2 = 0.0, average2, SDT2 = 0.0, SD2, Num[4];
//All variable used in this project were created as global in order to ensure transferability between fuctions
string inputfile = "inMeanStd.dat";
string outputfile = "outMeanStd.dat";
//Strings were set up for the files in order to help reduce 
int main() {
	userinput();
	means();
	cout << "The mean is " << average << endl;
	standarddeviationuser();
	cout << "The standard deviation is " << SD << endl;
	fileinput();
	mean2();
	standarddeviation();
	fileoutput();
	return 0;
}
//All calculations were done within functions and called in main, with visual outputs being declared here
float userinput() {
	for (i = 0; i < 4; ++i)
	{
		cout << "Enter number here: ";
		cin >> num[i];
		sum += num[i];
	}
	return 0;
}
//This uses a loop and an array to store any 4 user input number
float means() {
	average = sum / 4;
	return 0;
}
//The mean of the user data
float mean2() {
	average2 = sum2 / 4;
	return 0;
}
//The mean of the file data
float standarddeviationuser() {
	for (i = 0; i < 4; ++i) {
		SDT += pow(num[i] - average, 2);
	}
	SD = pow(SDT / 4, 0.5);
	return 0;
}
//The standard deviation of the user inputted data
float fileinput() {
	ifstream infile;
	infile.open(inputfile);
	if (!infile)
		cout << "Can't find file!";
	for (j = 0; j < 4; ++j) {
		infile >> Num[j];
		sum2 += Num[j];
	}
	return 0;
}
//The file is opened in this function and its values are stored into a seperate array
float fileoutput() {
	ofstream outfile;
	outfile.open(outputfile);

	outfile << "The mean is: " << average2 << endl << "The standard deviation is: " << SD2;
	return 0;
}
//The output file is opened and the desired data is displayed inside
float standarddeviation() {
	for (j = 0; j < 4; ++j) {
		SDT2 += pow(Num[j] - average2, 2);
	}
	SD2 = pow(SDT2 / 4, 0.5);
	return 0;
}
//The standard devaition of the file data is calculated here