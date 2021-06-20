/*
 * LinearDynamicalSystem.cpp
 *
 * /brief The header file for the linear dynamical system instance
 *
 * Author: Tim Wroge
 * Significant History: 11/28/2020, created file
 */
#include <dynamics/NonLinearSystem.hh>

using namespace dynamics::core::nonlinear;

template <class TransformationType, class StateType, class InputType>
LinearSystem<TransformationType, StateType, InputType>::NonLinearSystem(const TransformationType nonLinearTransformation) :
    _transformation(nonLinearTransformation) {};

template <class TransformationType, class StateType, class InputType>
State<StateType> NonLinearSystem<TransformationType, StateType, InputType>::update(const InputType & SystemInputs) const {
    return _state+_transformation(SystemInputs);
}
