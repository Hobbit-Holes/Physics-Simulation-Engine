# Physics-Simulation-Engine

Repository to track and delivary the examples, exercises and final project of the course Physics Simulation Engines. This team is composed of <b>Borja Sanz de Bremond O'Neill</b> and <b>Laura Ferrer Haba</b>, and the name of the team is <b><code>Hobbit Holes</code></b>.

## Index

Here you can see the different sections that have been carried out during the course:

- [Introduction](#introduction)
- [Game Loop](#game-loop)
- [Color](#color)
- [Rendering Primitives](#rendering-primitives)
- [Vectors](#vectors)
- [Entity Component System](#entity-component-system)

## Introduction

This project consists on...

## Game Loop

...

## Color

In this section we have implemented a functionality where the engine can manage the colors of the screen when it draw lines, forms, polygons and even the background. Here we have create two files named <b><code>Color.hh</code></b> and <b><code>Color.cpp</code></b> which have the following functions:

- <b>Constructor and Deconstructor</b>: It create the Color in different ways <i>(Without parameters, with the RGB or RGBA parameters and Hexadecimal parameter)</i>.
- <b>Transformation</b>: It make some variations to the Colors, making it darker, ligther or get a Color between two Colors, amon other things.
- <b>Operators</b>: It show in a easy way the values of the Color and merge two Colors.
- <b>Basic colors</b>: This are some basic Color which the user can use without introducing the RGBA or Hexadecimal values.

In this section there is a example called [Bootstrap](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/bootstrap) that draw a filled rectangle with the struct created. The result obtained is the folllowing: 

![Bootstrap]()

## Rendering Primitives

At this point we know how to draw some pixels with Colors, but we need to improve the techniques to draw figures and polygons. So, in this section, we have learn how to draw any polygon from scratch. This is drawing lines drawed by pixels. Some types of draws are the following: 

- <b>Grid</b>: Grid the screen so that you can better see where an object will be, if needed.
- <b>Line</b>: Draw a series of pizels given a start poiint and a end point.
- <b>Rectangles</b>: Draw 4 lines given the vertices and can be filled or not.
- <b>Polygons</b>: Draw geometric forms with lines and can be filled or not.
- <b>Circles</b>: Draw a circle given the radius and can be filled or not.

All these functions have been added to the <code>Graphics</code> files. In this section we have had an exercise <i>([Exercise 04](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/exercise-04))</i> where we have to scaffold our game engine and render some shapes while ge obtain some information with the <code>Logger</code>. The result is as follows: 

![Exercise 04]()

## Vectors

Here, we have created the files <code>Vec2.hh</code> and <code>Vec2.cpp</code> to add Vectors to our game engine. With these vectors we can manage the data in a easier way, per example, when we want to do some calculus between vectors or to determine the position of a object. Inside the scripts there are functions and operators. Some of the functions are: 

- <b>Sume, subtraction, multiplication...</b>.
- <b>Magnitude, Normal...</b>

Some of the operators are: 

- <b>=, == , !=</b>
- <b>+, -, *, /, Inverse</b>
- <b>+=, -=, *=, /=</b>

By this point we have seen the example [vectors-01](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/vectors-01) where we can check the good behaviour of our code and also, we have to do the exercise [Exercise 05](https://github.com/Hobbit-Holes/Physics-Simulation-Engine/tree/main/MorgulEngine/exercises/exercise-05) where we have to define more operators and functions. The new functions and operators are the following:

- <b>Angle</b>: It calculate the angle between two vectors. The another angle function only calculate it between the vector and the x axis.
- <b>Projection</b>: 
- <b>Scalar Projection</b>: 
- <b>Orthogonal Projection</b>: 

...

## Entity Component System

...

