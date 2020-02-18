#include <bits/stdc++.h>

using namespace std;

long long int SortCountInv(long long int arr[], long long int first, long long int last);
long long int MergeCountSplitInv(long long int ar[], long long int start, long long int mid, long long int end);

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		long long int n, r;
		scanf("%lld%lld", &n, &r);
		long long int ar[n];
		for(long long int i = 0; i < n; i++)
		{
			scanf("%lld", &ar[i]);
		}
		long long int x = SortCountInv(arr, 0, n - 2);
		if(x % 2 == 1)
			printf("YES\n");
		else
			printf("NO\n");
		t--;
	}
	return 0;
}

long long int SortCountInv(long long int arr[], long long int first, long long int last)
{
	if(last - first + 1 == 1)
	{
		return 0;
	}
	else
	{
		/*long long int leftArray[(last - first) / 2 + 1];
		long long int rightArray[last - first - ((last - first) / 2)];
		long long int i;
		for(i = first; i < last - first + 1; i++)
		{
			if(i <= (last - first) / 2 )
			{
				leftArray[i] = arr[i];
			}
			else
			{
				rightArray[i - ((last - first) / 2) - 1] = arr[i];
			}
		}*/
		long long int i;

		long long int x = SortCountInv(arr, first, first + ((last - first) / 2));
		//printf("left half: %d\n", x);
		
		/*for(i = 0; i <= (last - first) / 2; i++)
			printf("%d  ", leftArray[i]);*/

		long long int y = SortCountInv(arr, last - ((last - first) / 2), last);
		//printf("right half: %d\n", y);
		/*printf("                  ");
		for(i = 0; i <= (last - first) / 2; i++)
			printf("%d  ", rightArray[i]);*/
		long long int z = MergeCountSplitInv(arr, first, last - ((last - first) / 2) - 1, last);
		//printf("split inv%d\n", z);
		/*for(i = 0; i < last - first + 1; i++)
		{
			arr[i] = mergedArray[i];
		}
		return x + y + z;*/
		return x + y + z;
	}
}


long long int MergeCountSplitInv(long long int ar[], long long int start, long long int mid, long long int end)
{
	long long int CountInv = 0;
    long long int kar[end - start + 1];
    long long int i, j, k; // i for left half, j for right half, k for kar 
    for(i = start, j = (mid + 1), k = 0;;)
    {
        if(i <= mid && j <= end)
        {
            if(ar[i] > ar[j])
            {
                kar[k] = ar[j];
                CountInv += mid - i + 1;
                j++;
                k++;
            }
            else if(ar[i] < ar[j])
            {
                kar[k] = ar[i];
                i++;
                k++;
            }
            else
            {
                kar[k] = ar[i];
                k++;
                kar[k] = ar[i];
                k++;
                i++;
                j++;
            }
        }
        else if(i > mid && j <= end)
        {
            kar[k] = ar[j];
            j++; 
            k++;
        }
        else if(j > end && i <= mid)
        {
            kar[k] = ar[i];
            i++;
            k++;
        }
        else if(i > mid && j > end)
        {
            break;
        }
    }
    
    for(i = 0; (i < (end - start + 1)) ; i++)
    {
        ar[start + i] = kar[i];
    }
    return CountInv;
}
 

