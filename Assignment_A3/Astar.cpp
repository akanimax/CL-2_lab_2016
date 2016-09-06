#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
#define INFINITY 999

using namespace std;

// implementing the depth first and breadth first search (Uninformed search algos)
class Graph {
private:
    int GraphMatrix[100][100]; // hard limit on the number of nodes as 100
    int number_of_nodes; // number of nodes

    void init() { // private helper method
        for(int i=0; i<number_of_nodes; i++) {
            for(int j=0; j<number_of_nodes; j++) {
                GraphMatrix[i][j] = INFINITY;
            }
        }
    }

	int g(int node) {
		// g(n): cost of the path from the start node to n 
		// TODO implement g(n) function
		return 0; // for now
	}

	int h(int node) {
		// h(n): heuristic function that estimates the cost of the cheapest path from n to the goal. 
		// TODO implement h(n) function
		
		static avg = 0;
		if(avg == 0) {
			// calc the average cost of a link between the nodes
			int total_edges = 0;
			for(int i=0; i<number_of_nodes; i++) {
				for(int j=0; j<number_of_nodes; j++) {
				}
			}	
		}
		
		return 0; // for now
	}
	
	int f(int node) { 
		// f(n) = g(n) + h(n)
		return g(node) + h(node); 
	}
	

public:

    Graph(int nodes) { // constructor of the class
        number_of_nodes = nodes;
        init();
    }

	void a*(int start, int goal) { // astar algo to find least cost path from the start to goal
	
	}


    void inputGraph() { // input the graph from the command line
        for(int i=0; i<number_of_nodes; i++) {
            for(int j=i+1; j<number_of_nodes; j++) {
                char choice;
                cout << "Is there an edge from " << i << " to " << j <<" (y/n): ";
                cin  >> choice;

                if(choice == 'y' or choice == 'Y') {
                    int weight; cout << "Enter Weight: "; cin >> weight;
                    GraphMatrix[i][j] = GraphMatrix[j][i] = weight; // assign the weight to the graph
                }
            }
        }
    }

    void printGraph() { // to print the graph
        cout << "The current contents of the graph are: " << endl;
        for(int i=0; i<number_of_nodes; i++) {
            for(int j=0; j<number_of_nodes; j++) {
                cout << GraphMatrix[i][j] << "\t";
            }
            cout << endl; // for new line
        }
    }

    void generateRandom() { // generate Random graph
        srand(time(0)); // Probability of an empty edge is 1/10
        for(int i=0; i<number_of_nodes; i++) {
            for(int j=i+1; j<number_of_nodes; j++) {
                int randomNo = rand() % 10 + 1; // generate Random numbers between 1 to 10
                if(randomNo != 10) {
                    GraphMatrix[i][j] = GraphMatrix[j][i] = randomNo;
                }
            }
        }
    }
};

int main() {
	Graph g1(10);
	g1.generateRandom();
	g1.printGraph();	

}
