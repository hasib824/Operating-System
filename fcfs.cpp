#include<bits/stdc++.h>
using namespace std;
struct type_a
{
    string p;
    int w;
    int b;

};

struct type_b
{
    string p;
    int w;

};
bool cmp(type_a A,type_a B)
{
   return A.w<B.w;
}
int main()
{
    type_a node;
    type_b node1;
    printf("How many times ? ");
    int t;
    while(scanf("%d",&t)==1)
    {
        for(int g=0;g<t;g++)
        {
            vector<type_a> fc, gantt;
            vector<type_b>wait, turn;
            double awt=0,trnt=0;
            printf("How many process ? : ");
            int pn; scanf("%d",&pn);
            int w,b;
            string pid;
            // inputting the necessary datas
            for(int i=0;i<pn;i++)
            {
                printf("Enter process Id ,  Arrival time , Burst time : ");
                cin>>pid>>w>>b;
                node.p=pid;
                node.w=w;
                node.b=b;
                fc.push_back(node);
            }  // End of Inputting datas
              cout<<"\nEnd of Input : "<<endl;
               cout<<"*******************\n"<<endl;
            //std:: vector<type_a>::iterator it;
            sort(fc.begin(),fc.end(),cmp);  // sorting the Process based on Arrival time
           // Printing the Process
            for(int i=0;i<pn;i++)
            {

               cout<<"id : "<< fc[i].p<<", arrival time : "<<fc[i].w << ", Burst Time : "<<fc[i].b<<endl;
            }
                // end of Printing

            int ager=fc[0].w;
            for(int i=0;i<pn;i++)
            {
               node.p=fc[i].p;
               node.w=ager;
               node.b=ager=node.w+fc[i].b;
               gantt.push_back(node);

                 // Making the Waiting
                node1.p=gantt[i].p;
                node1.w=gantt[i].w-fc[i].w;
                awt=awt+node1.w;
                wait.push_back(node1);
                  // Making the Turnaround
                node1.p=gantt[i].p;
                node1.w=gantt[i].b-gantt[i].w;
                turn.push_back(node1);
                trnt=trnt+node1.w;
            }
            cout<<"\nPrinting The gantt chart : "<<endl;
            cout<<"****************************\n"<<endl;
            for(int i=0;i<pn;i++)
            {

               cout<<"id : "<< gantt[i].p<<", visit time : "<<gantt[i].w << ", finish time : "<<gantt[i].b<<endl;
            }

            awt=awt/pn;
            trnt=trnt/pn;
            cout<<"\nPrinting Waiting and Turnaround time  : "<<endl;
            cout<<"******************************************\n"<<endl;
            for(int i=0;i<pn;i++)
            {

               cout<<"id : "<<  wait[i].p<<", Waiting time : "<<  wait[i].w<< ", Turnaround time : "<< turn[i].w<<endl;
            }
            cout<<"********************************************************\n"<<endl;
            cout<<"The avergae Waiting time is : "<<awt<<endl;

            cout<<"The avergae Turnaround time is : "<<trnt<<endl;

            cout<<"********************************************************\n"<<endl;
        }
    }

    return 0;
}
