using System.Collections.Generic;

namespace DataStructures;

public class BinaryHeap {

    private readonly List<int> heap;
    public int Capacity { get; }
    public int Size { get; private set; }

    public BinaryHeap(int capacity) {
        heap = new List<int>(capacity);
        Capacity = capacity;
    }

    public bool Insert(int value) {
        if (Size == Capacity) {
            return false;
        }

        return true;
    }
}
