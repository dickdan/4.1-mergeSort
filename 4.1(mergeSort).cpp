#include <iostream>
using namespace std;
const int MAX = 100;
int s1[MAX], s2[MAX];
void merge(int low, int mid, int high){
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high)
        if(s1[i] < s1[j])
            s2[k++] = s1[i++];
        else
            s2[k++] = s1[j++];
    while(i <= mid)
        s2[k++] = s1[i++];
    while (j <= high)
        s2[k++] = s1[j++];
    for (i = low; i <= high ; i++){
        s1[i] = s2[i];
        cout << s1[i] << " ";
    }
    cout << endl;
}
 
void mergeSort(int a, int b){
	int mid;
    if(a < b){
        mid = (a + b) / 2;
        mergeSort(a, mid);
        mergeSort(mid + 1, b);
        merge(a, mid, b);
    }
}

int main(){
	int n, i;
	cin >> n;
	for(i = 1; i <= n; i++)
	cin >> s1[i];
	s2[i] = 0;
	mergeSort(1, n);
}
