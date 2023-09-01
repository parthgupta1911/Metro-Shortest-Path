#include <bits/stdc++.h>
#include <climits>

using namespace std;

// swapp function
template <typename t>
void swapp(t &a, t &b)
{
  t temp = b;
  b = a;
  a = temp;
}

// implementation of vector data structure
template <typename T>
class myvec
{
  T *arr;
  int cap;
  int size;

public:
  myvec()
  {
    arr = new T[1];
    cap = 1;
    size = 0;
  }

  myvec(int s, T val)
  {
    arr = new T[s];
    size = s;
    cap = s;
    for (int i = 0; i < size; i++)
    {
      arr[i] = val;
    }
  }

  void push(T x)
  {
    if (size == cap)
    {
      T *narr = new T[2 * cap];

      for (int i = 0; i < size; i++)
      {
        narr[i] = arr[i];
      }

      delete[] arr;
      cap = 2 * cap;
      arr = narr;
      arr[size] = x;
      size++;
    }
    else
    {
      arr[size] = x;
      size++;
    }
  }

  void push(T x, int index)
  {

    if (index == size)
      push(x);
    else
    {
      push(x);
      int j = size - 1;
      while (j > index)
      {
        arr[j] = arr[j - 1];
        j--;
      }
      arr[index] = x;
    }
  }

  void pop()
  {
    size--;
  }

  int getsize()
  {
    return size;
  }

  int getcapacity()
  {
    return cap;
  }

  void print()
  {
    cout << endl;
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  T operator[](int i)
  {
    if (i >= 0 && i < size)
    {
      return arr[i];
    }
    return arr[0];
  }

  bool operator==(myvec<T> x)
  {
    int s2 = x.getsize();
    if (s2 != size)
    {
      return false;
    }
    for (int i = 0; i < size; i++)
    {
      if (arr[i] != x[i])
      {
        return false;
      }
    }
    return true;
  }

  bool del(T x)
  {
    if (size == 0)
    {
      cout << endl
           << "NO ELEMENTS!" << endl;
      return false;
    }
    else
    {
      int i;
      for (i = 0; i < size; i++)
      {
        if (arr[i] == x)
        {
          break;
        }
      }
      if (i == size)
      {
        cout << endl
             << "D.N.E" << endl;
        return false;
      }
      else
      {
        for (int j = i; j < size - 1; j++)
        {
          arr[j] = arr[j + 1];
        }
        size--;
        return true;
      }
    }
  }
};

// implementation of pair data structure
template <typename t1, typename t2>
class mypair
{
  t1 f;
  t2 s;

public:
  mypair()
  {
  }

  mypair(t1 ff, t2 ss)
  {
    f = ff;
    s = ss;
  }

  t1 getfirst()
  {
    return f;
  }

  t2 getsecond()
  {
    return s;
  }
};

// operator < overloaded for pair
template <typename t1, typename t2>
bool operator<(mypair<t1, t2> p1, mypair<t1, t2> p2)
{
  if (p1.getfirst() < p2.getfirst())
  {
    return true;
  }
  else if (p1.getfirst() == p2.getfirst())
  {
    if (p1.getsecond() < p2.getsecond())
    {
      return true;
    }
  }
  return false;
}

// operator > overloaded for pair
template <typename t1, typename t2>
bool operator>(mypair<t1, t2> p1, mypair<t1, t2> p2)
{
  if (p1.getfirst() > p2.getfirst())
  {
    return true;
  }
  else if (p1.getfirst() == p2.getfirst())
  {
    if (p1.getsecond() > p2.getsecond())
    {
      return true;
    }
  }
  return false;
}

// implementation of data structure min heap
template <typename T>
struct minheap
{
  T *arr;
  int size;
  int cap;

  minheap(int c)
  {
    cap = c;
    size = 0;
    arr = new int[c];
  }

  minheap()
  {
    cap = 1;
    size = 0;
    arr = new T[1];
  }

