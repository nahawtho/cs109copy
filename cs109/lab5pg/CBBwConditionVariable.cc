#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class CircularBoundedBuffer {
	private:
		int *buffer;
		int capacity;
		int next_in = 0;
		int next_out = 0;
		int occupied = 0;
		std::condition_variable modified;
		std::mutex mutex;
	public:
		CircularBoundedBuffer(int cap);
		void put(int i);
		int get();
};

CircularBoundedBuffer::CircularBoundedBuffer(int cap) {
	capacity = cap;
	buffer = new int[capacity]; //new is malloc in c++
};

void CircularBoundedBuffer::put(int value) {
	std::unique_lock<std::mutex> guard(mutex);
	modified.wait(guard, [this] {
			if (occupied == capacity) return false;
			return true;
			});
	buffer[next_in] = value;
	next_in = (next_in + 1) % capacity;
	occupied++;
	modified.notify_one();
}

int CircularBoundedBuffer::get(){
	std::unique_lock<std::mutex> guard(mutex);
	modified.wait(guard, [this] {
			if (occupied == 0) return false;
			return true;
			});
	int value = buffer[next_out];
	next_out = (next_out + 1) % capacity;
	occupied--;
	modified.notify_one();
	return value;
}

int main(int argc, char *argv[]) {
	CircularBoundedBuffer cbb(4);
	std::thread producer([&] {
			for (int i=0; i < 6; i++) {		
			std::cout << "put " << i << "\n";
			cbb.put(i);
			}
			});
	std::thread consumer([&] {
			for (;;) {
			std::cout << cbb.get() << " get\n";
			}
			});
	producer.join();
	consumer.join();
}













