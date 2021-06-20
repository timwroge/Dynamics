#include <dynamics/Dynamics.hh>
#include <dynamics/LinearSystem.hh>
#include <vector>
#include <functional>

using InputType = std::vector<double>;
using StateType = double;
using TransformationType= std::function<State<StateType>(State<StateType>);


State<StateType> linearTransformation(InputType const & state){
    return state;
}

int main(void) {
    // Simple Linear System : a frictionless rotating point mass
    State<StateType> InitialState = {1, -1, 1};
    auto transform = linearTransformation;
    dynamics::core::System linearSystem = new dynamics::core::linear::LinearSystem<TransformationType, StateType, InputType>(transform) ;
    InputType inputs = {0, 1, 2};
    linearSystem(inputs);
}
