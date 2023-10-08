#include<bits/stdc++.h>
using namespace std;
#define Mx 10

class Process{
public:
    int Pid;  //process id
    int Allocation[Mx]; // allocation input
    int Max[Mx];   //
    int Need[Mx];
    int alreadyexecuted;
    Process(){}

    print(){
//        cout<<"P"<<Pid<<" ";
//        for(int i=1;i<=3;i++)cout<<Allocation[i]<<" ";
//        for(int i=1;i<=3;i++)cout<<Max[i]<<" ";
        for(int i=1;i<=3;i++)cout<<Need[i]<<" ";
        cout<<endl;
    }
};

int Available[10];  //koitha resource

Process P[10];  // koi tha process ase
/*
5 3
1 0 1 0 7 5 3
2 2 0 0 3 2 2
3 3 0 2 9 0 2
4 2 1 1 2 2 2
5 0 0 2 4 3 3
3 3 2 Available resource

*/


int main()
{
    /// number of Process = 5
    /// number of Resources = 3
    int NumberofProcess, NumberofResources;
    cin>>NumberofProcess>>NumberofResources;
    for(int i=1;i<=NumberofProcess;i++)
    {
        Process p;  // process dekliar kore nilam
        p.alreadyexecuted = 0;
        cin>>p.Pid;  // process id input nilam
        for(int j=1;j<=NumberofResources;j++)
        {
            cin>>p.Allocation[j];  //allocation input// kar allocation p.allocation
        }
        for(int j=1;j<=NumberofResources;j++)
        {
            cin>>p.Max[j];  //max resource
        }
        P[i] = p;
    }
//1 2 3
//7 5 3 ->Max
//0 1 7 ->Allocation
//-----
//7 4 3 -> need[i] = Max[i] - Allocation[i];
    for(int j=1;j<=NumberofResources;j++)
        {
            cin>>Available[j];  //Available
        }
    for(int i=1;i<=NumberofProcess;i++)
    {
        for(int j=1;j<=NumberofResources;j++)
        {
            P[i].Need[j] = P[i].Max[j] - P[i].Allocation[j];
       //i tomo processo     need er j tomo index= p[i]er max[j] tomo inddex er valu thake p{i}er allocation[j] er valu subtrction
            if(P[i].Need[j]<0) P[i].Need[j] = 0;
        }
    }

    for(int i=1;i<=NumberofProcess;i++)P[i].print();

//    /// jotokhon porjonto shobgulu process execution sesh na hoy
//        /// P1 to p5 execute korar try korbe
//            --> P[i] already execute hole kisu korte hobe na
//
//            ---> ith process er Need <=Available ki na?
//            ---> jodi availabe hoy, tobe ith process execute korbe,
//                & available resource barbe.

    int ProcessCount = 0;
    while(ProcessCount!=5) /// numofProcess
    {
        for(int i=1;i<=5;i++) //P1 to p5 execute korar try korbe
        {
            if(P[i].alreadyexecuted==0) //P[i] already execute hole kisu korte hobe na
            {
                /// ---> otherwise, chk ??? need<=available
                  possible = true;
                for(int j=1;j<=3;j++)
                {
                    if(P[i].Need[j]>Available[j])possible = false; //ekti pertikuler process er jonno
                }

                /// Jodi possible true --> executable.
                if(possible == true)
                {
                    P[i].alreadyexecuted=1;
                    for(int j=1;j<=3;j++)Available[j]+= P[i].Allocation[j];

                    cout<<"Process P"<<P[i].Pid<<" will be executed\n";
                    ProcessCount++;
                }
                else
                {
                    cout<<"Process P"<<P[i].Pid<<" needs to wait\n";
                }
            }

        }
    }



    return 0;
}
