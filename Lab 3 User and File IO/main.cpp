#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
float userinput();
float means();
float standarddeviationuser();
float fileinput();
float fileoutput();
float standarddeviation();
float mean2();
int i, j;
float sum = 0.0, average, SDT = 0.0, SD, num[4], sum2 = 0.0, average2, SDT2 = 0.0, SD2, Num[4];

string inputfile = "inMeanStd.dat";
string outputfile = "outMeanStd.dat";

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
float userinput() {
	for (i = 0; i < 4; ++i)
	{
		cout << "Enter number here: ";
		cin >> num[i];
		sum += num[i];
	}
	return 0;
}
float means() {
	average = sum / 4;
	return 0;
}
float mean2() {
	average2 = sum2 / 4;
	return 0;
}
float standarddeviationuser() {
	for (i = 0; i < 4; ++i) {
		SDT += pow(num[i] - average, 2);
	}
	SD = pow(SDT / 4, 0.5);
	return 0;
}
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
float fileoutput() {
	ofstream outfile;
	outfile.open(outputfile);

	outfile << "The mean is: " << average2 << endl << "The standard deviation is: " << SD2;
	return 0;
}
float standarddeviation() {
	for (j = 0; j < 4; ++j) {
		SDT2 += pow(Num[j] - average2, 2);
	}
	SD2 = pow(SDT2 / 4, 0.5);
	return 0;
}