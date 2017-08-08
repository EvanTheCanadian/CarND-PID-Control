#ifndef PID_H
#define PID_H
#include <math.h>
class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double total_error;
  double best_error = 0;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  
  /*
  * Rolling values
  */
  double prev_cte;
  double sum_cte;
  int timestep;
  int iteration = 0;
  
  
  const int min_steps = 50;
  const int max_iterations = 100;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);
  
  /*
  * Get the steering angle normalized between -1 and 1 (using a sigmoid)
  */
  double getSteeringAngle();

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
