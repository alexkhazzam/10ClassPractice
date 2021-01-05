#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

class ArrayProcessor
{
private:
    std::string _array_name;
    int _array_length;

public:
    ArrayProcessor();
    ArrayProcessor(std::string arr_name, int array_length);

    int *create_array();

    void sort_array(int array[]);
    void print_array(int array[]);
};

ArrayProcessor::ArrayProcessor()
{
    std::cout << "Class called with no args" << endl;
};

ArrayProcessor::ArrayProcessor(std::string arr_name, int arr_length) : _array_name{arr_name}, _array_length{arr_length} {};

int *ArrayProcessor::create_array()
{
    int *new_arr_ptr{new int[_array_length]{}};
    for (size_t i{0}; i < _array_length; ++i)
    {
        int el{};
        std::cout << "Array " << _array_name << " element " << i + 1 << ": ";
        std::cin >> el;
        new_arr_ptr[i] = el;
    }

    return new_arr_ptr;
}

void ArrayProcessor::print_array(int arr_ptr[])
{
    std::cout << _array_name << ": [";
    for (size_t i{0}; i < _array_length; ++i)
    {
        std::cout << " " << *(arr_ptr + i) << " ";
    }
    std::cout << "]";
    cout << 5 << endl;
}

void ArrayProcessor::sort_array(int arr_ptr[])
{
    for (size_t i{0}; i < static_cast<size_t>(_array_length); ++i)
    {
        for (size_t k{static_cast<size_t>(_array_length)}; k > i; --k)
        {
            if (arr_ptr[k] < arr_ptr[i])
            {
                int cur_el = arr_ptr[k];
                arr_ptr[k] = arr_ptr[i];
                arr_ptr[i] = cur_el;
            }
        }
    }
    std::cout << _array_name << " Sorted: [";
    for (size_t i{0}; i < static_cast<size_t>(_array_length); ++i)
    {
        std::cout << " " << arr_ptr[i] << " ";
    }
    std::cout << "]";
}

int main()
{
    ArrayProcessor *array_1{new ArrayProcessor{}};
    ArrayProcessor *array_2{new ArrayProcessor{"Array2", 5}};

    int *arr2_ptr{array_2->create_array()};
    array_2->print_array(arr2_ptr);
    array_2->sort_array(arr2_ptr);
    std::cout << 5 << std::endl;

    delete array_2;
    delete[] arr2_ptr;

    return 0;
}