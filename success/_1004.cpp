#include <stdio.h>
#include <iostream>
#include <cmath>

#define MAGIC 3
#define MAX_SYS 50

using namespace std;

float distance(int x1, int y1, int x2, int y2){
	return pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
}

int includeFunc(int x1, int y1, int x2, int y2, int cx, int cy, int r){
	int flag_start = 0;
	int flag_end = 0;
	
	if(distance(x1,y1,cx,cy) < r){
		flag_start = 1;
	}
	
	if(distance(x2,y2,cx,cy) < r){
		flag_end = 1;
	}
	
	if(flag_start == 1 && flag_end == 1){
		return 0;
	}
	else if(flag_start == 1 && flag_end == 0){
		return 1;
	}
	else if(flag_start == 0 && flag_end == 1){
		return 2;
	}
	else{
		return 3;
	}
}

int main(){
	int testCase = 0;
	int x1, y1, x2, y2;	int cx, cy, r;
	int common, start, end;
	int system = 0;
	int temp = 0;
	
	scanf("%d", &testCase);
	for(int i = 0; i< testCase; i++){
		common = 0;
		start = 0;
		end = 0;
		
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &system);
		for(int j = 0; j < system; j++){
			scanf("%d %d %d", &cx, &cy, &r);
			temp = includeFunc(x1,y1, x2, y2, cx, cy, r);
			
			switch(temp){
				case 0:
					common++;
					start++;
					end++;
					break;
				case 1:
					start++;
					break;
				case 2:
					end++;
					break;
				default:
					break;
			}
			
		}
		printf("%d\n",(start - common) + (end - common));
		
	}
	
}
