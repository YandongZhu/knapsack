#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

struct info
{
	int value = 0;
	string item = "";
	int count = 0;
};

int space = 0;
int file = 0;
std::vector<pair <int, int> > totalFile;

struct info add(struct info cur, int i, int val)
{
	struct info temp;
	temp.value = cur.value + val;
	temp.item = cur.item + to_string(i+1) + " ";
	temp.count = cur.count + 1;
	return temp;
}

struct info max(struct info lhs, struct info rhs)
{
	struct info temp;
	if (lhs.value > rhs.value)
	{
		temp.value = lhs.value;
		temp.item = lhs.item;
		temp.count = lhs.count;
		return temp;
	}
	else
	{
		temp.value = rhs.value;
		temp.item = rhs.item;
		temp.count = rhs.count;
		return temp;		
	}
}

struct info knapsack(int i, int rest, struct info cur){
	struct info temp;
 	if (rest < 0)
	{
		temp.value = -1;
		return temp;
	}
	else if (i >= file)
	{
		return cur;
	}
	else
	{
		temp = knapsack(i+1, rest - totalFile[i].first, add(cur, i, totalFile[i].second));
		//cout << " temp " << temp.value << " " << temp.item << endl;
		struct info temp1 = knapsack(i+1, rest, cur);
		//cout << " temp1 " << temp1.value << " " << temp1.item << endl;

		return max(temp, temp1);
	}

}

int main(int argc, char const *argv[])
{
	int size;
	int weight;
	pair <int, int> temp;
	cin >> file >> space;

	for (int i = 0; i < file; ++i)
	{
		cin >> size >> weight;
		temp = make_pair(size, weight);
		totalFile.push_back(temp);
	}
	struct info base;
	struct info info_temp = knapsack(0, space, base);
	cout << info_temp.value << " " << info_temp.count << endl;
	cout << info_temp.item << endl;
	return 0;
}