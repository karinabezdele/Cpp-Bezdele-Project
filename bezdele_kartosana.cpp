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

//bubblesort(no labas uz kreiso)
void bubblesort2 (int mas[],int n){
    int i,j,x;
    int apm;
    int sal = 0;
    int apm_kopa = 0;
    mas_izvads(mas,n);
    for(j=0;j<n-1;j++){
        cout<<"\nStep = "<<j+1;
        apm = 0;
    
        for (i=n-1;i>j;i--){
            sal++;
            
            if (mas[i] < mas[i-1]){
            x = mas[i];
            mas[i] = mas[i-1];
            mas[i-1] = x;
            apm++;
            apm_kopa++;
            
            mas_izvads(mas,n);
            cout<<endl;
            }
        }
        
        if (apm == 0){
            cout<<"\nMasivs ir sakartots";
            cout<<"\nSalidzinajumu skaits: "<<sal;
            cout<<"\nApmainu skaits: "<<apm_kopa;
            return;
        }
    }
    cout<<"\nSalidzinajumu skaits: "<<sal;
    cout<<"\nApmainu skaits: "<<apm_kopa;
}

//------------------------------------SHAKERSORT-----------------------------------------------
void shakersort (int mas[],int n){ //no kreisas uz labo
    int L = 0;
    int R = n - 1;
    int x, i, st = 0;
    int apm;
    
   mas_izvads(mas,n);
    
    while (L<R){
        apm = 0;
        
        //no kr uz labo
        for(i = L; i < R; i++) {
            
            if (mas[i] > mas[i+1]){
                if (apm == 0) {
                    cout << "\nStep = " << st + 1;
                }
            x = mas[i];
            mas[i] = mas[i+1];
            mas[i+1] = x;
            
            apm++;
            //mas_izvads(mas,n);
            }
            mas_izvads(mas,n);
        }
        R--;
         //no labas uz kr
        for (i = R; i > L; i--) {

            if (mas[i] < mas[i-1]) {
                x = mas[i];
                mas[i] = mas[i-1];
                mas[i-1] = x;

                apm++;
                //mas_izvads(mas, n);
            }
            mas_izvads(mas,n);
        }
        L++; 
        
        if (apm == 0){
            return;
        }
        st++; 
    }
}

void shakersort2 (int mas[],int n){ //no labas uz kreiso
    int L = 0;
    int R = n - 1;
    int x, i, st = 0;
    int apm;
    
    mas_izvads(mas,n);
    
    while (L<R){
        apm = 0;
        
        //no labas uz kr
        for(i = R; i > L; i--) {

            if (mas[i] < mas[i-1]) {
                if (apm == 0) {
                    cout << "\nStep = " << st + 1;
                }
                x = mas[i];
                mas[i] = mas[i-1];
                mas[i-1] = x;

                apm++;
                mas_izvads(mas, n);
            }
        }
        L++;
         //no kr uz labo
        for (i = L; i < R; i++) {

            if (mas[i] > mas[i+1]){
            x = mas[i];
            mas[i] = mas[i+1];
            mas[i+1] = x;
            
            apm++;
            mas_izvads(mas,n);
            }
        }
        R--; 
        
        if (apm == 0){
            return;
        }
        st++; 
    }
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
        //saraksts
        cout<<"\n\t\tSorting Algorithms";
        cout<<"\n 1. BubbleSort(no kr uz labo)";
        cout<<"\n 2. BubbleSort(no labas uz kreiso)";
        cout<<"\n 3. ShakerSort (no kr uz labo)";
        cout<<"\n 4. ShakerSort (no labas uz kreiso)";
        cout<<"\n 0. Exit";
        cout<<"\nInput number: ";
        cin>>choice;
        //alg.izvele
        switch(choice){
            case 1: bubblesort(mas,n); 
            break;
            
            case 2: bubblesort2(mas,n); 
            break;
            
            case 3: shakersort(mas,n); 
            break;
            
            case 4: shakersort2(mas,n); 
            break;
            
            case 0: cout<<"\nExit"; break;
            
            default: cout<<"\nWrong choice";
        }
    }
    while (choice!=0);
    return 0;
}
