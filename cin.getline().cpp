#include<iostream>
using namespace std;
void read_line(char a[], int n, char delim){
    int i=0;
    char ch;
    ch=cin.get();
    while(ch!=delim){
        a[i]=ch;
        i++;
        ch=cin.get();
        if(i==n-1)
        break;
    }
    a[i]='\0';
}

int main(){
    char a[1000];
    read_line(a,1000,'@');
    cout<<a;
    
    
   return 0;
}