#include "PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe() {
}

// Destructor
PmergeMe::~PmergeMe() {
}

// Validar que una string sea un número positivo
bool PmergeMe::isValidNumber(const std::string& str) const {
    if (str.empty()) return false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    
    return true;
}

// Convertir string a int con validación
int PmergeMe::stringToInt(const std::string& str) const {
    if (!isValidNumber(str)) {
        throw std::invalid_argument("Invalid number: " + str);
    }
    
    long num = std::atol(str.c_str());
    if (num <= 0 || num > 2147483647) {
        throw std::out_of_range("Number out of range: " + str);
    }
    
    return static_cast<int>(num);
}

// Calcular tiempo en microsegundos
double PmergeMe::getTimeInMicroseconds(clock_t start, clock_t end) const {
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

// ========== IMPLEMENTACIÓN PARA STD::VECTOR ==========

// Insertion sort para std::vector
void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) const {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge para std::vector
void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) const {
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    
    while (i < leftArr.size()) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    
    while (j < rightArr.size()) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Merge-Insert Sort para std::vector
void PmergeMe::mergeInsertSort(std::vector<int>& arr, int left, int right) const {
    if (left < right) {
        // Usar insertion sort para arrays pequeños (Ford-Johnson optimization)
        if (right - left <= 10) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            
            mergeInsertSort(arr, left, mid);
            mergeInsertSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

// Ford-Johnson Sort para std::vector
void PmergeMe::fordJohnsonSort(std::vector<int>& container) const {
    if (container.size() <= 1) return;
    mergeInsertSort(container, 0, container.size() - 1);
}

// ========== IMPLEMENTACIÓN PARA STD::DEQUE ==========

// Insertion sort para std::deque
void PmergeMe::insertionSort(std::deque<int>& arr, int left, int right) const {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge para std::deque
void PmergeMe::merge(std::deque<int>& arr, int left, int mid, int right) const {
    std::deque<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    
    while (i < leftArr.size()) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    
    while (j < rightArr.size()) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Merge-Insert Sort para std::deque
void PmergeMe::mergeInsertSort(std::deque<int>& arr, int left, int right) const {
    if (left < right) {
        // Usar insertion sort para arrays pequeños (Ford-Johnson optimization)
        if (right - left <= 10) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            
            mergeInsertSort(arr, left, mid);
            mergeInsertSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

// Ford-Johnson Sort para std::deque
void PmergeMe::fordJohnsonSort(std::deque<int>& container) const {
    if (container.size() <= 1) return;
    mergeInsertSort(container, 0, container.size() - 1);
}

// ========== FUNCIONES DE PARSING Y DISPLAY ==========

// Parsear argumentos a std::vector
std::vector<int> PmergeMe::parseToVector(int argc, char* argv[]) const {
    std::vector<int> result;
    
    for (int i = 1; i < argc; ++i) {
        int num = stringToInt(argv[i]);
        result.push_back(num);
    }
    
    return result;
}

// Parsear argumentos a std::deque
std::deque<int> PmergeMe::parseToDeque(int argc, char* argv[]) const {
    std::deque<int> result;
    
    for (int i = 1; i < argc; ++i) {
        int num = stringToInt(argv[i]);
        result.push_back(num);
    }
    
    return result;
}

// Imprimir secuencia de std::vector
void PmergeMe::printSequence(const std::vector<int>& container, const std::string& prefix, size_t maxDisplay) const {
    std::cout << prefix;
    
    for (size_t i = 0; i < container.size() && i < maxDisplay; ++i) {
        std::cout << container[i];
        if (i < container.size() - 1 && i < maxDisplay - 1) {
            std::cout << " ";
        }
    }
    
    if (container.size() > maxDisplay) {
        std::cout << " [...]";
    }
    
    std::cout << std::endl;
}

// Imprimir secuencia de std::deque
void PmergeMe::printSequence(const std::deque<int>& container, const std::string& prefix, size_t maxDisplay) const {
    std::cout << prefix;
    
    for (size_t i = 0; i < container.size() && i < maxDisplay; ++i) {
        std::cout << container[i];
        if (i < container.size() - 1 && i < maxDisplay - 1) {
            std::cout << " ";
        }
    }
    
    if (container.size() > maxDisplay) {
        std::cout << " [...]";
    }
    
    std::cout << std::endl;
}

// Ordenar std::vector y medir tiempo
double PmergeMe::sortVector(std::vector<int>& container) const {
    clock_t start = clock();
    fordJohnsonSort(container);
    clock_t end = clock();
    
    return getTimeInMicroseconds(start, end);
}

// Ordenar std::deque y medir tiempo
double PmergeMe::sortDeque(std::deque<int>& container) const {
    clock_t start = clock();
    fordJohnsonSort(container);
    clock_t end = clock();
    
    return getTimeInMicroseconds(start, end);
}

// Función principal para procesar argumentos
void PmergeMe::processArguments(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::invalid_argument("Error: no input provided");
    }
    
    // Parsear a ambos contenedores
    std::vector<int> vectorContainer = parseToVector(argc, argv);
    std::deque<int> dequeContainer = parseToDeque(argc, argv);
    
    // Mostrar secuencia original
    printSequence(vectorContainer, "Before: ");
    
    // Ordenar y medir tiempos
    double vectorTime = sortVector(vectorContainer);
    double dequeTime = sortDeque(dequeContainer);
    
    // Mostrar secuencia ordenada
    printSequence(vectorContainer, "After:  ");
    
    // Mostrar tiempos
    std::cout << "Time to process a range of " << vectorContainer.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << dequeContainer.size() 
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}