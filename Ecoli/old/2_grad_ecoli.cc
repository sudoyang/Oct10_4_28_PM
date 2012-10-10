/*
 * =====================================================================================
 *
 *       Filename:  2_grad_ecoli.cc
 *
 *    Description:  A simple simulation of Ecoli's movement with two opposite gradient (Left: L-Serine Right: MeAsp)  
 *
 *        Version:  1.0
 *        Created:  09/29/2012 22:48:23
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

using namespace std;


double length=400; //um
double Ser_C_L=20; //uM
double Ser_C_R=8;
double MeAsp_C_L=130;
double MeAsp_C_R=300;
//double p_r=0.1;

double ratio=0.5;
int    N=400;
int    tstep=500000;

double L_Serine_C(double left_C, double right_C, double position_x, double position_y); 
double MeAsp_C(double left_C, double right_C, double position_x, double position_y); 
double Pro_ratio(double ratio); 

int main() {

  
//	int map[N][N];
	double step=N/2;
	double brownian_step=0;

//	int step_y=N/2;
	

	srand(time(0));
	for(int i=0; i<tstep; i++) {

//		cout << (float)rand()/RAND_MAX << endl;

	brownian_step=2*(float)rand()/RAND_MAX-1; 


	if((float)rand()/RAND_MAX < Pro_ratio(ratio))
		step++;
	else
		step--;

	step=step+brownian_step;
	cout << i << " " << step << endl;
/*  
	for(int i=0; i<400; i++)
	{
		cout << L_Serine_C(Ser_C_L, Ser_C_R, i, i) << "  " <<MeAsp_C(MeAsp_C_L, MeAsp_C_R, i, i) << endl;
	}
*/

	}
	return 0;
}



double L_Serine_C(double left_C, double right_C, double position_x, double position_y) {

	return left_C-position_x*(left_C-right_C)/length; 
}



double MeAsp_C(double left_C, double right_C, double position_x, double position_y) {


	return left_C-position_x*(left_C-right_C)/length;
}

//Based on the ratio of receptor, we can determine the probability of directions.
double Pro_ratio(double ratio) {

	double pro=0;
		   pro=0.500;
	return pro;
}
