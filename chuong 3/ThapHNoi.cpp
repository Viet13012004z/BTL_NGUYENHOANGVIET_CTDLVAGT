#include<iostream>
using namespace std;
void chuyen(int n, char a, char b){
	cout<<"\nchuyen dia thu "<< n <<" tu coc "<< a <<" sang coc "<< b;
}
void ThapHN( int n, char a, char b, char c){
	if(n==1) chuyen(1,a,c);
	else {
	ThapHN (n-1,a,c,b);
	chuyen (n,a,c);
	ThapHN(n-1,b,a,c);	
}
}
int main(){
	int n;
	char a='A',b='B',c='C';
	cin>>n;
	ThapHN(n,a,b,c);
}
