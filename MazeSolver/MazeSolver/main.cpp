#include"MazeSolver.h"

int main(int argc, char* argv[])
{
	if(argc<2)
	{
		return -1;
	}

	MazeSolver myMazeSolver(argv[1]);
	myMazeSolver.solveMaze();

	if(argc==3)
	{
		if (string(argv[2]) == "-d")
		{
			myMazeSolver.DisplaySolutionSteps();
		}
		else if(string(argv[2]) == "-r")
		{
			myMazeSolver.DisplayFinalSolution();
		}
		else
		{
			cerr << "3rd PARAMETER UNDEFINED!!" << endl;
		}
	}
	
	
	waitKey(0);
	return 0;
}
