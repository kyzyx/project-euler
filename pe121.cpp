#include <iostream>
#include <fstream>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)
#define N 15

using namespace std;

int predsn[N+1][N+1];
int predsd[N+1][N+1];
double preds[N+1][N+1];

int main(){
	fori(N+1){
		forj(N+1){
			predsn[i][j] = 0;
			predsd[i][j] = 1;
			preds[i][j] = 0;
		}
	}
	preds[0][0] = 1;
	predsn[0][0] = 1;
	predsd[0][0] = 1;
	for(int i=1; i<=N; i++){
		cout << i << ": ";
		for(int j=0; j<=i; j++){
			if(j==0){
				predsn[i][j] = predsn[i-1][0]*i;
				predsd[i][j] = predsd[i-1][0]*(i+1);
				preds[i][j] = preds[i-1][0]*(double)i/(i+1);
			}
			else{
				predsn[i][j] = predsn[i-1][j]*i*predsd[i-1][j-1] + predsn[i-1][j-1]*predsd[i-1][j];
				predsd[i][j] = predsd[i-1][j]*predsd[i-1][j-1]*(i+1);
				preds[i][j] = (preds[i-1][j]*i + preds[i-1][j-1])/(double)(i+1);
			}
			//cout << predsn[i][j] << "/" << predsd[i][j] << " ";
		}
		cout << endl;
	}
	
	double tp = 0;
	for(int i=N/2+1; i<=N; i++){
		//cout << preds[N][i] << " ";
		tp += preds[N][i];
	}
	cout << endl<<tp << "->" << (int)(1/tp) << endl;
	//cin.get();
	return 0;
}
