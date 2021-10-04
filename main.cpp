#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector<vector <T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {cerr << "\n"; for (auto i : v) { for( auto t : i){cerr<<t; cerr << " ";} cerr<<"\n";}}

void printDFS( int** edges , int n , int sv , bool* visited){

	cout<<sv<<" ";
	visited[sv] = true;

	for( int i = 0; i< n; i++){

		if(i == sv) continue;

		if( edges[sv][i] == 1){
			if( visited[i]) continue;

			printDFS(edges,n,i,visited);
		}
	}

	return;
}


void printBFS(int **edges, int n , int sv , bool *visited){

	queue<int> nodes;
	nodes.push(sv);

	// bool* visited = new bool[n];
	// for( int i = 0; i < n ; i++) visited[i] = 0;

	visited[sv] = 1;

	while(!nodes.empty()){

		int temp = nodes.front();
		nodes.pop();
		cout<<temp<<" ";

		for( int i = 0; i < n ; i++){

			if(edges[temp][i] == 1 && !visited[i]){
				nodes.push(i);
				visited[i] = 1;
			}
		}
	}

}

void DFS( int** edges , int n){

	bool* visited = new bool[n];

	memset(visited , 0, sizeof(visited));

	for( int i = 0; i < n; i++){

		if( !visited[i]) printDFS(edges,n,i,visited);
	}

	delete [] visited;

}

void BFS( int** edges , int n){


	bool* visited = new bool[n];

	memset(visited , 0, sizeof(visited));

	for( int i = 0; i < n; i++){

		if( !visited[i]) printBFS(edges,n,i,visited);
	}

	delete [] visited;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();

	int n,v;
	cin>>n>>v;

	int **edges = new int*[n];
	for( int i = 0; i < n; i++){
		edges[i] = new int[n];
		for( int j = 0; j < n; j++) edges[i][j] = 0;
	}

	// memset(edges , 0 , sizeof(edges));

	for( int i = 0; i < v; i++){
		int f,s;
		cin>>f>>s;

		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	cout<<"Depth First Search : ";
	DFS(edges,n);
	cout<<"\n";

	cout<<"Breadth First Search : ";
	BFS(edges,n);

	for( int i = 0; i < n; i++){

		delete[] edges[i];
	}

	delete [] edges;
 

return 0;

}

/*
Input:
8 9
0 4
0 5
4 3
2 3
2 1
1 3
5 6
3 6
6 7

Ouput:
Depth First Search : 0 4 3 1 2 6 5 7 
Breadth First Search : 0 4 5 3 6 1 2 7 

 */
