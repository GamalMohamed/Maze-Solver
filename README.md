# Maze Solver app

## What's this?
 It's an app that solves a Maze!  
 The app takes the Maze's image as an input and outputs the solution path superimposed on its image..  
   
 Built using OpenCV 3.1 in C++  and developed on VS2015...
 
## How to use?
 * User provides the path for the **maze image** and **a flag** whether to display the steps of maze solution "-d" or just display the final solution "-r".
 * If no or wrong flag is provided, default behaviour is to output the final solution as a png image only.  
 * The app takes the command line arguments as follows: <exe name> <image_name> <-d or -r>  
 * e.g. MazeSolver.exe maze.png -d  OR  MazeSolver.exe maze.png -r

  
## Constraints

**Maze must be a Perfect maze**  
A “Perfect maze” is defined as a maze which has one and only one path from any point in the maze to any other point.  
This means that the maze has no inaccessible sections, no circular paths, and no open areas.
 

## Algorithms used 
 * Binary image analysis
 * OpenCV findContours algorithm (Suzuki, S. and Abe, K., Topological Structural Analysis of Digitized Binary Images by Border Following)
 * Mathematical Morphology methods (Dilation & Erosion)
 * Standard image processing methods (Pre & Post-Processing, Image enhancement & segmentation)

