#ifndef FENWICKTREE_H_
#define FENWICKTREE_H_
/** 
    Fenwick trees
    also known as Binary Indexed Trees (BIT)

    Useful for getting the sum of an subset.
    Runtime:
        Create: O(n)
        Compute sum: O(log n)
        Update prefix sums: O(log n)

    Author: Marcus Östling
*/

#include <cstddef>

namespace malg
{

class Fenwicktree 
{
private:
    size_t m_size;
    int *m_table;

    int lowestOneBit(int i);

public:
    explicit Fenwicktree(int size) //Move outside
    {
        m_size = size;
        m_table = new int[size];
        for(unsigned int i = 0; i < size; i++) 
        {
            m_table[i] = 0;
        }
    }

    size_t size();
    void update(int i, int delta);
    int sum(int i);
    int rangeSum(int i, int j);
};

int Fenwicktree::lowestOneBit(int i)
{
    return i&-i;
}

size_t Fenwicktree::size()
{
    return m_size;
}

void Fenwicktree::update(int i, int delta)
{
    while(i < m_size)
    {
        m_table[i] += delta;
        i += this->lowestOneBit(i);
    }
}

int Fenwicktree::sum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += m_table[i];
        i -= this->lowestOneBit(i);
    }
    return sum;
}


int Fenwicktree::rangeSum(int i, int j)
{
    return sum(j) - sum(i-1);

}

} // namespace malg
#endif //FENWICKTREE_H_
