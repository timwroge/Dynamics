/*
 * LinearDynamicalSystem.hh
 *
 * /brief The header file for the linear dynamical system instance
 *
 * Author: Tim Wroge
 * Significant History: 11/28/2020, created file
 */
#include <vector>
#include <dynamics/Dynamics.hh>

using namespace Dynamics::core;

namespace Dynamics{
namespace core{
namespace linear{

/* /brief  System
 *
 * the system is the core interface for this library it has a set of INPUTS
 * and outputs. The inputs are retained in a Eigen container or a std::vector
 * as are the outputs.
 */

template <class TransformationType\
        , class StateType\
        , class InputType>
class LinearSystem : System{
    public:
        /* /brief The system class must take in a transformation which describes the
         * transformation from teh current state of the system, and the inputs to the output of the system
         */
        LinearSystem(const TransformationType ) ;
        /*
         * The update function is intended to be identical the call operator, it will return the next state of
         * the system
         */
        State<StateType> update (const InputType & ) const override;
        /*
         * The call operator is overloaded to consume the new system inputs of the system
         * and generate the output
         */
        State<StateType> operator () (const InputType & inputs) const override{
            return update(inputs);
        } ;
    private:
        TransformationType _transformation;
        StateType _state;
};

} // namespace linear
} // namespace core
} // namespace Dynamics
