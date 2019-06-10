#include<iostream>
#include<conio.h>
using namespace std;
bool moves(int x,int y, int mat [][8], int ith)
{
    int mat1[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            mat1[i][j]=mat[i][j];
        }

    if(ith == 63)
    {
        return true;
    }
    
    if(!((mat[x][y] == -1)&&(ith<63)))
    {
        return false;
    }
        
        mat[x][y]=1;
        ith=ith+1;

    if(((x+1)>=0&&(x+1)<8)&&((y+2)>=0&&(y+2)<8)){
        cout<<x+1 <<y+2 << ith<<endl;
        moves(x+1,y+2,mat1,ith);
        }

    if(((x+2)>=0||(x+2)<8)&&((y+1)>=0||(y+1)<8)){
        cout<<x+2 <<y+1 << ith<<endl;
        moves(x+2,y+1,mat1,ith);
        }


    if(((x+2)>=0||(x+2)<8)&&((y-1)>=0||(y-1)<8)){
        cout<<x+2 <<y-1 << ith<<endl;
        moves(x+2,y-1,mat1,ith);
    }

    if(((x+1)>=0||(x+1)<8)&&((y-2)>=0||(y-2)<8)){
        cout<<x+1 <<y-2 << ith<<endl;
        moves(x+1,y-2,mat1,ith);
        }

    if(((x-1)>=0||(x-1)<8)&&((y-2)>=0||(y-2)<8)){
        cout<<x-1 <<y-2 << ith<<endl;
        moves(x-1,y-2,mat1,ith);
        }

    if(((x-2)>=0||(x-2)<8)&&((y-1)>=0||(y-1)<8)){
        cout<<x-2 <<y-1 << ith<<endl;
        moves(x-2,y-1,mat1,ith);
        }

    if(((x-2)>=0||(x-2)<8)&&((y+1)>=0||(y+1)<8)){
        cout<<x-2 <<y+1 << ith<<endl;
        moves(x-2,y+1,mat1,ith);
        }

    if(((x-1)>=0||(x-1)<8)&&((y+2)>=0||(y+2)<8)){
        cout<<x-1 <<y+2 << ith<<endl;
        moves(x-1,y+2,mat1,ith);
    }
    
    return false;
   

}

int main(){
    int mat[8][8], xPos, yPos, ithCount=0;
    bool solve;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            mat[i][j]=-1;
        }
    cout<<"enter the position of Knights"<<endl;
    cin>>xPos>>yPos;
    solve = moves(xPos,yPos,mat,ithCount);

    cout<<"possible moves:- "<<solve;
    return 0;
}