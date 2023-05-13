# Final Project

This final project consist in creating our own videogame with the game engine we have been working these months. Adding new features if necessary and improving what we have.

## Index

These are the different parts of the game:

- [Idea](#idea)
- [Environment](#environment)
    - [Bricks](#bricks)
    - [Scenes](#scenes)
- [Physics](#Physics)
- [Player Movement](#player-movement)
- [Ball Movement](#ball-movement)
- [Boosters](#boosters)
- [Score](#score)
- [Sounds and Music](#soundsand-music)

## Idea

The name of the game is <code>PongOut</code> and it is a videogame that use the <code>Morgul Engine</code> created during the course of Physics Simulation Engine.

The idea of the game is to merge the iconic game Pong with the Breakout. In this case, there are two player that are trying to goal to each other and obtain points. But, there are some block / bricks that make the task harder. And because we are merging these two games, some of the feaures are introduce of each one inside our game.

## Environment

The scenes consist of a box where are the players, the goals, the ball and the different bricks. The bricks are distributed on the middle of the screen and on the laterals. Outside the box, in each lateral, appear the names of the players, and on the top, it is the punctuation of the game. All the envioroment have been build with the lua scripts, where wee determine the entities that will appear, the sounds and the sprites.

### Bricks

There are two types of bricks that are in the scenes:

- <b>Normal</b>: These bricks are blocking the path of the ball. They have different lives <i>(Between 1 and 3)</i> that are reduce when the ball hits them. When the have 0 lifes, the bricks will explote.
- <b>Bonus</b>: There bricks are similar to the normal ones, with the difference that they have powerups when you break it. These bricks only have 1 life and give the bonus 1 time in all the game.

### Scenes

We have created two different scenes that the player can choose when it run the executable.

- <b>First Scene</b>: In this scene, there is only one powerup that expand the height of the player. The first player to play is the one that is located at the left.
- <b>Second Scene</b>: In this scene, there are two powerups: One that reduce the speed of the ball and another that restart the serve. The first player to play is the one that is located at the right.

## Physics

To implement the Physics for our game, we have being using the <code>Collisions</code> implemented before with some variations to obtain better results for our game. First of all, we have desactivate the resolve function and implement a new function that fits better <i>(It can be activated or dissactivated at any moment)</i>. 

The difference between these two functions is in the calculations of the new velocities. With the original one, the speed of the ball was not constant. With the new one, the speed will remain constant no matter what happend <i>(Except when it hits with the players)</i>.

Also, we have enable the possibility that the user of the game engine wants to use the AABB approach when it tries to know if two objects are colliding. We have done this, because, for this game, we only use rectangular shapes.

With the <code>Collider Component</code> and <code>Collision System</code> modified, the ball will travel through the screen with no complications. 

> To be able to use these new functions, the user has to enable the AABB collision of the Collider Component and set the resolve to false of only the ball.

## Player Movement

The players are using a new component and sytem. The <code>Racket Movement Component</code> determine some variables for the speed of the player, the limits of movements, the keys to control it and if it has a booster. While the <code>Racket Movement System</code> update the positions and other staff.

The <b>controls</b> can be the arrows or the typical ways of movements. Depending the value of this variable, the controls change. The first one is the <b>W</b> and <b>S</b> to move up and down. The other control is <b>Up Arrow</b> and <b>Down Arrow</b>.

The <b>booster</b> is a variable of the racket that depending if the player hit an specific bonus brick, the racket will be larger to reach the ball in a easier way.

These two players are have different sections which will change the ball behaviour depending where the ball hits. These sections are:

- <b>Upper</b>: This section always throws the ball int a upward direction and also, we add an additional velocity and desviate the ball with some degrees.
- <b>Lower</b>: This section always throws the ball int a downward direction and also, we add an additional velocity and desviate the ball with some degrees.
- <b>Middle</b>: This section reculate the desviation produce by the two other sections and also, we add an additional velocity.

## Ball Movement

The ball, while travelling across the screen, it will hits the borders, the bricks and the players. When it hits the the different objects, the direction will change, following a reflexion ray. The only case it is different, it is in the moment it hits the player, where the direction and velocity variate. To manage all these, we have implement a <code>Ball Movement Component</code> and <code>Ball Movement System</code> where it makes the calculations of the collisions and the serve.

The component has different variables:

- <b>Initial Velocity</b>: It is use for the serve and when the player hit an specific type of block <i>(Bonus)</i>.
- <b>Maximum parameters</b>: These are the maximum valocity the ball can reach and the maximum desviation the ball can go. We have these variables to control the ball for going to verticaly or opposite.
- <b>Sum parameters</b>: These are the steps the ball will increase the velocity or the desviation when it hits the player.
- <b>Num Desviation</b>: When the ball hit the central part of the player, the desviation will be corrected in one step. This variable is use to know if it is neccesary to correct it.
- <b>Serve</b>: It is use to know whio sserev when there is a score.
- <b>Last Hit</b>: It is use to give the bonus when the ball hit the Bonus bricks.

## Boosters

There are different types of bonus bricks, that depending if the player hit them, the booster will change. These boosters are applied with the <code>Brick Component</code> and <code>Brick System</code>, and also, with the Racket and Ball systems.

- <b>Extend Player</b>: The racket of the player will be bigger for the rest of the game.
- <b>Restart Ball</b>: The ball will be serve by the player who hits it.
- <b>Reduce Speed of the Ball</b>: The velocity of the ball will be reduce to the initial one.

## Score

Each time a player goal in each other score, the text that appears on top of the screen will change. This is done thanks to the <code>Text Punctuation Component</code> and <code>Text Punctuation System</code> which control te collision of the ball when it hits the scores.

## Sounds and Music

We have download some sounds and music to make the game more attractive and enjoyable. The different sounds that appear are the following:

- <b>Music</b>: A calm music that sounds in the background.
- <b>Hit objects</b>: Effect that sounds each time the ball hits a player, brick or wall.
- <b>Score</b>: When there is a goal, it will sound an effect to have some feeadback.
