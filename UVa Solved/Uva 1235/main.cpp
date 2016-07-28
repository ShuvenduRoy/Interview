#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <set>

using namespace std;
int T;
string llaves [500];
int matriz[501][501];

int getindex(int n, vector<int> v)
{
	for(int i = 0; i<v.size();++i)
	{
		if (v[i] == n)
			return i;
	}
	return -1;
}

int recorrer(vector<int> desbloq, vector<int> bloq, int n)
{
	int ans = 0;
	int menor = 1000000;
	int pos;
	for(int i = 1; i<=n;++i)
	{
		if (menor > matriz[0][i])
		{
			pos = i;
			menor = matriz[0][i];
		}
	}
	ans += menor;
	desbloq.push_back(pos);
	bloq.erase(bloq.begin()+getindex(pos,bloq));

	while(bloq.size() > 0)
	{
		int x,y;
		int dist = 100000;
		for (int j = 0; j< bloq.size();++j)
		{
			int pos = bloq[j];

			for(int i =0; i<desbloq.size();++i)
			{
				if(matriz[desbloq[i]][pos] < dist && matriz[desbloq[i]][pos] != 0 && getindex(pos,bloq) != -1)
				{
					dist = matriz[desbloq[i]][pos];
					x = pos;
					y = desbloq[i];
				}
			}

		}
		ans += dist;
		desbloq.push_back(x);
		bloq.erase(bloq.begin()+getindex(x,bloq));
	}
	return ans;
}

int distancia(string llave1, string llave2)
{
	int dist = 0;
	if(llave1 == llave2)
		return 0;
	for(int i = 0; i<4;++i)
	{
		dist += min(abs(llave1[i]-llave2[i]),abs(10-abs(llave1[i]-llave2[i])));
	}
	return dist;
}

void crearMatriz(int n)
{
	for(int i = 0; i<=n; ++i)
	{
		for(int j = 0; j<=n;++j)
		{
			if (i == j)
			{
				matriz[i][j] = 0;
				continue;
			}
			int dist =  distancia(llaves[i],llaves[j]);
			matriz[i][j] = dist;
		}
	}
}

void pintar(int n)
{
	for(int i=0;i<=n;++i)
	{
		for(int j =0;j<=n;++j)
			cout<<matriz[i][j]<<" ";

	cout<<endl;
	}
}

int main()
{
	llaves[0] = "0000";
	cin >> T;
	for(int i=0; i<T; ++i)
	{
		int n;
		cin >> n;
		vector<int> bloq;
		for(int j = 1; j<=n;++j)
		{
			bloq.push_back(j);
			cin>>llaves[j];
		}
		vector<int> desbloq;
		crearMatriz(n);
		int ans = recorrer(desbloq,bloq,n);

		bloq.clear();
		desbloq.clear();
		cout<<ans<<endl;
	}
	return 0;
}
