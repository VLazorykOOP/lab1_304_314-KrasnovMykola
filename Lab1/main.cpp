#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void task1_v1()
{
	const int n = 5;
	const int n2 = n * 2;
	int a[n2];
	for (int i = 0; i < n2; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
	int b[n2];
	for (int i = 0; i < n; i++)
		b[i] = a[n + i];
	for (int i = 0; i < n; i++)
		b[n + i] = a[i];
	for (int i = 0; i < n2; i++)
		cout << b[i] << " ";
	cout << endl;
}

void task1_v2()
{
	int n;
	cout << "Input n: ";
	cin >> n;
	int n2 = n * 2;
	int* a = (int*)malloc(n2 * sizeof(int));
	for (int i = 0; i < n2; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
	int* b = (int*)malloc(n2 * sizeof(int));
	for (int i = 0; i < n; i++)
		b[i] = a[n + i];
	for (int i = 0; i < n; i++)
		b[n + i] = a[i];
	for (int i = 0; i < n2; i++)
		cout << b[i] << " ";
	cout << endl;
	free(a);
	free(b);
}

void task1_v3()
{
	int n;
	cout << "Input n: ";
	cin >> n;
	int n2 = n * 2;
	int* a = new int[n2];
	for (int i = 0; i < n2; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
	int* b = new int[n2];
	for (int i = 0; i < n; i++)
		b[i] = a[n + i];
	for (int i = 0; i < n; i++)
		b[n + i] = a[i];
	for (int i = 0; i < n2; i++)
		cout << b[i] << " ";
	cout << endl;
	delete[]a;
	delete[]b;
}

void task1_v4()
{
	int n, temp;
	cout << "Input n: ";
	cin >> n;
	int n2 = n * 2;
	vector<int> a;
	for (int i = 0; i < n2; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> temp;
		a.push_back(temp);
	}
	vector<int> b;
	for (int i = 0; i < n; i++)
		b.push_back(a[n + i]);
	for (int i = 0; i < n; i++)
		b.push_back(a[i]);
	for (int i = 0; i < n2; i++)
		cout << b[i] << " ";
	cout << endl;
	a.clear();
	b.clear();
}

void task2_v1()
{
	// !!!
}

void task2_v2()
{
	int n;
	ifstream fin("nums.txt");
	fin >> n;
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		fin >> a[i];
	int pos0 = 0;
	while (pos0 < n && a[pos0] != 0)
		pos0++;
	int pos_min = pos0;
	for (int i = pos0; i < n; i++)
	{
		if (a[i] > 0 && (a[i] < a[pos_min] || pos_min == pos0))
			pos_min = i;
	}
	if (pos_min != pos0)
		cout << pos_min << endl;
	else
		cout << "Solution not found!" << endl;
	free(a);
}

void task2_v3()
{
	int n;
	ifstream fin("nums.txt");
	fin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		fin >> a[i];
	int pos0 = 0;
	while (pos0 < n && a[pos0] != 0)
		pos0++;
	int pos_min = pos0;
	for (int i = pos0; i < n; i++)
	{
		if (a[i] > 0 && (a[i] < a[pos_min] || pos_min == pos0))
			pos_min = i;
	}
	if (pos_min != pos0)
		cout << pos_min << endl;
	else
		cout << "Solution not found!" << endl;
	delete[]a;
}

void task2_v4()
{
	int n, temp;
	ifstream fin("nums.txt");
	fin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		fin >> temp;
		a.push_back(temp);
	}
	int pos0 = 0;
	while (pos0 < n && a[pos0] != 0)
		pos0++;
	int pos_min = pos0;
	for (int i = pos0; i < n; i++)
	{
		if (a[i] > 0 && (a[i] < a[pos_min] || pos_min == pos0))
			pos_min = i;
	}
	if (pos_min != pos0)
		cout << pos_min << endl;
	else
		cout << "Solution not found!" << endl;
	a.clear();
}

void task3_v1()
{
	const int n = 20;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50; // [-50, 50)
		cout << a[i] << " ";
	}
	cout << endl;
	int posf = 0, posl = n - 1;
	while (posf < n && a[posf] >= 0)
		posf++;
	while (posl >= 0 && a[posl] >= 0)
		posl--;
	if (posf == n || posf == posl)
	{
		cout << "Solution not found!" << endl;
		return;
	}
	int s = 0;
	for (int i = posf + 1; i < posl; i++)
	{
		s += a[i];
		cout << a[i] << " ";
	}
	cout << endl << "s: " << s << endl;
}

void task3_v2()
{
	int n = rand() % 10 + 5;
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50; // [-50, 50)
		cout << a[i] << " ";
	}
	cout << endl;
	int posf = 0, posl = n - 1;
	while (posf < n && a[posf] >= 0)
		posf++;
	while (posl >= 0 && a[posl] >= 0)
		posl--;
	if (posf == n || posf == posl)
	{
		cout << "Solution not found!" << endl;
		return;
	}
	int s = 0;
	for (int i = posf + 1; i < posl; i++)
	{
		s += a[i];
		cout << a[i] << " ";
	}
	cout << endl << "s: " << s << endl;
	free(a);
}

void task3_v3()
{
	int n = rand() % 10 + 5;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50; // [-50, 50)
		cout << a[i] << " ";
	}
	cout << endl;
	int posf = 0, posl = n - 1;
	while (posf < n && a[posf] >= 0)
		posf++;
	while (posl >= 0 && a[posl] >= 0)
		posl--;
	if (posf == n || posf == posl)
	{
		cout << "Solution not found!" << endl;
		return;
	}
	int s = 0;
	for (int i = posf + 1; i < posl; i++)
	{
		s += a[i];
		cout << a[i] << " ";
	}
	cout << endl << "s: " << s << endl;
	delete[]a;
}

void task3_v4()
{
	int n = rand() % 10 + 5;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		a.push_back(rand() % 100 - 50); // [-50, 50)
		cout << a.back() << " ";
	}
	cout << endl;
	int posf = 0, posl = n - 1;
	while (posf < n && a[posf] >= 0)
		posf++;
	while (posl >= 0 && a[posl] >= 0)
		posl--;
	if (posf == n || posf == posl)
	{
		cout << "Solution not found!" << endl;
		return;
	}
	int s = 0;
	for (int i = posf + 1; i < posl; i++)
	{
		s += a[i];
		cout << a[i] << " ";
	}
	cout << endl << "s: " << s << endl;
	a.clear();
}

int main(int argc, char** argv)
{
	srand(time(0));
	//task1_v1();
	//task1_v2();
	//task1_v3();
	//task1_v4();

	//task2_v1();
	//task2_v2();
	//task2_v3();
	//task2_v4();

	//task3_v1();
	//task3_v2();
	//task3_v3();
	//task3_v4();
}