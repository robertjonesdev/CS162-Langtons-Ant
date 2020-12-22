# Langtons-Ant
OOP-based simulation of the classic Universal Turing Machine, Langton's Ant, written in C++

# Description
Langton's ant is a two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior. It was invented by Chris Langton in 1986 and runs on a square lattice of black and white cells.[1] The universality of Langton's ant was proven in 2000.[2] The idea has been generalized in several different ways, such as turmites which add more colors and more states.
https://en.wikipedia.org/wiki/Langton%27s_ant

# Rules
Squares on a plane are colored variously either black or white. We arbitrarily identify one square as the "ant". The ant can travel in any of the four cardinal directions at each step it takes. The "ant" moves according to the rules below:
* At a white square, turn 90° clockwise, flip the color of the square, move forward one unit
* At a black square, turn 90° counter-clockwise, flip the color of the square, move forward one unit
Langton's ant can also be described as a cellular automaton, where the grid is colored black or white and the "ant" square has one of eight different colors assigned to encode the combination of black/white state and the current direction of motion of the ant.[2]

# Modes of Behavior
These simple rules lead to complex behavior. Three distinct modes of behavior are apparent,[3] when starting on a completely white grid.

Simplicity. During the first few hundred moves it creates very simple patterns which are often symmetric.
Chaos. After a few hundred moves, a large, irregular pattern of black and white squares appears. The ant traces a pseudo-random path until around 10,000 steps.
Emergent order. Finally the ant starts building a recurrent "highway" pattern of 104 steps that repeats indefinitely.
All finite initial configurations tested eventually converge to the same repetitive pattern, suggesting that the "highway" is an attractor of Langton's ant, but no one has been able to prove that this is true for all such initial configurations. It is only known that the ant's trajectory is always unbounded regardless of the initial configuration[4] – this is known as the Cohen–Kong theorem.[5]

** Description from wikipedia article: https://en.wikipedia.org/wiki/Langton%27s_ant
