//Brute force method 
#include <iostream>
using namespace std;


int cell[3][3],x,y;

void printing()
{
    int i,j;
    cout<<endl;
    for(i=0;i<3;i++)
    {	cout<<"-------------"<<endl;
        for(j=0;j<3;j++)
        {
            if(cell[i][j]==0)
                cout<<"| |  ";
            else if(cell[i][j]==1)
                cout<<"|X|  ";
            else
                cout<<"|O|  ";
        }
        cout<<endl;
    }
    cout<<"-------------"<<endl;
}

int checking()

    {
    for(int i=0;i<3;i++)	
    	if((cell[i][0]!=0 and cell[i][0]==cell[i][1] and cell[i][1]==cell[i][2]) or (cell[0][i]!=0 and cell[0][i]==cell[1][i] and cell[1][i]==cell[2][i])) 
        	return 1; 
    
    if(cell[0][0]!=0 and cell[0][0]==cell[1][1] and cell[1][1]==cell[2][2])	
        return 1; 
    else if(cell[0][2]!=0 and cell[0][2]==cell[1][1] and cell[1][1]==cell[2][0]) 
        return 1; 
    else
        return 0;
    
}


void input()
{
    int row,column,block;
    cout<<"choose your block(press number between 1-9) out of empty blocks : ";
    cin>>block;
    row=(block+2)/3;
    column=block%3;
    if(column==0){
    	column=3;
	}
    row--;
    column--;
    if(cell[row][column]!=0)
    {
        cout<<"cell is already filled. choose an empty cell."<<endl;
        input();
    }
    else	{
        cell[row][column]=x;}
}

