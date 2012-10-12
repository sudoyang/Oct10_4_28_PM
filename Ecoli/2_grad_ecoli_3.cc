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


#include "ecoli.h"

int main() {
	
	const char filename[] = "hist_data.txt";

	ifstream   ifile;
	ifile.open(filename);

	cout <<  endl;
	cout <<  endl;
	cout <<  endl;
	cout << "Reading input data" << endl;

	if(!ifile) {
		cerr << "No input file" << endl;
		exit(1);
	}

	double ratio, hist_1, hist_2, hist_3;
	double sum_1, sum_2, sum_3;
	
	sum_1=sum_2=sum_3=0;

	while(ifile >> ratio >> hist_1 >> hist_2 >> hist_3){

		sum_1+=hist_1;
		sum_2+=hist_2;
		sum_3+=hist_3;

	}

	ifile.close();
	cout << "N for 1 list: " << sum_1  << endl; 
	cout << "N for 2 list: " << sum_2  << endl; 
	cout << "N for 3 list: " << sum_3  << endl; 
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
			Angle[i]=(2*(float)rand()/RAND_MAX-1.0)*PI;
			Speed[i]=30;  // um 60 before.
 
	}


    cout << "Done" << endl;

	//start the simulation.
	
	cout <<  endl;
	cout <<  endl;
	cout <<  endl;
	cout << "Start the simulation!" << endl;
	cout << "Total Cell number is " << Cellnumber << endl;
	cout <<	"The area for cells are " << Xlength << "um *" << Ylength << "um squre." << endl;
	cout << "Total simulation time is " << Time  << " us" << ", and the time step is " << tstep << " us"<< endl;
	cout << "Bias contains two kinds, which are, Ser and MeAsp" << endl;
	cout << "Ser, left " << Ser_C_L << " and right " << Ser_C_R << endl;
	cout << "MeAsp, left " << MeAsp_C_L << " and right " << MeAsp_C_R << endl;
	

	for(int t=0; t < Time; t=t+tstep) {


		for(int i=0; i<Cellnumber; i++) {

			if(X[i] > Xlength) {
				X[i] = Xlength;
				if(Angle[i] > 0)
					Angle[i] = PI - Angle[i];
				else
					Angle[i] = -PI - Angle[i];
			}

			if(X[i] < 0) {
				X[i] = 0;
				if(Angle[i] > 0)
					Angle[i] = PI - Angle[i];
				else
					Angle[i] = -PI - Angle[i];
			}

			if(Y[i] < 0) {
				Y[i] = 0;
					Angle[i] = - Angle[i];
			}
			
			if(Y[i] > Ylength) {
				Y[i] = Ylength;
					Angle[i] = - Angle[i];
			}


	
			double C_Serine, C_MeAsp;

			C_Serine = L_Serine_C(X[i], Y[i]);
			C_MeAsp = MeAsp_C(X[i], Y[i]);

			if((float)rand()/RAND_MAX < Pro_ratio(Ratio[i], C_Serine, C_MeAsp)) {
				
				Angle[i]=(2*(float)rand()/RAND_MAX-1.0)*PI;
				Speed[i]=Speed[i]/3.0;
				X[i] = X[i] + cos(Angle[i])*Speed[i]*tstep;
				Y[i] = Y[i] + sin(Angle[i])*Speed[i]*tstep;
				Speed[i]=Speed[i]*3.0;
				}
			else{
				X[i] = X[i] + cos(Angle[i])*Speed[i]*tstep;
				Y[i] = Y[i] + sin(Angle[i])*Speed[i]*tstep;
				}

				
			if(X[i] > Xlength) {
				X[i] = Xlength;
				if(Angle[i] > 0)
					Angle[i] = PI - Angle[i];
				else
					Angle[i] = -PI - Angle[i];
			}

			if(X[i] < 0) {
				X[i] = 0;
				if(Angle[i] > 0)
					Angle[i] = PI - Angle[i];
				else
					Angle[i] = -PI - Angle[i];
			}

			if(Y[i] < 0) {
				Y[i] = 0;
					Angle[i] = - Angle[i];
			}
			
			if(Y[i] > Ylength) {
				Y[i] = Ylength;
					Angle[i] = - Angle[i];
			}


		}


		if( t%1000 == 0 ) {
		
			finish = clock();
		    duration=(double)(finish-start)/CLOCKS_PER_SEC;
			start  = finish;

		cout << "Time(simulation): " << t << " us      Mathcine time: " << duration << " seconds" << endl;
 
		std::string s = std::to_string(t);

		ofstream   ofile;

		s="./data/coordinates"+s;
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
double Pro_ratio(double ratio, double L_Serine_C, double MeAsp_C) {

	double pro=0;
  
	L_1 = MeAsp_C;
	L_2 = L_Serine_C;

double N_2 = 12.0/(ratio+1.0);
double N_1 = N_2*ratio;
double L_j = pow(l_1, N_1)*pow(l_2, N_2)*pow(l_0, 4.0); //4.0 is from N_1/f_1
	//L_1 and L_2 use uM, which is the same with MeAsp and L_Serine.
	
	pro=A_j*L_j*pow((1+C_1*L_1/K_1),N_1)*pow((1+C_2*L_2/K_2), N_2)/(pow((1+L_1/K_1),N_1)*pow((1+L_2/K_2),N_2)+L_j*pow((1+C_1*L_1/K_1),N_1)*pow((1+C_2*L_2/K_2), N_2));

	return pro;
}
