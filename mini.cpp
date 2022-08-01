#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;
struct bat{
    string name;
    int indica,runs, score, total_runs, total_overs, xtras;
};
struct bowl{
    string name;
    int total_overs,runs_given,wickets_taken;
};
int main(){
    int plno;
    int plytyp;
    bat pl1;
    bowl pl2;
    cout<<"Enter the batsmen details:"<<endl;
    fstream bat("bat.txt",ios::app);
    for (int i=0;i<3;i++){
    cout<<"Enter name of player "<<i+1<<endl;
    cin>>pl1.name;fflush(stdin);
    cout<<"enter the runs scored by player "<<i+1<<endl;
    cin>>pl1.runs;fflush(stdin);
    cout<<"Enter the overs played by the player"<<i+1<<endl;
    cin>>pl1.total_overs;fflush(stdin);
    cout<<"Enter the status of the player if out(0) or not(1)"<<endl;
    cin>>pl1.indica;fflush(stdin);
    bat.write((char*)&pl1,sizeof(pl1));
    }
    bat.close();
    fstream f1("bat.txt",ios::in);
    cout<<"\n";
    while(f1.read((char*)&pl1,sizeof(pl1))){
        cout<<"\n\n\n\nBATSMAN DETAILS"<<endl;
        cout<<"name of batsman:"<<pl1.name<<"\n";
        cout<<"runs scored by batsaman:"<<pl1.runs<<"\n";
        cout<<"no of overs played by batsman:"<<pl1.total_overs<<"\n";
    }
    f1.close();
    cout<<"Enter the bowlers details "<<endl;
    fstream bowl("bowl.txt",ios::app);
    for (int i=0;i<3;i++){
        cout<<"Enter the name of the bowler "<<endl;
        cin>>pl2.name;fflush(stdin);
        cout<<"Enter the runs given by the bowler "<<endl;
        cin>>pl2.runs_given;fflush(stdin);
        cout<<"Enter the wickets taken by the bowler "<<endl;
        cin>>pl2.wickets_taken;fflush(stdin);
        cout<<"Enter the total overs played by the  bowler "<<endl;
        cin>>pl2.total_overs;fflush(stdin);
        bowl.write((char *)&pl2,sizeof(pl2));
    }
    bowl.close();
    fstream f2("bowl.txt",ios::in);
    cout<<"BOWLERS DETAILS";
    while(f2.read((char*)&pl2,sizeof(pl2))){
        cout<<"\nbowler Name:"<<pl2.name<<endl;
        cout<<"the runs given by the bowler:"<<pl2.runs_given<<endl;
        cout<<"the wickets taken by the bowler:"<<pl2.wickets_taken<<endl;
        cout<<"total overs played by the bowler:"<<pl2.total_overs;
    }
    f2.close();
   cout<<"Thank you all details recorded!!"<<endl;
   xyz:
     cout<<"Select between batsmen(1) or bowlers(2) to see their details"<<endl;
   abc:
    cin>>plytyp;
   switch (plytyp){
            case 1:
                cout<<"Enter the batsman number to see his details "<<endl<<endl<<endl;
                cin>>plno;
                plno--;
                cout<<"Batsman number :"<<plno+1<<endl;
                cout<<"Batsman name :";
                cout<<pl1.name;
                cout<<"Runs scored by the batsman :"<<pl1.runs<<endl;
                cout<<"Total overs played by the batsman :"<<pl1.total_overs<<endl;
                cout<<"Player status out "<<pl1.indica<<endl;
                break;
            case 2:
                cout<<"Enter the bowlers number to see his details "<<endl<<endl<<endl;
                cin>>plno;
                plno--;
                cout<<"Bowlers name :";
                cout<<pl2.name;
                cout<<"Runs given by the player is :"<<pl2.runs_given<<endl;
                cout<<"Total overs played by the player :"<<pl2.total_overs<<endl;
                cout<<"Total wickets taken by the user :"<<pl2.wickets_taken<<endl;
                break;
            default:
               cout<<" enter a decent value"<<endl;
               goto abc;
    }
cout<<endl<<endl<<endl<<"Do you wish to continue? Y-1 N-2"<<endl;
cin>>plno;
if (plno==1){
   goto xyz;
}
else{
   cout<<"Thank you Press any key to exit";
}
return 0;
}
