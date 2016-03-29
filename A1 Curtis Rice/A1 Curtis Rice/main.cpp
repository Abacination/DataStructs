#include "Array.h"
#include "Exception.h"


#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
	using std::cout;
	using std::endl;

#include <string>
	using std::string;

int main()
{

	cout << "-----------------------------" << endl;
	cout << "ARRAY CLASS TESTING INTS" << endl;
	cout << "-----------------------------" << endl;

	cout << "Testing Default Constructor (ar1)" << endl;
	Array<int> ar1;
	
	
	cout << "Testing Constructor with 2 arguments (ar2 size 10 starting index 100)" << endl;
	Array<int> ar2(10, 100);

	cout << "Filling Array (ar2)" << endl;
	for (int i(0); i < 10; ++i)
		ar2[i + ar2.getStartIndex()] = i;

	cout << "Displaying Array (ar2)" << endl;
	for (int i(0); i < 10; ++i)
		cout << ar2[i + ar2.getStartIndex()] << endl;

	cout << "Testing Copy Constructor (ar3 with ar2)" << endl;
	Array<int> ar3(ar2);

	cout << "Testing operator = (ar2 to ar1)" << endl;
	ar1 = ar2;

	cout << "Displaying ar1" << endl;
	for (int i(0); i < 10; ++i)
		cout << ar1[i + ar1.getStartIndex()] << endl;

	cout << "Setting length to 0 (ar2)" << endl;
	ar2.setLength(0);

	
	cout << "Making exception by trying to access element of 0 element array (ar2)" << endl;
	try 
	{
		cout << ar2[100];
	}
	catch(Exception e)
	{
		cout << e << endl;
	}

	cout << "Testing exception class with nullptr" << endl;
	Exception ex(nullptr);
		cout << ex << endl;
	

	cout << "Setting length to 5 (ar2)" << endl;
	ar2.setLength(5);
	cout << "Setting start index to -5" << endl;
	ar2.setStartIndex(-5);

	cout << "Filling ar2" << endl;
	for (int i(0); i < ar2.getLength(); ++i)
		ar2[i + ar2.getStartIndex()] = i;

	cout << "Displaying ar2" << endl;
	for (int i(0); i < ar2.getLength(); ++i)
		cout << ar2[i + ar2.getStartIndex()] << endl;

	cout << "Accessing element above array bounds" << endl;
	try
	{
		cout << ar2[100];
	}
	catch (Exception e)
	{
		cout << e << endl;
	}


	cout << "Accessing element below array bounds" << endl;
	try
	{
		cout << ar2[-10];
	}
	catch (Exception e)
	{
		cout << e << endl;
	}









	cout << "-----------------------------" << endl;
	cout << "ARRAY CLASS TESTING STRINGS" << endl;
	cout << "-----------------------------" << endl;

	string hi = "HI";

	cout << "Testing Default Constructor (ar1s)" << endl;
	Array<string> ar1s;


	cout << "Testing Constructor with 2 arguments (ar2s size 10 starting index 100)" << endl;
	Array<string> ar2s(10, 100);


	cout << "Filling Array (ar2s)" << endl;
	for (int i(0); i < 10; ++i)
		ar2s[i + ar2s.getStartIndex()] = hi;

	cout << "Displaying Array (ar2s)" << endl;
	for (int i(0); i < 10; ++i)
		cout << ar2s[i + ar2s.getStartIndex()] << endl;

	cout << "Testing Copy Constructor (ar3s with ar2s)" << endl;
	Array<string> ar3s(ar2s);

	cout << "Testing operator = (ar2s to ar1s)" << endl;
	ar1s = ar2s;

	cout << "Displaying ar1s" << endl;
	for (int i(0); i < 10; ++i)
		cout << ar1s[i + ar1s.getStartIndex()] << endl;

	cout << "Setting length to 0 (ar2s)" << endl;
	ar2s.setLength(0);


	cout << "Making exception by trying to access element of 0 element array (ar2s)" << endl;
	try
	{
		cout << ar2s[100];
	}
	catch (Exception e)
	{
		cout << e << endl;
	}


	cout << "Setting length to 5 (ar2s)" << endl;
	ar2s.setLength(5);
	cout << "Setting start index to -5" << endl;
	ar2s.setStartIndex(-5);

	cout << "Filling ar2s" << endl;
	for (int i(0); i < ar2s.getLength(); ++i)
		ar2s[i + ar2s.getStartIndex()] = hi;

	cout << "Displaying ar2s" << endl;
	for (int i(0); i < ar2s.getLength(); ++i)
		cout << ar2s[i + ar2s.getStartIndex()] << endl;

	cout << "Accessing element above array bounds" << endl;
	try
	{
		cout << ar2s[100];
	}
	catch (Exception e)
	{
		cout << e << endl;
	}

	cout << "Accessing element below array bounds" << endl;
	try
	{
		cout << ar2s[-10];
	}
	catch (Exception e)
	{
		cout << e << endl;
	}

	_CrtDumpMemoryLeaks();

	cout << "---------------------------------" << endl;
	cout << "EXCEPTION CLASS TESTING" << endl;
	cout << "---------------------------------" << endl;
	
	cout << "Testing default constructor (ex1)" << endl;
	Exception ex1;

	cout << "Testing 1 arg constructor (ex2)" << endl;
	Exception ex2("Test message");
	cout << "Displaying ex2" << endl;
	cout << ex2 << endl;

	cout << "Testing copy constructor (ex2 to ex3)" << endl;
	Exception ex3(ex2);
	
	cout << "Displaying ex3 with get message" << endl;
	cout << ex3.getMessage() << endl;

	cout << "Testing Operator = (ex3 to ex1)" << endl;
	ex1 = ex3;

	cout << "Displaying ex1" << endl;
	cout << ex1 << endl;

	cout << "Setting message in ex1" << endl;
	ex1.setMessage("Message Changed");
	cout << "Displaying new message for ex1" << endl;
	cout << ex1 << endl;

	

	return 0;
}