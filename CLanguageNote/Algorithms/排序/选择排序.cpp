void selectSort(int arr[],int len)//ιζ©ζεΊ
{
    for(int i=0; i<len; i++)
    {
        int pos=i;
        for(int j=i+1; j<len; ++j)
        {
            if(arr[j]<arr[pos])
                pos=j;
        }
        swap(arr[i],arr[pos]);
    }
    return ;
}