  minheap(T temp[], int s)
  {
    arr = new T[s];
    size = s;
    cap = s;
    for (int i = 0; i < s; i++)
    {
      arr[i] = temp[i];
    }
    buildheap();
  }

  int right(int i)
  {
    return 2 * i + 2;
  }

  int left(int i)
  {
    return 2 * i + 1;
  }

  int parent(int i)
  {
    return ((i - 1) / 2);
  }

  void min_heapify(int i)
  {
    while (1)
    {
      int l = left(i);
      int r = right(i);
      int mini = i;
      if (l < size && arr[l] < arr[mini])
      {
        mini = l;
      }
      if (r < size && arr[r] < arr[mini])
      {
        mini = r;
      }
      if (mini != i)
      {
        swapp(arr[i], arr[mini]);
        i = mini;
      }
      else
      {
        break;
      }
    }
  }

  void buildheap()
  {
    int lin = parent(size - 1);
    for (int i = lin; i >= 0; i--)
    {
      min_heapify(i);
    }
  }

  T top()
  {
    return arr[0];
  }

  T pop()
  {
    swapp(arr[0], arr[size - 1]);
    size--;
    min_heapify(0);
    return arr[size];
  }

  void push(T x)
  {
    if (size == cap)
    {
      return;
    }
    arr[size] = x;
    int i = size;
    int ip = parent(i);
    while (i != 0 && arr[i] < arr[ip])
    {
      swapp(arr[i], arr[ip]);
      i = ip;
      ip = parent(i);
    }
    size++;
  }

  void print()
  {
    cout << endl;
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
  }

  void increasekey(int i, T x)
  {
    if (i > size - 1)
    {
      return;
    }
    arr[i] = x;
    int ip = parent(i);
    min_heapify(i);
  }

  void decreasekey(int i, T x)
  {
    if (i > size - 1)
    {
      return;
    }
    arr[i] = x;
    int ip = parent(i);
    while (i != 0 && arr[i] < arr[ip])
    {
      swapp(arr[i], arr[ip]);
      i = ip;
      ip = parent(i);
    }
  }

  bool empty()
  {
    if (size == 0)
    {
      return true;
    }
    return false;
  }
};

// implementation of data structure queue
template <typename T>
class myqueue
{
  T *arr;
  int cap;
  int size;
  int f, l;

public:
  myqueue(int c)
  {
    cap = c;
    size = 0;
    arr = new T[c];
    f = -1;
    l = -1;
  }

  myqueue()
  {
    cap = 1;
    size = 0;
    arr = new T;
    f = -1;
    l = -1;
  }

  void push(T x)
  {
    if (f == -1)
    {
      f = 0;
    }
    if (l == cap)
    {
      T *narr = new T[2 * cap];

      for (int i = 0; i < size; i++)
      {
        narr[i] = arr[i];
      }

      delete[] arr;
      cap = 2 * cap;
      arr = narr;
      arr[l + 1] = x;
      l++;
    }
    else
    {
      l++;
      arr[l] = x;
    }
  }

  void pop()
  {
    if (f == -1)
    {
      return;
    }
    f++;
  }

  T front()
  {
    return arr[f];
  }

