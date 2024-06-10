#include <iostream>
#include <vector>

int SequentialSearch() {
    std::vector<int>& arr int target {
        for(size_t i = 0; i < arr.size(); ++i) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1,2,3,4,5,5};
    int target = 5;
    int index = SequentialSearch(arr, target);
    std::cout << "index dari" << target << "adalah" << index << std::endl;
    return 0;
}