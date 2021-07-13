
#include <iostream>

using namespace std;
int arr[100];

// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

int main()
{   cout<< "Programmed by AKSHAYA RAJ S A\n";
	int n, i;
	cout<<"\n  Enter the number of elements : ";
	cin>>n;
    cout<<"\n  Enter the elements : ";

	for(i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	MergeSort(arr, 0, n-1);

cout<<"\n\n ----------------------------- MERGE SORT ---------------------------";


	cout<<"\n\n  List sorted in ASCENDNG ORDER : ";
	for (i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
	cout<<"\n\n  List sorted in DESCENDING ORDER : ";
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<endl<<endl;
    return 0;
}
