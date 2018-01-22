#include <iostream>
#include <math.h> 
#include <stdlib.h>
#include <time.h> 

#include <set> 	
#include <map>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#ifdef USE_DEBUG
#define debug(x) std::cout << x << std::endl;
#else
#define debug(x) 
#endif

#define ll long long int

#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)

#define forri(n) for(int i = n - 1; i >= 0; i--)
#define forrj(n) for(int j = n - 1; j >= 0; j--)
#define forrk(n) for(int k = n - 1; k >= 0; k--)

#define fori2(s,n) for(int i = s; i < n; i++)
#define forj2(s,n) for(int j = s; j < n; j++)
#define fork2(s,n) for(int k = s; k < n; k++)

#define forit(v) for(auto it = (v).begin(); it != (v).end(); it++)
#define forrit(v) for(auto it = (v).rbegin(); it != (v).rend(); it++)
#define forit2(v) for(auto it2 = (v).begin(); it2 != (v).end(); it2++)
	