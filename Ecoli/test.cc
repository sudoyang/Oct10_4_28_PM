/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  test
 *
 *        Version:  1.0
 *        Created:  10/10/2012 00:43:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang YANG (http://sites.google.com/site/yangslittlesite/), uk0052003@gmail.com
 *        Company:  University of Pittsburgh
 *
 * =====================================================================================
 */


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()  {


/*
	ofstream ofile;

	for(int i=1; i < 10; i++) {


		ofile.open("file"+i, ios::out);
		ofile.close();
	}

	*/

	std::string s = std::to_string(42);
	s=s+" add";
	cout << s << endl;
/*  
	char file[30];
	for(int m=0; m<10; m++) {
		sprintf(file, "%d.txt", m);
		if(fopen(file, "at+") == NULL) {
			printf("error");
			return 1;
		}
	} */
		return 0;


}
