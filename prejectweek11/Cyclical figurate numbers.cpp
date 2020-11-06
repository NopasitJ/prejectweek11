#include <iostream>
using namespace std;
bool chain(long long seq, int used, const int a[])
{
	int end = seq % 100;
	if (used == (1 << 6) - 1) {
		if (a[end * 100 + seq / 10000000000LL] & (1 << 5)) {
			int sum = end * 100 + seq / 10000000000LL;
			for (; used > 1; used >>= 1, seq /= 100)
			{
				sum += seq % 10000;
			}
			cout << sum << "\n";
			return true;
		}
		return false;
	}
	for (int start = 10; start < 100; start++) 
	{
		int satisfies = a[end * 100 + start] & (~used);
		for (int crit = 0; satisfies > 0; satisfies >>= 1, crit++)
		{
			if (satisfies % 2 && chain(seq * 100 + start, used + (1 << crit), a))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int ar[10000] = { 0 };
	for (int tri = 0; tri * (tri + 1) / 2 < 10000; tri++)
	{
		ar[tri * (tri + 1) / 2] += 1 << 0;
	}
	for (int sq = 0; sq * sq < 10000; sq++) 
	{
		ar[sq * sq] += 1 << 1;
	}
	for (int pen = 0; pen * (3 * pen - 1) / 2 < 10000; pen++)
	{
		ar[pen * (3 * pen - 1) / 2] += 1 << 2;
	}
	for (int hex = 0; hex * (2 * hex - 1) < 10000; hex++)
	{
		ar[hex * (2 * hex - 1)] += 1 << 3;
	}
	for (int hep = 0; hep * (5 * hep - 3) / 2 < 10000; hep++)
	{
		ar[hep * (5 * hep - 3) / 2] += 1 << 4;
	}
	for (int oct = 0; oct * (3 * oct - 2) < 10000; oct++)
	{
		ar[oct * (3 * oct - 2)] += 1 << 5;
	}
	for (int start = 10; start < 100; start++)
	{
		if (chain(start, 1 << 5, ar))
			break;
	}
}