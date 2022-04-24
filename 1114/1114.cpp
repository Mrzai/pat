#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define maxsize 10000
using namespace std;
int father[maxsize];

struct node {
  int id;
  float sets, area;
} v[1010];

struct family {
  int id, num;
  float avgs, avga;
};

bool cmp(family a, family b) {
  return a.avga == b.avga ? a.id < b.id : a.avga > b.avga;
}

int findfather(int x) {
  while (x != father[x]) {
    x = father[x];
  }
  return x;
}

void Union(int x, int y) {
  int fa = findfather(x);
  int fb = findfather(y);
  if (fa < fb) {
    father[fb] = fa;
  } else {
    father[fa] = fb;
  }
}

int main() {
  vector<int> index(maxsize, -1);
  vector<bool> visited(maxsize);
  vector<family> temp;
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < maxsize; i++) {
    father[i] = i;
  }
  for (int i = 0, id, fid, mid, k; i < n; i++) {
    scanf("%d %d %d %d", &id, &fid, &mid, &k);
    v[i].id = id;
    visited[id] = true;
    if (fid != -1) {
      visited[fid] = true;
      Union(id, fid);
    }
    if (mid != -1) {
      visited[mid] = true;
      Union(id, mid);
    }
    for (int j = 0, temp; j < k; j++) {
      scanf("%d", &temp);
      visited[temp] = true;
      Union(id, temp);
    }
    scanf("%f %f", &v[i].sets, &v[i].area);
  }
  for (int i = 0; i < n; i++) {
    if (visited[v[i].id]) {
      int fid = findfather(v[i].id);
      if (index[fid] != -1) {
        temp[index[fid]].avgs += v[i].sets;
        temp[index[fid]].avga += v[i].area;
      } else {
        index[fid] = temp.size();
        temp.push_back({fid, 0, v[i].sets, v[i].area});
      }
    }
  }
  for (int i = 0; i < maxsize; i++) {
    if (visited[i]) {
      int fid = findfather(i);
      temp[index[fid]].num++;
    }
  }
  for (auto &it : temp) {
    it.avgs /= it.num;
    it.avga /= it.num;
  }
  sort(temp.begin(), temp.end(), cmp);
  cout << temp.size() << endl;
  for (auto it : temp) {
    printf("%04d %d %.3f %.3f\n", it.id, it.num, it.avgs, it.avga);
  }
  return 0;
}