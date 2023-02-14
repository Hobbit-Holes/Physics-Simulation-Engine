# Game-Loops

Creation of different game loops where a cube moves diagonally across the screen. There are three different game loops with different ways to work.

- Game Loop <b>Examples</b>: In this game loops, the cube travels accross the screen indefinitely, without taking into account the borders of the screen. And for each example, the game loops are CPU dependant <i>(Example 1)</i>, FPS dependant <i>(Example 2)</i> and finally, it depends on the delta time variable <i>(Example 3)</i>.
- Game Loop <b>Fixed</b>: In this game loop, the cube travels accross the screen, but the position of the cube will get reset if it gets out of the screen. In addition, the variable delta time it will be constant.
- Game Loop <b>Variable</b>: In this game loop, the cube travels accross the screen, but the position of the cube will get reset if it gets out of the screen. In addition, the variable delta time it will variate in each iteration.

In the last two game loops, when resetting the player's position, we have created a functionality that makes the player's direction change. This way you can see how the cube collides with the different walls. 

Below we can see how one of the game loops works:

## Records

Game Loop Variable
![Game Loop Variable](https://github.com/Hobbit-Holes/Game-Loops/blob/main/Records/Secuencia%2001.gif?raw=true)
