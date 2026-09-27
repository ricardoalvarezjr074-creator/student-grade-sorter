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

int main()
{
    Student students[SIZE];
    Student scoreStudents[SIZE];

    ifstream fin;
    fin.open("210-lab-13-grade.txt");

    if (!fin.good())
    {
        cout <<"File not found!" << endl;
        return 1;       
    }

    int count = 0;
    while (count < SIZE && 
        fin >> students[count].studentID >> students[count].score)
    {
        count++;
    }
    fin.close();

    cout << "Read " << count << " student records." << endl;

    for (int i = 0; i < count; i++)
    {
        scoreStudents[i] = students[i]; 
    }

    int minIndex = findMinimum(students, count);
    double minScore = students[minIndex].score;
    int minID = students[minIndex].studentID;

    int maxIndex = findMaximum(students, count);
    double maxScore = students[maxIndex].score;
    int maxID = students[maxIndex].studentID;

    double mean = findMean(students, count);
   double standardDeviation =
    findStandardDeviation(students, count, mean);

    selectionSortScore(scoreStudents, count);
    int medianIndex = count / 2;
    double medianScore = scoreStudents[medianIndex].score;
    int medianID = scoreStudents[medianIndex].studentID;

    // sort original array by student ID
    selectionSortID(students, count);
    //output file 
    ofstream fout;
    fout.open("210-lab-13-output.txt");
    if (!fout.good())
    {
        cout << "Error opening output file!" << endl;
        return 1;
    }
    for (int i = 0; i < count; i++)
    {
        fout << students[i].studentID << " " << students[i].score << endl;
    }
    fout.close();
    cout << "Sorted results written to " << endl;
         << "210-lab-13-output.txt" << endl;

    cout << endl;
    cout << "--- Summary Statistics ---" << endl;

    cout << "Minimum Score: "
     << minScore
      << " (Student ID: "
         << minID << ")" << endl;
    cout << "Maxium Score: "
         << maxScore
          << " (Student ID: "
             << maxID << ")" << endl;

             cout << "Mean Score: " 
             << mean << endl;

             cout << "Median Score: " 
                  << medianScore
                  << " (Student ID: "
                  << medianID << ")" << endl;

            cout << "Standard Deviation: " 
                  << standardDeviation << endl;
                
                  return 0;
}                  