  bool isempty()
  {
    if (l - f + 1 == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int getsize()
  {
    return l - f + 1;
  }

  void print()
  {
    for (int i = f; i <= l; i++)
    {
      cout << arr[i] << " ";
    }
  }
};

// function to add station in a vector
void addstation(myvec<string> &s, string name)
{
  s.push(name);
}

// function to display the name of all stations saved in the vector
void print(myvec<string> s)
{
  cout << endl
       << "LIST OF STATIONS ARE:";
  cout << endl
       << "__________________";
  cout << endl
       << "S.no"
       << "\t| "
       << "S.name"
       << endl
       << "__________________";

  for (int i = 0; i < s.getsize(); i++)
  {
    cout << endl;
    cout << i << "\t| " << s[i];
  }

  cout << endl
       << "__________________";
  cout << endl;
}

// funtion to search for a station name in vector if present return index else -1
int lookup(myvec<string> s, string name)
{
  for (int i = 0; i < s.getsize(); i++)
  {
    if (s[i] == name)
    {
      return i;
    }
  }

  return -1;
}

// funtion to add edge of graph using 2-d vectors
void addedge(myvec<myvec<int>> graph[], int v, int s, int d, int wt)
{
  myvec<int> a;
  a.push(d);
  a.push(wt);
  graph[s].push(a);
}

// function to add vertice to graph(station to map)
void addvertice(myvec<myvec<int>> graph[], int &v)
{
  // myvec<myvec<int>>ngraph[v+1];
  // for(int i=0;i<v;i++)
  // {
  //     ngraph[i]=graph[i];
  // }
  // //delete []graph;
  // graph=new myvec<myvec<int>>[v+1];
  // for(int i=0;i<v;i++)
  // {
  //     graph[i]=ngraph[i];
  // }
  v++;
}

// function to delete vertice from the graph(station from map)
void deletevertice(myvec<myvec<int>> graph[], int &v, int u)
{
  for (int j = u; j < v - 1; j++)
  {
    graph[j] = graph[j + 1];
  }

  v--;

  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < graph[i].getsize(); j++)
    {
      myvec<int> a = graph[i][j];
      if (a[0] == u)
      {
        graph[i].del(a);
        break;
      }
    }
  }
}

// function to print the graph(display all stations and their connectivity)
void printgraph(myvec<myvec<int>> graph[], int v, myvec<string> s)
{
  cout << endl
       << "ADJACENCY LIST:" << endl;
  for (int i = 0; i < v; i++)
  {
    cout << endl
         << "ADJACENT OF " << i << ") " << s[i] << " are:\t";
    for (int j = 0; j < graph[i].getsize(); j++)
    {
      myvec<int> a = graph[i][j];
      cout << " { " << a[0] << " => " << s[a[0]] << " and mins: " << a[1]
           << " } "
           << ",\t";
    }
  }
}

// function to delete an edge from graph
void deleteedge(myvec<myvec<int>> graph[], int v, int src, int dest)
{
  for (int j = 0; j < graph[src].getsize(); j++)
  {
    myvec<int> a = graph[src][j];
    if (a[0] == dest)
    {
      graph[src].del(a);
      return;
    }
  }
  cout << endl
       << "NO SUCH EDGE EXISTS" << endl;
}

// function to modify a station
void modify(myvec<myvec<int>> graph[], int &v, myvec<string> &s)
{
  while (1)
  {
    int cho;
    cout << endl
         << "Enter 1 to add an edge:" << endl;
    cin >> cho;
    if (cho == 1)
    {
      string sname;
      cout << endl
           << "Enter station name to be modified" << endl;
      cin >> sname;
      int src = lookup(s, sname);
      if (src == -1)
      {
        cout << endl
             << sname << "Doesn't exist enter 1 to add it to the graph" << endl;
        cin >> cho;
        if (cho == 1)
        {
          addstation(s, sname);
          addvertice(graph, v);
          src = lookup(s, sname);
          cout << endl
               << sname << " added at " << src << endl;
        }
        else
        {
          return;
        }
      }

      cout << "enter 1 to add a new edge from " << sname << endl;
      cin >> cho;
      if (cho != 1)
      {
        return;
      }
      cout << "enter sname where the edge terminates" << endl;
      cin >> sname;
      int dest = lookup(s, sname);
      if (dest == -1)
      {
        cout << endl
             << sname << " Doesn't exist enter 1 to add it to the graph" << endl;
        cin >> cho;
        if (cho == 1)
        {
          addstation(s, sname);
          addvertice(graph, v);

          dest = lookup(s, sname);
          cout << endl
               << sname << " added at " << dest << endl;
        }
        else
        {
          return;
        }
      }
      int wt;
      cout << endl
           << "enter the weight of the edge" << endl;
      cin >> wt;
      addedge(graph, v, src, dest, wt);
      cout << endl
           << "EDGE ADDED SUCCESFULLY ";
    }
    cout << endl
         << "enter 1 to add an vertice in graph:" << endl;
    cin >> cho;
    if (cho == 1)

    {
      string sname;
      cout << endl
           << "enter station name:" << endl;
      cin >> sname;
      addstation(s, sname);
      addvertice(graph, v);

      int x = lookup(s, sname);
      cout << endl
           << sname << " added at " << x << endl;
    }
    cout << endl
         << "enter 1 to perform deletion:" << endl;
    cin >> cho;
    if (cho == 1)
    {
      cout << endl
           << "enter 1 to delete a station(vertice)" << endl;
      cin >> cho;
      if (cho == 1)
      {
        string ds;
        cout << endl
             << "enter station name to be deleted";
        cin >> ds;
        int u = lookup(s, ds);
        if (u != -1 && s.del(ds))
        {
          deletevertice(graph, v, u);
          cout << endl
               << "CHANGES MADE!!" << endl;
          print(s);
          printgraph(graph, v, s);
        }
      }
      cout << endl
           << "enter 1 to delete an EDGE" << endl;
      cin >> cho;
      if (cho == 1)
      {
        int ss, dd;
        cout << endl
             << "Enter src of EDGE" << endl;
        cin >> ss;
        cout << endl
             << "Enter dest of EDGE" << endl;
        cin >> dd;
        cout << endl
             << "CHANGES MADE!!" << endl;
        deleteedge(graph, v, ss, dd);
        printgraph(graph, v, s);
      }
    }

    cout << endl
         << "enter 1 if modification to graph are done:" << endl;
    cin >> cho;
    if (cho == 1)
    {
      return;
    }
  }
}

// function to find shortest path using dijsktra
myvec<int> dijsktra(myvec<myvec<int>> graph[], int v, int S)
{
  vector<int> dist(v, INT_MAX);
  vector<bool> fin(v, false);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, S});
  dist[S] = 0;
  while (pq.empty() == false)
  {
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (fin[node] == false)
    {
      fin[node] = true;
      for (int i = 0; i < graph[node].getsize(); i++)
      {
        myvec<int> x = graph[node][i];
        if (fin[x[0]] == false)
        {
          int v = x[0];
          if (dist[v] > dist[node] + x[1])
          {
            dist[v] = dist[node] + x[1];
            pq.push({dist[v], v});
          }
        }
      }
    }
  }

  myvec<int> d;
  for (int i = 0; i < v; i++)
  {
    d.push(dist[i]);
  }
  return d;
}

