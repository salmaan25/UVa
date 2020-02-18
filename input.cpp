#include <bits/stdc++.h>
using namespace std;
int main(void) {
	srand(time(0));
	FILE* f = fopen("input.txt", "w");
	fprintf(f,"100 ");
	for(int i = 0; i < 100; i++) {
		int n = rand() % 50;
		fprintf(f, "%d ", n);
		for(int j = 0; j < n; j++) {
			int tmp = rand()%50;
			fprintf(f, "%d ", tmp);
		}
	}
}