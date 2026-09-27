#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 150;

struct Student {
    int studentID;
    double score;
};
void selectionSortID(Student students[], int size)
{
    int minIndex;
    Student temp;
    for (int start = 0; start < size - 1; start++)
    { 
        minIndex = start;
        for (int i = start + 1; i < size; i++)
        {
            if (students[i].studentID < students[minIndex].studentID)
            {
                minIndex = i;
            }
        }
        
    }
}