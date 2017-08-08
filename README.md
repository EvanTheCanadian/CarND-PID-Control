# CarND-Controls-PID
##Self-Driving Car Engineer Nanodegree Program

[Video Result](https://www.youtube.com/watch?v=wyaSk0300W4&feature=youtu.be)
---
## Discussion:
I set my initial values to the examples given by Sebastian in the PID controller lectures, then watched how 
they performed on the simulator. I noticed that the car was weaving strongly, so using my intuition I adjusted
all parameters simultaneously in the direction I thought was most appropriate:
* "P" should decrease as it was turning too strongly towards the center line and overshooting
* "I" could go either way but I decided to trend downwards as I'm not sure if the simulator is programmed to simulate drift
* "D" should increase to help prevent the drastic overshoot that was happening. 

I let the simulator loop over 1000 frames and adjusted each parameters in the specified direction, printing out the error each time. Once the total error stopped improving, I grabbed the PID output params and initialized the controller with them to watch how it would perform on the simulator. The improvement was drastic, and I think the car even made it all the way around the track. Now that the car was moving further along the track without going off raod, I could sample from more frames and fine tune each parameter individually in the direction opposite from the initial tuning, in case I overdid it. I think I could have implemented a full twiddle algorithm, but I did not want to wait for the simulator to run multiple times, and I think my approach captured the essence of twiddle (twiddle-lite?). I think trying to improve the parameters in real time would be an interesting challenge, assuming you were already close enough to stay on the track.

My final D parameter is very high, which has me a little concerned - but the car was making it all the way around the track repeatedly, so I guess it can't be that bad of a thing. It might have something to do with the occasional sudden jerk in steering angle though, and could probably be rectified with more tuning.

I cranked up the speed a little bit when the steering angle was low, and gradually eased on throttle as steering angle increased.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


