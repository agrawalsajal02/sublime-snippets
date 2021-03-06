#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool canplace(ll mat[][9],ll i,ll j,ll n,ll num){
    //three cases
    /*1)not in the same comulm
      2)not in the same row
      3)not in the subgrid
      */
    for(ll x=0;x<n;x++){
     //same row check
  if(mat[i][x]==num){
    return false; }
}
    for(ll x=0;x<n;x++){
     //same com check
  if(mat[x][j]==num){
    return false; }
}
//check for the subgrid
ll tt=sqrt(n);
ll w1=(i/tt)*tt;
ll w2=(j/tt)*tt;
for(ll x=w1;x<w1+tt;x++){
 for(ll w=w2;w<w2+tt;w++){
        if(mat[x][w]==num){
            return false;
        }
    }   
}
return true;



}
bool solversudoko(ll mat[][9],ll i,ll j,ll n){
    //base case
    //we are also crosees last row
    if(i==n){

        for(ll x=0;x<n;x++){
         for(ll w=0;w<n;w++){
             cout<<mat[x][w]<<" ";   
            }
            cout<<endl;   
        }
        cout<<endl;
       // print(mat);
        
        return true;//hame sol mil gya he

    }
//case for the row end
   if(j==n){
    return solversudoko(mat,i+1,0,n);
   } 
if(mat[i][j]!=0){
    return solversudoko(mat,i,j+1,n);
}


//re case
        //we are calling cell by cell and at the end of row we call another row

//rec case
//fill number with possible options (1..9)
for(ll num=1;num<=n;num++){
    if(canplace(mat,i,j,n,num)){
       //assume this is correct
        mat[i][j]=num;
       bool couldwesolve=solversudoko(mat,i,j+1,n);
       if(couldwesolve==true){
        return true;
       }
       //if not solve sudoko we backtrack and try different number       
    mat[i][j]=0;

    }
}
//backtrack here
//all possible number for i,j is tried , therefore we change the 
//the cell to original i.e 0 and return false to backtrack to find next possible answer
return false;






}





int main(){
ll mat[9][9]={
   {5,3,0,0,7,0,0,0,0},
   {6,0,0,1,9,5,0,0,0},
   {0,9,8,0,0,0,0,6,0},
   {8,0,0,0,6,0,0,0,3},
   {4,0,0,8,0,3,0,0,1},
   {7,0,0,0,2,0,0,0,6},
   {0,6,0,0,0,0,2,8,0},
   {0,0,0,4,1,9,0,0,5},
   {0,0,0,0,8,0,0,7,9}
};
//sudoko solver()
solversudoko(mat,0,0,9);


/*output 
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 

*/

}
