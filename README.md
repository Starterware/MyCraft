# Starterware

Welcome to **Starterware Training**, I created this repository in order to work on my craft.
It's a space where I try out different kind of practices, exercises, programming languages and techniques.

## Table of Contents

* [Kata](#kata)
* [Languages](#languages)
* [Playground](#playground)
* [Project Euler](#project-euler-problems)

## Kata

Short coding exercises that can be repeated multiple times in order to have the hang of it. 
They allow to train easily your Test Driven Development skills.

### How to Build & Run

#### C++

##### Prerequisites

* CMake must be installed and accessible from the sources
* The sources require a C++ 11 compiler
* [googletests](https://github.com/google/googletest) must be installed on the system

#### Build & Run

* First, run the __setup.pl__ script which can be found in the [Kata sources directory](Kata/sources)
	* The scripts requires a parameter --gtest or -g followed by the path to the googletest include and lib directory
	* It updates the CMakeFileList.txt for all the sources
* Create a build directory in the source folder where CMakeFileList.txt is
* In a command prompt, in the build directory run:
	* __cmake ..__ (I add [__-G "Visual Studio 14 2015 Win64"__] to generate a visual studio solution on windows)

_Rem 1: some projects may not work on all platforms. See the projects page for more information about that._
_Rem 2: in Visual Studio, when gtest is used, set the project to the same C/C++ > Code Generation > Runtime Library._
_Rem 3: nothing prevents you to use your own compilation method._

#### Python

For python, I used [nose](http://nose.readthedocs.io/en/latest/) to run the tests and [spyder](https://pythonhosted.org/spyder/) as IDE in order to have nice formatted unit tests outputs.

When nose is installed and accessible from any directory :
* In a command prompt, go to the directory containing the unit tests
* Run nosetests, and the tests results will appear

### Katas

* [String Calculator](Kata/sources/StringCalculator/README.md) : implemented in [c++](Kata/sources/StringCalculator/c++), [python](Kata/sources/StringCalculator/python)

## Playground

Space for testing out little projects/ideas that take a bit of time.

### How to Build & Run

#### C++

##### Prerequisites

* CMake must be installed and accessible from the sources
* The sources require a C++ 11 compiler
* [googletests](https://github.com/google/googletest) must be installed on the system

#### Build & Run

* First, run the __setup.pl__ script which can be found in the [Playground directory](Playground)
	* The scripts requires a parameter --gtest or -g followed by the path to the googletest include and lib directory
	* It updates the CMakeFileList.txt for all the sources
* Create a build directory in the source folder where CMakeFileList.txt is
* In a command prompt, in the build directory run:
	* __cmake ..__ (I add [__-G "Visual Studio 14 2015 Win64"__] to generate a visual studio solution on windows)

_Rem 1: some projects may not work on all platforms. See the projects page for more information about that._
_Rem 2: in Visual Studio, when gtest is used, set the project to the same C/C++ > Code Generation > Runtime Library._
_Rem 3: nothing prevents you to use your own compilation method._

### Projects

* [Languages](Playground/Languages/README.md) : implemented in [c++](Playground/Languages/c++)
* [Levenstein Distance In Tries](Playground/LevensteinDistanceInTries/README.md) : implemented in [c++](Playground/LevensteinDistanceInTries/c++)

## Project Euler Problems

My project euler username is **Starter101**. Not all the problems I did are listed below and all of them are done in C++.

### How to Build & Run

#### C++

##### Prerequisites

* [CMake](https://cmake.org/) must be installed and accessible from the sources
* The sources require a C++ 11 compiler

##### Build & Run

* First, run the __setup.pl__ script which can be found in the [project euler directory](ProjectEuler)
	* It generates the CMakeFileList.txt for all the sources
* Create a build directory in the source folder where CMakeFileList.txt is
* In a command prompt, in the build directory run:
	* __cmake ..__ (I add [__-G "Unix Makefiles"__] to generate a simple makefile)
	* Afterwards run __make__ to compile and run the program
	
_Rem: the compiling instructions represent my preferred way and allow to compile easily on all platforms. Nothing prevents you to use your own compilation method._

### Problems

* [Almost Equilateral Triangles](https://projecteuler.net/problem=94) : problem 94 [[source](ProjectEuler/sources/AlmostEquilateralTriangles)]
* [Amicable Chains](https://projecteuler.net/problem=95) : problem 95 [[source](ProjectEuler/sources/AmicableChains)]
* [Anagramic Squares](https://projecteuler.net/problem=98) : problem 98 [[source](ProjectEuler/sources/AnagramicSquares)]
* [Arithmetic Expressions](https://projecteuler.net/problem=93) : problem 93 [[source](ProjectEuler/sources/ArithmeticExpressions)]
* [Arranged Probability](https://projecteuler.net/problem=100) : problem 100 [[source](ProjectEuler/sources/ArrangedProbability)]
* [Coin Partitions](https://projecteuler.net/problem=78) : problem 78 [[source](ProjectEuler/sources/CoinPartitions)]
* [Counting Fractions](https://projecteuler.net/problem=72) : problem 72 [[source](ProjectEuler/sources/CountingFractions)]
* [Counting Fractions In A Range](https://projecteuler.net/problem=73) : problem 73 [[source](ProjectEuler/sources/CountingFractionsInARange)]
* [Counting Rectangles](https://projecteuler.net/problem=85) : problem 85 [[source](ProjectEuler/sources/CountingRectangles)]
* [Cube Digit Pairs](https://projecteuler.net/problem=90) : problem 90 [[source](ProjectEuler/sources/CubeDigitPairs)]
* [Cuboid Route](https://projecteuler.net/problem=86) : problem 86 [[source](ProjectEuler/sources/CuboidRoute)]
* [Digit Factorial Chains](https://projecteuler.net/problem=74) : problem 74 [[source](ProjectEuler/sources/DigitFactorialChains)]
* [Magic 5-gon Ring](https://projecteuler.net/problem=68) : problem 68 [[source](ProjectEuler/sources/Magic5gonRing)]
* [Monopoly Odds](https://projecteuler.net/problem=84) : problem 84 [[source](ProjectEuler/sources/MonopolyOdds)]
* [Ordered Fractions](https://projecteuler.net/problem=71) : problem 71 [[source](ProjectEuler/sources/OrderedFractions)]
* [Prime Power Triples](https://projecteuler.net/problem=87) : problem 87 [[source](ProjectEuler/sources/PrimePowerTriples)]
* [Prime Summations](https://projecteuler.net/problem=77) : problem 77 [[source](ProjectEuler/sources/PrimeSummations)]
* [Product-Sum Numbers](https://projecteuler.net/problem=88) : problem 88 [[source](ProjectEuler/sources/ProductSumNumbers)]
* [Right Triangle With Integer Coordinates](https://projecteuler.net/problem=91) : problem 91 [[source](ProjectEuler/sources/RightTriangleWithIntegerCoordinates)]
* [Roman Numerals](https://projecteuler.net/problem=89) : problem 89 [[source](ProjectEuler/sources/RomanNumerals)]
* [Singular Integer Right Triangles](https://projecteuler.net/problem=75) : problem 75 [[source](ProjectEuler/sources/SingularIntegerRightTriangles)]
* [Square Root Digital Expansion](https://projecteuler.net/problem=80) : problem 80 [[source](ProjectEuler/sources/SquareRootDigitalExpansion)]
* [Su Doku](https://projecteuler.net/problem=96) : problem 96 [[source](ProjectEuler/sources/SuDoku)]
