// computational geometr

#include <bits/stdc++.h>
using namespace std;

class point{
public:
int x,y;
};

bool cross_pr(point p,point q,point r){
	int x1 = q.x - p.x;
	int y1 = q.y - p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;
	int value = x1*y2 - y1*x2;
	return value<0;
}

void convex_hull(point *points,int n){
	vector<point> hull;
	int left = 0;
	for(int i=1;i<n;i++){
		if(points[i].x < points[left].x){
			left = i;
		}
	}

	int p = left;
	do {
		hull.push_back(points[p]);
		int q = (p+1)%n;
		for(int i=0;i<n;i++){
			if(cross_pr(points[p],points[q],points[i])){
				q = i;
			}
		}
		p = q;
	}
	while(p!=left);

	for(auto it:hull){
		cout<<it.x << " " << it.y << endl;
	}
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr1[n],arr2[n];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}
	point* points = new point[n];
	for(int i=0;i<n;i++){
		point p;
		p.x = arr1[i];
		p.y = arr2[i];
		points[i] = p;
	}
	convex_hull(points,n);
	return 0;
}