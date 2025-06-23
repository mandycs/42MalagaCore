#include <iostream>
#include <iomanip>
#include "Serializer.hpp"
#include "Data.hpp"

void testBasicSerialization() {
    std::cout << "\n=== Basic Serialization Test ===" << std::endl;
    
    // Create a Data object
    Data* original = new Data(42, "Test Data", 3.14159, true);
    
    std::cout << "Original Data object:" << std::endl;
    original->display();
    std::cout << "Original pointer address: " << original << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serialized value: 0x" << std::hex << serialized << std::dec << std::endl;
    
    // Deserialize back to pointer
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer address: " << deserialized << std::endl;
    
    // Verify they are the same
    std::cout << "\nComparison Results:" << std::endl;
    std::cout << "Pointers are equal: " << (original == deserialized ? "YES" : "NO") << std::endl;
    std::cout << "Data content is equal: " << (*original == *deserialized ? "YES" : "NO") << std::endl;
    
    std::cout << "Deserialized Data object:" << std::endl;
    deserialized->display();
    
    // Clean up
    delete original; // original and deserialized point to the same object
}

void testMultipleObjects() {
    std::cout << "\n=== Multiple Objects Test ===" << std::endl;
    
    // Create multiple Data objects
    Data* data1 = new Data(1, "First", 1.1, true);
    Data* data2 = new Data(2, "Second", 2.2, false);
    Data* data3 = new Data(3, "Third", 3.3, true);
    
    std::cout << "Original objects:" << std::endl;
    std::cout << "data1: "; data1->display();
    std::cout << "data2: "; data2->display();
    std::cout << "data3: "; data3->display();
    
    // Serialize all
    uintptr_t ser1 = Serializer::serialize(data1);
    uintptr_t ser2 = Serializer::serialize(data2);
    uintptr_t ser3 = Serializer::serialize(data3);
    
    std::cout << "\nSerialized values:" << std::endl;
    std::cout << "ser1: 0x" << std::hex << ser1 << std::dec << std::endl;
    std::cout << "ser2: 0x" << std::hex << ser2 << std::dec << std::endl;
    std::cout << "ser3: 0x" << std::hex << ser3 << std::dec << std::endl;
    
    // Deserialize all
    Data* deser1 = Serializer::deserialize(ser1);
    Data* deser2 = Serializer::deserialize(ser2);
    Data* deser3 = Serializer::deserialize(ser3);
    
    std::cout << "\nDeserialized objects:" << std::endl;
    std::cout << "deser1: "; deser1->display();
    std::cout << "deser2: "; deser2->display();
    std::cout << "deser3: "; deser3->display();
    
    // Verify all pointers
    std::cout << "\nPointer Verification:" << std::endl;
    std::cout << "data1 == deser1: " << (data1 == deser1 ? "YES" : "NO") << std::endl;
    std::cout << "data2 == deser2: " << (data2 == deser2 ? "YES" : "NO") << std::endl;
    std::cout << "data3 == deser3: " << (data3 == deser3 ? "YES" : "NO") << std::endl;
    
    // Clean up
    delete data1;
    delete data2;
    delete data3;
}

void testNullPointer() {
    std::cout << "\n=== NULL Pointer Test ===" << std::endl;
    
    Data* nullPtr = NULL;
    std::cout << "Original NULL pointer: " << nullPtr << std::endl;
    
    uintptr_t serializedNull = Serializer::serialize(nullPtr);
    std::cout << "Serialized NULL: 0x" << std::hex << serializedNull << std::dec << std::endl;
    
    Data* deserializedNull = Serializer::deserialize(serializedNull);
    std::cout << "Deserialized NULL: " << deserializedNull << std::endl;
    
    std::cout << "NULL pointers are equal: " << (nullPtr == deserializedNull ? "YES" : "NO") << std::endl;
}

void testRoundTripSerialization() {
    std::cout << "\n=== Round-trip Serialization Test ===" << std::endl;
    
    Data* original = new Data(999, "Round Trip", 9.99, false);
    std::cout << "Starting with: ";
    original->display();
    
    // Multiple round trips
    for (int i = 1; i <= 3; i++) {
        uintptr_t serialized = Serializer::serialize(original);
        Data* deserialized = Serializer::deserialize(serialized);
        
        std::cout << "Round trip " << i << ": " 
                  << (original == deserialized ? "SUCCESS" : "FAILED") << std::endl;
        
        original = deserialized; // Use the deserialized pointer for next iteration
    }
    
    std::cout << "Final object: ";
    original->display();
    
    delete original;
}

int main() {
    std::cout << "=== SERIALIZER TESTING PROGRAM ===" << std::endl;
    
    testBasicSerialization();
    testMultipleObjects();
    testNullPointer();
    testRoundTripSerialization();
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    
    return 0;
}