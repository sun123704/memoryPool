
#include <chrono>
#include <iostream>
#include <vector>
#include "MemoryPools.h"

#define BUFFER_SIZE 256*512

int main() {
  auto start_time = std::chrono::system_clock::now();
  for (int i = 0; i < 100; i++) {
    std::vector<float> vec;
    vec.resize(BUFFER_SIZE);
  }
  auto end_time = std::chrono::system_clock::now();
  auto duration_time = std::chrono::duration_cast<std::chrono::milliseconds>(
      end_time - start_time);
  std::cout << "duration_time: " << duration_time.count() << std::endl;

  start_time = std::chrono::system_clock::now();
  for (int i = 0; i < 100; i++) {
	void* addr = CMemoryPools::Instance().GetBuff(BUFFER_SIZE *4);
	CMemoryPools::Instance().DelBuff(BUFFER_SIZE *4, addr);
  }
  end_time = std::chrono::system_clock::now();
  duration_time = std::chrono::duration_cast<std::chrono::milliseconds>(
      end_time - start_time);
  std::cout << "duration_time: " << duration_time.count() << std::endl;
}