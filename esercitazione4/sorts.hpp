
template<typename T>
void BubbleSort(std::vector<T>& v) {

    int N = v.size();
    if (N < 2) return;
    for (int imax = 0; imax < N - 1; imax++) {
        for (int i = 0; i < N - 1 - imax; i++) {
            if (v[i] > v[i+1]) {
                T temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
}

template<typename T>
void InsertionSort(std::vector<T>& v) {
    size_t N = v.size();
    if (N < 2) return;
    for (size_t j = 1; j < N; j++) {
        T key = v[j];
        int i = j-1;
        while (i >= 0 && v[i] > key) {
            v[i+1] = v[i];
            i = i-1;
        }
        v[i+1] = key;
    }
}

template<typename T>
void SelectionSort(std::vector<T>& v) {
    int N = v.size();
    if (N < 2) return;
    for (int i = 0; i < N-1; i++) {
        int min = i;
        for (int j = i+1; j < N; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            T temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}


template<typename T>
void print_vector(const std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
bool is_sorted(const std::vector<T>& v) {
    int N = v.size();
    if (N < 2) return true;
    for (int i = 0; i < N - 1; i++) {
        if (v[i] > v[i+1]) {
            return false;
        }
    }
    return true;
}