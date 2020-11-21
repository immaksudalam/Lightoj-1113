#include <bits/stdc++.h>
using namespace std;
#define mx 101
int flag[mx][mx];
char grid[mx][mx];
int row, col;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int numpixel;
void floodfill(int i, int j, char type){
    if(i<0 || j<0 || i>row-1 || j>col-1) return;
    if(grid[i][j]==type)numpixel++;
    if(grid[i][j] ==type && flag[i][j] == 0){
        flag[i][j]=1;
        grid[i][j]=type+32;
        for(int k=0; k<8; k++){
             int y = dy[k]+j;
             int x = dx[k]+i;
             floodfill(x, y, type);
        }
    }
}
int main()
{
    int cnt=0;
    memset(flag, 0, sizeof(flag));
    cin>>row>>col;
    getchar();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%c", &grid[i][j]);
        }
        getchar();
    }
    int a[3];
    int val[3];
    for(int k=0; k<3; k++){
    char x;
    if(k==0) x='R';
    else if(k==1) x='G';
    else if(k==2) x='B';
    numpixel=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]==x && flag[i][j]==0){
                cnt++;
                floodfill(i,j, x);
            }
        }
    }
    a[k]=cnt;
    val[k]=numpixel;
    cnt=0;
  }
    for(int i=0; i<3; i++)
    cout<<"Number of colored region is: "<<a[i]<<" "<<val[i]<<endl;
    cout<<"New 2D array is :" <<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) cout<<grid[i][j];
        cout<<endl;
    }
}

