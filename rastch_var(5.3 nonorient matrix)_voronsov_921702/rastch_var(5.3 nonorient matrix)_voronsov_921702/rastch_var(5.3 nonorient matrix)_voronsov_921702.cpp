#include <fstream>
#include <iostream> 
#include <string>
using namespace std;


 

void printSolution(int path[],int sides);


bool isSafe(int v, bool** graph,int path[], int pos,int sides)
{
	//check if next is a neibor to previous
	if (graph[path[pos - 1]][v] == 0)
		return false;

	//check if its already in place
	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return false;

	return true;
}


bool hamCycleUtil(bool** graph,int path[], int pos, int sides)
{
	//for when all are in path
	if (pos == sides)
	{
		//when there is side from last to first
		if (graph[path[pos - 1]][path[0]] == 1)
			return true;
		else
			return false;
	}


	for (int v = 1; v < sides; v++)
	{

		if (isSafe(v, graph, path, pos,sides))
		{
			path[pos] = v;


			if (hamCycleUtil(graph, path, pos + 1,sides) == true)
				return true;

             //to remove point if if doesnt lead to solution
			path[pos] = -1;
		}
	}

	//when we cant add more but not done yet
	return false;
}


bool hamCycle(bool** graph,int sides)
{
	int* path = new int[sides];
	for (int i = 0; i < sides; i++)
		path[i] = -1;

    //if there is hamil cycle starting point doesnt matter
	path[0] = 0;
	if (hamCycleUtil(graph, path, 1, sides) == false)
	{
		cout << "\nSolution does not exist";
		return false;
	}

	printSolution(path,sides);
	return true;
}


void printSolution(int path[],int sides)
{
	cout << "Solution Exists:"
		" Following is one Hamiltonian Cycle \n";
	for (int i = 0; i < sides; i++)
		cout << path[i] << " ";


	cout << path[0] << " ";
	cout << endl;
}


int main()
{
	string path="graph";
	int swi;
	cout << "0 for graph.txt or 1 to input file nime in console, max graph size 10"<<endl;
	cin >> swi;
	switch(swi)
	{
	case 0: path = "graph"; break;
	case 1:cin >> path; break;
	};
	

	
	int lines = 0, sides=0;
	string chek[100];
	ifstream fread;
	fread.open(path+".txt");
	while(!fread.eof())
	{
		fread >> chek[lines];
		cout << chek[lines] <<endl;
		lines++;
	}
	sides = sqrt(lines);
	
	
	
	

	bool **arr = new bool* [sides];
    for (int i = 0; i < sides; i++)
    {
	    arr[i] = new bool[sides];
    }
	int counter=0;
	for (int f = 0; f < sides-1; f++)
	{
	
		for(int j=0;j<sides-1;j++)
		{
		
			arr[f][j] = stoi(chek[counter]);
			counter++;
		}
  	    counter++; }

	hamCycle(arr, sides);
	
	
	
	
	/*bool graph1[V][V] = { {0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{0, 1, 1, 1, 0} };

	hamCycle(graph1);

	cout << " " << endl;
	bool graph2[V][V] = { {0, 1, 0, 1, 0},
						 {1, 0, 1, 1, 1},
						 {0, 1, 0, 0, 1},
						 {1, 1, 0, 0, 0},
						 {0, 1, 1, 0, 0} };


	hamCycle(graph2);
	cout << " " << endl;
	bool graph3[V][V] = { {0, 0, 0, 1, 1},
						{1, 0, 1, 1, 0},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{1, 0, 1, 1, 0} };


	hamCycle(graph3);
	cout << " " << endl;
	bool graph4[V][V] = { {0, 0, 1, 0, 1},
						{0, 0, 1, 0, 1},
						{1, 1, 0, 1, 0},
						{0, 0, 1, 0, 1},
						{1, 1, 0, 1, 0} };

	hamCycle(graph4);
	
	
	cout << " " << endl;*/

for (int i = 0; i < sides; i++)
     {
	  delete[] arr[i];
     }
     delete[] arr;
	return 0;
}
