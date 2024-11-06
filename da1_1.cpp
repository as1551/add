#include<iostream>
#include<algorithm>
using namespace std;
struct Item {
int profit;
int weight;
};
bool static comp(Item a , Item b ){
double r1=(double)a.profit/(double)a.weight;
double r2=(double)b.profit/(double)b.weight;
return r1>r2;
}
int main(){
int n,w;
cout<<"enter the total items:";
cin>>n;
Item arr [n] ;
cout<<"enter the total weight:";
cin>>w;
cout<<"enter the weight of the items:";
for(int i =0;i<n;i++){
cout<<"weight for item "<<i<<":"<<endl;
cin>>arr[i].weight;
}
cout<<"enter the profit of the items:"<<endl;
for(int i =0;i<n;i++){
cout<<"profit for item"<<i<<":"<<endl;
cin>>arr[i].profit;
}
sort(arr,arr+n,comp);
int curw=0;
double tp=0.0;
for(int i=0 ; i<n;i++){

if(curw+arr[i].weight<=w){
tp+=arr[i].profit;
curw+=arr[i].weight;

}
else{
int rem=w-curw;
tp+=((double)arr[i].profit / (double)arr[i].weight) * (double)rem;
break;

}
}

cout<<"the max profit is :"<<tp<<endl;

}
