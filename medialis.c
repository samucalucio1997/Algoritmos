#include <stdio.h>
int main(){
    int n;
    float s=0.0;
    scanf("%d",&n);
    long long d=0,k=0;
    unsigned long long int a[n];
    for(int c=0;c<n;c++){
         scanf("%llu",&a[c]);
         s+=a[c]; 
    }
    s=s/n;
    for(int i=0;i<n;i++){
        if(a[i]<s)
           d++;
        else
           k++;    
    }
    printf("%.1lf\n",s);
    printf("%lld\n",d);
    printf("%lld\n",k);
}