// funtion for minimum spanning tree
bool mst(int V, myvec<myvec<int>> adj[], int &sum)
{
  vector<int> vis(V, false);

  priority_queue<pair<int, int>,
                 vector<pair<int, int>>, greater<pair<int, int>>>
      pq;
  int co = 0;
  //  {weight, node } would include parent too, if need to find the whole MST
  pq.push({0, 0});

  while (!pq.empty())
  {
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (!vis[node])
    {
      co++;
      // if node is not visited add the node weight to answer.
      sum += weight;
      vis[node] = true;

      for (int i = 0; i < adj[node].getsize(); i++)
      {
        myvec<int> x = adj[node][i];
        //  similiarly do for all neighbours
        if (!vis[x[0]])
        {
          pq.push({x[1], x[0]});
        }
      }

      // since we are using a PQ the sum will automatically
      //  be always the minimum.
    }
  }
  //  if(co==V-1)
  //  {
  //      return true;
  //  }
  //  else {
  //      return false;
  //  }
  return true;
}

// funtion to perform bfs operation
void Bfs(int src, myvec<myvec<int>> graph[], bool vis[], int V)
{
  myqueue<int> q(V);
  q.push(src);
  cout << " " << src;
  vis[src] = true;
  while (q.isempty() == false)
  {
    int v = q.front();
    q.pop();
    for (int i = 0; i < graph[src].getsize(); i++)
    {
      myvec<int> x = graph[src][i];
      if (vis[x[0]] == false)
      {
        q.push(x[0]);
        cout << " " << x[0] << " ";
        vis[x[0]] = true;
      }
    }
  }
}

