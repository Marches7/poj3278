//AC 《catch that cow》
#include<iostream>
#include<queue>
#include<string>
#define MAXN 100001
using namespace std;

bool vis[MAXN] ;//记录是否访问
int step[MAXN] ;//记录到达某个位置所需要的最小步数

int bfs(int N, int K) {
	queue<int> q;
	q.push(N);
	step[N] = 0;
	vis[N] = true;
	while (!q.empty()) {
		int head = q.front();		
		int next;
		if (head == K) return step[K];
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				next = head + 1;
			}
			if (i == 1) {
				next = head - 1;
			}
			if (i == 2) {
				next = head * 2;
			}
			if (next<0 || next>MAXN) continue;
			if (!vis[next]) {
				q.push(next);
				vis[next] = true;
				step[next] = step[head] + 1;
			}
		}
	}
}

int main() {
	int N, K;
	while (cin >> N >> K) {
		memset(vis, false, sizeof(vis));
		memset(step, 0, sizeof(step));
		if (N >= K) cout << N - K << endl;
		else cout <<bfs(N, K) << endl;
	}
	return 0;
}