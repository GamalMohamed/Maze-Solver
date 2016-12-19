#pragma once
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class MazeSolver
{
private:
	Mat _mazeImage, _mazeSolution;
	Mat _binaryMaze, _initialMazeContours, _dilatedContours, _erodedContours, _dilationErosion_diff;
	Mat* _processedMazeContours;
	Mat _processedBinaryMaze;

	bool fetchMazeContours();
	void showMazePath();

public:
	MazeSolver(const string&);

	void solveMaze();

	void DisplayFinalSolution()const;
	void DisplaySolutionSteps()const;

	Mat getMazeSolution()const;
	Mat getMazeImage()const;


};

