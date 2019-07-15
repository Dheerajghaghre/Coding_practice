// Example program
#include <iostream>
#include <string>
using namespace std;
int chess[8][8];
int m=0;
int numberOfSolutions = 0;

void isPosi(int s){
   
    if(s==9){

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<chess[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        numberOfSolutions++;
        return;
    }
       
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            
            int flag=0;
            int k,q;
            if(chess[i][j]>=1){
                flag=1;
                break;
                }
            
            if(flag==0) {   
                for( k=i-1;k>=0;k--){
                    if(chess[k][j]>=1){
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                for( k=i+1;k<=7;k++){
                    if(chess[k][j]>=1){
                        flag=1;
                        break;
                    }
                }
            } 
            
            if(flag==0){
                for( k=j-1;k>=0;k--){
                    if(chess[i][k]>=1){
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                for( k=j+1;k<=7;k++){
                    if(chess[i][k]>=1){
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                for( k=i-1,q=j-1;k>=0&&q>=0;k--,q--){
                    if(chess[k][q]>=1){
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                for( k=i+1,q=j+1;k<=7&&q<=7;k++,q++){
                    if(chess[k][q]>=1){
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                for( k=i+1,q=j-1;k<=7&&q>=0;k++,q--){
                    if(chess[k][q]>=1){
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                for( k=i-1,q=j+1;k>=0&&q<=7;k--,q++){
                    if(chess[k][q]>=1){
                        flag=1;
                        break;
                    }
                } 
            }
            
            if(flag==0){
                chess[i][j]=s; 
                s++;                  
                isPosi(s);
                s--;
                chess[i][j]=0;
            }
        }
    }
    return;
}
int main()
{
    int s=1;
  for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
          chess[i][j]=0;
          }
      }
    
    isPosi(s);
    cout<<"number = " <<numberOfSolutions;
    return 0;
}