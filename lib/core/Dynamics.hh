/*
 * Dynamics.hh
 *
 * /brief A major header file for the dynamics library including the core linear and nonlinear
 * dynamics
 *
 * Author: Tim Wroge
 * Significant History: 11/28/2020, created file
 */
#include <vector>

namespace Dynamics{
namespace core{

/* /brief  State
 *
 * the state is a simple container that keeps track of whatever state variables fully describe
 * the state of the system
 */

template <class T>
class State : public std::vector<T> {};

/* /brief  System
 *
 * the system is the core interface for this library it has a set of INPUTS
 * and outputs. The inputs are retained in a Eigen container or a std::vector
 * as are the outputs.
 */
class System {
    /* /brief The system class must take in a transformation which describes the
     * transformation from teh current state of the system, and the inputs to the output of the system
     */
    template <class TransformationType>
    virtual System(TransformationType );
    /*
     * The call operator is overloaded to consume the new system inputs of the system
     * and generate the output
     */
    template <class T>
    virtual State operator () (const T ...) const ;
    /*
     * The update function is intended to be identical the call operator, it will return the next state of
     * the system
     */
    template <class T>
    virtual State update() (const T ...) const ;
};

} // namespace core
} // namespace Dynamics
