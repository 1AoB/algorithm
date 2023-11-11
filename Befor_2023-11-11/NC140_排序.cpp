/*
题目地址:
https://www.nowcoder.com/practice/2baf799ea0594abd974d37139de27896?tpId=117&tqId=37851&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
*/
#include <any>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    /*vector<int> MySort(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        return arr;
    }*/
    /*
    vector<int> MySort(vector<int>& arr) {
        //冒泡排序
        int n = arr.size();
        for(int i = 0 ; i < n-1 ; i++)//遍历n-1lun
        {
            for(int j = 0 ; j < n-i-1 ;j++)//每次遍历少一个数
            {
                if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
            }
        }
        return arr;
    }*/
    /*
    vector<int> MySort(vector<int>& arr) {
        //选择排序
        int n = arr.size();
        for(int i = 0 ; i < n-1 ; i ++)
        {
            int min_idx = i;
            for(int j = i+1 ; j < n ; j++){//找到[i,n]范围内,最小数的下标
                if(arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
            swap(arr[i],arr[min_idx]);
        }
        return arr;
    }
    */
    /*
    vector<int> MySort(vector<int>& arr) {
        //插入排序
        //其基本思路:将数组分成已排序和未排序的两部分,每次从未排序的元素中选取一个元素
        //,将它插入到已排序的部分的正常位置
        //
        int n = arr.size();
        //arr[0]是已排序好的,arr[1~n-1]还没排序好
        for(int i = 1 ; i < n ; i++)//遍历每个未排序的元素
        {
            int key = arr[i];//key就是我们要排序的元素,要将它插入到已排序好的部分中的正确位置
            int j = i - 1;//已排序的部分就是[0,j]
            while (j >= 0 && arr[j] > key) {//j不越界 , 只要arr[j]>key,就将arr[j]后移一位,然后j不断前移
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;//最后j会落到<=key的位置,key应该放在j+1的位置
        }
        return arr;
    }*/
    /*
    vector<int>tmp;//新的数组
    void merge_sort(vector<int>& q,int l ,int r)
    {
        if(l>=r)return;
        int mid = l + r >> 1;
        merge_sort(q, l,mid);
        merge_sort(q, mid + 1,r);
        
        int k = 0;//临时数组的下标
        int i = l, j = mid+1 ;//i<mid<r
        while (i <= mid && j <= r) {
            if(q[i] <= q[j])tmp[k++]=q[i++];
            else tmp[k++]=q[j++];
        }
        while (i <= mid) { tmp[k++]=q[i++]; }
        while ( j<=r ) { tmp[k++]=q[j++];}

        for(i=l,j=0;i<=r;i++,j++)q[i]= tmp[j];//将[l,r]放入正确的位置
    }
    vector<int> MySort(vector<int>& arr) {
        int n = arr.size();
        //归并排序
        tmp.resize(n,0);
        merge_sort(arr, 0, n-1);
        return arr;
    }*/

    /*
    void quick_sort(vector<int>& q,int l,int r)
    {
        if(l>=r)return ;
        //i在数组最左边,j在数组最右边
        int x = q[ l+r >>1],i=l-1,j=r+1; //x是最中间的那个数,i要多往前一步,j要多往后一步,因为是do while
        while(i<j)
        {
            do i++; while(q[i] < x);
            do j--; while(q[j] > x);
            if(i<j)swap(q[i],q[j]);
        }
        quick_sort(q,  l, j);
        quick_sort(q, j+1,r);
    }
    vector<int> MySort(vector<int>& arr) {
        int n = arr.size();
        //快速排序
        quick_sort(arr, 0, n-1);
        return arr;
    }*/

    /*
    //我们首先定义了增量序列,然后不断缩小增量序列,对分组内的元素进行插入排序.
    //其中,j>=0 && arr[j]>temp是插入排序的核心部分,他表示如果当前元素比前面的元素小,
    //则将前面的元素后移一位,直到插入位置找到为止
    void shellSort(vector<int>&q , int n)
    {
        //定义增量序列
        int gap = n / 2;
        while(gap > 0)
        {
            for(int i = gap ; i < n ; i++)
            {
                int temp = q[i];
                int j = i - gap;
                while (j >= 0 && q[j]>temp) {
                    q[j+gap] = q[j];
                    j -= gap;
                }
                q[j + gap] = temp;
            }
            gap /= 2;
        }
    }
    vector<int> MySort(vector<int>& arr) {
        int n = arr.size();
        //希尔排序
        shellSort(arr, n);
        return arr;
    }*/


    //我们先建好了一个堆,然后不断地取出堆顶元素,并重新调整剩余元素成为一个新的堆.
    //其中,Heapify()函数用于调整堆的结构,这函数也称"下沉操作",它的作用是将当前节点与其子节点比较并交换位置,直到满足堆的性质为止
    //堆排序
    void heapSort(vector<int>&q,int n)
    {
        //建堆
        for(int i = n/2-1; i >= 0;i--)//这个循环从最后一个非叶子节点开始向前遍历，直到第一个非叶子节点结束。因此，整个建堆过程构建出的就是一个大根堆。
        {
            heapify(q, n, i);
        }
        
        //在堆排序的排序阶段中，我们通过不断地从大根堆的顶部取出元素来进行排序。
        //具体来说，我们每次将堆顶元素与堆底元素交换，然后将堆大小减1并对新的堆顶元素进行下沉操作，使其重新满足堆的性质。
        //这样就可以保证每次从堆顶取出的元素都是当前堆中的最大值。
        //排序
        for(int i = n-1 ; i > 0;i--)
        {
            swap(q[0], q[i]);
            heapify(q, i, 0);
        }
    }
    //调整堆,下沉操作
    void heapify(vector<int>&q,int n ,int i)
    {
        int largest = i;
        int l = 2 * i + 1;//计算左孩子节点
        int r = 2 * i + 2;//计算右孩子节点
        if(l < n && q[l] > q[largest])largest = l;
        if(r < n && q[r] > q[largest])largest = r;
        if(largest != i)
        {
            swap(q[i],q[largest]);
            heapify(q, n, largest);
        }
    }
    vector<int> MySort(vector<int>& arr) {
        int n = arr.size();
        //堆排序
        heapSort(arr, n);
        return arr;
    }
    /*
    1. 大根堆示例：[8, 3, 6, 2, 5, 1, 4]
    在这个示例中，我们可以将其构造成如下的一棵二叉树：
           8
         /   \
        3     6
       / \   / \
      2   5 1   4
    可以看到，这棵二叉树满足大根堆的性质，即任意一颗子树的最大值都是它的根节点。
    <通过堆排序算法，我们可以将大根堆示例中的元素从小到大排列。
    具体来说，堆排序算法中的最后一步是将堆顶元素（即最大值）与堆底元素交换位置，并将堆大小减1，然后再对新的堆顶元素进行下沉操作，使其重新满足大根堆的性质。
    重复这个过程，直到所有元素都已经排好序为止。
    因此，大根堆示例经过堆排序后得到的结果是：
    [1, 2, 3, 4, 5, 6, 8]>
    <注:在堆排序完成后，得到的结果已经不再是一个大根堆了。
    因为在堆排序的过程中，我们将堆顶元素与堆底元素互换位置，并对除去已排序的堆底元素外的部分重新进行堆化操作，以重新构建成一个堆。
    这个过程可能会破坏堆的性质，因此排序完成后得到的结果往往不再是一个堆。>
    2.小根堆示例：[2, 4, 1, 5, 3, 8, 6]
    同样地，我们可以将该示例构造成如下的一棵二叉树： 
           2
         /   \
        4     1
       / \   / \
      5   3 8   6
    可以看到，这棵二叉树满足小根堆的性质，即任意一颗子树的最小值都是它的根节点。
    <同样地，我们也可以将小根堆示例中的元素从小到大排列。
    在这种情况下，堆排序算法中的最后一步操作仍然是将堆顶元素与堆底元素交换位置，并将堆大小减1，然后再对新的堆顶元素进行下沉操作，使其重新满足小根堆的性质。
    重复这个过程，直到所有元素都已经排好序为止。因此，小根堆示例经过堆排序后得到的结果也是：
    [1, 2, 3, 4, 5, 6, 8]>
    需要注意的是，无论是大根堆还是小根堆，它们在经过堆排序后都会变成一个升序（从小到大）的序列。
    差别仅在于建堆时的操作不同（大根堆以及小根堆），对于排序过程而言，都按照从小到大的顺序来进行的。
    */
    //注:已更七大排序算法,还有计数排序、桶排序、基数排序还未更新
};
