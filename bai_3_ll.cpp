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
    return i % 7;
}

void print_hash(int n, vector<int> arr[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "+++++++" << endl;
}

int main()
{

    vector<int> adding_arr;
    adding_arr.push_back(7);  // 0
    adding_arr.push_back(14); // 0 > 1
    adding_arr.push_back(21); // 1 > 2
    adding_arr.push_back(8);
    adding_arr.push_back(15);

    int n = 7;
    vector<int> arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].push_back(0);
    }
    // print_hash(n, arr);

    // insert
    for (int i = 0; i < adding_arr.size(); i++)
    {
        int insert_value = adding_arr[i];
        int insert_index = h(insert_value);

        arr[insert_index].push_back(insert_value);
        arr[insert_index][0]++;
    }
    print_hash(n, arr);

    //  get
    int search_value = 3;
    int search_index = h(search_value);
    bool found = false;

    if (arr[search_index][0] != 0)
    {

        for (int i = 1; i < arr[search_index].size(); i++)
        {
            if (arr[search_index][i] == search_value)
            {
                found = true;
                cout << "tim thay tai " << search_index << " " << i << endl;
                break;
            }
        }
    }
    if (!found)
    {
        cout << "khong tim thay" << endl;
    }

    // detect
    search_value = 7;
    search_index = h(search_value);
    found = false;

    if (arr[search_index][0] != 0)
    {

        for (int i = 1; i < arr[search_index].size(); i++)
        {
            if (arr[search_index][i] == search_value)
            {
                found = true;
                cout << "tim thay tai " << search_index << " " << i << endl;
                arr[search_index].erase(arr[search_index].begin() + i);
                arr[search_index][0]--;
                break;
            }
        }
    }
    if (!found)
    {
        cout << "khong tim thay" << endl;
    }
    print_hash(n, arr);
    return 0;
}
