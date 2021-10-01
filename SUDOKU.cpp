#include <bits/stdc++.h>

using namespace std;

struct sudoku
{
    bool visited[10];
    int possibility;
    int number;
    list<int> queue;
};

struct location
{ int row,column; };

int assumptions=0;

int find_grid_number(int r , int c)
{
    int row,column;
    
    if(r%3==0)
    { row= r/3; }
    else
    { row= (r/3)+1; }
    
    if(c%3==0)
    { column= c/3; }
    else
    { column= (c/3)+1; }
    
    if(row==2 && column==2)
    { return 5; }
    
    if((row-column)>0)
    { return (row*column)+((row-column)*2); }
    else
    { return (row*column); }
}

int triple_splash(sudoku *arr , int row , int column , int &count)
{
    int i,j,r,c,num,temp,grid,x;
    num= (*(arr+(11*row)+column)).number;
    //cout<<"ROW: "<<row<<"  COLUMN: "<<column<<endl;
     
    for(i=1;i<=9;i++)
    {
        // ROW
        if((*(arr+(11*row)+i)).number==0)
        {
            if( (*(arr+(11*row)+i)).visited[num] == false )
            {
                (*(arr+(11*row)+i)).visited[num] = true;
                (*(arr+(11*row)+i)).queue.remove(num);
                (*(arr+(11*row)+i)).possibility--;
            }
            
            if( (*(arr+(11*row)+i)).possibility == 1)
            {
                x= (*((*(arr+(11*row)+i)).queue.begin()));
                grid= find_grid_number(row,i);
                
                if( (*(arr+(11*row))).visited[x]==false && (*(arr+i)).visited[x]==false && (*(arr+(11*grid)+10)).visited[x]==false)
                {
                    (*(arr+(11*row)+i)).number = x;
                    (*(arr+(11*row)+i)).possibility= 0;
                    (*(arr+(11*row)+i)).queue.clear();
                    
                    (*(arr+(11*row))).visited[x]= true;
                    (*(arr+i)).visited[x]= true;
                    (*(arr+(11*grid)+10)).visited[x]= true;
                    
                    count++;
                    if(count==81)
                    { return 1; }
                    //cout<<"recursion start-------->"<<endl;
                    temp= triple_splash(arr,row,i,count);
                    //cout<<"recursion ends--------->"<<endl;
                    if(temp==1)
                    { return 1; }
                }
                else
                { 
                    //cout<<"row= "<<row<<" column= "<<i<<"   ***row"<<endl;
                    return 0; 
                
                }
            }
        }
        
        //COLUMN
        if((*(arr+(11*i)+column)).number==0)
        {
            if( (*(arr+(11*i)+column)).visited[num] == false )
            {
                (*(arr+(11*i)+column)).visited[num] = true;
                (*(arr+(11*i)+column)).queue.remove(num);
                (*(arr+(11*i)+column)).possibility--;
            }
            
            if( (*(arr+(11*i)+column)).possibility == 1)
            {
                x= (*((*(arr+(11*i)+column)).queue.begin()));
                grid= find_grid_number(i,column);
                //cout<<i<<" "<<x<<endl;
                if( (*(arr+(11*i))).visited[x]==false && (*(arr+column)).visited[x]==false && (*(arr+(11*grid)+10)).visited[x]==false  )
                {
                    (*(arr+(11*i)+column)).number = x;
                    (*(arr+(11*i)+column)).possibility= 0;
                    (*(arr+(11*i)+column)).queue.clear();
                    
                    (*(arr+(11*i))).visited[x]= true;
                    (*(arr+column)).visited[x]= true;
                    (*(arr+(11*grid)+10)).visited[x]= true;
                    
                    count++;
                    if(count==81)
                    { return 1; }
                    //cout<<"recursion start-------->"<<endl;
                    temp= triple_splash(arr,i,column,count);
                    //cout<<"recursion ends--------->"<<endl;
                    if(temp==1)
                    { return 1; }
                }
                else
                { 
                    //cout<<"row= "<<i<<" column= "<<column<<"   ***column"<<endl;
                    return 0; 
                    
                }
            }
        }
    }
    
    if(row%3 == 0)
    { r = (((row/3)-1)*3)+1; }
    else
    { r = ((row/3)*3)+1; }
    
    if(column%3 == 0)
    { c = (((column/3)-1)*3)+1; }
    else
    { c = ((column/3)*3)+1; }
    
    // GRID
    for(i=r; i<=(r+2);i++)
    {
        for(j=c; j<=(c+2) ; j++)
        {
            if( (*(arr+(11*i)+j)).number == 0 )
            {
                if( (*(arr+(11*i)+j)).visited[num] == false )
                {
                    (*(arr+(11*i)+j)).visited[num] = true;
                    (*(arr+(11*i)+j)).queue.remove(num);
                    (*(arr+(11*i)+j)).possibility--;
                }
                
                if( (*(arr+(11*i)+j)).possibility == 1)
                {
                    x= (*((*(arr+(11*i)+j)).queue.begin()));
                    grid= find_grid_number(i,j);
                    
                    if( (*(arr+(11*i))).visited[x]==false && (*(arr+j)).visited[x]==false && (*(arr+(11*grid)+10)).visited[x]==false)
                    {
                        (*(arr+(11*i)+j)).number = x;
                        (*(arr+(11*i)+j)).possibility= 0;
                        (*(arr+(11*i)+j)).queue.clear();
                        
                        (*(arr+(11*i))).visited[x]= true;
                        (*(arr+j)).visited[x]= true;
                        (*(arr+(11*grid)+10)).visited[x]= true;
                        
                        count++;
                        if(count==81)
                        { return 1; }
                        //cout<<"recursion start-------->"<<endl;
                        temp= triple_splash(arr,i,j,count);
                        //cout<<"recursion ends--------->"<<endl;
                        if(temp==1)
                        { return 1; }
                    }
                    else
                    {
                        //cout<<"row= "<<i<<" column= "<<j<<"   ***grid"<<endl;
                        return 0; 
                        
                    }
                }
            }
        }
    }
    
    return 0;
}



