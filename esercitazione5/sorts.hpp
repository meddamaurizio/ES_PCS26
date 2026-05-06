
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
            i--;
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
void merge(std::vector<T>& vec, int sx, int center, int dx) {
	std::vector<T> temp(dx - sx + 1);
	int i = sx, j = center + 1;
	int k = 0;

	while (i <= center && j <= dx) {
		if (vec[i] <= vec[j])
			temp[k++] = vec[i++];
		else
			temp[k++] = vec[j++];
	}

	while (i <= center) temp[k++] = vec[i++];
	while (j <= dx)     temp[k++] = vec[j++];

	for (int m = 0; m < k; m++)
		vec[sx + m] = temp[m];
}

template<typename T>
void MergeSort(std::vector<T>& vec, int sx, int dx) {
	if (sx < dx) {
		int center = sx + (dx - sx) / 2;
		MergeSort(vec, sx, center);
		MergeSort(vec, center + 1, dx);
		merge(vec, sx, center, dx);
	}
}

template<typename T>
void MergeSort(std::vector<T>& v) {
    if (v.size() < 2) return;
    MergeSort(v, 0, v.size() - 1);
}


template<typename T>
int partition(std::vector<T>& v, int p, int r) {
    T x = v[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (v[j] <= x) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[++i], v[r]);
    return i;
}

template<typename T>
void QuickSort(std::vector<T>& v, int p, int r) {
    if (p < r) {
        int q = partition(v, p, r);
        QuickSort(v, p, q-1);
        QuickSort(v, q+1, r);
    }
}

template<typename T>
void QuickSort(std::vector<T>& v) {
    if (v.size < 2) return;
    QuickSort(v, 0, v.size() - 1);
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


// mySort()
template<typename T>
void InsertionSort(std::vector<T>& v, int p, int r) {
    for (int j = p + 1; j <= r; j++) {
        T key = v[j];
        int i = j - 1;
        while (i >= p && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}

template<typename T>
void mySort(std::vector<T>& v, int p, int r) {
    if (p < r) {
        // vettori piccoli con insertionsort
        if (r - p < 100) { // 
            InsertionSort(v, p, r);
        } else {
            int q = partition(v, p, r);
            mySort(v, p, q - 1);
            mySort(v, q + 1, r);
        }
    }
}

template<typename T>
void mySort(std::vector<T>& v) {
    if (v.size() < 2) return;
    mySort(v, 0, (int)v.size() - 1);
}