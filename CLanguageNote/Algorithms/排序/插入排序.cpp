void insertSort(int arr[],int len)//ζε₯ζεΊ
{
    if(len<=1)
        return;
    for(int i=1; i<len; ++i)
    {
        int j=i-1;
        int insertvalue=arr[i];
        for(; j>=0; j--)
        {
            if(arr[j]>insertvalue)
            {
                arr[j+1]=arr[j];
            }
            else
                break;
        }
        arr[j+1]=insertvalue;
    }
    return;
}
