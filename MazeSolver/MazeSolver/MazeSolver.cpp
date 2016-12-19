#include "MazeSolver.h"

MazeSolver::MazeSolver(const string &imagePath)
{
	this->_mazeImage = imread(imagePath);
	this->_processedMazeContours = nullptr;
}

Mat MazeSolver::getMazeImage() const
{
	return this->_mazeImage;
}

Mat MazeSolver::getMazeSolution() const
{
	return this->_mazeSolution;
}


void MazeSolver::DisplayFinalSolution()const
{
	imshow("Maze solution", this->_mazeSolution);
}

void MazeSolver::DisplaySolutionSteps() const
{
	imshow("STEP #1: Maze image ", this->_mazeImage);

	imshow("STEP #2: Maze binary", this->_binaryMaze);

	imshow("STEP #3: Maze contours ", this->_initialMazeContours);

	imshow("STEP #4: Dilation", this->_dilatedContours);

	imshow("STEP #5: Erosion", this->_erodedContours);

	imshow("STEP #6: Dilation-Erosion", this->_dilationErosion_diff);

	imshow("STEP #7: Maze solution", this->_mazeSolution);
}


Mat convertToBinary(const Mat &image)
{
	Mat bi;
	cvtColor(image, bi, CV_BGR2GRAY);
	threshold(bi, bi, 10, 255, CV_THRESH_BINARY_INV);

	return bi;
}

Mat imageClosing(Mat image)
{	
	Mat dilte = Mat::ones(19, 19, CV_8UC1);
	dilate(image, image, dilte);

	Mat erde;
	erode(image, erde, dilte);

	return erde;
}


bool MazeSolver::fetchMazeContours()
{

	vector<vector<Point>> contours;
	findContours(this->_processedBinaryMaze, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	if (contours.size() != 2)
	{
		return false;
	}

	this->_processedMazeContours = new Mat(this->_processedBinaryMaze.size(), CV_8UC3, Scalar(0, 0, 0));
	Scalar colors[3];
	colors[0] = Scalar(255, 0, 0);
	colors[1] = Scalar(0, 0, 0);
	colors[2] = Scalar(0, 0, 0);
	for (size_t idx = 0; idx < contours.size(); idx++)
	{
		drawContours(*this->_processedMazeContours, contours, idx, colors[idx % 3]);
	}

	this->_initialMazeContours = this->_processedMazeContours->clone();

	return true;
}

void MazeSolver::showMazePath()
{
	Mat erodedMaze = imageClosing(*this->_processedMazeContours);
	this->_dilatedContours = this->_processedMazeContours->clone();
	this->_erodedContours = erodedMaze;

	absdiff(*_processedMazeContours, erodedMaze, *_processedMazeContours);
	this->_dilationErosion_diff = _processedMazeContours->clone();

	addWeighted(this->_mazeImage, 0.5, *_processedMazeContours, 1.0 - 0.5, 0.0, this->_mazeSolution);
}

void MazeSolver::solveMaze()
{
	this->_processedBinaryMaze = convertToBinary(this->_mazeImage);
	this->_binaryMaze = this->_processedBinaryMaze.clone();

	if(!fetchMazeContours())
	{
		cerr << "THIS IS NOT A PERFECT MAZE !!" << endl;
		return;
	}

	showMazePath();

	imwrite("MazeSolution.png", this->_mazeSolution);
}