location find_min(sudoku arr[][11])
{
    int i,j;
    location loc;
    
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            if(arr[i][j].number==0)
            { 
                loc.row= i;
                loc.column= j;
                return loc;
            }
        }
    }
}

void show(sudoku arr[][11])
{
    int i,j;
    
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        { cout<<arr[i][j].number<<" "; }
        cout<<endl;
    }
}

int solve_sudoku(sudoku arr[][11] , int count)
{
    int temp,r,c,grid;
    location min_poss_vertex;
    list<int>::iterator itr;
    
    // find min_possibility element
    min_poss_vertex = find_min(arr);
    r= min_poss_vertex.row;
    c= min_poss_vertex.column;
    
    grid= find_grid_number(r,c);
    // assume 1 of it and solve
    for(itr= arr[r][c].queue.begin();itr!=arr[r][c].queue.end() ; itr++)
    {
        if(arr[0][c].visited[*itr]==false && arr[grid][10].visited[*itr]==false && arr[r][0].visited[*itr]==false)
        {
            assumptions++;
            arr[r][c].number= (*itr);
            arr[0][c].visited[*itr]= true;
            arr[r][0].visited[*itr]= true;
            
            
            arr[grid][10].visited[*itr]= true;
            count++;
            if(count==81)
            { 
                show(arr);
                return 1;
            }
            
            temp = solve_sudoku(arr,count);
            if(temp==1)
            { return 1; }
            
            count--;
            arr[r][c].number= 0;
            arr[0][c].visited[*itr]= false;
            arr[r][0].visited[*itr]= false;
            
            arr[grid][10].visited[*itr]= false;
            
        }
    }
    
    return 0;
}



