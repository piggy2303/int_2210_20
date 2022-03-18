#include <iostream>
#include <vector>

using namespace std;

// 3.	Draw the 17-entry hash that results from using the hash function
// h(i) = (i+3) mod 17 to hash keys
// 1, 3, 18, 8, 23, 35, 11, 36, 20, 16.
// c)	Assume collisions are handled by chaining.
// d)	Assume collisions are handled by linear probing.

int h(int i)
{
    return i % 17;
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

int main()
{

    vector<int> adding_arr;
    adding_arr.push_back(17); // 0
    adding_arr.push_back(17); // 0 > 1
    adding_arr.push_back(18); // 1 > 2

    int n = 17;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    int coutting = 0;
    // insert
    for (int i = 0; i < adding_arr.size(); i++)
    {
        int x = adding_arr[i];
        int index_insert = h(x);
        // cout << index_insert << endl;

        while (arr[index_insert] != 0)
        {
            index_insert = (index_insert + 1) % n;

            if (coutting == n)
            {
                cout << "khong the them" << endl;
                break;
            }
            coutting++;
        }
        arr[index_insert] = x;
    }
    print_hash(n, arr);

    // get
    int search_value = 19;

    int index_get = h(search_value);

    coutting = 0;
    while (true)
    {
        if (arr[index_get] == search_value)
        {
            cout << "tim thay vi tri " << index_get << endl;
            break;
        }

        index_get = (index_get + 1) % n;
        coutting++;
        if (coutting == n)
        {
            cout << "khong tim thay" << endl;
            break;
        }
    }

    // delete
    int delete_value = 17;
    int index_detele = h(delete_value);
    coutting = 0;
    while (true)
    {
        if (arr[index_detele] == delete_value)
        {
            cout << "delete tai vi tri " << index_detele << endl;
            arr[index_detele] = 0;
            break;
        }

        index_detele = (index_detele + 1) % n;
        coutting++;
        if (coutting == n)
        {
            cout << "khong tim thay, can not delete" << endl;
            break;
        }
    }

    print_hash(n, arr);

    return 0;
}