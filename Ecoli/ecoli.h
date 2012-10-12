#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <time.h>



using namespace std;

clock_t start, finish;
double duration; // The time of duration

const double PI=3.1415926535;

const double Time=40000; //us
const int tstep=1;
const double Xlength=400; //um
const double Ylength=400;


int    Cellnumber=100000;
const double Ser_C_L=20; //uM
const double Ser_C_R=8;
const double MeAsp_C_L=130;
const double MeAsp_C_R=300;

// Activity ~~ Probability function based parameters
double l_1 = 1.23;
double l_2 = 1.54;
double l_0 = 0.826;
double C_1 = 0.449;
double C_2 = 0.314;
double K_1 = 49.2; //um
double K_2 = 34.5; //um
double L_1 = 0;    //um
double L_2 = 0;    //um
double A_j = 0.09;
//double A_j = 0.0947/(1.0+pow((1.43/T), 2.61)); //Assume

double L_Serine_C( double position_x, double position_y); 
double MeAsp_C( double position_x, double position_y); 
double Pro_ratio(double ratio, double L_Serine_C, double MeAsp_C); 


