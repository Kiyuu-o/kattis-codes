/*
Time: 22:13 2022/9/24
Author: Kexuan Miao
Reference: UofA Code Archive
*/
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 2010;

char e[MAXN][MAXN];
int match[MAXN], back[MAXN], q[MAXN], tail;

void addEdge(int x, int y, int n) {
	e[x][y+n] = e[y+n][x] = 1;
}

int find(int x, int n, int m){
  int i, j, r;

  if(match[x] != -1) return 0;
  memset(back, -1, sizeof(back));
  for(q[i=0]=x, tail = 1; i < tail; i++)
    for(j = 0; j < n+m; j++){
      if(!e[q[i]][j]) continue;
      if(match[j] != -1){
	if(back[j] == -1){
	  back[j] = q[i];
	  back[q[tail++] = match[j]] = j;
	}
      } else {
	match[match[q[i]] = j] = q[i];
	for(r = back[q[i]]; r != -1; r = back[back[r]])
	  match[match[r] = back[r]] = r;
	return 1;
      }
    }
  return 0;
}

void bipmatch(int n, int m){
  int i;
  memset(match, -1, sizeof(match));
  for(i = 0; i < n+m; i++) if(find(i,n,m)) i = 0;
}

int main() {
	int n, m, esize, x, y;
	int i, count, t;

	cin >> n >> m;

		memset(e, 0, sizeof(e));
		for (int i = 0; i < n; ++i) {
			cin >> t;
			while(t--) {
				cin >> y;
				addEdge(i, y - 1, n);
			}
		}

		bipmatch(n, m);

		for (count = i = 0; i < n; i++){
			if(match[i] != -1){
				count++;
			}
		}
		cout << count << "\n";
}
