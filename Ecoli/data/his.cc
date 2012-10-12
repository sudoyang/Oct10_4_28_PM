/*
 * =====================================================================================
 *
 *       Filename:  his.cc
 *
 *    Description:  Draw histogram based on the final data
 *
 *        Version:  1.0
 *        Created:  10/10/2012 18:04:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang YANG (http://sites.google.com/site/yangslittlesite/), uk0052003@gmail.com
 *        Company:  University of Pittsburgh
 *
 * =====================================================================================
 */


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int N=99536;


int main()  {

	string s;
	cout << "plot which set of data?" <<endl;
	cin  >> s;
	s = "coordinates"+s;
	ifstream ifile;
	ifile.open("coordinates39000");

	if(!ifile) {
		cerr << "No input file" << endl;
//		exit(1);
	}

	double hist[40];

	for(int i=0; i<40; i++) {
		hist[i]=0;
	}
	
	double X[N], Y[N];

	for(int i=0; i<N; i++) {

		ifile >> X[i] >> Y[i];

	}

	for(int i=0; i<N; i++) {

		if(0<= X[i] && X[i] <=10.0)
				hist[0]++;
		else if ( 10.0 < X[i] && X[i] <= 20.0 )
				hist[1]++;
		else if ( 20.0 < X[i] && X[i] <= 30.0 )
				hist[2]++;
		else if ( 30.0 < X[i] && X[i] <= 40.0 )
				hist[3]++;
		else if ( 40.0 < X[i] && X[i] <= 50.0 )
				hist[4]++;
		else if ( 50.0 < X[i] && X[i] <= 60.0 )
				hist[5]++;
		else if ( 60.0 < X[i] && X[i] <= 70.0 )
				hist[6]++;
		else if ( 70.0 < X[i] && X[i] <= 80.0 )
				hist[7]++;
		else if ( 80.0 < X[i] && X[i] <= 90.0 )
				hist[8]++;
		else if ( 90.0 < X[i] && X[i] <= 100.0 )
				hist[9]++;
		else if ( 100.0 < X[i] && X[i] <= 110.0 )
				hist[10]++;
		else if ( 110.0 < X[i] && X[i] <= 120.0 )
				hist[11]++;
		else if ( 120.0 < X[i] && X[i] <= 130.0 )
				hist[12]++;
		else if ( 130.0 < X[i] && X[i] <= 140.0 )
				hist[13]++;
		else if ( 140.0 < X[i] && X[i] <= 150.0 )
				hist[14]++;
		else if ( 150.0 < X[i] && X[i] <= 160.0 )
				hist[15]++;
		else if ( 160.0 < X[i] && X[i] <= 170.0 )
				hist[16]++;
		else if ( 170.0 < X[i] && X[i] <= 180.0 )
				hist[17]++;
		else if ( 180.0 < X[i] && X[i] <= 190.0 )
				hist[18]++;
		else if ( 190.0 < X[i] && X[i] <= 200.0 )
				hist[19]++;
		else if ( 200.0 < X[i] && X[i] <= 210.0 )
				hist[20]++;
		else if ( 210.0 < X[i] && X[i] <= 220.0 )
				hist[21]++;
		else if ( 220.0 < X[i] && X[i] <= 230.0 )
				hist[22]++;
		else if ( 230.0 < X[i] && X[i] <= 240.0 )
				hist[23]++;
		else if ( 240.0 < X[i] && X[i] <= 250.0 )
				hist[24]++;
		else if ( 250.0 < X[i] && X[i] <= 260.0 )
				hist[25]++;
		else if ( 260.0 < X[i] && X[i] <= 270.0 )
				hist[26]++;
		else if ( 270.0 < X[i] && X[i] <= 280.0 )
				hist[27]++;
		else if ( 280.0 < X[i] && X[i] <= 290.0 )
				hist[28]++;
		else if ( 290.0 < X[i] && X[i] <= 300.0 )
				hist[29]++;
		else if ( 300.0 < X[i] && X[i] <= 310.0 )
				hist[30]++;
		else if ( 310.0 < X[i] && X[i] <= 320.0 )
				hist[31]++;
		else if ( 320.0 < X[i] && X[i] <= 330.0 )
				hist[32]++;
		else if ( 330.0 < X[i] && X[i] <= 340.0 )
				hist[33]++;
		else if ( 340.0 < X[i] && X[i] <= 350.0 )
				hist[34]++;	
		else if ( 350.0 < X[i] && X[i] <= 360.0 )
				hist[35]++;
		else if ( 360.0 < X[i] && X[i] <= 370.0 )
				hist[36]++;
		else if ( 370.0 < X[i] && X[i] <= 380.0 )
				hist[37]++;
		else if ( 380.0 < X[i] && X[i] <= 390.0 )
				hist[38]++;
		else if ( 390.0 < X[i] && X[i] <= 400.0 )
				hist[39]++;
		else
			cout << "error!" << endl;

		}
	
	ifile.close();

	

	ofstream ofile;

	ofile.open("his.data");

	for(int i=0; i<40; i++)
	ofile << hist[i] << endl;

	ofile.close();

}
