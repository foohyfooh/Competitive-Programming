#include <array>

template<int N>
class BinaryIndexTree{

  private:
    array<int, N + 1> tree;

  public:
    BinaryIndexTree(){
      tree.fill(0);
    }

    void update(int pos, int val){
      for(; pos <= N; pos += pos & -pos)
        tree[pos] += val;
    }

    int query(int pos){
      int sum = 0;
      for(; pos > 0; pos -= pos & -pos)
        sum += tree[pos];
      return sum;
    }

    int rangeQuery(int start, int end){
      return query(end) - query(start - 1);
    }

};
