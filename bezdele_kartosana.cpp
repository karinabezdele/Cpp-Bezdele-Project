#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 1000
using namespace std;

//mas ievads
void mas_ievads(int mas[],int n) {
    int i;
    for (i=0;i<n;i++) {
        cout << "mas[" << i << "]= ";
        cin >> mas[i];
    }
}

//mas izvads
void mas_izvads(int mas[],int n) {
    int i;
    cout<<"\n";
    for (i = 0;i < n;i++) {
        cout << mas[i] << " ";
    }
    cout<<endl;
}
//-----------------------------------BUBBLESORT-----------------------------------------------
//bubblesort(no kreisas uz labo)
void bubblesort (int mas[],int n){
    int i,j,x;
    int apm;
    int sal = 0;
    int apm_kopa = 0;
    mas_izvads(mas,n);
    for(j=0;j<n-1;j++){
        cout<<"\nStep = "<<j+1;
        apm = 0;
    
        for (i=0;i<n-1-j;i++){
            sal++;
            
            if (mas[i] > mas[i+1]){
            x = mas[i];
            mas[i] = mas[i+1];
            mas[i+1] = x;
            apm++;
            apm_kopa++;
            
            mas_izvads(mas,n);
            cout<<endl;
            }
        }
        
        if (apm == 0){
            cout<<"\nSalidzinajumu skaits: "<<sal;
            cout<<"\nApmainu skaits: "<<apm_kopa;
            return;
        }
    }
    cout<<"\nSalidzinajumu skaits: "<<sal;
    cout<<"\nApmainu skaits: "<<apm_kopa;
}


//=======================================MAIN================================================
int main(){
    //srand(time(NULL));
    int mas[N];
    int n,choice;
    cout << "\nn = ";
    cin >> n;
    //arrayInputGen(n, mas);
    mas_ievads(mas, n);
    mas_izvads(mas, n);
    
    do {
        system("cls"); //clear
        //saraksts
        cout<<"\n\t\tSorting Algorithms";
        cout<<"\n 1. BubbleSort(no kr uz labo)";
        
        cout<<"\n 0. Exit";
        cout<<"\nInput number: ";
        cin>>choice;
        //alg.izvele
        switch(choice){
            case 1: bubblesort(mas,n); 
            system("pause>>nul");
            break;
            
            case 0: cout<<"\nExit"; break;
            
            default: cout<<"\nWrong choice";
        }
    }
    while (choice!=0);
    
    
    system("pause>>nul");
    return 0;
}
