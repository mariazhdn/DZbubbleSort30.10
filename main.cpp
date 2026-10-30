#include <iostream>
using namespace std;

typedef unsigned int uint;

void gnome_sort_asc(int* arr, uint size)
{
    long long iterations = 0;
    if (size > 1 && arr != nullptr)
    {
        uint i = 0;
        while (i < size - 1)
        {
            iterations++;
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                if (i == 0) { ++i; }
                else { --i; }
            }
            else { ++i; }
        }
    }
    cout << "Iterations: " << iterations << endl;
}

void stupid_sort_asc(int* arr, uint size)
{
    if (arr == nullptr || size <= 1) return;

    int temp;
    long long iterations = 0;

    for (int i = 0; i < (int)size - 1; i++)
    {
        iterations++;
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i = -1;
        }
    }
    cout << "Iterations: " << iterations << endl;
}

void bubble_sort(int* arr, uint size)
{
    long long iterations = 0;
    if (arr != nullptr && size > 0)
    { 
        for (int i = 0; i < (int)size - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < (int)size - 1 - i; j++)
            {
                iterations++;
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
            {
                break;
            }
        }
    }
    cout << "Iterations: " << iterations << endl;
}

void fill_array_randomly(int* arr, uint size)
{
    for (uint i = 0; i < size; i++)
    {
        arr[i] = rand() % 101; 
    }
}

int main()
{
    srand(time(0));

    const uint n = 1000;

    int basic_arr[n];
    int arr1[n];
    int arr2[n];
    int arr3[n];

    fill_array_randomly(basic_arr, n);

    for (uint i = 0; i < n; i++)
    {
        arr1[i] = basic_arr[i];
        arr2[i] = basic_arr[i];
        arr3[i] = basic_arr[i];
    }

    cout << "Comparing of sorting algorithms for " << n << " elements\n" << endl;

    cout << "Gnome sort:" << endl;
    gnome_sort_asc(arr1, n);
    cout << endl;

    cout << "Stupid sort:" << endl;
    stupid_sort_asc(arr2, n);
    cout << endl;

    cout << "Bubble sort:" << endl;
    bubble_sort(arr3, n);
    cout << endl;

    return 0;
}