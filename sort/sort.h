void bubble_sort(int *ary, int size);

int sorted[10000]; // ** sorted array must be a global variable.
void merge(int* ary, int low, int middle, int high);
void merge_sort(int *ary, int low, int high);

int partition(int* list, int left, int right);
void quick_sort(int* list, int left, int right);

void insertion_sort(int* ary, int size);

void count_sort(int *ary, int size, int exp);
void radix_sort(int *ary, int size);

void bucket_sort(int* ary, int size, int buck_size);

