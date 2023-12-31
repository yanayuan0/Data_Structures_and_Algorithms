#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <string>

#include "adts/list.h"
#include "maze.h"

using std::string;

/**
 * Reads a map from the specified file.
 * @param filename The name of the map file.
 * @return A pointer to the Maze object containing that map.  Deleting this
 *         object is the caller's responsibility.
 * @throws runtime_error If an error occurs while reading the file.
 */
Maze* loadMap(string filename);

/**
 * Transforms a solution into a string.
 * @param maze The Maze to use.
 * @param solution A list of the Position objects in the path.
 * @return The string representing the solution.
 */
string renderAnswer(Maze* maze, List<Position*>* solution);
