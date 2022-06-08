/*
* Title: CS202 Spring 2022
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 4
* Description: Graph.cpp
*/
#include "Graph.h"



Graph::Graph() : size(0) , airports(NULL) {

}
Graph::Graph(int airPortCount) {
    totalAirPortSize = airPortCount;
    size = 0;
    airports = new LinkedList* [airPortCount];
    // Allocate memory for all nodes
    for (int i = 0; i < airPortCount; ++i) {
        airports[i] = new LinkedList();
    }

}
Graph::Graph(const Graph &aGraph) {

}
Graph::~Graph() {

}

void Graph::printGraph() {
    for (int i = 0; i < size; ++i) {
        airports[i]->print();
        cout << endl;
    }
}

void Graph::addEdgesWithoutPrint(int airport1, int airport2, int weight) {

    // Try to find that vertex
    LinkedList* currentTarget1 = getVertex(airport1);
    LinkedList* currentTarget2 = getVertex(airport2);

    // If there is not any vertex create head of linkedList
    if (currentTarget1 == NULL) {
        currentTarget1 = addVertex(airport1);
        size++;
    }
    if (currentTarget2 == NULL) {
        currentTarget2 = addVertex(airport2);
        size++;
    }

    // Add edge to the end of the vertex

    // Add one direction
    int air1Size = currentTarget1->getLength() + 1;
    currentTarget1->insert(air1Size , airport2, weight);
    // Add other direction
    int air2Size = currentTarget2->getLength() + 1;
    currentTarget2->insert(air2Size , airport1, weight);


}
void Graph::addEdges(int airport1, int airport2, int weight) {

    // Try to find that vertex
    LinkedList* currentTarget1 = getVertex(airport1);
    LinkedList* currentTarget2 = getVertex(airport2);

    // If there is not any vertex create head of linkedList
    if (currentTarget1 == NULL) {
        currentTarget1 = addVertex(airport1);
        size++;
    }
    if (currentTarget2 == NULL) {
        currentTarget2 = addVertex(airport2);
        size++;
    }

    // Add edge to the end of the vertex

    // Add one direction
      int air1Size = currentTarget1->getLength() + 1;
      currentTarget1->insert(air1Size , airport2, weight);
    // Add other direction
      int air2Size = currentTarget2->getLength() + 1;
      currentTarget2->insert(air2Size , airport1, weight);

      cout << "Inserted a new flight between " << airport1 << " and " << airport2 << "." << endl ;
      cout << "   The number of flights from " << airport1 << " is " <<  (currentTarget1->getLength()-1) << "." << endl ;
}

//
LinkedList* Graph::addVertex(int airport) {

    airports[size]->insert(1,airport,0);
    return airports[size];
}

LinkedList* Graph::getVertex(int airport) {
    for (int i = 0; i < totalAirPortSize; ++i) {
        int currentAirport;
        int currentWeight;

        airports[i]->retrieve(1 , currentAirport, currentWeight );
        if (currentAirport == airport) {
            return  airports[i];

        }
    }
    return NULL;
}

void Graph::listFlights( int airPortNo) {
    LinkedList* current = getVertex(airPortNo);
    int count = 0;
    if (current != NULL) {

        cout << "List of flights from " << airPortNo << ":" << endl;
        count =  current->print();

    }
    else {
        cout << "Cannot Listed because airport did not be inserted!";
    }
        cout << "The number of flights is " << count << "." << endl;
}

