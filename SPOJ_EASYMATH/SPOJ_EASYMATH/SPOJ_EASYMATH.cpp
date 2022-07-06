#include <iostream>
using namespace std;

int main()
{											// #1 WA
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, a, d;
		cin >> n >> m >> a >> d;

		int cnt = 0, 
		mn = m - n + 1, 
		ad = a + d, a2d = a + 2 * d, a3d = a + 3 * d, a4d = a + 4 * d;


		for (int ia = 0; ia < 2; ia++)
		{
			for (int iad = 0; iad < 2; iad++)
			{
				for (int ia2d = 0; ia2d < 2; ia2d++)
				{
					for (int ia3d = 0; ia3d < 2; ia3d++)
					{
						for (int ia4d = 0; ia4d < 2; ia4d++)
						{
							int d = 1, elements = 0;

							if (ia)   { d *= a;   elements++; }
							if (iad)  { d *= ad;  elements++; }
							if (ia2d) { d *= a2d; elements++; }
							if (ia3d) { d *= a3d; elements++; }
							if (ia4d) { d *= a4d; elements++; }

							if (elements == 0)
								continue;

							int sign = elements % 2 == 0 ? -1 : 1;

							cnt += sign * mn / d;
						}
					}
				}
			}
		}

		cout << mn - cnt << endl;
	}


}