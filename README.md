# Dynamics Library
This is a general purpose dynamics library and tutorial.

## Dynamics : Overview
Dynamics describe any process and how systems change over time. The purpose of this
library is to give a in depth description and set of tools to deal with these dynamic
systems and how to decompose and analyze them. The cheif practical usage of this library
is to give a set of tools to analyze systems (whether it be through a model or a set of data) 
and produce a controller that would allow the system to reach any desired point in the state
space.

### Continuous Time Dynamics

The general formula for continuous time dynamics is below:
<p align="center"><img src="doc/equations/75b915291e2c04089a650f35562fd7d9.svg?invert_in_darkmode" align=middle width=100.75349295pt height=16.438356pt/></p> 

This function <p align="center"><img src="doc/equations/64aa5c1e6fe36c1ffde4e18afba4eba3.svg?invert_in_darkmode" align=middle width=50.71936485pt height=16.438356pt/></p> takes in a state <p align="center"><img src="doc/equations/27af798ea97597b94155589e0f113784.svg?invert_in_darkmode" align=middle width=28.116518099999997pt height=16.438356pt/></p> and produces the change 
in state with respect of time of the system. This mapping from input to output is referred
to in this library as a `Transformation`. Transformations can take a number of different forms. 
The following sections will describe the set of possibles models for your system and its change of
state

#### Linear dynamics
Generally a linear system can be described by the following equation:

<p align="center"><img src="doc/equations/da81762c84774df9ab27af3a522cf23d.svg?invert_in_darkmode" align=middle width=90.47941979999999pt height=20.339257949999997pt/></p>

The dynamics of the system are here modeled by the linear transformation `A`, where `A` is a matrix that
has the same rank as x(t).

This library provides functionality to establish any linear transformation you would like. The perferred
interfaces are "Eigen" matrices.

#### Nonlinear dynamics
Nonlinear dynamics are the core of this library and its tools. Non linear dyanmics are defined by systems in 
the form: 
<p align="center"><img src="doc/equations/75b915291e2c04089a650f35562fd7d9.svg?invert_in_darkmode" align=middle width=100.75349295pt height=16.438356pt/></p> 

Where `f()` is an arbitrary function. 

## Control

Control is broadly used to change the dynamics of a system and produce a desired state of the system.
Depending on the system, you may have more or less control of the dynamics of the system. The distinction
here is made for two such systems:

### Fully Actuated Systems
This form of system is broadly used in robotics and other communities. Fully actuated robotic systems are
capable of controlling all aspects of the state space. For instance, with a 3D printer, the state space might
look like this:

<p align="center"><img src="doc/equations/7b783a70a4040078b2e49ef6d7f084e7.svg?invert_in_darkmode" align=middle width=81.46864605pt height=16.438356pt/></p>

Where the state x is defined as just the cartesian coordinates of any point in space. A 3D printer is able to
indendently actuate all of these states, that is, if torque is applied to the x-axis, the y-axis, or the z-axis,
the system will reach its goal (any other point in the box of a 3D printer) pretty quickly and there is nothing
else to worry about. This library has support for these systems, but likely the dynamics are highly linear 
and a simple PID controller would suffice for any of your control needs.

### Underactuated Systems
Underactuated systems by comparison have much more limitations to their dynamics. These systems are such that
they are only able to be changed in only about one or more dimension at a time. These systems look closer to 
traditional biological systems, like walking robots (like Boston Dynamics walking dog, Spot) or bipedal robots 
(like Atlas).

[source and more reading material](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-832-underactuated-robotics-spring-2009/readings/MIT6_832s09_read_ch01.pdf)


NOTE: The control algorithms presented here will likely work well for the fully actuated system as well as the 
under actuated system but the general rule of thumb is to stick with the simplest solution and work up from 
there. i.e. PID controllers, then PID controllers with Gain Scheduling, then LQR, then the more complicated
algorithms.