int defending(int c, int d, int b)
{
    if(b<3)
        return 0;
    else if(cell[0][0]+cell[1][1]+cell[2][2]==2*c and cell[0][0]!=d && cell[1][1]!=d and cell[2][2]!=d)
    {
        for(int i=0;i<3;i++)
        {
            if(cell[i][i]==0)
            {
                cell[i][i]=y;
                cout<<"game state:";
                return 1;
            }
        }
    }
    else if(cell[0][2]+cell[1][1]+cell[2][0]==2*c and cell[0][2]!=d and cell[1][1]!=d and cell[2][0]!=d)
    {
        for(int i=0;i<3;i++)
        {
            if(cell[i][2-i]==0)
            {
                cell[i][2-i]=y;
                cout<<"game state:";
                return 1;
            }
        }
    }
    else
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            if(cell[i][0]+cell[i][1]+cell[i][2]==2*c and cell[i][0]!=d and cell[i][1]!=d and cell[i][2]!=d)
            {
                for(j=0;j<3;j++)
                {
                    if(cell[i][j]==0)
                    {
                        cell[i][j]=y;
                        cout<<"game state:";
                        return 1;                    }
                }
            }
            else if(cell[0][i]+cell[1][i]+cell[2][i]==2*c and cell[0][i]!=d and cell[1][i]!=d and cell[2][i]!=d)
            {
                for(j=0;j<3;j++)
                {
                    if(cell[j][i]==0)
                    {
                        cell[j][i]=y;
                        cout<<"game state:";
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int attacking() 
{
    int i,j;
    if(cell[0][0]+cell[0][2]+cell[2][0]+cell[2][2]==x or cell[0][0]+cell[0][2]+cell[2][0]+cell[2][2]==2*x)
    {
        for(i=0;i<3;i++)
        {
            if( cell[i][0]+cell[i][1]+cell[i][2]==y and (cell[i][0]==y or cell[i][1]==y or cell[i][2]==y) )
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(cell[i][j]==0)
                        {
                            cell[i][j]=y;
                            cout<<"game state:";
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(cell[i][j]==0)
                        {
                            cell[i][j]=y;
                            cout<<"game state:";
                            return 1;
                        }
                    }
                }
            }
            if(cell[0][i]+cell[1][i]+cell[2][i]==y and (cell[0][i]==y or cell[1][i]==y or cell[2][i]==y))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(cell[j][i]==0)
                        {
                            cell[j][i]=y;
                            cout<<"game state:";
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(cell[j][i]==0)
                        {
                            cell[j][i]=y;
                            cout<<"game state:";
                            return 1;
                        }
                    }
                }
                
            }
        }
        
        if(cell[0][0]+cell[1][1]+cell[2][2]==y and (cell[0][0]==y or cell[1][1]==y or cell[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((cell[i][i]==0)and ((cell[i][0]+cell[i][1]+cell[i][2]==y and (cell[i][0]==y or cell[i][1]==y or cell[i][2]==y)) ||( (cell[0][i]+cell[1][i]+cell[2][i]==y)and(cell[0][i]==y or cell[1][i]==y or cell[2][i]==y))))
                {
                    cell[i][i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(cell[i][i]==0)
                {
                    if((cell[i][0]+cell[i][1]+cell[i][2]==x and(cell[i][0]==x or cell[i][1]==x or cell[i][2]==x))and(cell[0][i]+cell[1][i]+cell[2][i]==x and (cell[0][i]==x or cell[1][i]==x or cell[2][i]==x)))
                    {
                        cell[i][i]=y;
                        cout<<"game state:";
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(cell[i][i]==0)
                {
                    cell[i][i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
        }
        else if( cell[0][2]+cell[1][1]+cell[2][0]==y and (cell[0][2]==y or cell[1][1]==y or cell[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(cell[i][2-i]==0 and ((cell[i][0]+cell[i][1]+cell[i][2]==y and (cell[i][0]==y or cell[i][1]==y or cell[i][2]==y))or( (cell[0][2-i]+cell[1][2-i]+cell[2][2-i]==y)and(cell[0][2-i]==y or cell[1][2-i]==y or cell[2][2-i]==y))))
                {
                    cell[i][2-i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(cell[i][2-i]==0)
                {
                    if((cell[i][0]+cell[i][1]+cell[i][2]==x and(cell[i][0]==x or cell[i][1]==x or cell[i][2]==x))and(cell[0][2-i]+cell[1][2-i]+cell[2][2-i]==x and (cell[0][2-i]==x or cell[1][2-i]==x or cell[2][2-i]==x)))
                    {
                        cell[i][2-i]=y;
                        cout<<"game state:";
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(cell[i][2-i]==0)
                {
                    cell[i][2-i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
        }
    }
    else
    {
        if(cell[0][0]+cell[1][1]+cell[2][2]==y and (cell[0][0]==y or cell[1][1]==y or cell[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((cell[i][i]==0)and ((cell[i][0]+cell[i][1]+cell[i][2]==y and(cell[i][0]==y or cell[i][1]==y or cell[i][2]==y)) or( (cell[0][i]+cell[1][i]+cell[2][i]==y)and(cell[0][i]==y or cell[1][i]==y or cell[2][i]==y))))
                {
                    cell[i][i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(cell[i][i]==0)
                {
                    if((cell[i][0]+cell[i][1]+cell[i][2]==x and (cell[i][0]==x or cell[i][1]==x or cell[i][2]==x))and(cell[0][i]+cell[1][i]+cell[2][i]==x and (cell[0][i]==x or cell[1][i]==x or cell[2][i]==x)))
                    {
                        cell[i][i]=y;
                        cout<<"game state:";
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(cell[i][i]==0)
                {
                    cell[i][i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
        }
        
        else if( cell[0][2]+cell[1][1]+cell[2][0]==y and (cell[0][2]==y or cell[1][1]==y or cell[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(cell[i][2-i]==0 and ((cell[i][0]+cell[i][1]+cell[i][2]==y and(cell[i][0]==y or cell[i][1]==y or cell[i][2]==y))or( (cell[0][2-i]+cell[1][2-i]+cell[2][2-i]==y)and(cell[0][2-i]==y or cell[1][2-i]==y or cell[2][2-i]==y))))
                {
                    cell[i][2-i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(cell[i][2-i]==0)
                {
                    if((cell[i][0]+cell[i][1]+cell[i][2]==x and(cell[i][0]==x or cell[i][1]==x and cell[i][2]==x))and(cell[0][2-i]+cell[1][2-i]+cell[2][2-i]==x and(cell[0][2-i]==x and cell[1][2-i]==x or cell[2][2-i]==x)))
                    {
                        cell[i][2-i]=y;
                        cout<<"game state:";
                        return 1;
                    }
                }
            }
            
            for(i=2;i>=0;i--)
            {
                if(cell[i][2-i]==0)
                {
                    cell[i][2-i]=y;
                    cout<<"game state:";
                    return 1;
                }
            }
        }
        
        else
        {
            for(i=0;i<3;i++)
            {
                if( cell[i][0]+cell[i][1]+cell[i][2]==y and (cell[i][0]==y or cell[i][1]==y or cell[i][2]==y) )
                {
                    if(i==1)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(cell[i][j]==0)
                            {
                                cell[i][j]=y;
                                cout<<"game state:"<<endl;
                                return 1;
                            }
                        }
                    }
                    else{
                        for(j=2;j>=0;j--)
                        {
                            if(cell[i][j]==0)
                            {
                                cell[i][j]=y;
                                cout<<"game state:";
                                return 1;
                            }
                        }
                    }
                }
                else if(cell[0][i]+cell[1][i]+cell[2][i]==y and (cell[0][i]==y or cell[1][i]==y or cell[2][i]==y))
                {
                    if(i==1)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(cell[j][i]==0)
                            {
                                cell[j][i]=y;
                                cout<<"game state:";
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for(j=2;j>=0;j--)
                        {
                            if(cell[j][i]==0)
                            {
                                cell[j][i]=y;
                                cout<<"game state:";
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void control(int b)
{
    if(!defending(y,x,b))
    {
        if(!defending(x,y,b))
        {
            if((cell[0][0]+cell[0][2]+cell[2][0]+cell[2][2]==x+y or cell[0][0]+cell[0][2]+cell[2][0]+cell[2][2]==x+2*y) and cell[1][1]==0)
            {
                for(int i=0;i<3;i+=2)
                {
                    for(int j=0;j<3;j+=2)
                        if(cell[i][j]==0)
                        {
                            cell[i][j]=y;
                            cout<<"game state:";
                            goto finish;
                        }
                }
                
            }
            else if(b==2 and cell[1][1]==0)
            {
                cell[1][1]=y;
                cout<<"game state:";
                goto finish;
            }
            if(!attacking())
            {
                if(b==0)
                {
                    int i,j;
                    cell[2][0]=y;
                    for(i=0;i<3;i+=2)
                    {
                        for(j=0;j<3;j+=2)
                            if(cell[i][j]==y)
                                cout<<"game state:";
                    }
                }
                else if(cell[1][1]==0)
                {
                    cell[1][1]=y;
                    cout<<"game state:";
                }
                else
                {
                    int i,j;
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(cell[i][j]==0)
                            {
                                cell[i][j]=y;
                                cout<<"game state:";
                                goto finish;
                            }
                        }
                    }
                }
            }
        }
    }
finish:
    cout<<endl;
}

int main()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cell[i][j]=0;
	cout<<"Choose whether you want to be player1(press 1) or player2(press 2): ";
    
    cin>>x;
    switch(x)
    {	
        case 1:
            y=2;
            printing();
            for(i=0;i<9;)
            {
                input();
                printing();
                i++;
                if(i>=8)
                    break;
                control(i);
                printing();
                i++;
                if(i>5)
                    if(checking())
                    {
                        cout<<"Match won by CPU"<<endl;
                        break;
                    }
            }
            break;
       
        case 2:
            y=1;
            printing();
            for(i=0;i<9;)
            {
                control(i);
                printing();
                i++;
                if(i>4)
                    if(checking())
                    {
                        cout<<"Match won by CPU"<<endl;
                        break;
                    }
                if(i>=8)
                    break;
                input();
                printing();
                i++;
    
            }
            default:
            break;
    }
    if(!checking())
    {
        cout<<"Match is drawn: Neither player nor CPU win"<<endl;
    }
    int n;
    cout<<"IF YOU WANT TO PLAY ONE MORE GAME 'PRESS 1'ELSE 'PRESS 0' : ";
    cin>>n;
    if(n==1)
    {
        main();
    }
    else
        exit(0);
    return 0;
}
