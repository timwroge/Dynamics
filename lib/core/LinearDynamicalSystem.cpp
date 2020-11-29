/*
 * LinearDynamicalSystem.cpp
 *
 * /brief The header file for the linear dynamical system instance
 *
 * Author: Tim Wroge
 * Significant History: 11/28/2020, created file
 */
#include <LinearDynamicalSystem.hh>

using namespace Dynamics::core::linear;

template <class TransformationType>
LinearSystem(TransformationType linearTransformation) {

}
template <class T>
State operator () (const T ...) const override;
template <class T>
State update() (const T ...) const override;
