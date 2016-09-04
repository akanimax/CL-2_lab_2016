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

public:

    Graph(int nodes) { // constructor of the class
        number_of_nodes = nodes;
        init();
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

    void depthFirst(int searchNode) { // generate the depthFirst Search
        stack<int> Stack; Stack.push(0);
        bool found = false; // found is false
        while(!Stack.empty()) {
            int node = Stack.top(); Stack.pop(); // pop the first element
            cout << node << endl;

            if(node == searchNode) {
                found = true; break;
            }

            for(int j=number_of_nodes - 1; j > node; j--) {
                if(GraphMatrix[node][j] != INFINITY) Stack.push(j);
            }
        }

        if(found) {
            cout << "NODE FOUND!!!" << endl;
        } else cout << "NODE NOT FOUND!!" << endl;
    }

    void breadthFirst(int searchNode) {
        queue<int> Queue; Queue.push(0);
        bool found = false; // found is false
        while(!Queue.empty()) {
            int node = Queue.front(); Queue.pop(); // pop the first element
            cout << node << endl;

            if(node == searchNode) {
                found = true; break;
            }

            for(int j=node+1; j < number_of_nodes; j++) {
                if(GraphMatrix[node][j] != INFINITY) Queue.push(j);
            }
        }

        if(found) {
            cout << "NODE FOUND!!!" << endl;
        } else cout << "NODE NOT FOUND!!" << endl;
    }
};

int main() {
    Graph g1(5); // graph of 5 nodes
    g1.generateRandom();
    g1.printGraph();
    cout << endl;
    g1.depthFirst(3); // node possible
    cout << endl;
    g1.depthFirst(123); // node not possible
    cout << endl;
    g1.breadthFirst(3); // node possible
    cout << endl;
    g1.breadthFirst(123); // node not possible
}
