#include <bits / stdc++.h>
#define ZOZO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main()
{
	ZOZO
	int t; cin >> t;
	while (t--)
	{
		int a[3];
		for (int i = 0; i < 3; i++)
		{
			cin >> a[i];
		}
		sort(a, a + 3);
		if (a[0] == a[1] && a[0] != a[2])
			cout << a[2] << "\n";
		else if (a[0] != a[1] && a[0] != a[2])
			cout << a[0] << "\n";

	}
	return 0;
}