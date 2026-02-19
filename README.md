# Cpp Undirected Graphs 

## Overview

This project is a modular C++ command-line application designed to support the study of Undirected Graphs. It combines theoretical content (Definitions) with an interactive assessment module (Interactive Quiz).


## Project Structure

### main.cpp

* Entry point of the application.
* Acts as a wrapper/orchestrator.

### structure.*

Responsible for:

* Displaying the application title (intro screen).
* Implementing the main menu:
  * 1.Definitions
  * 2.Test
  * 3.Exit
* Exit message display.

### def.*

* Contains the function responsible for displaying definitions.
* Taken as separate module due to the large volume of content.

### test.*

Contains the function that displays the questions, as well as the assessment logic:

* Question handling
* Multiple input types:
  * Letter
  * Number
  * Single word
* Answer verification
* Score calculation

### util.*

Reusable utility functions:

* Input validation
* Menu handling helpers
* Console formatting (borders, titles)
* Screen transition logic

## Build Instructions

This project uses a Makefile for compilation.

### Compile
```bash
make all
```

Then run:
```bash
./out
```

### Clean build files
```bash
make clean
```



## Requirements

* C++ compiler supporting C++11 or later (e.g., g++)
* GNU Make
