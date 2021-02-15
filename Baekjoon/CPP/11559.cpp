#include <iostream>

#include <string>

#include <queue>

#include <algorithm>

using namespace std;

 

typedef struct

{

        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

 

int result;

string Puyo[12];

 

//정렬할 때 필요한 cmp 함수

bool cmp(pair<int, int> a, pair<int, int> b)

{

        if (a.second < b.second)

                 return true;

        else if (a.second == b.second)

        {

                 if (a.first < b.first)

                         return true;

                 return false;

        }

        return false;

}

 

int BFS(void)

{

        queue<pair<int, int>> q;

        int cnt = 0;

 

        while (1)

        {

                 vector<pair<int, int>> v; //부실 블럭 저장

                 bool visited[12][6] = { false };

                 for (int y = 11; y >= 0; y--)

                 {

                         for (int x = 0; x < 6; x++)

                         {

                                 if (Puyo[y][x] == '.')

                                          continue;

                                 else

                                 {

                                          queue<pair<int, int>> popped;

                                          char color = Puyo[y][x];

                                          q.push({ y, x });

                                          visited[y][x] = true;

 

                                          while (!q.empty())

                                          {

                                                  int curY = q.front().first;

                                                  int curX = q.front().second;

                                                  popped.push({ curY, curX });

                                                  q.pop();

 

                                                  for (int i = 0; i < 4; i++)

                                                  {

                                                          int nextY = curY + moveDir[i].y;

                                                          int nextX = curX + moveDir[i].x;

 

                                                          if (0 <= nextY && nextY < 12 && 0 <= nextX && nextX < 6)

                                                                   if (!visited[nextY][nextX] && Puyo[nextY][nextX] == color)

                                                                   {

                                                                           visited[nextY][nextX] = true;

                                                                           q.push({ nextY, nextX });

                                                                   }

                                                  }

                                          }

 

                                          if (popped.size() >= 4) //같은 색깔인 블록이 4개 이상이면 벡터에 넣는다

                                          {

                                                  while (!popped.empty())

                                                  {

                                                          v.push_back({ popped.front().first, popped.front().second });

                                                          popped.pop();

                                                  }

                                          }

                                 }

                         }

                 }

                 //부실 블럭이 있으면 부시고 블록을 내린다

                 if (v.size() > 0)

                 {

//x를 기준으로 오름차순 정렬

                         sort(v.begin(), v.end(), cmp);

                         for (int i = 0; i < v.size(); i++)

                         {

                                 for (int j = v[i].first; j > 0; j--)

                                          Puyo[j][v[i].second] = Puyo[j - 1][v[i].second];

                                 Puyo[0][v[i].second] = '.';

                         }

                         cnt++; //연쇄 추가

                 }

                 else

                         break;

        }

        return cnt;

}

 

int main(void)

{

        for (int y = 0; y < 12; y++)

                 cin >> Puyo[y];

 

        cout << BFS() << "\n";

        return 0;

}

