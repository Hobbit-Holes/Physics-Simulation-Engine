# Physics-Simulation-Engine

Repository to track and delivary the examples, exercises and final project of the course Physics Simulation Engines. This team is composed of <b>Borja Sanz de Bremond O'Neill</b> and <b>Laura Ferrer Haba</b>, and the name of the team is <b><code>Hobbit Holes</code></b>.

## Index

Here you can see the different sections that have been carried out during the course:

- [Introduction](#introduction)
- [Game Loop](#game-loop)
- [Project Architecture](#project-architecture)
- [Color](#color)
- [Rendering Primitives](#rendering-primitives)
- [Vectors](#vectors)
- [Entity Component System](#entity-component-system)

## Introduction

This project consists of creating our own graphic engine from scratch, for it, in this repository you can find and show the functionalities that we will be adding. These can be mathematical functions, such as adding vectors between them, to graphics rendering functions.

## Game Loop

For this firt part of the course and the begining of the creating of the game engine, we have make some game loops to understand how it works. All this can be seen in the folder [Game Loops](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/Game-Loops) where we have created some folder per each game loop learn in the course. As the course progresses, the same loops will be created but with the structure of the game engine.

## Project Architecture

The creating of a game engine is difficult, so it is so important to have the project well structured and don't commit errors or redundance. The idea is to separate in different files <i>(Classes and structures)</i> the physics, graphics, inputs, etc. Here we have to create a class to handle and rule <i>(like the One Ring)</i> all the functionalities, classes and other stuff, in our case, we have called our game engine <b><code>MorgulEngine</code></b>.

Some of these classes are the <code>Graphics</code> or the <code>Logger</code>. The first one handle the visual aspects of the screen, per example: 

- <b>Open Window</b>
- <b>Close Window</b>
- <b>Render Frame</b>
- Etc

And the second one give us information of the process during the execution of the game engine. When the message appear, it also show us the time that occurs. There are three main types that are: 

- <b>Info</b>
- <b>Warning</b>
- <b>Error</b>

## Color

In this section we have implemented a functionality where the engine can manage the colors of the screen when it draw lines, forms, polygons and even the background. Here we have create two files named <b><code>Color.hh</code></b> and <b><code>Color.cpp</code></b> which have the following functions:

- <b>Constructor and Deconstructor</b>: It create the Color in different ways <i>(Without parameters, with the RGB or RGBA parameters and Hexadecimal parameter)</i>.
- <b>Transformation</b>: It make some variations to the Colors, making it darker, ligther or get a Color between two Colors, amon other things.
- <b>Operators</b>: It show in a easy way the values of the Color and merge two Colors.
- <b>Basic colors</b>: This are some basic Color which the user can use without introducing the RGBA or Hexadecimal values.

In this section there is a example called [Bootstrap](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/bootstrap) that draw a filled rectangle with the struct created. The result obtained is the folllowing: 

<p align="center"><img src="https://github.com/Hobbit-Holes/Physics-Simulation-Engine/blob/main/Screenshots/Bootstrap.gif" alt="Bootstrap" height="300"/></p>

## Rendering Primitives

At this point we know how to draw some pixels with Colors, but we need to improve the techniques to draw figures and polygons. So, in this section, we have learn how to draw any polygon from scratch. This is drawing lines drawed by pixels. Some types of draws are the following: 

- <b>Grid</b>: Grid the screen so that you can better see where an object will be, if needed.
- <b>Line</b>: Draw a series of pizels given a start poiint and a end point.
- <b>Rectangles</b>: Draw 4 lines given the vertices and can be filled or not.
- <b>Polygons</b>: Draw geometric forms with lines and can be filled or not.
- <b>Circles</b>: Draw a circle given the radius and can be filled or not.

All these functions have been added to the <code>Graphics</code> files. In this section we have had an exercise <i>([Exercise 04](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/exercise-04))</i> where we have to scaffold our game engine and render some shapes and a grid, while we obtain some information with the <code>Logger</code>. The result is as follows: 

<p align="center"><img src="https://github.com/Hobbit-Holes/Physics-Simulation-Engine/blob/main/Screenshots/Exercise04.gif" alt="Exercise 04" height="300"/></p>

## Vectors

Here, we have created the files <code>Vec2.hh</code> and <code>Vec2.cpp</code> to add our custom Vectors of 2 dimensions to our game engine. With these vectors we can manage the data in a easier way, per example, when we want to do some calculus between vectors or to determine the position of a object. Inside the scripts, there are functions and operators. Some of the functions are: 

- <b>Sume, subtraction, multiplication...</b>.
- <b>Magnitude, Normal, Lerp...</b>
- <b>Dot, Cross...</b>

And some of the operators are: 

- <b>=, == , !=</b>
- <b>+, -, *, /, Inverse</b>
- <b>+=, -=, *=, /=</b>

By this point we have seen the example [Vectors 01](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/vectors-01) where we can check the good behaviour of our code and also, we have to do the exercise [Exercise 05](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/exercise-05) where we have to define more operators and functions. The new functions and operators are the following:

- <b>Angle</b>: It calculate the angle between two vectors. The another angle function only calculate it between the vector and the x axis.
- <b>FromModuleAngle</b>: It create a vector given the module and the angle.
- <b>Projection</b>: We obtain the projection of our principal vector into a given one.
- <b>Scalar Projection</b>: Give us the scalar value of the projection define above.
- <b>Orthonormal Projection</b>: It is the normal projection of the projection of a vector into another.

With all these function, operations and operators we can do some problems with more complexity, like the example [Vectors 02](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/vectors-02). In this example, we have two objects, the player and a enemy. The enemy will go against the player depending in the direction that the player and the enemy are. The speed of the enemy can variate because it depends only in the direction, and this vector can be larger or shorter dependind in the distance with the player. 

This is resolve in the [Exercise 06](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/exercise-06) where the speed of the enemy is constant because we use the unit vector of the direction. Also, the player is moved with the mouse thanks to the SDL. The result obtained is as follow: 

<p align="center"><img src="https://github.com/Hobbit-Holes/Physics-Simulation-Engine/blob/main/Screenshots/Exercise06.gif" alt="Exercise 06" height="300"/></p>

At this point, we can also make a more difficult game. In the [Exercise 07](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/exercise-07) we have to create a mechanic where the enemy can only chase the player if the player is in front of him <i>(With a 180º FOV)</i>. Finally, for this exercise we have use a variable that change the FOV grades of the enemy. The result obtained is:

<p align="center"><img src="https://github.com/Hobbit-Holes/Physics-Simulation-Engine/blob/main/Screenshots/Exercise07.gif" alt="Exercise 07" height="300"/></p>

To finish with this unit on vectors, we have carried out some more examples. One is about a object moving accross the screen with a random desviation that make the object travel with noise <i>([Random Rotation](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/random-rotation))</i>. Another one is about the same logic that the mentioned before, but the object chase the player with additional logic <i>([Steering Rocket](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/steering-rocket))</i>. Finally, the last examples we have made are about the vectors, in the first one <i>([Vectors 03](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/vectors-03))</i> we have the vertex of a cube that rotate in a direction, and in the last example <i>([Vectors 04](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/vectors-03))</i> we have different objects whose behaviour varies, making the movement go at different speeds but reaching the objective at the same time. The results of the last two examples are: 

<p align="center"><img src="https://github.com/Hobbit-Holes/Physics-Simulation-Engine/blob/main/Screenshots/Vectors03.gif" alt="Vectors 03" height="300"/></p>

<p align="center"><img src="" alt="Vectors 04" height="300"/></p>

## Entity Component System

...

<p align="center"><img src="https://github.com/Hobbit-Holes/Physics-Simulation-Engine/blob/main/Screenshots/Exercise08.gif" alt="Exercise 08" height="300"/></p>


