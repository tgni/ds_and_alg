/* 基本思想：
 *  1. e + 1 = v; 注意v可能为零也算树。并且如果有环这个条件也可以把环排除
 *  2. 入度为零的顶点个数为1.(只有一个root，也可以用并查集)
 */

#include <stdio.h>
#include <set>
#include <map>

using namespace std;

int main()
{
	int a, b, cas = 1, cnt = 0, edge = 0;
	map<int, int> inDegree;
	set<int> V;

	while (scanf("%d%d", &a, &b) != EOF) {
		if (a < 0 && b < 0) {
			break;
		} else if (a == 0 && b == 0) {
			if (V.size() && edge + 1 != V.size()) {
				printf("Case %d is not a tree.\n", cas);
				goto clear;
			}

			cnt = 0;
			for (auto i : V) {
				if (inDegree[i] == 0) {
					if (++cnt > 1) {
						printf("Case %d is not a tree.\n", cas);
						goto clear;
					}
				}
			}

			printf("Case %d is a tree.\n", cas);
clear:
			inDegree.clear();
			V.clear();
			edge = 0;
			cas++;
		} else {
			V.insert(a); V.insert(b);
			inDegree[b]++;
			++edge;
		}
	}

	return 0;
}