// wrapper function for bfs
int bfs(myvec<myvec<int>> graph[], int V)
{
  int co = 0;
  bool vis[V]; // all vertices must be visited once
  for (int i = 0; i < V; i++)
  {
    vis[i] = false;
  }
  for (int i = 0; i < V; i++)
    if (vis[i] == false)
    {
      Bfs(i, graph, vis, V); // doing bfs taking i as src
      co++;
    }
  return co;
}

// funtion to perform dfs operation
void dfsrec(int src, myvec<myvec<int>> graph[], bool vis[])
{
  cout << " " << src << " "; // processing src
  vis[src] = true;           // in dfs when proceesed than mark visited
  for (int i = 0; i < graph[src].getsize(); i++)
  {
    myvec<int> x = graph[src][i];
    if (vis[x[0]] == false)
    {
      dfsrec(x[0], graph, vis); // for all adjacent of src doing dfs taking them as src(if not visited)
    }
  }
}

// wrapper function for dfs
void dfs(myvec<myvec<int>> graph[], int V)
{

  bool vis[V]; // all vertices must be visited once

  for (int i = 0; i < V; i++)
  {
    vis[i] = false;
  }

  for (int i = 0; i < V; i++)
  {
    if (vis[i] == false)
    {
      dfsrec(i, graph, vis); // dfs taking i as src
    }
  }
}

// articulation point
void APUtil(myvec<myvec<int>> graph[], int V, int u, bool visited[], int disc[], int low[], int &timee, int parent, bool ap[])
{

  int children = 0;

  visited[u] = true;

  disc[u] = low[u] = ++timee;

  for (int i = 0; i < V; i++)
  {
    myvec<int> x = graph[u][i];

    int v = x[0];

    if (!visited[v])
    {
      children++;

      APUtil(graph, V, v, visited, disc, low, timee, u, ap);

      low[u] = min(low[u], low[v]);

      if (parent != -1 && low[v] >= disc[u])
      {
        ap[u] = true;
      }
      else if (v != parent)
      {
        low[u] = min(low[u], disc[v]);
      }
      if (parent == -1 && children >= 2)
      {
        ap[u] = true;
      }
    }
  }
}

// articulation point wrapper function
void AP(myvec<myvec<int>> graph[], int V, myvec<string> station)
{
  bool visited[V];
  int disc[V];
  int low[V];
  int timee = 0;
  bool ap[V];
  int parent = -1;
  for (int i = 0; i < V; i++)
  {
    disc[i] = 0;
    visited[i] = false;
    ap[i] = false;
  }

  for (int i = 0; i < V; i++)
    if (visited[i] == false)
    {
      APUtil(graph, V, i, visited, disc, low, timee, parent, ap);
    }

  for (int i = 0; i < V; i++)
    if (ap[i] == true)
    {
      cout << endl
           << i << ") " << station[i] << " is IMP";
    }
}

// to cehck if edge from pos-1 to pos and if vertice already in path 
int issafe(myvec<myvec<int>> graph[], vector<int> path, int val, int pos)
{
  int i;
  myvec<int> a;
  for (i = 0; i < graph[path[pos - 1]].getsize(); i++)
  {
    a = graph[path[pos - 1]][i];
    if (a[0] == val)
    {
      break;
    }
  }
  if (i == graph[path[pos - 1]].getsize())
  {
    return 0;
  }
  for (int j = 0; j < path.size(); j++)
  {
    if (path[j] == val)
    {
      return 0;
    }
  }
  // cout<<a[0]<<a[1]<<endl;
  return a[1];
}