int main()
{
    int i,j, input,k,grid,count,temp,error=0,t;
    
    list<int>::iterator itr;
    clock_t time_req;
    
    cin>>t;
    
    while(t--)
    {
        count= 0;
        assumptions=0;
        sudoku arr[10][11];
        
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                arr[0][i].visited[j]=false;
                arr[i][0].visited[j]=false;
                arr[i][10].visited[j]=false;
            }
        }
        
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                cin>>input;
                if(input>=1 && input<=9)
                {
                    count++;
                    arr[i][0].queue.push_back(input);
                    arr[i][0].visited[input]= true;
                    
                    arr[0][j].queue.push_back(input);
                    arr[0][j].visited[input]= true;
                    
                    grid= find_grid_number(i,j);
                    arr[grid][10].queue.push_back(input);
                    arr[grid][10].visited[input]= true;
                    
                    arr[i][j].number = input;
                    arr[i][j].possibility = 0;
                }
                else
                {
                    arr[i][j].number = 0;
                    arr[i][j].possibility = 9;
                    for(k=1;k<=9;k++)
                    { arr[i][j].visited[k]= false; }
                }
            }
        }
    
        cout<<count<<" Known parameters (out of 81)"<<endl;
        
        time_req= clock();
        
        // compensate    (solves medium level sudoku problems)
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                if(arr[i][j].number==0)
                {
                    grid= find_grid_number(i,j);
                    
                    for(itr= arr[i][0].queue.begin() ; itr!= arr[i][0].queue.end() ; itr++)
                    { 
                        if(arr[i][j].visited[*itr]==false)
                        {
                            arr[i][j].visited[*itr]= true; 
                            arr[i][j].possibility--;
                        }
                    }
                    
                    for(itr= arr[0][j].queue.begin() ; itr!= arr[0][j].queue.end() ; itr++)
                    {
                        if(arr[i][j].visited[*itr]==false)
                        {
                            arr[i][j].visited[*itr]= true; 
                            arr[i][j].possibility--;
                        }
                    }
                    
                    for(itr= arr[grid][10].queue.begin() ; itr!= arr[grid][10].queue.end() ; itr++)
                    { 
                        if(arr[i][j].visited[*itr]==false)
                        {
                            arr[i][j].visited[*itr]= true; 
                            arr[i][j].possibility--;
                        }
                    }
                }
            }
        }
        
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                for(k=1;k<=9;k++)
                {
                    if(arr[i][j].visited[k]==false)
                    {
                        arr[i][j].queue.push_back(k);
                    }
                }
            }
        }
        error=0;
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                if(arr[i][j].number==0)
                {
                    if(arr[i][j].possibility==1)
                    {
                        count++;
                        itr= arr[i][j].queue.begin();
                        arr[i][j].number = (*itr);
                        
                        arr[i][0].visited[*itr]= true;
                        arr[0][j].visited[*itr]= true;
                        grid= find_grid_number(i,j);
                        arr[grid][10].visited[*itr]= true;
                        
                        arr[i][j].queue.clear();
                        arr[i][j].possibility= 0;
                        //cout<<"main function call---------------------------->"<<endl;
                        temp= triple_splash(&arr[0][0],i,j,count);
                        //cout<<"main function stops--------------------------->"<<endl;
                        if(temp==1)
                        { 
                            cout<<count<<endl;
                            show(arr); 
                            error=-1;
                            break;
                        }
                    }
                }
            }
            
            if(error==-1)
            { break; }
        }
        // compensation ends
        
        // solve hard level sudoku problems
        if(error==0)
        { solve_sudoku(arr,count); }
        time_req= clock() - time_req;
        
        cout<<"Total assumptions made: "<<assumptions<<endl;
        cout<<"Time taken (in seconds): "<<(float)time_req/CLOCKS_PER_SEC<<endl<<endl;
        
    }
    return 0;
}


