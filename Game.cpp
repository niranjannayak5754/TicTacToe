using namespace std;
int gameFunction(char show[],int run,int pos);
void gameShow(char show[]);
int gameWin(char show[],int row,int pos);
int diagonalWin(char show[]);
int main()
{
    string P1,P2;
    int win=0;
    cout<<"Player 1 : ";getline(cin,P1);cout<<endl;
    cout<<"Player 2 : ";getline(cin,P2);cout<<endl;
    cout<<P1<<"\tVS\t"<<P2<<endl;
    rematch:
    char show[]="_________";
    gameShow(show);

    int run=0,choice,temp[9]; 
    cout<<"Choose the spot(1-9).\n One having his/her represented symbol filled horizontally,vertically or diagonally wins the game else match will be drawn... "<<endl;
    cout<<"Press Enter to start the game"<<endl;

    do
     {
         invalid:
         cin.clear();
         cin.ignore(10000,'\n');
         if(run%2==0)
            cout<<P1<<"'s turn(1-9): "; 
         else
            cout<<P2<<"'s turn(1-9): ";
         if(!(cin>>choice))
         {
             cout<<"input error.. input 'integer value' again"<<endl;
             goto invalid;
         }
         temp[run]=choice;
         for(int a=0;a<run;a++)
         {
             if(choice==temp[a])
             {
                 choice=0;
                 break;
             }
         }   
         switch(choice)
         {
             case 1 ... 9 :
             win=gameFunction(show,run,choice-1);
             break;

             default:
             cout<<"Invalid entry! Choose empty slot"<<endl;
             goto invalid;   
         } 
         if(win==1)
         {
            cout<<"Congratulations! You won..."<<endl;
            goto victory;
         }
         run++;
     } while (run<9);

     cout<<"Whoo... Match tied"<<endl;
     victory:
     string next,same;
     cout<<"Wanna play again (Y/N) : ";getline(cin,next);
     cin.clear();
     cin.ignore(10000,'\n');

     if(next[0]=='Y'||next[0]=='y')
     {
         cout<<"Same Players (Y/N) : ";getline(cin,same);
         cin.clear();
         cin.ignore(10000,'\n');
         if(same[0]=='Y'||same[0]=='y')
         {
             cout<<"Next match"<<endl;
             goto rematch;  
         }
         else
             main();
     }

    return 0;
}

void gameShow(char show[])
{
    for(int a=0;a<9;a++)
    {
        cout<<show[a];
        if(a==2||a==5||a==8)
            cout<<endl;
        else
            cout<<" | ";      
    }
}

int gameFunction(char show[],int run,int pos)
{
    int Fn_val,row,dia_val;
    if(run%2==0)
        show[pos]='N';
    else
        show[pos]='S';
    gameShow(show);      
    if(run>3) 
    {
        switch(pos)
        {
            case 0 ... 2:
            row=0;
            if(pos!=1)
                dia_val=diagonalWin(show);
            break;

            case 3 ... 5:
            row=3;
            Fn_val=gameWin(show,row,pos);
            if(pos==4)
                dia_val=diagonalWin(show);
            break;

            case 6 ... 8:
            row=6;
            Fn_val=gameWin(show,row,pos);
            if(pos!=7)
                dia_val=diagonalWin(show);
            break;
        }
        if(Fn_val==1||dia_val==1)
            return 1;
    } 
    return 0; 
}

int gameWin(char show[],int row,int pos)
{
    for(int a=row;a<row+3;a++)
    {
        if(show[pos]!=show[a])
            goto next;
    }
    return 1;
    next:
    int col=pos-row;
    for(int a=col;a<=col+6;a+=3)
    {
        if(show[pos]!=show[a])
            return 0;
    }
    return 1;
}
int diagonalWin(char show[])
{
    if(show[0]==show[4] && show[4]==show[8])
        return 1;
    else if(show[2]==show[4] && show[4]==show[6])
        return 1;
    else
        return 0;       
}