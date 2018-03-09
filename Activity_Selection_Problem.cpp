#include<iostream>
using namespace std;

void activities(int s[],int f[],int n){
int i = 0;
for(int j = 1;j < n;j++){
    if(s[j]>=f[i]){
        cout<<j<<" ";
        i=j;

    }
}
}

int main(){
int s[100],f[100],n;
cout<<"Enter element's Value: ";
cin>>n;
cout<<"Enter elements: "<<endl;
for(int i = 0;i<n; i++){
cin>>s[i]>>f[i];
}
activities(s,f,n);

return 0;
}
