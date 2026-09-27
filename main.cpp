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
        temp = students[start];
        students[start] = students[minIndex];
        students[minIndex] = temp;
    }
}

void selectionSortScore(Student students[], int size)
{
    int minIndex;
    Student temp;
    for (int start = 0; start < size - 1; start++)
    { 
        minIndex = start;
        for (int i = start + 1; i < size; i++)
        {
            if (students[i].score < students[minIndex].score)
            {
                minIndex = i;
            }
        }
        temp = students[start];
        students[start] = students[minIndex];
        students[minIndex] = temp;
    }
}

int findMinimum(Student students[], int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (students[i].score < students[minIndex].score)
        {
            minIndex = i;
        }
    }
    return minIndex;
}
int findMaximum(Student students[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (students[i].score > students[maxIndex].score)
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}
double findMean(Student students[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += students[i].score;
    }
    return total / size;        
}
double findStandardDeviation(Student students[], int size, double mean)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += pow(students[i].score - mean, 2);
    }
    return sqrt(total / size);
}
