#include <iostream>

using namespace std;

#define CASE 4
#define CountofNation 6

const int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
const int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

int ResultTable[CountofNation][3];
int TestTable[CountofNation][3];
bool ans[CASE];

void DFS(int tc, int round) {
	if (round == 15) {
		if (ans[tc]) return;

		for (int r = 0; r < CountofNation; r++) {
			for (int c = 0; c < 3; c++) {
				if (ResultTable[r][c] != TestTable[r][c])
					return;
			}
		}

		// 모든 예측이 일치한다면 가능한 결과로 처리
		ans[tc] = 1;
		return;
	}

	// {승리(0), 무승부(1), 패배(2)}
	int t1 = team1[round];
	int t2 = team2[round];

	// t1 승, t2 패
	TestTable[t1][0]++; TestTable[t2][2]++;
	DFS(tc, round + 1);
	TestTable[t1][0]--; TestTable[t2][2]--;

	// t1 무, t2 무
	TestTable[t1][1]++; TestTable[t2][1]++;
	DFS(tc, round + 1);
	TestTable[t1][1]--; TestTable[t2][1]--;

	// t1 패, t2 승
	TestTable[t1][2]++; TestTable[t2][0]++;
	DFS(tc, round + 1);
	TestTable[t1][2]--; TestTable[t2][0]--;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < CASE; i++) {
		
		for (int j = 0; j < CountofNation; j++) {
			cin >> ResultTable[j][0]; // 승
			cin >> ResultTable[j][1]; // 무
			cin >> ResultTable[j][2]; // 패
		}
		DFS(i, 0);
	}

	for (int i = 0; i < CASE; i++) {
		if (ans[i]) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}

	return 0;
}




/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAXN (50)
int H, W;//지도 세로, 가로 크기
char map[MAXN + 10][MAXN + 10];//지도정보(W:바다, L:육지)
int DT[MAXN + 10][MAXN + 10];

struct info {
	int h;
	int w;
	int d;
};

void InputData() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		cin >> &map[i][1];
	}
}

int dH[] = { 1,-1,0,0 };
int dW[] = { 0,0,1,-1 };

int FF(info startpoint) {
	queue<info> todo;
	int maxdistance = 0;

	todo.push(startpoint);
	DT[startpoint.h][startpoint.w] = true;

	while (!todo.empty()) {
		info nowinfo = todo.front();
		todo.pop();
		maxdistance = std::max(maxdistance, nowinfo.d);

		for (int i = 0; i < 4; i++) {
			int newH = nowinfo.h + dH[i];
			int newW = nowinfo.w + dW[i];
			int newD = nowinfo.d + 1;
			if (map[newH][newW] == 'L' && DT[newH][newW] > newD) {
				todo.push({newH, newW, newD});
				DT[newH][newW] = newD;
			}
		}
	}

	return maxdistance;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == 'L') {
				fill(&DT[0][0], &DT[MAXN + 10 - 1][MAXN + 10], 99999);
				int distance = FF({i,j,0});
				ans = std::max(ans, distance);
			}
		}
	}

	cout << ans << "\n";//출력하는 부분
	return 0;
}
*/
/*

#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main()
{
	queue<int> myqueue;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string cmd;
		int arg;
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			cin >> arg;
			myqueue.push(arg);
		}
		else if (cmd.compare("pop") == 0) {
			if (myqueue.empty()) {
				cout << "-1\n";
			}
			else {
				cout << myqueue.front() << '\n';
				myqueue.pop();
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << myqueue.size() << '\n';
		}
		else if (cmd.compare("empty") == 0) {
			if (myqueue.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cmd.compare("front") == 0) {
			if (myqueue.empty()) {
				cout << "-1\n";
			}
			else {
				cout << myqueue.front() << '\n';
			}
		}
		else if (cmd.compare("back") == 0) {
			if (myqueue.empty()) {
				cout << "-1\n";
			}
			else {
				cout << myqueue.back() << '\n';
			}
		}
	}
	return 0;
}
*/


/*
#include <iostream>
#include <string>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		string str;
		cin >> str;
		int check=0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				check++;
			}
			if (str[j] == ')') {
				check--;
			}
			if (check < 0) {
				check = -9999999999;
				continue;
			}
		}
		if (check != 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}

*/
/*
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
	stack<int> mystack;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string cmd;
		int arg;
		cin >> cmd;
		if(cmd.compare("push") == 0){
			cin >> arg;
			mystack.push(arg);
		}
		else if(cmd.compare("pop") == 0){
			if (mystack.empty()) {
				cout << "-1\n";
			}
			else {
				cout << mystack.top() << '\n';
				mystack.pop();
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << mystack.size() << '\n';
		}
		else if (cmd.compare("empty") == 0) {
			if (mystack.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cmd.compare("top") == 0) {
			if (mystack.empty()) {
				cout << "-1\n";
			}
			else {
				cout << mystack.top() << '\n';
			}
		}
	}
	return 0;
}
*/