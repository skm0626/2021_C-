#include <iostream>
using namespace std;

int cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	if(x1==x2){
		if((x1>x3 && x1<x4)||(x1<x3 && x1>x4)){
			if(y3==y1 || y3 == y2) return 2;
			else if((y3>y1 && y3<y2)||(y3<y1 && y3>y2)) return 1;
			else return 0;
		}
		else if((x1==x3)||(x1==x4)){
			if(y3==y1 || y3 == y2) return 2;
			else if((y3>y1 && y3<y2)||(y3<y1 && y3>y2)) return 2;
			else return 0;
		}
		else {
		    return 0;
		}
	}
	else if(y1==y2){
		if((y1>y3 && y1<y4)||(y1<y3 && y1>y4)){
			if(x3==x1 || x3 == x2) return 2;
			else if((x3>x1 && x3<x2)||(x3<x1 && x3>x2)) return 1;
			else return 0;
		}
		else if((y1==y3)||(y1==y4)){
			if(x3==x1 || x3 == x2) return 2;
			else if((x3>x1 && x3<x2)||(x3<x1 && x3>x2)) return 2;
			else return 0;
		}
		else {
		    return 0;
		}
	}
	return 0;
}

int main(){
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
	cout << cross(x1, y1, x2, y2 ,x3, y3, x4, y4)<< endl;
	return 0;
}
