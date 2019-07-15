#include<iostream>
using namespace std;
int chess[8][8];
int f1=0,f2=0;
void hasPosi(int x, int y,int s){
    if(f1==0){
        if(s==64){
            cout<<"yes"<<endl;
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    cout<<chess[i][j]<<" ";
                }
                cout<<endl;
            }
            f1=1;
            return;

        }

        if(((x+1)>=0&&(x+1)<=7)&&((y+2)>=0&&(y+2)<=7)){
            if(chess[x+1][y+2]==0){
                s++;
                chess[x+1][y+2]=s;                
                hasPosi(x+1,y+2,s);
                s--;
                chess[x+1][y+2]=0;
            }
        }

        if(((x+2)>=0&&(x+2)<=7)&&((y+1)>=0&&(y+1)<=7)){
            if(chess[x+2][y+1]==0){
                s++;
                chess[x+2][y+1]=s;                
                hasPosi(x+2,y+1,s);
                s--;
                chess[x+2][y+1]=0;
            }
        }

        if(((x+2)>=0&&(x+2)<=7)&&((y-1)>=0&&(y-1)<=7)){
            if(chess[x+2][y-1]==0){
                s++;
                chess[x+2][y-1]=s;                
                hasPosi(x+2,y-1,s);
                s--;
                chess[x+2][y-1]=0;
            }
        }

        if(((x+1)>=0&&(x+1)<=7)&&((y-2)>=0&&(y-2)<=7)){
            if(chess[x+1][y-2]==0){
                s++;
                chess[x+1][y-2]=s;                
                hasPosi(x+1,y-2,s);
                s--;
                chess[x+1][y-2]=0;
            }
        }

        if(((x-1)>=0&&(x-1)<=7)&&((y-2)>=0&&(y-2)<=7)){
            if(chess[x-1][y-2]==0){
                s++;
                chess[x-1][y-2]=s;            
                hasPosi(x-1,y-2,s);
                s--;
                chess[x-1][y-2]=0;
            }
        }

        if(((x-2)>=0&&(x-2)<=7)&&((y-1)>=0&&(y-1)<=7)){
            if(chess[x-2][y-1]==0){
                s++;
                chess[x-2][y-1]=s;                
                hasPosi(x-2,y-1,s);
                s--;
                chess[x-2][y-1]=0;
            }
        }

        if(((x-2)>=0&&(x-2)<=7)&&((y+1)>=0&&(y+1)<=7)){
            if(chess[x-2][y+1]==0){
                s++;
                chess[x-2][y+1]=s;               
                hasPosi(x-2,y+1,s);
                s--;
                chess[x-2][y+1]=0;
            }
        }
        if(((x-1)>=0&&(x-1)<=7)&&((y+2)>=0&&(y+2)<=7)){
            if(chess[x-1][y+2]==0){
                s++;
                chess[x-1][y+2]=s;                
                hasPosi(x-1,y+2,s);
                s--;
                chess[x-1][y+2]=0;
            }
        }

        return;
    }
    return;
}
int main(){
    int x,y,s=1;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            chess[i][j]=0;
        }
    }
cout<<"Please enter the value of X, Y: ";
cin>>x>>y;
chess[x][y]=s;
hasPosi(x,y,s);
cout<<"end";

return  0;
}