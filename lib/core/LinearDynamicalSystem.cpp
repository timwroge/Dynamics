/*
 * LinearDynamicalSystem.cpp
 *
 * /brief The header file for the linear dynamical system instance
 *
 * Author: Tim Wroge
 * Significant History: 11/28/2020, created file
 */
#include <dynamics/LinearSystem.hh>

using namespace Dynamics::core::linear;

template <class TransformationType, class StateType, class InputType>
LinearSystem<TransformationType, StateType, InputType>::LinearSystem(const TransformationType linearTransformation) :
    _transformation(linearTransformation) {};

template <class TransformationType, class StateType, class InputType>
State<StateType> LinearSystem<TransformationType, StateType, InputType>::update(const InputType & SystemInputs) const {
    return _transformation(SystemInputs);
}
