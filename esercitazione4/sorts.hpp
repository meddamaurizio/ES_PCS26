template<typename T>
int is_sorted(std::vector<T> vec) {
    int N = vec.size();
    for (int i = 1; i < N; i++) {
        if (vec[i] < vec[i-1]){
            return 1;
        }
    }
    return 0;
}