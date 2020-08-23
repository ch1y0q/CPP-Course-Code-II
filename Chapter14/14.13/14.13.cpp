#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#define TO_STR(x) #x			// convert x to "x"

using namespace std;


int main()
{
	// output without file processing
	cout << "Output without file processing: " << endl;
	#define COUNTER(TYPE) cout<<  "sizeof "<< left << setw(18) << TO_STR(TYPE) << right << setw(3) << sizeof(TYPE)<<endl;	// output format
	#include "14.13.def"			// include macro definition file containing all the types

	fstream outdata("datasize.dat",ios::out|ios::in|ios::binary);
	if (!outdata)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	} // end if
	int t;
	#define COUNTER(TYPE) t = sizeof(TYPE);outdata.write(reinterpret_cast<const char*> (&t), sizeof(int));	// output format
	#include "14.13.def"			// include macro definition file containing all the types

	// exit program if fstream cannot open file
	fstream f("sizeof.txt", ios::out);
	if (!f)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	} // end if
	outdata.clear();
	outdata.seekg(0);

	#define COUNTER(TYPE) outdata.read(reinterpret_cast<char*> (&t), sizeof(int));f <<  "sizeof "<< left << setw(18) << TO_STR(TYPE) << right << setw(3) << t <<endl;	// output format
	#include "14.13.def"			// include macro definition file containing all the types

	outdata.close();
	f.close();
	return 0;
}