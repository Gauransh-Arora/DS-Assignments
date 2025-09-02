#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      return i;
    }
  }
  return -1;
}

int binarySearch(int arr[], int n, int target)
{
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int n, target;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  int arr[100];
  cout << "Enter " << n << " sorted elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "Enter element to search: ";
  cin >> target;

  int linearResult = linearSearch(arr, n, target);
  if (linearResult != -1)
    cout << "Linear Search: Element found at index " << linearResult << endl;
  else
    cout << "Linear Search: Element not found" << endl;

  int binaryResult = binarySearch(arr, n, target);
  if (binaryResult != -1)
    cout << "Binary Search: Element found at index " << binaryResult << endl;
  else
    cout << "Binary Search: Element not found" << endl;

  return 0;
}