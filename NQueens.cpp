// Example program
#include <iostream>
#include <string>
using namespace std;
int numberOfSolution = 0;

void invalidate(int arr[][8], int i, int j){
    
                
            if(j==7){
                arr[i][j] -= 1;
            }
            else{
                for(int k=j+1; k<8; k++)
                    arr[i][k]-=1; 
            }

            if(j==0)
                arr[i][j]== -1;
            else{
                for(int k=j-1; k>=0; k--)
                    arr[i][k]-=1;
            }

            if(i==7)
                arr[i][j] -= 1;
            else{           
                for(int k=i+1; k<8; k++)
                    arr[k][j]-=1;
            } 
            if(i==7 || j==7)
                arr[i][j] -= 1;
            else{   
                for(int k=i+1, l=j+1; k<8 || l<8; k++, l++)
                    arr[k][l]-=1;
            }

            if(i==0 || j==7)
                arr[i][j] -= 1;
            else{
                for(int k=i-1, l=j-1; k>=0 || l>=0; k--, l--)
                     arr[k][l]-=1;    
            }
            arr[i][j] = 1;
}
void myInRevalidate(int arr[][8], int i, int j, bool flag){
    int offset = -1;
    if(!flag){
        offset = 1;
    }
    for(int k = 0; k<8;k++){
        arr[i][k] = arr[i][k] + offset; // collumn
        arr[k][j] = arr[k][j] + offset; //row
    }
    int k,l;
    if(i>j){
        k = i-j;
        l = 0;
        
    }else{
        k = 0;
        l = j-i;
    }
    for(;k<8&&l<8;k++,l++){
        arr[k][l] = arr[k][l]+ offset; 
    }
    if(i+j<8){
        k = 0;
        l = i+j;
    }else{
        k = i+j - 7;
        l = 7;
    }
    for(;k>=0&&l>=0;k++,l--){
        arr[k][l] = arr[k][l]+ offset; 
    }
    if(flag){
        arr[i][j] = 1;
    }else{
        arr[i][j] = 0;
    }
}

void revalidate(int arr[][8],int i,int j){
    //if(arr[i][j]==0){
        arr[i][j] = 1;    
    
    for(int k=j+1; k<8; k++)
        arr[i][k]+=1; 
        
    for(int k=j-1; k>=0; k--)
        arr[i][k]+=1;
        
    for(int k=i+1; k<8; k++)
        arr[k][j]+=1;
        
    for(int k=i+1, l=j+1; k<8 || l<8; k++, l++)
        arr[k][l]+=1;
        
    for(int k=i-1, l=j-1; k>=0 || l>=0; k--, l--)
        arr[k][l]+=1;

        for(int k = 0; k<8; k++){
            for(int j = 0; j<8; j++){
                cout<<arr[k][j]<<" ";   
            }
            cout<<"\n";
        }   
        
}


void NQueen(int arr[][8], int i){
   // cout<<"Value of i is"<<i; 
    if(i==8){
        numberOfSolution++;
        for(int k = 0; k<8; k++){
            for(int j = 0; j<8; j++){
                std::cout<<arr[k][j]<<" ";   
            }
            std::cout<<"\n";
        }   
        std::cout<<"\n";
        return;
    }

    for(int j=0; j<8; j++){
         if(arr[i][j] == 0){
            myInRevalidate(arr,i,j,true);
            NQueen(arr, i+1);
            myInRevalidate(arr, i, j,false);
        }
    }
}

int main(){
    int arr[8][8] = {0};
    int i=0;
    NQueen(arr, i);
    std::cout<<numberOfSolution;
    return 0;
}