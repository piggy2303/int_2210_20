#include <iostream>
#include <vector>

using namespace std;

// 2.	Draw the 11-entry hash that results from using the hash function
// h(i) = (2i+5) mod 11

// to hash keys 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5.
// a)	Assume collisions are handled by chaining.
// b)	Assume collisions are handled by linear probing.

int h(int x)
{
    return x % 11;
}

int *insert(int x, int arr[])
{

    return arr;
}

void print_hash(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// delete
// get

int main()
{

    vector<int> a;
    a.push_back(12);
    a.push_back(23);

    int n = 11;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    int arr_v[n];
    // insert
    for (int i = 0; i < a.size(); i++)
    {
        int index_insert = h(a[i]);
        while (arr[index_insert] != 0)
        {
            index_insert = (index_insert + 1) % 11;
        }
        arr[index_insert] = a[i];
    }

    print_hash(n, arr);

    // get
    int x = 23;
    int index_get = h(x);
    int coutting = 0;
    while (true)
    {
        if (coutting == n)
        {
            cout << "not found" << endl;
            break;
        }
        if (arr[index_get] == x)
        {
            cout << "found at" << index_get << endl;
            break;
        }

        index_get = (index_get + 1) % 11;
        coutting++;
    }

    // delete
    int x_delete = 23;
    int index_detele = h(x_delete);
    coutting = 0;
    while (true)
    {
        if (coutting == n)
        {
            cout << "not found" << endl;
            break;
        }
        if (arr[index_get] == x)
        {
            cout << "delete" << endl;
            arr[index_get] = 0;
            break;
        }
        index_get = (index_get + 1) % 11;
        coutting++;
    }

    print_hash(n, arr);

    cout << "end" << endl;
    return 0;
}