//  utility function to get actual path of station 
void getpathutil(myvec<myvec<int>> graph[], int v, int pos, int dest, vector<int> &spath, vector<int> path, int cost, int &ans)
{

  if (path[pos - 1] == dest)
  {
    if (cost < ans)
    {
      ans = cost;
      for (int i = 0; i < path.size(); i++)
      {
        cout << path[i];
      }
      cout << endl;
      spath = path;
    }

    return;
  }

  if (pos == v)
  {
    return;
  }

  for (int i = 0; i < v; i++)
  {
    if (issafe(graph, path, i, pos))
    {
      path.push_back(i);
      int wt;
      for (int j = 0; j < graph[path[pos - 1]].getsize(); j++)
      {
        myvec<int> a = graph[path[pos - 1]][j];
        if (a[0] == i)
        {
          wt = a[1];
          break;
        }
      }
      cost = cost + wt;
      getpathutil(graph, v, pos + 1, dest, spath, path, cost, ans);
      path.pop_back();
    }
  }
}

// wrapper function to get actual path of station 
bool getpath(myvec<myvec<int>> graph[], int v, int src, int dest, vector<int> &spath)
{
  vector<int> path;
  path.push_back(src);
  int ans = INT_MAX;
  getpathutil(graph, v, 1, dest, spath, path, 0, ans);
  if (ans == INT_MAX)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int main()
{
  int cho;
  while (1)
  {
    cout << "enter 1 for user input and 2 for static input" << endl;
    cin >> cho;
    if (cho == 2)
    {
      myvec<string> station;
      addstation(station, "NDLS");
      addstation(station, "JIIT");
      addstation(station, "Sec-62");
      addstation(station, "Sec-63");
      addstation(station, "Sec-61");
      addstation(station, "J128");

      int v = 6;
      myvec<myvec<int>> graph[100];
      addedge(graph, v, 0, 1, 1);
      addedge(graph, v, 1, 2, 2);
      addedge(graph, v, 1, 4, 8);
      addedge(graph, v, 1, 3, 7);
      addedge(graph, v, 2, 0, 3);
      addedge(graph, v, 3, 1, 4);
      addedge(graph, v, 3, 5, 5);
      addedge(graph, v, 4, 5, 9);
      addedge(graph, v, 5, 1, 6);
      addedge(graph, v, 4, 2, 10);
      addedge(graph, v, 5, 2, 11);

      cout << endl
           << "SAVED MAP USED....";
      print(station);
      cout << endl;
      printgraph(graph, v, station);
      //   int v = 3;
      //       myvec < myvec < int >>graph[100];
      //       addedge (graph, v, 0, 1, 1);
      //       addedge (graph, v, 1, 2, 3);
      //       addedge (graph, v, 1, 0, 2);
      //       addedge (graph, v, 2, 0, 4);

      cout << endl
           << "enter 1 to print the graph:" << endl;
      cin >> cho;
      if (cho == 1)
      {
        cout << endl
             << "enter 1 to perform BFS , 2 to perform DFS, 3 to print adjacency list" << endl;
        cin >> cho;
        int src;
        if (cho == 1)
        {
          //  cout<<endl<<"enter src: "<<endl;
          //  cin>>src;
          cout << endl
               << "BFS:  ";
          int x = bfs(graph, v);
          cout << endl
               << "NO. OF ISLANDS = " << x << endl;
        }
        else if (cho == 2)
        {
          //  cout<<endl<<"enter src: "<<endl;
          //  cin>>src;
          cout << endl
               << "DFS:  ";
          dfs(graph, v);
        }
        else if (cho == 3)
        {
          printgraph(graph, v, station);
        }
      }

      cout << endl
           << "enter 1 to modify grah"
           << endl;
      cin >> cho;
      if (cho == 1)
      {
        modify(graph, v, station);
        cout << endl
             << "enter 1 to print modified graph:" << endl;
        cin >> cho;
        if (cho == 1)
        {
          cout << endl
               << "enter 1 to perform BFS , 2 to perform DFS, 3 to print adjacency list" << endl;
          cin >> cho;
          int src;
          if (cho == 1)
          {
            //  cout<<endl<<"enter src: "<<endl;
            //  cin>>src;
            cout << endl
                 << "BFS:  ";
            int x = bfs(graph, v);
            cout << endl
                 << "NO. OF ISLANDS = " << x << endl;
          }
          else if (cho == 2)
          {
            //  cout<<endl<<"enter src: "<<endl;
            //  cin>>src;
            cout << endl
                 << "DFS:  ";
            dfs(graph, v);
          }
          else if (cho == 3)
          {
            printgraph(graph, v, station);
          }
        }
      }
      cout << endl
           << "enter 1 to perform operation on graph"
           << endl;
      cin >> cho;
      if (cho == 1)
      {
        cout << endl
             << "enter 1 to calculate fare/min " << endl;
        cin >> cho;
        if (cho == 1)
        {
          int s;
          cout << endl
               << "enter source" << endl;
          cin >> s;
          myvec<int> dist = dijsktra(graph, v, s);
          cout << endl
               << "enter 1 to print the whole map and 2 to calcularte for 1 station " << s << " ) " << station[s] << endl;
          cin >> cho;
          if (cho == 1)
          {
            cout << endl
                 << "LIST OF STATIONS ARE:";
            cout << endl
                 << "____________________________________";
            cout << endl
                 << "S.no."
                 << "\t|S.name"
                 << "\t|Time"
                 << "\t|FARE";
            for (int i = 0; i < station.getsize(); i++)
            {
              cout << endl;
              int fare;
              if (dist[i] < 5)
              {
                fare = 5 * dist[i] + 2;
              }
              else if (dist[i] < 8)
              {
                fare = 4 * dist[i];
              }
              else
              {
                fare = 3 * dist[i];
              }
              cout << i << "\t|" << station[i] << "\t|" << dist[i] << "\t|" << fare;
            }

            cout << endl
                 << "____________________________________";
            cout << endl;
          }
          else if (cho == 2)
          {
            int d;
            cout << endl
                 << "enter dest:" << endl;
            cin >> d;
            vector<int> path;

            if (getpath(graph, v, s, d, path))
            {
              cout << endl
                   << "THE MIN DIST/FARE PATH IS:";
              for (int i = 0; i < path.size() - 1; i++)
              {
                cout << " " << path[i] << " -> ";
              }
              cout << path[path.size() - 1];
            }
            cout << endl
                 << "time in mins: " << dist[d];
            cout << endl;
            int fare;
            if (dist[d] < 5)
            {
              fare = 5 * dist[d] + 2;
            }
            else if (dist[d] < 8)
            {
              fare = 4 * dist[d];
            }
            else
            {
              fare = 3 * dist[d];
            }
            cout << "fare in rs.: " << fare;
          }
        }
        // cout<<endl<<"enter 1 to get mst of the network "<<endl;
        // cin>>cho;
        // if(cho==1)
        // {
        //   int sum=0;
        //   if(mst(v,graph,sum))
        //         {cout<<endl<<"M.S.T possible with total weight: "<<sum<<endl;}
        //         else{
        //             cout<<endl<<"M.S.T. not possible "<<endl;
        //         }

        // }
        cout << endl
             << "enter 1 to find imp stations " << endl;
        cin >> cho;
        if (cho == 1)
        {
          AP(graph, v, station);
        }
      }
    }
    else if (cho == 1)
    {
      int s, src, dest, wt;
      cout << endl
           << "ENTER NO. OF STATION " << endl;
      cin >> s;
      myvec<string> station;
      for (int i = 0; i < s; i++)
      {
        string s;
        cout << endl
             << "enter " << i << " th station" << endl;
        cin >> s;
        addstation(station, s);
      }

      print(station);
      int v;
      cout << endl
           << "ENTER NO. OF EDGES " << endl;
      cin >> v;
      myvec<myvec<int>> graph[100];
      for (int i = 0; i < v; i++)
      {
        cout << endl
             << "ENTER SRC " << endl;
        cin >> src;
        cout << endl
             << "ENTER DEST " << endl;
        cin >> dest;
        cout << endl
             << "ENTER WEIGHT OF EDGE FROM " << src << " TO " << dest << endl;
        cin >> wt;
        addedge(graph, v, src, dest, wt);
      }

      cout << endl
           << "enter 1 to print the graph:" << endl;
      cin >> cho;
      if (cho == 1)
      {
        cout << endl
             << "enter 1 to perform bfs , 2 to perform dfs, 3 to print adjacency list" << endl;
        cin >> cho;
        int src;
        if (cho == 1)
        {
          //  cout<<endl<<"enter src: "<<endl;
          //  cin>>src;
          cout << endl
               << "BFS:  ";
          bfs(graph, v);
        }
        else if (cho == 2)
        {
          //  cout<<endl<<"enter src: "<<endl;
          //  cin>>src;
          cout << endl
               << "DFS:  ";
          bfs(graph, v);
        }
        else if (cho == 3)
        {
          printgraph(graph, v, station);
        }
      }

      cout << endl
           << "enter 1 to modify station and 2 to peerform operations"
           << endl;
      cin >> cho;
      if (cho == 1)
      {
        modify(graph, v, station);
        cout << endl
             << "enter 1 to print modified graph:" << endl;
        cin >> cho;
        if (cho == 1)
        {
          printgraph(graph, v, station);
        }
      }
      else if (cho == 2)
      {
        cout << endl
             << "enter 1 to calculate fare/min " << endl;
        cin >> cho;
        if (cho == 1)
        {
          int s;
          cout << endl
               << "enter source" << endl;
          cin >> s;
          myvec<int> dist = dijsktra(graph, v, s);
          cout << endl
               << "enter 1 to print the whole map from and 2 to calcularte for 1 station " << s << " ) " << station[s] << endl;
          cin >> cho;
          if (cho == 1)
            if (cho == 1)
            {
              cout << endl
                   << "LIST OF STATIONS ARE:";
              cout << endl
                   << "____________________________________";
              cout << endl
                   << "S.no."
                   << "\t|S.name"
                   << "\t|Time"
                   << "\t|FARE";
              for (int i = 0; i < station.getsize(); i++)
              {
                cout << endl;
                int fare;
                if (dist[i] < 5)
                {
                  fare = 5 * dist[i] + 2;
                }
                else if (dist[i] < 8)
                {
                  fare = 4 * dist[i];
                }
                else
                {
                  fare = 3 * dist[i];
                }
                cout << i << "\t|" << station[i] << "\t|" << dist[i] << "\t|" << fare;
              }

              cout << endl
                   << "____________________________________";
              cout << endl;
            }
            else if (cho == 2)
            {
              int d;
              cout << endl
                   << "enter dest:" << endl;
              cin >> d;
              cout << endl
                   << "time in mins: " << dist[d];
              cout << endl;
              int fare;
              if (dist[d] < 5)
              {
                fare = 5 * dist[d] + 2;
              }
              else if (dist[d] < 8)
              {
                fare = 4 * dist[d];
              }
              else
              {
                fare = 3 * dist[d];
              }
              cout << "fare in rs.: " << fare;
            }
        }

        cout << endl
             << "enter 1 to find imp stations " << endl;
        cin >> cho;
        if (cho == 1)
        {
          AP(graph, v, station);
        }
      }
    }
    else
    {
      cout << endl
           << "Wrong choice!" << endl;
      cout << endl
           << "DO YOU WANT TO RUN THE CODE AGAIN??" << endl;
      cout << endl
           << "1 for yes 2 for no";
      cin >> cho;
      if (cho == 1)
      {
        continue;
      }
      else
      {
        break;
      }
    }
    cout << endl
         << "DO YOU WANT TO RUN THE CODE AGAIN??" << endl;
    cout << endl
         << "1 for yes 2 for no";
    cin >> cho;
    if (cho == 1)
    {
      continue;
    }
    else
    {
      break;
    }
  }
  return 0;
}