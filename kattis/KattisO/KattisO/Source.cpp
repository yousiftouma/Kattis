#include <iostream>
#include <cstring>
using namespace std;

const auto maxN = 1000001;
bool winWithStonesLeft[maxN]; //dp array
int allowedMoves[11];


int main()
{
	int n, m, i, k;
	
	while(cin >> n >> m)
	{
		memset(winWithStonesLeft, false, sizeof(winWithStonesLeft));

		for (i = 0; i < m; i++)
		{
			cin >> allowedMoves[i];
		}

		for (i = 1; i <= n; i++)
		{
			for (k = 0; k < m; k++)
			{
				if (i >= allowedMoves[k] && winWithStonesLeft[i - allowedMoves[k]] == false)
				{
					winWithStonesLeft[i] = true;
					break;
				}
			}
		}
		if (winWithStonesLeft[n]) cout << "Stan wins" << endl;
		else cout << "Ollie wins" << endl;
	}


	return 0;
}