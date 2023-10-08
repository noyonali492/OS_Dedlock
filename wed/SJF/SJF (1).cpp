#include<bits/stdc++.h>


using namespace std;

///BT = 6, Run = 1, Rem = 5

class Process
{
public:
    int id=0; /// Pid
    int At=0; /// Arrival Time
    int Bt=0; /// Burst Time
    int Ct=0; /// Completion Time
    int Wt=0; /// Waiting Time
    int Tat=0; /// Turn Around TIme
    int Rem=0; /// Time reamining to complete the job.
    int Frs=0; /// Time when the process got the CPU. /// Dorkar nai

    /// Print Detials of a Process
    void print()
    {
        cout<<"Process ID ="<<id<<" AT= "<<At<<", BT="<<Bt<<", CT= "<<Ct<<", WT= "<<Wt<<" TAT= "<<Tat<<endl;
    }

    friend bool operator <(const Process &A,const Process &B)
    {
        return A.Bt>B.Bt;
    }

};

/// Input Array to Store All the input Processes
Process Input[100];


/*
3
1 24
5 3
7 3
Input Array
  P A B
  I T T
  D

P111 1 24
P22 5 3
P33 7 3


Tim[0] {}
Tim[1] {P1}
Tim[2] {P2}
Tim[3] {P3}

4
0 8
1 4
2 9
3 5



*/



vector<Process>Tim[100];
priority_queue<Process>ReadyQ;

int Grantt[100];

int main()
{
    int numberOfprocess,x,y;
    cin>>numberOfprocess;  // 3


    for(int i=1;i<=numberOfprocess;i++)
    {

        Process p;
        p.id = i;
        cin>>p.At>>p.Bt;
        Input[i] = p;

        /// Kon time a kon process ashlo, ta timer r vector e save kore rakhlam.
        Tim[p.At].push_back(p);

    }

    for(int i=1;i<=numberOfprocess;i++)
    {
        Input[i].print();
    }


//    0 | 1 | 2| 3| 4| 5| 6|

    bool CPU_Busy=0;
    Process In_CPU;
    int RQSize = 0;
    for(int i=0;i<=100;i++)
    {

        ///step 1
        /// ei time e kono process arrive korse ki/na?
        /// jodi yes, ---> Ready queue


        /// Jodi No,---> ja ase ta e.

        if(Tim[i].size()>0)
        {
            /// Ready Queue te push korte hobe.'

            for(int j=0;j<Tim[i].size();j++)
            {
                ReadyQ.push(Tim[i][j]);
                RQSize++;
            }
        }

        /// Jodi na ashe, tahole kono kaz nai.

        if(CPU_Busy==0 && ReadyQ.size())
        {
            In_CPU=ReadyQ.top();
            ReadyQ.pop();
            CPU_Busy=1;
            In_CPU.Rem = In_CPU.Bt;


            cout<<i<<": "; In_CPU.print();
            cout<<RQSize--<<endl;
        }

        /// "CPU faka & Ready Q te kew ase" - satisfy kore ?
            /// Yes, RQ theke CPU te ekta process dibo.



        /// step 2
        /// Ei muhurte ready Queue te kew ase ki/na
        /// jodi ready Q te kew thake & CPU Faka thake, tobe ready Q theke ekta
        /// process niye take , CUP te dibo. CPU busy declare korbo.

        /// CUP
//            ID = set kora
//            At = set kora
//            BT = Set kora
//            Rem = BT kora

        if(CPU_Busy==1)
        {
            In_CPU.Rem--;
            Grantt[i] = In_CPU.id;
        }

        if(CPU_Busy==1 && In_CPU.Rem==0)
        {
            Process p = In_CPU;
            p.Ct = i+1;
            //BT , AT , CT ,
            p.Wt = p.Ct - p.At - p.Bt;


            CPU_Busy = 0;
            cout<<"Done: ";
            p.print();
        }

        /// Step 3
        ///CPU dekhbe CPU te kono process ase ki/na?
        /// Jodi thake, tobe 1 sec se run korbe, oi process r rem time 1 kobme.
            /// tar rem = 0 ki na!
            /// Jodi 0 hoy, tobe process ta complete,
            /// Amra CPU faka declare korbo.
    }

for(int i=0;i<=30;i++)
{
    cout<<"|";
    if(Grantt[i]>0)cout<<"P";
    cout<<Grantt[i];
}
cout<<endl;

}

/*

3
0 4
0 3
0 3


4
0 6
0 8
0 7
0 3'


3
0 7
10 12
15 3

4
0 6 1
0 8 2
0 7 3
0 3 4


OS Lab:
1) Linux Operating System Installation/ Virtual Box
2) Basic Linux Command
3) Process forking - II
4) CPU Scheduling ( FCFS)
5) CPU Scheduling ( SJF)
6) Priority Scheduling
7) Round Robin Scheduling
8) Deadlock Detection Algorithm
9) Parallel Processing





*/


