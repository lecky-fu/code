/**
 * 堆数据结构和堆排序算法
 * 实现堆的数据结构：
 *      1，数据插入
 *          
 *      2，数据删除
 * 堆排序算法:算法导论堆排序算法实现参考https://www.cnblogs.com/hzhesi/p/3961199.html
 *      1，对于以每个节点为跟的子树，将其构造为最大堆结构
 *      2，从后往前依次将以每个节点为跟的子树构造成最大堆结构，那么整个数组就构成一个二叉堆
 *      3，将二叉堆的根节点依次与二叉堆的最后元素进行交换得到升序排列的数组，从而构成原地排序
 */
#include <vector>
class heap
{
private:
    /* data */
    std::vector<int> heapVec;
    int size;
public:
    heap(/* args */);
    ~heap();

    push_heap(T &ele);
    T pop_heap();

    void heap_sort();    //进行堆排序算法
private:
    void build_maxheap(int size);    //对大小为size的数组进行二叉堆构建
    void max_heapify(int index, int size);   //将以index为根节点、大小为size的
};

/**
 * 效果：构造为原地堆排序
 * 执行过程：
 *  1，将大小为n的数组构造成二叉堆
 *  2，将根节点元素与最后一个元素进行交换
 *  3，n--
 * 结束条件：
 *  1，n=[size,1]
 * 结果：
 *  1，执行完之后，heapVec就会进行inplace排序，元素按照升序排列
 */
void heap::heap_sort()
{
    int curSize = size;

    while (curSize > 1)
    {
        build_maxheap(curSize);

        int temp = heapVec[curSize-1];
        heapVec[curSize-1] = heapVec[0];
        heapVec[0] = temp;

        --curSize;
    }
}

/**
 * 效果：将大小为size的数组构造成二叉堆
 * 执行过程：
 *  1，对于一个大小为size的完全二叉树，从最后一个非叶子节点开始往前的所有节点为根节点的子树，将其构造为二叉堆
 *  2，最后一个非叶子节点索引为size/2 -1,即最后一个节点的父节点
 * 结束条件：
 *  1，index=[size/2-1,0]
 * 效果：
 *  1，执行完成之后，大小为size的完全二叉树就构成了最大堆
 */
void heap::build_maxheap(int size)
{
    int _last_leaf_index = size/2 - 1;  //最后一个非叶子节点的索引
    for (int i = _last_leaf_index; i >= 0; --i)
    {
        max_heapify(i,size);    //将以索引i为根节点，大小为size的子完全二叉树构造成二叉堆
    }
}

/**
 * 效果：对于大小为size的完全二叉树，将以index索引为根节点的子树构造成完全二叉树
 * 函数前提：该函数的前提：假设index的左子树和右子树均为最大堆
 * 执行过程：
 *  1，找出左子节点和右子节点中最大的节点，将index根节点与其进行交换
 *  2，交换之后的新节点为根节点，继续上述过程
 * 结束条件：
 *  1，直到根节点>max(heapVecs[left],heapVec[right])
 */
void heap::max_heapify(int index, int size)
{
    bool check = true;

    while (check)
    {
        int _left_index = 2*index +1;
        int _right_index = _left_index +1;
        int _max_index = index;

        //需要考虑索引超出size范围的情况
        if (_left_index<size && heapVec[_left_index]>heapVec[_max_index])
        {
            _max_index = _left_index;
        }
        if(_right_index<size && heapVec[_right_index]>heapVec[_max_index])
        {
            _max_index = _right_index;
        }

        if(_max_index != index)
        {
            int temp = heapVec[_max_index];
            heapVec[_max_index] = heapVec[index]
            heapVec[index] = temp;

            index = _max_index; //交换根节点继续构造二叉堆
        }
        else
        {
            check = false;      //结束
        }
    }
}


heap::heap(/* args */)
{
}

heap::~heap()
{
}
