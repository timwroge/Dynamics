# Dynamic Programming

Big idea: formulate control as optimization. 

Given: 

```
for all t: x(t), u(t)
produce a real valued scalar "score" 
```

Goal:
 
find the optimal controller "policy":

```
auto u = optimal_policy (x)
```

Ex: 
minimum time problem for the double integrator

```
q''  = u , |u| <= 1
```

solution is "bang bang control": use the maximum torque allowed to toggle between the two states


## Integration with Dynamic Programming
discrete states ` s \in S `
discrete actions: `a_i \in A`
dynamics: s[n+1]  = f(s[n], a[n]) 
