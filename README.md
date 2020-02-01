# Starterware

Welcome to **Starterware Training**, I created this repository in order to work on my craft.
It's a space where I try out different kind of practices, exercises, programming languages and techniques.


## Table of Contents

* [Kata](#kata)
* [Playground](#playground)
* [Project Euler](#project-euler-problems)
* [Appendix](#Appendix)
	* [How to build](#how-to-build)


## Kata

Short coding exercises that can be repeated multiple times in order to have the hang of it. 
They allow to train easily your Test Driven Development skills.

### Katas

* [Bowling](Kata/sources/Bowling/README.md) : implemented in [java](Kata/sources/Bowling/java)
* [String Calculator](Kata/sources/StringCalculator/README.md) : implemented in [c++](Kata/sources/StringCalculator/c++), [python](Kata/sources/StringCalculator/python)
* [XUnit](Kata/sources/XUnit/README.md) : implemented in [java](Kata/sources/XUnit/java)


## Playground

Space for testing out little projects/ideas that take a bit of time.

### Projects

* [Languages](Playground/Languages/README.md) : implemented in [c++](Playground/Languages/c++), [java](Playground/Languages/java)
* [Levenstein Distance In Tries](Playground/LevensteinDistanceInTries/README.md) : implemented in [c++](Playground/LevensteinDistanceInTries/c++)


## Project Euler Problems

My project euler username is **Starter101**. Not all the problems I did are listed below and all of them are done in C++.

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


## Appendix

### How to Build & Run

Here are some insights on how the projects can be compiled and ran.

#### C++

For C++, I'm using [cmake](https://cmake.org/overview/) allowing to compile the project on all the platforms.

##### Prerequisites

* CMake must be installed and accessible from the sources
* Most of the sources require a C++ 11 compiler
* [googletests](https://github.com/google/googletest) must be installed on the system
* Perl must be installed on the system to run the setup script

##### Build & Run <sup>[1](#note1)</sup> <sup>[2](#note2)</sup>

* First, run the __setup.pl__ script which can be found in the [Kata sources directory](Kata/sources)
	* Depending on the project, it will create or update the CMakeFileList.txt of the different directories (projects).
	* Some scripts will require parameters. Those are mentioned in the usage of the script (simply run the program without parameters)
* Then, run the cmake commands
	* Example:
		* Create a build directory in the source folder where CMakeFileList.txt is
		* In a command prompt, in the build directory run:
			* __cmake ..__ 
			* Add [__-G "Visual Studio 14 2015 Win64"__] to generate a visual studio solution on windows <sup>[3](#note3)</sup>
			* Add [__-G "Unix Makefiles"__] to generate a simple makefile

#### Python

For python, I'm using [nose](http://nose.readthedocs.io/en/latest/) to run the tests and [spyder](https://pythonhosted.org/spyder/) as IDE in order to have nice formatted unit test outputs.

When nose is installed and accessible from any directory :
* In a command prompt, go to the directory containing the unit tests
* Run nosetests, and the tests results will appear

#### Java

For Java, I'm using maven. With IDEs like Intellij and eclipse, simply import the project (pom.xml file). 
For the tests, I'm using JUnit 5 with the [Google Truth library](https://github.com/google/truth) for assertions.
	
	
---

_<a name="note1">1</a>: The compiling instructions represent my preferred way and allow to compile easily on all platforms. Nothing prevents you to use your own compilation method._

_<a name="note2">2</a>: Some projects may not work on all platforms. See the projects page for more information about that._

_<a name="note3">3</a>: In Visual Studio, when gtest is used, set the project to the same C/C++ > Code Generation > Runtime Library._
