#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

class PmergeMe {
private:
    // Funciones de utilidad
    bool isValidNumber(const std::string& str) const;
    int stringToInt(const std::string& str) const;
    double getTimeInMicroseconds(clock_t start, clock_t end) const;
    
    // Algoritmo Ford-Johnson para std::vector
    void fordJohnsonSort(std::vector<int>& container) const;
    void mergeInsertSort(std::vector<int>& arr, int left, int right) const;
    void insertionSort(std::vector<int>& arr, int left, int right) const;
    void merge(std::vector<int>& arr, int left, int mid, int right) const;
    
    // Algoritmo Ford-Johnson para std::deque
    void fordJohnsonSort(std::deque<int>& container) const;
    void mergeInsertSort(std::deque<int>& arr, int left, int right) const;
    void insertionSort(std::deque<int>& arr, int left, int right) const;
    void merge(std::deque<int>& arr, int left, int mid, int right) const;
    
    // Funciones de display
    void printSequence(const std::vector<int>& container, const std::string& prefix, size_t maxDisplay = 10) const;
    void printSequence(const std::deque<int>& container, const std::string& prefix, size_t maxDisplay = 10) const;

public:
    // Constructor
    PmergeMe();
    
    // Destructor
    ~PmergeMe();
    
    // Función principal para procesar argumentos
    void processArguments(int argc, char* argv[]);
    
    // Parsear argumentos a contenedores
    std::vector<int> parseToVector(int argc, char* argv[]) const;
    std::deque<int> parseToDeque(int argc, char* argv[]) const;
    
    // Ordenar y medir tiempo
    double sortVector(std::vector<int>& container) const;
    double sortDeque(std::deque<int>& container) const;
};

#endif