#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	//P: adjust in Proportion to the CTE
	//I: adjust in proportion to the sum of continuous error to counter systematic bias
	//D: adjust based on Derivative to prevent overshooting and smooth steering
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	p_error = 0;
	i_error = 0;
	d_error = 0;
	prev_cte = 0;
	sum_cte = 0;
	timestep = 0;
	total_error = 0;
}

void PID::UpdateError(double cte) {
	sum_cte += cte;
	double diff_cte = cte - prev_cte;
	prev_cte = cte;
	p_error = -Kp * cte;
	i_error = -Ki * sum_cte;
	d_error = -Kd * diff_cte;
	timestep++;
	if (timestep > min_steps) {
		total_error += pow(cte, 2);
	}
}

double PID::getSteeringAngle() {
	double steeringAngle = p_error + i_error + d_error;
	double normalizedAngle = 2. / (1 + exp(-2.2 * (steeringAngle)));
	normalizedAngle -= 1;

	return normalizedAngle;
	
}

double PID::TotalError() {
	if (timestep > 0) {
		return total_error / (timestep - min_steps);
	} else {
		return 0;
	}
}

