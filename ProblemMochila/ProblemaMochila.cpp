#include <iostream>
using namespace std;

int main()
{
 int n,m;
 int comp=-1;
 int best = 0;
 cout<<"Ingresa N (numero de objetos) y M (peso maximo) "<<endl;
 cin>>n;
 cin>>m;
 n=n+1;
 m=m+1;
 int Mochila[n][m];
 int peso[n+1];
 int ben[n+1];

    for(int i=1;i<n;++i){
     cout<<"Peso ["<<i<<"] : "<<endl;
     cin>>peso[i];
 }

  for(int j=1;j<n;++j){
     cout<<"Beneficio ["<<j<<"] : "<<endl;
     cin>>ben[j];
 }

 for(int i=0;i<m;i++){
     Mochila[0][i]=0;
     if(i<n){
         Mochila[i][0]=0;
     }
 }

 for(int i=1;i<=n-1;++i){
    for(int j=1;j<=m-1;++j){
        if(j-peso[i]<0){
                Mochila[i][j]=Mochila[i-1][j];
        }
        else{
        Mochila[i][j]= max(Mochila[i-1][j], Mochila[i-1][j-peso[i]] + ben[i]);
        }
    }
 }

 for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        if(Mochila[i][j]>comp){
            comp=Mochila[i][j];
            best=Mochila[i][j];
        }
    }
}
cout<<"\n";
cout<<"Mayor Beneficio: "<<best<<endl;
}