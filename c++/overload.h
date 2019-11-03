#include<iostream>
#include<unordered_set>

/**
 * 结构体需要重载的各种方法
 */
struct numPair
{
    int i,j;
    public:
        //构造函数
        numPair(int first,int second):i(first),j(second){};

        //重载<，SET、MAP等红黑树结构的STL容器默认的排序方法
        bool operator < (const numPair& p) const
        {
            if(i<p.i)
            {
                return true;
            }
            else if(i == p.i && j < p.j)
            {
                return true;
            }

            return false;
        }
        //友元函数实现
        friend bool operator <(const numPair&frist,const numPair&second)
        {
            return false;
        }

        //重载>
        bool operator > (const numPair& p)const
        {
            return false;
        }
        //友元数实现
        friend bool operator>(const numPair&first, const numPair& second)
        {
            return false;
        }

        //重载+
        numPair operator+(const numPair&p)
        {
            numPair temp(i+p.i,j+p.j);
            return temp;
        }
        //重载+
        friend numPair operator+ (const numPair&first,const numPair& second)
        {
            return numPair(first.i+second.i,first.j+second.j);
        }

        //重载输出
        friend std::ostream& operator<<(std::ostream& out,const numPair&p)
        {
            out<<"("<<p.i<<","<<p.j<<")";
            return out;
        }

        //重载输入
        friend std::istream& operator>>(std::istream& in ,const numPair&p)
        {
            // in>>p.i>>p.j;
            return in;
        }

        //重载==
        bool operator==(const numPair&p)const
        {
            return this->i==p.i&&this->j==p.j ? true:false;
        }
        //重载hash算法，作为hashset使用
};

//实现numsPair的比较函数，用于hash的数据结构
//参考地址：https://blog.csdn.net/adream307/article/details/83989213
//https://blog.csdn.net/lpstudy/article/details/54345050
struct numsPairsCmp
{
    bool operator()(const numPair& lhs,const numPair& rhs) const
    {
        return false;
    }
};
//实现numsPair的hash函数，用于hash数据结构
struct numsParisHash
{
    std::size_t operator()(const numPair& rhs)const
    {   
        return std::hash<int>()(rhs.i)^std::hash<int>()(rhs.j);
    }
};

/**
 * 测试函数
 */
int test()
{
    unordered_set<numPair,numsParisHash,numsPairsCmp> numsSet;
    numsSet.insert(numPair(1,2));
    numsSet.insert(numPair(2,1));
    for(auto const &p:numsSet)
    {
        cout<<p<<","<<endl;
    }
    cout<<"hello,world" <<endl;
    return 0;
}

