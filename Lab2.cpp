#include <iostream>
using namespace std;
//Task no. 1
#define R 5
#define C 4

#define X 2
#define Y 3
#define Z 4

 int main(){
    //1-D array
    int* arr1=new int[R];

    for(int i=0;i<R;i++)
    arr1[i]=i+1;

    cout<<"\nPrinting elements of 1-D array:\n\n";
    for(int i=0;i<R;i++){
        cout<<arr1[i]<<"\t";
        }
    delete[] arr1;

    cout<<endl;

    //2-D array
    int** arr2=new int*[R];
     
    for(int i=0;i<R;i++){
        arr2[i]=new int[C];
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            arr2[i][j]= rand()% 100; 
        }
    }

    cout<<"\nPrinting elements of 2-D array:\n\n";

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<arr2[i][j]<<" , "; 
        }
        cout<<"\b\b \n";
    }
    for(int i=0;i<R;i++)
    delete[] arr2[i];

    delete[] arr2;

    //3-D Array
    int*** arr3=new int**[X];

    for(int i=0;i<X;i++){
        arr3[i]=new int*[Y];
    

    for(int j=0;j<Y;j++)
        arr3[i][j]=new int[Z];
    }

    for(int i=0;i<X;i++)
        for(int j=0;j<Y;j++)
            for(int k=0;k<Z;k++)
                arr3[i][j][k]= rand()% 100;
            
    cout<<"\nPrinting elements of 3-D array:\n\n";

    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            for(int k=0;k<Z;k++){
            cout<<arr3[i][j][k]<<" ,"; 
            }
                cout<<"\b \t";

        }
        cout<<"\b\b \n";
    }

    
    for(int i=0;i<X;i++){
            for(int j=0;j<Y;j++){
                delete[] arr3[i][j];
            }
            delete[] arr3[i];
    }
    delete[] arr3;
 }
    

//Task no. 2
/*
int main(){
    int R,C;
    cout<<"Enter no. of rows of your jagged-array:";
    cin>>R;

    int** p=new int*[R];  //pointer array of R size
    int *Col=new int[R];  //stores how many col each row will have

    for(int i=0;i<R;i++){
        cout<<"Enter no. of column of jagged array no. "<<i+1<<":";
        cin>>C;

        p[i]=new int[C];//actual creation of the row of size C
        Col[i]=C;   //store no. of col in col array
    }

    for(int i=0;i<R;i++){
        cout<<"Enter values in jagged array no. "<<i+1<<endl;
        for(int j=0;j<Col[i];j++){
            cin>>p[i][j];
        }
        cout<<endl;
    }

    cout<<"The values are :\n";
    for(int i=0;i<R;i++){
        cout<<"Entered values in jagged array no. "<<i+1<<" are:";
        for(int j=0;j<Col[i];j++){
            cout<<p[i][j];
            cout<<"\t";
        }
        cout<<endl;
    }

    for(int i=0;i<R;i++)
    delete p[i];
    delete[] p;
    system("pause"); //ask user to press key if wanna c;ise the program

}
  */  

/*
//Task no. 3
int main(){
    int stds, subs;
    cout<<"Total number of students:";
    cin>>stds;

    int** p=new int*[stds];
    int *col=new int[stds];

    for(int i=0;i<stds;i++){
        cout<<"enter no. of subject for student "<<i+1<<":";
        cin>>subs;

        p[i]=new int[subs];
        col[i]=subs;
    }
    for(int i=0;i<stds;i++){
        cout<<"Enter Marks of student no. "<<i+1<<":";
        for(int j=0;j<col[i];j++){
           cin>>p[i][j];
        }
        cout<<endl;
    }
    float avg=0;

    for(int i=0;i<stds;i++){
        cout<<"Student no. "<<i+1<<" marks are:";
        for(int j=0;j<col[i];j++){
            avg+=p[i][j];
            cout<<p[i][j];
            cout<<"\t";
        }
        cout<<"\nAverage :"<<avg/col[i];
        avg=0;
        cout<<endl;
    }
}
*/
