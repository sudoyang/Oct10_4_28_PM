/*
 * =====================================================================================
 *
 *       Filename:  2_grad_ecoli_2.cc
 *
 *    Description:  A simple simulation of Ecoli's movement with two opposite gradient (Left: L-Serine Right: MeAsp)  
 *
 *        Version:  1.0
 *        Created:  10/05/2012 15:26:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yang YANG (http://sites.google.com/site/yangslittlesite/), uk0052003@gmail.com
 *        Company:  University of Pittsburgh
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>


using namespace std;

const double PI=3.1415926535;
const double Time=40000;

const double Xlength=400; //um
const double Ylength=400;


int    Cellnumber=100000;
const double Ser_C_L=20; //uM
const double Ser_C_R=8;
const double MeAsp_C_L=130;
const double MeAsp_C_R=300;
//double p_r=0.1;

const int tstep=1;

double L_Serine_C( double position_x, double position_y); 
double MeAsp_C( double position_x, double position_y); 
double Pro_ratio(double ratio, double L_Serine_C, double MeAsp_C, double x, double y); 

int main() {
	
	const char filename[] = "hist_data.txt";

	ifstream   ifile;
	ifile.open(filename);

	cout << "Reading input data" << endl;

	if(!ifile) {
		cerr << "No input file" << endl;
		exit(1);
	}

	double ratio, hist_1, hist_2, hist_3;
	double sum_1, sum_2, sum_3;
	
	sum_1=sum_2=sum_3;


	while(ifile >> ratio >> hist_1 >> hist_2 >> hist_3){

		sum_1+=hist_1;
		sum_2+=hist_2;
		sum_3+=hist_3;


	}

	ifile.close();
	cout << "Done" <<endl;

	Cellnumber = sum_1;

	cout << "Initializing the set" <<endl;
	srand(time(0));
	
	double X[Cellnumber], Y[Cellnumber];
	double Angle[Cellnumber];
	double Speed[Cellnumber];
	double Ratio[Cellnumber];


	ifile.open(filename);

	if(!ifile) {
		cerr << "No input file" << endl;
		exit(1);
	}

	int i = 0;
	while(ifile >> ratio >> hist_1 >> hist_2 >> hist_3){

		Ratio[i] = ratio;
		i++;
	}
	
	ifile.close();


	//initialize the positioins, angles and speed.
	for(int i=0; i< Cellnumber; i++)	{
			X[i]=(float)rand()/RAND_MAX*Xlength;
	        Y[i]=(float)rand()/RAND_MAX*Ylength;
			Angle[i]=(float)rand()/RAND_MAX*2*PI;
			Speed[i]=60;
 
	}


    cout << "Done" << endl;

	//start the simulation.


	for(int t=0; t < Time; t=t+tstep) {

		for(int i=0; i<Cellnumber; i++) {

			if(X[i] > Xlength || X[i] < 0)
				Angle[i]=PI-Angle[i];

			if(Y[i] > Ylength || Y[i] < 0)
				Angle[i] = -Angle[i];

			double C_Serine, C_MeAsp;

			C_Serine = L_Serine_C(X[i], Y[i]);
			C_MeAsp = MeAsp_C(X[i], Y[i]);

			if((float)rand()/RAND_MAX < Pro_ratio(Ratio[i], C_Serine, C_MeAsp, X[i], Y[i])) {
				
				Angle[i]=(float)rand()/RAND_MAX*PI;
				Speed[i]=Speed[i]/3.0;
				X[i] = X[i] + cos(Angle[i])*Speed[i]*tstep;
				Y[i] = Y[i] + sin(Angle[i])*Speed[i]*tstep;
				Speed[i]=Speed[i]*3.0;
				}
			else{
				X[i] = X[i] + cos(Angle[i])*Speed[i]*tstep;
				Y[i] = Y[i] + sin(Angle[i])*Speed[i]*tstep;
				}
		}

	if( t%1000 == 0 ) {

		cout << "Time is " << t << endl;
//			const string filename1 = "coordinates";
 
		std::string s = std::to_string(t);

		ofstream   ofile;

		s="coordinates"+s;
		ofile.open(s);

		for(int i=0; i<Cellnumber; i++) 
		ofile << X[i] << "  " << Y[i] << endl;

		ofile.close();
		
	}
	


	}	


	return 0;
}



double L_Serine_C(double position_x, double position_y) {

	return Ser_C_L-position_x*(Ser_C_L-Ser_C_R)/Xlength; 
}



double MeAsp_C(double position_x, double position_y) {


	return MeAsp_C_L-position_x*(MeAsp_C_L-MeAsp_C_R)/Xlength;
}

//Based on the ratio of receptor, we can determine the probability of directions.
double Pro_ratio(double ratio, double L_Serine_C, double MeAsp_C, double x, double y) {

	double pro=0;
		   pro=0.500;
	return pro;
}