bool Graph::shortestPath(int startingVertexIndex ,  int *&weights, int *&previousVertex) {
        int visitedCount = 2;
    previousVertex = new int [totalAirPortSize];
    for (int i = 0; i < totalAirPortSize; ++i) {
        previousVertex[i] = -1;
    }

    // Getting the first vertex
    LinkedList* startingVertex = getVertex(startingVertexIndex);
    if (startingVertex !=  NULL) {


        // Creating the weight array
        weights = new int[totalAirPortSize];
        // Creating the vertexSet array

        int *vertexSet = new int[totalAirPortSize];
        for (int i = 0; i < totalAirPortSize; ++i) {
            vertexSet[i] = 0;
        }
        // Filling the weight array with initially INF
        for (int i = 0; i < totalAirPortSize; ++i) {
            weights[i] = 999999; // 999999 for inf
        }

        int currentVisitingIndex = startingVertexIndex;

        // Setting the initial vertex's weight as a 0
        weights[startingVertexIndex] = 0;

        //Adding the first element to vertex set
        vertexSet[startingVertexIndex] = 1;

       int go = startingVertex->initDijkstra(weights, previousVertex, totalAirPortSize,vertexSet);
        bool done ;
        while(visitedCount < totalAirPortSize) {
            getVertex(go)->addWeightsToArray(weights,totalAirPortSize,vertexSet,previousVertex,go);
            visitedCount++;
        }

        /*
        for (int i = 0; i < totalAirPortSize; ++i) {

            if (i != startingVertexIndex) {
                airports[i]->addWeightsToArray(weights, totalAirPortSize, vertexSet, previousVertex);
            }

        }
         */
        /*  while ( visitedSoFar != size ) {
              // Look their neighbors
              // if weight[current Neighbor] > currentVisitingWeight (= weight[currentVisitingIndex])
              // &&
              startingVertex->addWeightsToArray(weights, size , vertexSet ,previousVertex, visitedSoFar);
          }

      */
        return true;
    }
    return false;

}

void Graph::shortestPathCalculate(int first , int second) {


    int* weight;
    int* lPath ;
    int count = 1;

    bool isFound = shortestPath(second, weight , lPath);
    if (isFound) {
        cout << "The shortest path from " << first << " to " <<  second  << endl;
        /*
        for (int i = 0; i < 5; ++i) {
            cout << weight[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 5; ++i) {
            cout << lPath[i] << " ";
        }
*/      int totalDur = weight[first];
        int index1 = first;
        int index2 = lPath[index1];

        int weight1 = weight[first];
        int weight2 = weight[lPath[index1]];
        int fsub = weight1 - weight2;

        cout << "   " << first << " to " << lPath[index1] << " with a duration " << fsub << endl;

        while (lPath[index2] != -1) {
            count++;
            index1 = index2;
            index2 = lPath[index1];

            weight1 = weight2;
            weight2 = weight[lPath[index1]];
            int sub = weight1 - weight2;

            cout << "   " << index1 << " to " << lPath[index1] << " with a duration " << sub << endl;

            int index = lPath[second];
        }
        cout << "   The total flight duration of path: " << totalDur << endl;


    } else {
        cout << "No paths from " << first << " to " << second << "." << endl;
    }


}

Graph Graph::Prims() {

    Graph graphPrim(totalAirPortSize);

int* vertexSet = new int[totalAirPortSize];
    int sum=0;
    int sumTemp = 0;

    for (int i = 0; i < totalAirPortSize; ++i) {
        vertexSet[i] = 0;
    }
    LinkedList* current;
    bool finish = false;
    int index = 0;
    int nb = 1;

    current = getVertex(index);
    int minIndex = 99999;
    vertexSet[0] = 1;
    bool first = false;

   /* while (!first) {

        for (int i = 0; i < totalAirPortSize; ++i) {
            if (   airports[i]->getLength() > 1) {
                minIndex = airports[i]->primsAlgo(sum, vertexSet);
                first = true;
            }

        }
    }
*/
    while (!finish) {
        minIndex = 99999;
        int currentMinEdge = 99999;
        int currentMinFrom = -1;
     //   index =  current->primsAlgo(sum, vertexSet);
        bool c = false;
        for (int i = 0; i < totalAirPortSize ; ++i) {
            if (vertexSet[i] == 1) {
                current = getVertex(i);
                if (current->primsAlgo(sum, vertexSet, minIndex, currentMinEdge)) {
                    c = true;
                    current->retrieve(1, currentMinFrom);
                }


            }
        }
        if (c) {

            graphPrim.addEdgesWithoutPrint(currentMinFrom,minIndex, currentMinEdge);
            sum += currentMinEdge;
            vertexSet[minIndex] = 1;
            nb += vertexSet[minIndex];
        }
        if (totalAirPortSize == nb) {
            finish = true;
        }
    }

    cout << "Total cost of operations after minimization: " << sum << endl;
    return  graphPrim;

}

void Graph::findDuration() {
    int sum = 0;
    for (int i = 0; i < totalAirPortSize; ++i) {
       sum = sum + airports[i]->sumWeight();
    }
    cout << "Total cost of operations before minimization: " << (sum/2) << endl;

}