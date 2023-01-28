#include <bits/stdc++.h>
using namespace std;
double multiplication(int n,double num){
    if(n==0){
        return 1;
    }
    double numb2=multiplication(n/2,num);
    if(n%2==1){
        return (numb2*numb2)*num;
    }
    else{
        return (numb2*numb2);
    }
}
double findNthRootOfM(int n, int m) {
	double low=1,high=m;
    double eps=1e-6;
    while(high-low>eps){
        double mid=low+(high-low)/2.0;
        double ans=multiplication(n,mid);
        if(ans>m){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    return low;
    
}
int main(){
    cout<<findNthRootOfM(3,27);
}