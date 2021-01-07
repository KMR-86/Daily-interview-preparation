int majorityElement(int a[], int size)
{

    // your code here
    int count = 1;
    int majorityElement = a[0];
    for(int i = 1; i < size; i++){
        if(majorityElement == a[i]){
            count++;
        }
        else{
            count--;
            if(count == 0){
                majorityElement = a[i];
                count = 1;
            }
        }
    }
    count = 0;
    for(int i = 0; i < size; i++){
        if(a[i]==majorityElement)count++;
    }
    if(count > size/2)return majorityElement;
    else return -1;
}
