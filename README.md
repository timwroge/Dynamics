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
