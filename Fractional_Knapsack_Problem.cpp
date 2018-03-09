#include<iostream>
using namespace std;

void knapsack(float value[],float weight[],float max,int n)
  { float currentw=0,rem;
    float currentval=0;
    int i=0;
      while((currentw<=max)&& (weight[i]<=max-currentw))
       {    currentw = currentw+weight[i];
        currentval = currentval+value[i];
        i++;
        }
     rem=max-currentw;

    if(currentw<max)
       {currentw =currentw+rem;
       currentval=currentval+((rem * value[i])/weight[i] );
       }

   cout<<"\n\nmaximum profit is: "<<currentval;
   cout<<"\ncurrent weight is: "<<currentw;
  }

int  main()
{
  float value[50],weight[50],max;
  int i,n;

  cout<<"Enter the maximum capacity of knapsack: ";
  cin>>max;
  cout<<endl<<"Enter the number of item: ";
  cin>>n;
  cout<<"Enter the values and weight of item"<<endl;
  for( i=0;i<n;i++)
  {cin>>value[i]>>weight[i];
  }

  cout<<"Elements enter by you is \n";
  for( i=0;i<n;i++)
  {cout<<"\nvalue "<<value[i]<<" weight "<<weight[i];
  }
  knapsack(value,weight,max,n);
return 0;
}
