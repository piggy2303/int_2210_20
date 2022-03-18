#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct sv
{
    int key;
    string ten;
    string lop;

    sv()
    {
        key = 0;
        ten = "";
        lop = "";
    }

    sv(int k, string t, string l)
    {
        key = k;
        ten = t;
        lop = l;
    }
};

map<sv *, int> my_map;

// Insert(1,Tuan,K61CS)

void Insert(int k, string t, string l)
{

    map<sv *, int>::iterator it;

    bool found = false;
    for (it = my_map.begin(); it != my_map.end(); ++it)
    {
        if (it->first->key == k)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        sv *sv1 = new sv(k, t, l);
        my_map[sv1] = k;
    }
}

void Infor(int k)
{
    map<sv *, int>::iterator it;

    bool found = false;
    for (it = my_map.begin(); it != my_map.end(); ++it)
    {
        if (it->first->key == k)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << " " << it->first->ten << " " << it->first->lop << endl;
    }
    else
    {
        cout << "NA,NA" << endl;
    }
}

void Delete(int k)
{
    map<sv *, int>::iterator it;

    bool found = false;
    for (it = my_map.begin(); it != my_map.end(); ++it)
    {
        if (it->first->key == k)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        my_map.erase(it);
    }
}

int main()
{
    Insert(1, "Tuan", "K61CS");
    Insert(2, "Vinh", "K43C");
    Infor(3);
    Infor(2);
    Delete(2);
    Infor(2);

    return 0;
}