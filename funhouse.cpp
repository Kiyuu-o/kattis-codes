/*
 * direction (in row & col):
 * right: +1 col
 * left: -1 col
 * up: -1 row
 * down: +1 row
 *
 * //: right to up 0 to 2, up to right 2 to 0, down to left 1 to 3, left to down, 3 to 1
 * \\: right to down 0 to 3, down to right 3 to 0, left to up 1 to 2, up to left 2 to 1
*/
/*
 * direction: dir
 * members: row, col
 */
#include <iostream>
#include <cstring>
using namespace std;

int l, w; // width, length

int dir; // index in dir_x and dir_y
int tc = 1;
// 0, 1, 2, 3
int row, col;
int dir_x[] = {0, 0, -1, 1};
int dir_y[] = {1, -1, 0, 0};
int forw[] = {2, 3, 0, 1};
int back[] = {3, 2, 1, 0};
char room[45][45];

void solve() {
	memset(room, 0, sizeof(room));
	for (int i = 0; i < l; ++i)
		cin >> room[i];
	int init_x, init_y;
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < w; ++j)
			if (room[i][j] == '*') {
				init_x = i;
				init_y = j;
			}
	if (init_y == 0) dir = 0;
	else if (init_y == w-1) dir = 1;
	else if (init_x == 0) dir = 3;
	else dir = 2;
	row = init_x;
	col = init_y;
	while (true) {
		row += dir_x[dir];
		col += dir_y[dir];
		char cur = room[row][col];
		if (cur == '/') dir = forw[dir];
		else if (cur == '\\') dir = back[dir];
		else if (cur == 'x') break;
	}
	room[row][col] = '&';
	cout << "HOUSE " << tc++ << endl;
	for (int i = 0; i < l; ++i)
		cout << room[i] << endl;
}

int main() {
	while (cin >> w >> l) {
		if (w == 0 && l == 0)
			return 0;
		solve();
	}
	return 0;
}
