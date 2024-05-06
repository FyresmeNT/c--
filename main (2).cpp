#include <iostream>
using namespace std;

void printArray(float A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void scanArray(float A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
}

void bubbleSort(float A[], int size){
    
	for(int i = 1; i < size; i++)
		for(int j = 0; j < size-i; j++)
			if(A[j] > A[j+1])
				swap(A[j], A[j+1]);
		
}

int min_count(float A[], int size){
    int min=A[0];
    int count;
    for(int i = 0; i < size; i++)
	    if(A[i]==min)
            count++;
    return(count);
}
void MassTrans(float A[], int size, int count){
    int max_count;
    int max=A[size-1];
	for(int i = size-1; i > count-1; i--){
	    printArray(A,i);
	    cout<<endl;
	    if(A[i]==max)
            max_count++;
        else{
            for(int j = 0; j < size-max_count; j++)
                A[j]=A[j]+max*max_count*0.9/(size-max_count);
            cout<<max*max_count*0.9/(size-max_count);    
            max=A[i];
            max_count=1;
            
            cout<<"   )";
            cout<<endl;
        }
    for(int j = 0; j < size-max_count; j++)
                A[j]=A[j]+max*max_count*0.9/(size-max_count);    
	}
}

int main(){ 
    
    setlocale (LC_ALL, "Russian");

    int n,count;
    const int N = 100;
    float A[N];

    cout << "Введите размерность массива: " << endl;
    cin >> n;

    scanArray(A,n);
    bubbleSort(A,n);
    printArray(A,n);
    
    count=min_count(A,n);
    
    MassTrans(A, n, count);
    printArray(A,count);
    printArray(A,count);
return 0;

}