#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void swapValue(int&, int&);
void printArray(int[], int);
void bubbleSort(int[], int);
void otimizedBubbleSort(int[], int);

int main()
{
    int arriNumbers_1[] = {42, 7, 0, 3, 67, 1, 111, 10, 13};
    int iArraySize_1 = 9;

    cout << "Array original: ";
    printArray(arriNumbers_1, iArraySize_1);

    // time_point<std::chrono::high_resolution_clock>
    auto timeStart = high_resolution_clock::now();

    bubbleSort(arriNumbers_1, iArraySize_1);

    auto timeStop = high_resolution_clock::now();

    cout << "Array ordenado ";
    printArray(arriNumbers_1, iArraySize_1);

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;
    cout << "============================" << endl;

    int arriNumbers_2[] = {42, 7, 0, 3, 67, 1, 111, 10, 13, 137};
    int iArraySize_2 = 10;

    cout << "Array original: ";
    printArray(arriNumbers_2, iArraySize_2);

    timeStart = high_resolution_clock::now();

    otimizedBubbleSort(arriNumbers_2, iArraySize_2);

    timeStop = high_resolution_clock::now();

    cout << "Array ordenado ";
    printArray(arriNumbers_2, iArraySize_2);

    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;
    cout << "============================" << endl;

    return 0;
}

void swapValue(int& iValue_1, int& iValue_2)
{
    int iTemp = iValue_1;
    iValue_1 = iValue_2;
    iValue_2 = iTemp;
}

void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i++) cout << arriNumbers[i] << " ";
    cout << endl;
}

void bubbleSort(int arriNumbers[], int iLength)
{
    for (int iOuterLoop = 0; iOuterLoop < iLength; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iLength-1; iInnerLoop++)
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
}

void otimizedBubbleSort(int arriNumbers[], int iLength)
{
    bool bUnordered = false;

    for (int iOuterLoop = 0; iOuterLoop < iLength; iOuterLoop++)
    {
        bUnordered = false;

        for (int iInnerLoop = 0; iInnerLoop < (iLength-1)-iOuterLoop; iInnerLoop++)
        {
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
            {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
                bUnordered = true;
            }
        }

        if (bUnordered == false) break;
    }
}