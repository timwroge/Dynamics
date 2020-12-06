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
$$  \dot{ x}(t) = f( x(t))  $$ 

This function $$ f(x(t) )$$ takes in a state $$ x(t) $$ and produces the change 
in state with respect of time of the system. This mapping from input to output is referred
to in this library as a `Transformation`. Transformations can take a number of different forms. 
The following sections will describe the set of possibles models for your system and its change of
state

#### Linear dynamics
Generally a linear system can be described by the following equation:

$$\dot{x(t)} = A x(t)$$

The dynamics of the system are here modeled by the linear transformation `A`, where `A` is a matrix that
has the same rank as x(t).

This library provides functionality to establish any linear transformation you would like. The perferred
interfaces are "Eigen" matrices.

#### Nonlinear dynamics
Nonlinear dynamics are the core of this library and its tools. Non linear dyanmics are defined by systems in 
the form: 
$$  \dot{ x}(t) = f( x(t))  $$ 

Where `f()` is an arbitrary function. 
